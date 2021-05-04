#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

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


        SDL_Texture *animacion; //Texturas relacioadas con el jugador
        SDL_Texture *vidas;
        SDL_Texture *bala;
        SDL_Texture *municion;

        SDL_Rect posicion_bala;

        SDL_Rect recortar_vidas; //Recortar hara referencia a la parte de la imagen que se recorta
        SDL_Rect posicion_vidas;

        SDL_Rect recortar_animacion;
        SDL_Rect posicion_animacion;

        SDL_Rect recortar_municion;
        SDL_Rect posicion_municion;

    }variables_jugador;

SDL_Texture *cargar_texturas (char ruta[50],SDL_Renderer *render); //Crea las texturas
void you_win (SDL_Rect *posicion_texto, int numero_vidas, SDL_Renderer *escenario, SDL_Texture *texto); //Cuando termina el juego dice quién ha ganado
void generar_jugador(variables_jugador jugador[], int numero_jugador, SDL_Renderer *escenario); //Crea el jugador (establece valores predeterminados para cada componente)
void copiar_atributos(variables_jugador jugador[], int numero_jugador, SDL_Renderer *escenario); //Mejorar legibilidad, presenta el escenario en pantalla
void destruir_atributos(variables_jugador jugador[], int numero_jugador); //Mejorar legibilidad, destruye las texturas,renders,etc...utilizados
void movimiento_jugador(variables_jugador jugador[], int numero_jugador, int *tiempo);//Permite moverse al jugador
void limites_mapa(variables_jugador jugador[],int numero_jugador);//En qué zona de la pantalla puedes moverte
void disparar (variables_jugador jugador[], int numero_jugador, SDL_Renderer *escenario);//Crea una bala a modo de disparo
void recargar_y_movimiento(variables_jugador jugador[], int numero_jugador, int *tiempo_recarga);//Establece un tiempo hasta disparar la próxima bala y permite su movimiento
void interseccion(variables_jugador jugador[], int numero_jugador,variables_jugador victima[], int numero_victima);//Indica si dos objetos intersecan
int vidas_restantes(variables_jugador victima[], int numero_victima, variables_jugador shooter[], int numero_shooter);//Cuando 2 objetos intersecan resta una vida al especificado
void fichero (variables_jugador jugador[], int numero_jugador); //Guarda los datos de la partida en un fichero





