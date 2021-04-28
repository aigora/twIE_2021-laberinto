#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Funciones_principales.h"

int main (int argc, char *argv[])
{
    int tiempo_recarga_estructura=0;
    int tiempo_recarga_estructura1=0;
    int tiempo_jugador2=0;
    int tiempo_jugador=0;
    SDL_Window *ventanaprincipal=NULL;
    SDL_Surface *superficieprincipal=NULL;
    SDL_Renderer *escenario=NULL;

    SDL_Texture *texto_ganador=NULL;
    SDL_Event evento;
    _Bool ejecutando=1;

    SDL_Init(SDL_INIT_EVERYTHING);

    ventanaprincipal=SDL_CreateWindow("Juego laberinto",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,960,720,NULL);
    superficieprincipal=SDL_GetWindowSurface(ventanaprincipal);
    escenario=SDL_CreateRenderer(ventanaprincipal,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);


SDL_Rect posicion_texto;
posicion_texto.x=posicion_texto.y=250;
posicion_texto.w=posicion_texto.h=0;


variables_jugador *jugador;

jugador=malloc(sizeof(variables_jugador)*2);

if (jugador==NULL)
{
    SDL_Log("Error");
    exit(-1);
}

generar_jugador(jugador,0,escenario);
generar_jugador(jugador,1,escenario);

jugador[0].numero_vidas=3;
jugador[0].intersecan=0;
jugador[0].recargando=0;
jugador[1].numero_vidas=3;
jugador[1].intersecan=0;
jugador[1].recargando=0;

   while(ejecutando)
    {

        while(SDL_PollEvent(&evento)!=0)
        {
            if(evento.type==SDL_QUIT)
            {
                ejecutando=0;
            }

            if(jugador[0].recargando==0)
                disparar(jugador,0,evento,escenario);

            if(jugador[1].recargando==0)
                disparar(jugador,1,evento,escenario);
        }


        recargar_estructura(jugador,0,&tiempo_recarga_estructura1);
        recargar_estructura(jugador,1,&tiempo_recarga_estructura);

        if(jugador[1].posicion_bala.x<=700)
        {
            jugador[1].posicion_bala.x+=6;
        }
        else
        {
            SDL_DestroyTexture(jugador[1].bala);
        }


        if(jugador[0].posicion_bala.x<=700)
        {
            jugador[0].posicion_bala.x+=6;
        }
        else
        {
            SDL_DestroyTexture(jugador[0].bala);
        }



        movimiento_jugador_estructura(jugador,0,&tiempo_jugador);
        movimiento_jugador_estructura(jugador,1,&tiempo_jugador2);

        limites_mapa_estructura(jugador,0);
        limites_mapa_estructura(jugador,1);

        interseccion_estructura(jugador,0,jugador,1);
        interseccion_estructura(jugador,1,jugador,0);

        /*if(jugador[1].intersecan)
        {
            vidas_restantes_estructura(jugador,1,jugador[0].recargando);
        }

        if(jugador[0].intersecan)
        {
            vidas_restantes_estructura(jugador,0,jugador[1].recargando);
        }*/

        SDL_RenderClear(escenario);
        copiar_atributos(jugador,0,escenario);
        copiar_atributos(jugador,1,escenario);
        SDL_RenderPresent(escenario);

    }
    free(jugador);
    SDL_DestroyTexture(texto_ganador);
    destruir_atributos(jugador,0);
    destruir_atributos(jugador,1);
    SDL_DestroyRenderer(escenario);
    SDL_DestroyWindow(ventanaprincipal);
    ventanaprincipal=NULL;
    superficieprincipal=NULL;

    for (int i=0;i<2;i++)
    jugador[i].municion=jugador[i].vidas=jugador[i].animacion=jugador[i].bala=NULL;

    SDL_Quit();

    return 0;
}

