/**
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <stdio.h>

int main (int argc, char *argv[])
{

    SDL_Window *window;
    SDL_Surface *image;

    SDL_Init(SDL_INIT_VIDEO); // init video

    // create the window like normal
    window = SDL_CreateWindow("SDL2 Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);




    image = SDL_LoadBMP("Hola mundo.bmp");


    image=SDL_UpdateWindowSurface(window);


    SDL_Delay(2000);
    SDL_DestroyWindow(window);
    image=NULL;
    SDL_Quit();
    return 0;
}
*/
