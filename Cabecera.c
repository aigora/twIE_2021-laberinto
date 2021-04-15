#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Cabecera.h"


SDL_Texture *cargar (SDL_Renderer *render)
{
    SDL_Surface *superficie= IMG_Load("Imagen2.png");
    SDL_Texture *imagen= SDL_CreateTextureFromSurface(render,superficie);

    SDL_FreeSurface(superficie);

    return imagen;
}
SDL_Texture *cargarbala (SDL_Renderer *render)
{
    SDL_Surface *superficie= IMG_Load("Bala1.png");
    SDL_Texture *imagen= SDL_CreateTextureFromSurface(render,superficie);

    SDL_FreeSurface(superficie);

    return imagen;
}
