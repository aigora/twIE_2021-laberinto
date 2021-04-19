#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Funciones_principales.h"

typedef struct
{

}personaje;


int main (int argc, char *argv[])
{
    int tiempo_jugador1=0,tiempo_jugador2=0;
    int numero_jugador;
    int x=0,y=0;
    int tiempo_interseccion=0;
    SDL_Window *ventanaprincipal=NULL;
    SDL_Surface *superficieprincipal=NULL;
    SDL_Renderer *escenario=NULL;
    SDL_Texture *jugador1=NULL;
    SDL_Texture *jugador2=NULL;
    SDL_Texture *bala=NULL;
    SDL_Texture *vidas=NULL;
    SDL_Event evento;
    _Bool ejecutando=1;
    _Bool intersecan=0;
    int altoimagen,anchoimagen;
    int ancho_vida,alto_vida;
    const int velocidad_movimiento=2;


    SDL_Init(SDL_INIT_EVERYTHING);

    ventanaprincipal=SDL_CreateWindow("Juego laberinto",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,960,720,NULL);
    superficieprincipal=SDL_GetWindowSurface(ventanaprincipal);
    escenario=SDL_CreateRenderer(ventanaprincipal,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);

    jugador1=cargar_texturas("Animacion.png",escenario);
    jugador2=cargar_texturas("Animacion.png",escenario);
    vidas=cargar_texturas("Vida.png",escenario);

    SDL_QueryTexture(jugador1,NULL,NULL,&anchoimagen,&altoimagen);
    SDL_QueryTexture(vidas,NULL,NULL,&ancho_vida,&alto_vida);

SDL_Rect recortar_jugador1;
    recortar_jugador1.x=0;
    recortar_jugador1.y=0;
    recortar_jugador1.w=anchoimagen/8;
    recortar_jugador1.h=altoimagen/2;

SDL_Rect recortar_jugador2;
    recortar_jugador2.x=0;
    recortar_jugador2.y=0;
    recortar_jugador2.w=anchoimagen/8;
    recortar_jugador2.h=altoimagen/2;

SDL_Rect posicion;
    posicion.x=posicion.y=0;
    posicion.w=100;
    posicion.h=100;

SDL_Rect posicion2;
    posicion2.x=posicion2.y=300;
    posicion2.w=posicion2.h=100;


SDL_Rect posicionbala;

SDL_Rect posicion_vidas;
posicion_vidas.x=700;
posicion_vidas.y=0;
posicion_vidas.w=100;
posicion_vidas.h=50;

SDL_Rect recortar_vidas;
recortar_vidas.x=recortar_vidas.y=0;
recortar_vidas.w=ancho_vida;
recortar_vidas.h=alto_vida;

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
                bala=cargar_texturas("Zanahoria.png",escenario);
                posicionbala.x=posicion.x+posicion.w;
                posicionbala.y=posicion.y+posicion.h/2;
                posicionbala.w=posicionbala.h=50;
                }
            }
        }
        posicionbala.x+=6;

        movimiento_jugador(&posicion,&recortar_jugador1,anchoimagen,altoimagen,&tiempo_jugador1,1);
        movimiento_jugador(&posicion2,&recortar_jugador2,anchoimagen,altoimagen,&tiempo_jugador2,2);
        limites_mapa(&posicion);
        intersecan=interseccion(posicion,posicion2,jugador2);
        vidas_restantes(&recortar_vidas,intersecan,ancho_vida,altoimagen,&tiempo_interseccion);



        if(posicionbala.x>=550)
            SDL_DestroyTexture(bala);

        SDL_RenderClear(escenario);
        SDL_RenderCopy(escenario,jugador1,&recortar_jugador1,&posicion);
        SDL_RenderCopy(escenario,bala,NULL,&posicionbala);
        SDL_RenderCopy(escenario,jugador2,&recortar_jugador2,&posicion2);
        SDL_RenderCopy(escenario,vidas,&recortar_vidas,&posicion_vidas);
        SDL_RenderPresent(escenario);

    }
    SDL_DestroyTexture(vidas);
    SDL_DestroyTexture(jugador2);
    SDL_DestroyTexture(jugador1);
    SDL_DestroyTexture(bala);
    SDL_DestroyRenderer(escenario);
    SDL_DestroyWindow(ventanaprincipal);
    ventanaprincipal=superficieprincipal=jugador1=bala=vidas=jugador2=NULL;

    SDL_Quit();

    return 0;
}
