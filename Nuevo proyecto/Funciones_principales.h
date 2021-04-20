#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

SDL_Texture *cargar_texturas (char ruta[50],SDL_Renderer *render);
void limites_mapa (SDL_Rect *limite);
void movimiento_jugador(SDL_Rect *posicion, SDL_Rect *recortar, int anchoimagen, int altoimagen, int *tiempo, int numero_jugador);
_Boolinterseccion (SDL_Rect posicion, SDL_Rect posicion_bala,SDL_Texture *jugador);
int vidas_restantes (SDL_Rect *recortar, _Bool intersecan, int ancho_vida, int numero_vidas, SDL_Rect posicion_bala, SDL_Rect posicion_victima);
