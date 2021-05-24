#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <sys/time.h>
#include <stdlib.h>


typedef struct //Estructura que contiene todas las variables de un jugador
    {
        int numero_jugador; //Cantidad de jugadores
        int numero_vidas;
        int ancho_vida,alto_vida; //Alto, ancho imagen vida
        int ancho_municion,alto_municion;//Alto, ancho imagen municion
        int ancho_animacion, alto_animacion;//Alto, ancho imagen animacion
        int contador_bala; //Numero de balas usadas

        _Bool recargando; //Si la funcion recargar esta activa
        _Bool intersecan;//Si 2 jugadores intersecan
        _Bool bala_existe;//Si la bala esta en pantalla
        _Bool interseca_mina;
        _Bool trampa_cargada;
        _Bool interseca_trampa;


        SDL_Texture *animacion; //Texturas relacioadas con el jugador
        SDL_Texture *vidas;
        SDL_Texture *bala;
        SDL_Texture *municion;
        SDL_Texture *trampa;

        SDL_Rect posicion_trampa;

        SDL_Rect posicion_bala;

        SDL_Rect recortar_vidas; //Recortar hara referencia a la parte de la imagen que se recorta
        SDL_Rect posicion_vidas;

        SDL_Rect recortar_animacion;
        SDL_Rect posicion_animacion;

        SDL_Rect recortar_municion;
        SDL_Rect posicion_municion;

    }variables_jugador;

typedef struct
    {
    SDL_Texture *muro;
    SDL_Texture *mina;
    SDL_Texture *explosion;


    SDL_Rect posicion_muro;
    SDL_Rect recortar_muro;
    SDL_Rect posicion_mina;
    SDL_Rect recortar_mina;
    SDL_Rect posicion_explosion;

    _Bool mina_existe;
    _Bool explota;

    int numero_muro;
    }variables_barrera;



SDL_Texture *cargar_texturas (char ruta[50],SDL_Renderer *render); //Crea las texturas
void you_win (SDL_Rect *posicion_texto, int numero_vidas, SDL_Renderer *escenario, SDL_Texture *texto); //Cuando termina el juego dice quién ha ganado
void generar_jugador(variables_jugador jugador[], int numero_jugador, SDL_Renderer *escenario, _Bool cargar); //Crea el jugador (establece valores predeterminados para cada componente)
void copiar_atributos(variables_jugador jugador[], int numero_jugador, SDL_Renderer *escenario); //Mejorar legibilidad, presenta el escenario en pantalla
void destruir_atributos(variables_jugador jugador[], int numero_jugador); //Mejorar legibilidad, destruye las texturas,renders,etc...utilizados
void movimiento_jugador(variables_jugador jugador[], int numero_jugador, int *tiempo);//Permite moverse al jugador
void limites_mapa(variables_jugador jugador[],int numero_jugador);//En qué zona de la pantalla puedes moverte
void disparar (variables_jugador jugador[], int numero_jugador, variables_jugador victima[], int numero_victima, SDL_Renderer *escenario, int *distx, int *disty);//Crea una bala a modo de disparo
void recargar_y_movimiento(variables_jugador jugador[], int numero_jugador, int *tiempo_recarga, int distx, int disty);//Establece un tiempo hasta disparar la próxima bala y permite su movimiento
void interseccion(variables_jugador jugador[], int numero_jugador,variables_jugador victima[], int numero_victima);//Indica si dos objetos intersecan
void vidas_restantes(variables_jugador victima[], int numero_victima);//Cuando 2 objetos intersecan resta una vida al especificado
void fichero (variables_jugador jugador[], int numero_jugador, char nombre_partida[]); //Guarda los datos de la partida en un fichero
void cargar_partida(variables_jugador jugador[], int numero_jugador, _Bool cargar,  SDL_Renderer *escenario, char nombre_partida[]); //Lee el fichero y asigna cada los valores a cada jugador en el caso de que se quiera recuperar la partida
void datos_partida(char nombre_partida[50]);//Imprime los datos de la partida
void multijugador(_Bool cargar, char nombre_partida[]);//Funcion principal
void cargar_muro (variables_barrera barrera[],int numero_barrera, SDL_Renderer *escenario, char ruta[50], char ruta_mina[50]);
void hacer_muro (int x,int y, int w, int h, int n, char direccion_muro,variables_barrera barrera[],int numero_barrera,
                 SDL_Renderer *escenario,variables_jugador jugador[], int numero_jugador);
void mina(variables_barrera barrera[],int numero_barrera,SDL_Renderer *escenario,variables_jugador jugador[], int numero_jugador, int *tiempo_mina);
void interseccion_mina(variables_jugador jugador[], int numero_jugador,variables_barrera barrera[], int numero_barrera);
void explosion_mina(variables_jugador jugador[], int numero_jugador, variables_barrera barrera[],int numero_barrera);

void mapa_multijugador(variables_barrera barrera[], int numero_barrera, SDL_Renderer *escenario, variables_jugador jugador[], int numero_jugador); //Provisional
void mapa_1(variables_barrera barrera[], int numero_barrera, SDL_Renderer *escenario, variables_jugador jugador[], int numero_jugador);
void mapa_2(variables_barrera barrera[], int numero_barrera, SDL_Renderer *escenario, variables_jugador jugador[], int numero_jugador);
void mapa_3(variables_barrera barrera[], int numero_barrera, SDL_Renderer *escenario, variables_jugador jugador[], int numero_jugador);
void mapa_4(variables_barrera barrera[], int numero_barrera, SDL_Renderer *escenario, variables_jugador jugador[], int numero_jugador);
void hacer_mina(variables_barrera barrera[],int numero_barrera,SDL_Renderer *escenario,variables_jugador jugador[],double elapsed,double *segma,char ruta_mina[50],int *chocan);
void interseccion_trampa(variables_jugador jugador[], int numero_jugador, variables_jugador victima[], int numero_victima);
