/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Funciones_principales.h"
#include <sys/time.h>
int main (int argc, char *argv[])
{
    double segma;
    int chocan;
    long int seconds;
    long int microseconds;
    double elapsed=0;
    struct timeval begin,end;
    int segundos;
    int tiempo_mina=0;
    int tiempo_estructura=0;
    int tiempo_recarga_estructura=0;
    int tiempo_jugador2=0;
    int tiempo_jugador=0;
    int distx1=0,distx2=0,disty1=0,disty2=0;
    int ancho,alto,incremento;
    SDL_Window *ventanaprincipal=NULL;//Ventana donde se ejecuta el juego
    SDL_Surface *superficieprincipal=NULL;//Superficie para la ventana, como si fuera un lienzo
    SDL_Renderer *escenario=NULL;//Representa cosas sobre la superficie, como si fuese la pintura
    SDL_Texture *texto_ganador=NULL;
     SDL_Event evento; //Pulsar una tecla, mover el mouse... son eventos
    _Bool ejecutando=1; //Si el programa esta en proceso
    SDL_Init(SDL_INIT_EVERYTHING);//Inicializa la biblioteca SDL (no vamos a hacer comprobaciones de errores, por ahora)
    ventanaprincipal=SDL_CreateWindow("Juego laberinto",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1000,700,NULL);//Crea una ventana, centrada, de dimensiones 960x720
    superficieprincipal=SDL_GetWindowSurface(ventanaprincipal);//Aporta una superficie a la ventana
    escenario=SDL_CreateRenderer(ventanaprincipal,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);//Crea un render (necesario definirlo de esta forma para que funcione bien)
SDL_Rect posicion_texto; //La posicion en la que estara el texto al finalizar el programa
posicion_texto.x=posicion_texto.y=250;
posicion_texto.w=posicion_texto.h=0;
variables_jugador *jugador;//Se define un puntero del tipo variables_jugador
jugador=malloc(sizeof(variables_jugador)*2);//Indicamos para cuantos jugadores necesitamos espacio
if (jugador==NULL)//Comprobacion de error
{
    SDL_Log("Error");
    exit(-1);
}
else//Genera los jugadores con las funciones definidas de antes
{
    generar_jugador(jugador,0,escenario,0);
    generar_jugador(jugador,1,escenario,0);
}
variables_barrera *barrera;//Se define un puntero del tipo variables_jugador
barrera=malloc(sizeof(variables_barrera));//Indicamos para cuantos jugadores necesitamos espacio
if (jugador==NULL)//Comprobacion de error
{
    SDL_Log("Error");
    exit(-1);
}
else
{
    cargar_muro(barrera,0,escenario,"Barrera.png","Texto.png");
}
barrera[0].mina_existe=1;
   while(ejecutando)//El programa principal es un bucle que se reproduce infinitamente hasta que cambiemos el valor de ejecutando
    {
        gettimeofday(&begin, 0);
        tiempo_mina++;
        if (barrera[0].mina_existe==0)
        {
            barrera[0].mina=cargar_texturas("Texto.png",escenario);
            barrera[0].mina_existe=1;
        }
        while(SDL_PollEvent(&evento)!=0)//Procesa los eventos que se producen cada vez que se produce el bucle
        {
                                          //Finaliza el bucle cuando no queden eventos por procesar
            if(evento.type==SDL_QUIT)//Si el evento es quit (darle a la cruz roja) se sale del bucle y termina el juego
            {
                ejecutando=0;
            }
            if (evento.type==SDL_KEYDOWN)//Evento del tipo pulsar tecla
            {
                if (evento.key.keysym.sym==SDLK_SPACE)//Si la tecla pulsada es un espacio llama a la funcion disparar para el jugador 0
                {
                    if (jugador[0].recargando==0 && jugador[0].bala_existe==0)
                    disparar(jugador,0,jugador,1,escenario,&distx1,&disty1);
                }
                if(evento.key.keysym.sym==SDLK_f)//Si es una f lo mismo pero para el jugador 2
                {
                    if (jugador[1].recargando==0 && jugador[1].bala_existe==0)
                    disparar(jugador,1,jugador,0,escenario,&distx2,&disty2);
                }
            }
        }
        recargar_y_movimiento(jugador,0,&tiempo_estructura,distx1,disty1);//Mueve la bala y recarga la municion
        recargar_y_movimiento(jugador,1,&tiempo_recarga_estructura,distx2,disty2);
        movimiento_jugador(jugador,0,&tiempo_jugador);//Para mover los jugadores
        movimiento_jugador(jugador,1,&tiempo_jugador2);
        limites_mapa(jugador,0);//Donde se pueden mover
        limites_mapa(jugador,1);
        interseccion(jugador,0,jugador,1);//Si las balas intersecan con los jugadores
        interseccion(jugador,1,jugador,0);
        if (tiempo_mina>=200 && barrera[0].mina_existe)
        {
            mina(barrera,0,escenario,jugador,0,&tiempo_mina);
            mina(barrera,0,escenario,jugador,1,&tiempo_mina);
            tiempo_mina=0;
        }
        jugador[0].interseca_mina=jugador[1].interseca_mina=0;
        //barrera[0].explota=0;
        interseccion_mina(jugador,0,barrera,0);
        interseccion_mina(jugador,1,barrera,0);
        //explosion_mina(jugador,0,barrera,0);
        if(jugador[1].intersecan||jugador[1].interseca_mina)//Si la bala 0 interseca con el jugador 1 llama a la funcion vidas restantes
        {
            vidas_restantes(jugador,1);
        }
        if(jugador[0].intersecan||jugador[0].interseca_mina)
        {
            vidas_restantes(jugador,0);
        }
        SDL_RenderClear(escenario);//Limpia lo que haya en el escenario
        copiar_atributos(jugador,0,escenario); //Pega en el escenario las caracteristicas de cada jugador tras acabar el bucle
        copiar_atributos(jugador,1,escenario);
        if (barrera[0].mina_existe)
            SDL_RenderCopy(escenario,barrera[0].mina,&barrera[0].recortar_mina,&barrera[0].posicion_mina);
        if(barrera[0].explota)
            SDL_RenderCopy(escenario,barrera[0].explosion,NULL,&barrera[0].posicion_explosion);
        SDL_RenderPresent(escenario);//Presenta el render sobre la ventana principal
         gettimeofday(&end, 0);
         seconds = end.tv_sec - begin.tv_sec;
         microseconds = end.tv_usec - begin.tv_usec;
         elapsed += seconds + microseconds*1e-6;
         if (elapsed>100.0)
            elapsed=0.0;
    }//Fin del bucle principal y por tanto de la partida
    //fichero(jugador,0);
    free(jugador);
    free(barrera);//Libera lo reservado con malloc anteriormente
    SDL_DestroyTexture(texto_ganador);//Destruye todas las texturas creadas, la ventana, el render y lasuperficie
    destruir_atributos(jugador,0);
    destruir_atributos(jugador,1);
    SDL_DestroyRenderer(escenario);
    SDL_DestroyWindow(ventanaprincipal);
    ventanaprincipal=NULL; //Apunta todos los punteros a NULL
    superficieprincipal=NULL;
    for (int i=0;i<2;i++)
    jugador[i].municion=jugador[i].vidas=jugador[i].animacion=jugador[i].bala=NULL;
    SDL_Quit();//Sale de la libreria SDL
    return 0;
}*/

