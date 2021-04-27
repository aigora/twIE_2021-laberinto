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

void you_win(SDL_Rect *posicion_texto, int numero_vidas, SDL_Renderer *escenario, SDL_Texture *texto)
{
    if (numero_vidas==0)
        {
            posicion_texto->w+=5;
            posicion_texto->h+=2;
            SDL_RenderCopy(escenario,texto,NULL,posicion_texto);
        }
}

void movimiento_jugador_estructura(variables_jugador jugador[], int numero_jugador, int *tiempo)
{
    const Uint8 *captura=SDL_GetKeyboardState(NULL);
    int velocidad_movimiento=2;
    SDL_Scancode teclas[4];

    if(numero_jugador==0)
    {
    teclas[0]=SDL_SCANCODE_RIGHT;
    teclas[1]=SDL_SCANCODE_LEFT;
    teclas[2]=SDL_SCANCODE_UP;
    teclas[3]=SDL_SCANCODE_DOWN;
    }
    if(numero_jugador==1)
    {
    teclas[0]=SDL_SCANCODE_D;
    teclas[1]=SDL_SCANCODE_A;
    teclas[2]=SDL_SCANCODE_W;
    teclas[3]=SDL_SCANCODE_S;
    }

    if(captura[teclas[0]])
        {
            jugador[numero_jugador].recortar_animacion.y=0;
            jugador[numero_jugador].posicion_animacion.x+=velocidad_movimiento;
            *tiempo+=1;
            if(*tiempo>=5)
            {
                jugador[numero_jugador].recortar_animacion.x+=jugador[numero_jugador].ancho_animacion/8;
                if(jugador[numero_jugador].recortar_animacion.x>=jugador[numero_jugador].ancho_animacion)
                    jugador[numero_jugador].recortar_animacion.x=0;
                *tiempo=0;
            }
        }
       if (captura[teclas[1]])
        {
            jugador[numero_jugador].recortar_animacion.y=jugador[numero_jugador].alto_animacion/2;
            jugador[numero_jugador].posicion_animacion.x-=velocidad_movimiento;
            *tiempo+=1;
            if(*tiempo>=5)
            {
                jugador[numero_jugador].recortar_animacion.x-=jugador[numero_jugador].ancho_animacion/8;
                if(jugador[numero_jugador].recortar_animacion.x<=0)
                    jugador[numero_jugador].recortar_animacion.x=jugador[numero_jugador].ancho_animacion*7/8;
                *tiempo=0;
            }
        }
        if (captura[teclas[2]])
        {
            jugador[numero_jugador].posicion_animacion.y-=2;
        }
        if (captura[teclas[3]])
        {
            jugador[numero_jugador].posicion_animacion.y+=2;
        }
}
void limites_mapa_estructura (variables_jugador jugador[],int numero_jugador)
{
    const int velocidad_movimiento=2;

    if(jugador[numero_jugador].posicion_animacion.x>=550)
        jugador[numero_jugador].posicion_animacion.x-=velocidad_movimiento;

    if (jugador[numero_jugador].posicion_animacion.x<=0)
        jugador[numero_jugador].posicion_animacion.x+=velocidad_movimiento;

    if(jugador[numero_jugador].posicion_animacion.y<=0)
        jugador[numero_jugador].posicion_animacion.y+=velocidad_movimiento;

    if(jugador[numero_jugador].posicion_animacion.y>=400)
        jugador[numero_jugador].posicion_animacion.y-=velocidad_movimiento;
}
_Bool disparar (variables_jugador jugador[], int numero_jugador, SDL_Event evento, SDL_Renderer *escenario)
{
    _Bool recargando=0;
    SDL_KeyCode tecla;

    if (numero_jugador==0)
        tecla=SDLK_SPACE;
    else
        tecla=SDLK_f;

    if(evento.type==SDL_KEYDOWN)
    {
        if (evento.key.keysym.sym==tecla)
        {
            jugador[numero_jugador].bala=cargar_texturas("Bala.png",escenario);
            jugador[numero_jugador].posicion_bala.x=jugador[numero_jugador].posicion_animacion.x+jugador[numero_jugador].posicion_animacion.w;
            jugador[numero_jugador].posicion_bala.y=jugador[numero_jugador].posicion_animacion.y+jugador[numero_jugador].posicion_animacion.h/2;
            jugador[numero_jugador].posicion_bala.w=jugador[numero_jugador].posicion_bala.h=50;
            recargando=1;
        }
    }
    return recargando;
}
void recargar_estructura(variables_jugador jugador[], int numero_jugador, int *tiempo_recarga, _Bool *recargando)
{
    if (*recargando)
    {
    *tiempo_recarga+=1;
       if (jugador[numero_jugador].recortar_municion.x>=jugador[numero_jugador].ancho_municion/4)
        {
            jugador[numero_jugador].recortar_municion.x=0;
            jugador[numero_jugador].posicion_municion.w=100;
            *recargando=0;
        }


        if (*tiempo_recarga==2)
        {
            jugador[numero_jugador].recortar_municion.x+=1;
            jugador[numero_jugador].posicion_municion.w-=1;
            *tiempo_recarga=0;
        }
    }
}
void interseccion_estructura(variables_jugador jugador[], int numero_jugador, variables_jugador victima[], int numero_victima)
{
    float distancia=sqrt(pow(victima[numero_victima].posicion_animacion.x-jugador[numero_jugador].posicion_bala.x,2)
                         +pow(victima[numero_victima].posicion_animacion.y-jugador[numero_jugador].posicion_bala.y,2));

    if(distancia>50)
    {
        SDL_SetTextureColorMod(victima[numero_victima].animacion,255,255,255);
        victima[numero_victima].intersecan=0;
    }
    else
    {
        SDL_SetTextureColorMod(victima[numero_victima].animacion,255,0,0);
        victima[numero_victima].intersecan=1;
    }

}

int vidas_restantes_estructura (variables_jugador victima[], int numero_victima, _Bool contador_balas)
{
    if (contador_balas==1)
    {
    victima[numero_victima].numero_vidas--;

    switch(victima[numero_victima].numero_vidas)
    {
    case 2:
        victima[numero_victima].recortar_vidas.x+=victima[numero_victima].ancho_vida/3;
        victima[numero_victima].recortar_vidas.y=0;
        victima[numero_victima].posicion_vidas.w-=33;
        break;
    case 1:
        victima[numero_victima].recortar_vidas.x+=victima[numero_victima].ancho_vida/3;
        victima[numero_victima].posicion_vidas.w-=33;
        break;
    case 0:
        victima[numero_victima].numero_vidas=3;
        victima[numero_victima].recortar_vidas.x=0;
        victima[numero_victima].posicion_vidas.w-=34;
        victima[numero_victima].posicion_vidas.w=100;
        break;
    default:
        victima[numero_victima].recortar_vidas.x=victima[numero_victima].ancho_vida;
        break;
    }
    }
    return victima[numero_victima].numero_vidas;
}

void generar_jugador(variables_jugador jugador[], int numero_jugador, SDL_Renderer *escenario)
{
    int posicion_animacion,posicion_vidas,posicion_municion;
    if (numero_jugador==0)
    {
        posicion_animacion=50;
        posicion_vidas=700;
        posicion_municion=600;
    }
    else
    {
        posicion_animacion=300;
        posicion_vidas=200;
        posicion_municion=100;
    }

    jugador[numero_jugador].vidas=cargar_texturas("Vida.png",escenario);
    jugador[numero_jugador].municion=cargar_texturas("Zanahoria.png",escenario);
    jugador[numero_jugador].animacion=cargar_texturas("Animacion.png",escenario);

    SDL_QueryTexture(jugador[numero_jugador].vidas,NULL,NULL,&jugador[numero_jugador].ancho_vida,&jugador[numero_jugador].alto_vida);
    SDL_QueryTexture(jugador[numero_jugador].municion,NULL,NULL,&jugador[numero_jugador].ancho_municion,&jugador[numero_jugador].alto_municion);
    SDL_QueryTexture(jugador[numero_jugador].animacion,NULL,NULL,&jugador[numero_jugador].ancho_animacion,&jugador[numero_jugador].alto_animacion);

    jugador[numero_jugador].recortar_animacion.x=jugador[numero_jugador].recortar_animacion.y=0;
    jugador[numero_jugador].recortar_animacion.w=jugador[numero_jugador].ancho_animacion/8;
    jugador[numero_jugador].recortar_animacion.h=jugador[numero_jugador].alto_animacion/2;
    jugador[numero_jugador].posicion_animacion.x=jugador[numero_jugador].posicion_animacion.y=posicion_animacion;
    jugador[numero_jugador].posicion_animacion.w=jugador[numero_jugador].posicion_animacion.h=100;

    jugador[numero_jugador].recortar_vidas.x=jugador[numero_jugador].recortar_vidas.y=0;
    jugador[numero_jugador].recortar_vidas.w=jugador[numero_jugador].ancho_vida;
    jugador[numero_jugador].recortar_vidas.h=jugador[numero_jugador].alto_vida;
    jugador[numero_jugador].posicion_vidas.x=posicion_vidas;
    jugador[numero_jugador].posicion_vidas.y=0;
    jugador[numero_jugador].posicion_vidas.w=100;
    jugador[numero_jugador].posicion_vidas.h=50;

    jugador[numero_jugador].recortar_municion.x=jugador[numero_jugador].recortar_municion.y=0;
    jugador[numero_jugador].recortar_municion.w=jugador[numero_jugador].ancho_municion;
    jugador[numero_jugador].recortar_municion.h=jugador[numero_jugador].alto_municion;
    jugador[numero_jugador].posicion_municion.x=posicion_municion;
    jugador[numero_jugador].posicion_municion.y=0;
    jugador[numero_jugador].posicion_municion.w=100;
    jugador[numero_jugador].posicion_municion.h=50;
}
void copiar_atributos(variables_jugador jugador[], int numero_jugador, SDL_Renderer *escenario)
{
    SDL_RenderCopy(escenario,jugador[numero_jugador].animacion,&jugador[numero_jugador].recortar_animacion,&jugador[numero_jugador].posicion_animacion);
    SDL_RenderCopy(escenario,jugador[numero_jugador].vidas,&jugador[numero_jugador].recortar_vidas,&jugador[numero_jugador].posicion_vidas);
    SDL_RenderCopy(escenario,jugador[numero_jugador].municion,&jugador[numero_jugador].recortar_municion,&jugador[numero_jugador].posicion_municion);
    SDL_RenderCopy(escenario,jugador[numero_jugador].bala,NULL,&jugador[numero_jugador].posicion_bala);
}
void destruir_atributos(variables_jugador jugador[], int numero_jugador)
{
    SDL_DestroyTexture(jugador[numero_jugador].vidas);
    SDL_DestroyTexture(jugador[numero_jugador].animacion);
    SDL_DestroyTexture(jugador[numero_jugador].municion);
    SDL_DestroyTexture(jugador[numero_jugador].bala);
}


/*void multijugador(int numero_jugadores)
{
    _Bool contador_balas=0;
    int tiempo_jugador1=0,tiempo_jugador2=0;
    int numero_jugador;
    int x=0,y=0;
    int tiempo_disparo=0;
    int tiempo_interseccion=0;
    SDL_Window *ventanaprincipal=NULL;
    SDL_Surface *superficieprincipal=NULL;
    SDL_Renderer *escenario=NULL;
    SDL_Texture *jugador1=NULL;
    SDL_Texture *jugador2=NULL;
    SDL_Texture *bala=NULL;
    SDL_Texture *vidas=NULL;
    SDL_Texture *municion=NULL;
    SDL_Texture *texto_ganador=NULL;
    SDL_Event evento;
    _Bool ejecutando=1;
    _Bool intersecan=0;
    int altoimagen,anchoimagen;
    int ancho_vida,alto_vida;
    int ancho_municion,alto_municion;
    const int velocidad_movimiento=2;
    int numero_vidas=3;


    _Bool bala_activa=0;


    SDL_Init(SDL_INIT_EVERYTHING);

    ventanaprincipal=SDL_CreateWindow("Juego laberinto",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,960,720,NULL);
    superficieprincipal=SDL_GetWindowSurface(ventanaprincipal);
    escenario=SDL_CreateRenderer(ventanaprincipal,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);

    jugador1=cargar_texturas("Animacion.png",escenario);
    jugador2=cargar_texturas("Animacion.png",escenario);
    vidas=cargar_texturas("Vida.png",escenario);
    municion=cargar_texturas("Zanahoria.png",escenario);
    texto_ganador=cargar_texturas("Texto.png",escenario);

    SDL_QueryTexture(jugador1,NULL,NULL,&anchoimagen,&altoimagen);
    SDL_QueryTexture(vidas,NULL,NULL,&ancho_vida,&alto_vida);
    SDL_QueryTexture(municion,NULL,NULL,&ancho_municion,&alto_municion);

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



SDL_Rect posicion_municion;
posicion_municion.y=0;
posicion_municion.w=100;
posicion_municion.h=50;
posicion_municion.x=600;


SDL_Rect posicion_vidas;
posicion_vidas.x=700;
posicion_vidas.y=0;
posicion_vidas.w=100;
posicion_vidas.h=50;

SDL_Rect recortar_vidas;
recortar_vidas.x=recortar_vidas.y=0;
recortar_vidas.w=ancho_vida;
recortar_vidas.h=alto_vida;

SDL_Rect recortar_municion;
recortar_municion.x=0;
recortar_municion.y=0;
recortar_municion.w=ancho_municion;
recortar_municion.h=alto_municion;

SDL_Rect posicion_texto;
posicion_texto.x=posicion_texto.y=250;
posicion_texto.w=posicion_texto.h=0;


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
                if(evento.key.keysym.sym==SDLK_SPACE && bala_activa==0)
                {
                    bala=cargar_texturas("Bala.png", escenario);
                    posicionbala.x=posicion.x+posicion.w;
                    posicionbala.y=posicion.y+posicion.h/2;
                    posicionbala.w=posicionbala.h=50;
                    bala_activa=1;
                    contador_balas=1;
                }
            }
        }

        if(posicionbala.x<=700)
        {
            posicionbala.x+=6;
        }
        else
        {
            SDL_DestroyTexture(bala);
            bala_activa=0;
        }

        movimiento_jugador(&posicion,&recortar_jugador1,anchoimagen,altoimagen,&tiempo_jugador1,1);
        movimiento_jugador(&posicion2,&recortar_jugador2,anchoimagen,altoimagen,&tiempo_jugador2,2);
        limites_mapa(&posicion);


        intersecan=interseccion(posicion2,posicionbala,jugador2);

        if (intersecan)
        {
            numero_vidas=vidas_restantes(&recortar_vidas,&posicion_vidas,intersecan,ancho_vida,numero_vidas,posicionbala,posicion2,contador_balas);
            SDL_DestroyTexture(bala);
            contador_balas=0;
        }

        recargar(&recortar_municion,&posicion_municion,&tiempo_disparo,ancho_municion,contador_balas);

        SDL_RenderClear(escenario);

        SDL_RenderCopy(escenario,bala,NULL,&posicionbala);
        SDL_RenderCopy(escenario,jugador1,&recortar_jugador1,&posicion);
        SDL_RenderCopy(escenario,jugador2,&recortar_jugador2,&posicion2);
        SDL_RenderCopy(escenario,vidas,&recortar_vidas,&posicion_vidas);
        SDL_RenderCopy(escenario,municion,&recortar_municion,&posicion_municion);
        SDL_RenderPresent(escenario);

    }




    SDL_DestroyTexture(texto_ganador);
    SDL_DestroyTexture(municion);
    SDL_DestroyTexture(vidas);
    SDL_DestroyTexture(jugador2);
    SDL_DestroyTexture(jugador1);
    SDL_DestroyTexture(bala);
    SDL_DestroyRenderer(escenario);
    SDL_DestroyWindow(ventanaprincipal);
    ventanaprincipal=superficieprincipal=jugador1=bala=vidas=jugador2=municion=texto_ganador=NULL;

    SDL_Quit();

}*/
