#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef struct
    {
        int numero_jugador;
        int numero_vidas;
        int ancho_vida,alto_vida;
        int ancho_municion,alto_municion;
        int ancho_animacion, alto_animacion;

        _Bool recargando;
        _Bool intersecan;


        SDL_Texture *animacion;
        SDL_Texture *vidas;
        SDL_Texture *bala;
        SDL_Texture *municion;

        SDL_Rect posicion_bala;

        SDL_Rect recortar_vidas;
        SDL_Rect posicion_vidas;

        SDL_Rect recortar_animacion;
        SDL_Rect posicion_animacion;

        SDL_Rect recortar_municion;
        SDL_Rect posicion_municion;

    }variables_jugador;

SDL_Texture *cargar_texturas (char ruta[50],SDL_Renderer *render);//
void you_win (SDL_Rect *posicion_texto, int numero_vidas, SDL_Renderer *escenario, SDL_Texture *texto);
void multijugador(int numero_jugadores);
void generar_jugador(variables_jugador jugador[], int numero_jugador, SDL_Renderer *escenario);
void copiar_atributos(variables_jugador jugador[], int numero_jugador, SDL_Renderer *escenario);
void destruir_atributos(variables_jugador jugador[], int numero_jugador);
void movimiento_jugador_estructura(variables_jugador jugador[], int numero_jugador, int *tiempo);
void limites_mapa_estructura (variables_jugador jugador[],int numero_jugador);
_Bool disparar (variables_jugador jugador[], int numero_jugador, SDL_Event evento, SDL_Renderer *escenario);
void recargar_estructura(variables_jugador jugador[], int numero_jugador, int *tiempo_recarga, _Bool *recargando);
void interseccion_estructura(variables_jugador jugador[], int numero_jugador,variables_jugador victima[], int numero_victima);
int vidas_restantes_estructura (variables_jugador victima[], int numero_victima,_Bool contador_balas);






