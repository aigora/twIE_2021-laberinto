#include <stdio.h>
#include <math.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Funciones_principales.h"


SDL_Texture *cargar_texturas (char ruta[50],SDL_Renderer *render)
{
    SDL_Surface *superficie= IMG_Load(ruta);
    SDL_Texture *imagen= SDL_CreateTextureFromSurface(render,superficie);

    SDL_FreeSurface(superficie);

    return imagen;
}

void limites_mapa (SDL_Rect *posicion)
{
    const int velocidad_movimiento=2;

    if(posicion->x>=550)
        posicion->x-=velocidad_movimiento;

    if (posicion->x<=0)
        posicion->x+=velocidad_movimiento;

    if(posicion->y<=0)
        posicion->y+=velocidad_movimiento;

    if(posicion->y>=400)
        posicion->y-=velocidad_movimiento;
}

void movimiento_jugador(SDL_Rect *posicion, SDL_Rect *jugador, int anchoimagen, int altoimagen, int *tiempo, int numero_jugador)
{
    const Uint8 *captura=SDL_GetKeyboardState(NULL);
    int velocidad_movimiento=2;
    SDL_Scancode teclas[4];

    if(numero_jugador==1)
    {
    teclas[0]=SDL_SCANCODE_RIGHT;
    teclas[1]=SDL_SCANCODE_LEFT;
    teclas[2]=SDL_SCANCODE_UP;
    teclas[3]=SDL_SCANCODE_DOWN;
    }
    if(numero_jugador==2)
    {
    teclas[0]=SDL_SCANCODE_D;
    teclas[1]=SDL_SCANCODE_A;
    teclas[2]=SDL_SCANCODE_W;
    teclas[3]=SDL_SCANCODE_S;
    }

    if(captura[teclas[0]])
        {
            jugador->y=0;
            posicion->x+=velocidad_movimiento;
            *tiempo+=1;
            if(*tiempo>=5)
            {
                jugador->x+=anchoimagen/8;
                if(jugador->x>=anchoimagen)
                    jugador->x=0;
                *tiempo=0;
            }
        }
       if (captura[teclas[1]])
        {
            jugador->y=altoimagen/2;
            posicion->x-=velocidad_movimiento;
            *tiempo+=1;
            if(*tiempo>=5)
            {
                jugador->x-=anchoimagen/8;
                if(jugador->x<=0)
                    jugador->x=anchoimagen*7/8;
                *tiempo=0;
            }
        }
        if (captura[teclas[2]])
        {
            posicion->y-=2;
        }
        if (captura[teclas[3]])
        {
            posicion->y+=2;
        }
}

_Bool interseccion (SDL_Rect posicion, SDL_Rect posicion_bala, SDL_Texture *jugador)
{
    float distancia=sqrt(pow(posicion.x-posicion_bala.x,2)+pow(posicion.y-posicion_bala.y,2));
    _Bool intersecan=0;

    if(distancia>50)
    {
        SDL_SetTextureColorMod(jugador,255,255,255);
        intersecan=0;
    }
    else
    {
        SDL_SetTextureColorMod(jugador,255,0,0);
        intersecan=1;
    }

    return intersecan;
}

int vidas_restantes (SDL_Rect *recortar, SDL_Rect *posicion_vida, _Bool intersecan, int ancho_vida, int numero_vidas, SDL_Rect posicion_bala, SDL_Rect posicion_victima, _Bool contador_balas)
{
    if (contador_balas==1)
    {
    numero_vidas--;

    switch(numero_vidas)
    {
    case 2:
        recortar->x+=ancho_vida/3;
        recortar->y=0;
        posicion_vida->w-=33;
        break;
    case 1:
        recortar->x+=ancho_vida/3;
        posicion_vida->w-=33;
        break;
    case 0:
        numero_vidas=3;
        recortar->x=0;
        posicion_vida->w-=34;
        posicion_vida->w=100;
        break;
    default:
        recortar->x=ancho_vida;
        break;
    }
    }
    return numero_vidas;
}
void recargar(SDL_Rect *recortar_municion, SDL_Rect *posicion_municion, int *tiempo_recarga, int ancho_municion,_Bool bala_activa)
{
    if (bala_activa)
    {
    *tiempo_recarga+=1;

    if (recortar_municion->x>=ancho_municion/4)
    {
        recortar_municion->x=0;
        posicion_municion->w=100;
    }


    if (*tiempo_recarga==2)
    {
        recortar_municion->x+=1;
        posicion_municion->w-=1;
        *tiempo_recarga=0;
    }
    }
}
void you_win(SDL_Rect *posicion_texto, int numero_vidas, SDL_Renderer *escenario, SDL_Texture *texto)
{
    if (numero_vidas==0)
        {
            posicion_texto->w+=5;
            posicion_texto->h+=2;
            SDL_RenderCopy(escenario,texto,NULL,posicion_texto);
        }
}


