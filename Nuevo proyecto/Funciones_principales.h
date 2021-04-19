#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

SDL_Texture *cargar_texturas (char ruta[50],SDL_Renderer *render);
void limites_mapa (SDL_Rect *limite);
void movimiento_jugador(SDL_Rect *posicion, SDL_Rect *recortar, int anchoimagen, int altoimagen, int *tiempo, int numero_jugador);
_Bool interseccion (SDL_Rect posicion, SDL_Rect posicion_bala,SDL_Texture *jugador);
void vidas_restantes (SDL_Rect *recortar, _Bool intersecan, int ancho_vida, int numero_vidas,int *tiempo);
SDL_Texture *disparar(SDL_Renderer *escenario, SDL_Rect *posicion_bala, SDL_Rect posicion_shooter, int *numero_balas);
