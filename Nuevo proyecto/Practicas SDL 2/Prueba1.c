#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Cabecera.h"

SDL_Texture *cargar (SDL_Renderer *render);

int main (int argc, char *argv[])
{
    int tiempo=0;
    SDL_Window *ventanaprincipal=NULL;
    SDL_Surface *superficieprincipal=NULL;
    SDL_Renderer *escenario=NULL;
    SDL_Texture *imagen=NULL;
    SDL_Texture *bala=NULL;
    const Uint8 *estado=NULL;
    SDL_Event evento;
    _Bool ejecutando=1;
    _Bool derecha=0,izquierda=0;
    int cont=0;
    int altoimagen,anchoimagen;


    SDL_Init(SDL_INIT_EVERYTHING);

    ventanaprincipal=SDL_CreateWindow("Juego laberinto",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,640,480,NULL);
    superficieprincipal=SDL_GetWindowSurface(ventanaprincipal);
    escenario=SDL_CreateRenderer(ventanaprincipal,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);

    imagen=cargar(escenario);


    SDL_QueryTexture(imagen,NULL,NULL,&anchoimagen,&altoimagen);

SDL_Rect jugador;
    jugador.x=0;
    jugador.y=0;
    jugador.w=anchoimagen/8;
    jugador.h=altoimagen/2;

SDL_Rect posicion;
    posicion.x=posicion.y=0;
    posicion.w=100;
    posicion.h=100;

SDL_Rect posicionbala;


SDL_Scancode teclas[4];
teclas[0]=SDL_SCANCODE_RIGHT;
teclas[1]=SDL_SCANCODE_LEFT;
teclas[2]=SDL_SCANCODE_UP;
teclas[3]=SDL_SCANCODE_DOWN;


    estado=SDL_GetKeyboardState(NULL);


    while(ejecutando)
    {
        while(SDL_PollEvent(&evento)!=0)
        {
            if(evento.type==SDL_QUIT)
            {
                ejecutando=0;
            }
            if (evento.type==SDL_KEYDOWN)
            {
                if(evento.key.keysym.sym==SDLK_SPACE)
                {
                bala=cargarbala(escenario);
                posicionbala.x=posicion.x+posicion.w;
                posicionbala.y=posicion.y+posicion.h/2;
                posicionbala.w=posicionbala.h=20;
                }
            }
        }
        posicionbala.x+=4;

        if(estado[teclas[0]])
        {
            jugador.y=0;
            posicion.x+=2;
            tiempo++;


            if(tiempo==5)
            {
                jugador.x+=anchoimagen/8;
                if(jugador.x>=anchoimagen)
                    jugador.x=0;
                tiempo=0;
            }
        }
       if (estado[teclas[1]])
        {
            jugador.y=altoimagen/2;
            posicion.x-=2;
            tiempo++;
            if(tiempo==5)
            {
                jugador.x-=anchoimagen/8;
                if(jugador.x<=0)
                    jugador.x=anchoimagen*7/8;
                tiempo=0;
            }
        }
        if (estado[teclas[2]])
        {
            posicion.y-=2;
        }
        if (estado[teclas[3]])
        {
            posicion.y+=2;
        }


        if(posicion.x==550)
            posicion.x-=2;
        if (posicion.x<0)
            posicion.x+=2;
        if(posicion.y<0)
            posicion.y+=2;
        if(posicion.y>400)
            posicion.y-=2;
        if(posicionbala.x>=550)
            SDL_DestroyTexture(bala);




        SDL_RenderClear(escenario);
        SDL_RenderCopy(escenario,imagen,&jugador,&posicion);
        SDL_RenderCopy(escenario,bala,NULL,&posicionbala);
        SDL_RenderPresent(escenario);



    }

    SDL_DestroyTexture(imagen);
    SDL_DestroyTexture(bala);
    SDL_DestroyRenderer(escenario);
    SDL_DestroyWindow(ventanaprincipal);
    ventanaprincipal=superficieprincipal=imagen=bala=NULL;

    SDL_Quit();

    return 0;
}
