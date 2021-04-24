#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

SDL_Texture *cargar_texturas (char ruta[50],SDL_Renderer *render);
void limites_mapa (SDL_Rect *limite);
void movimiento_jugador(SDL_Rect *posicion, SDL_Rect *recortar, int anchoimagen, int altoimagen, int *tiempo, int numero_jugador);
_Boolinterseccion (SDL_Rect posicion, SDL_Rect posicion_bala,SDL_Texture *jugador);
int vidas_restantes (SDL_Rect *recortar, SDL_Rect *posicion_vida, _Bool intersecan, int ancho_vida, int numero_vidas, SDL_Rect posicion_bala, SDL_Rect posicion_victima, _Bool contador_balas);
void recargar(SDL_Rect *recortar_municion, SDL_Rect *posicion_municion, int *tiempo_recarga, int ancho_municion,_Bool bala_activa);//Modificar
void you_win (SDL_Rect *posicion_texto, int numero_vidas, SDL_Renderer *escenario, SDL_Texture *texto);
