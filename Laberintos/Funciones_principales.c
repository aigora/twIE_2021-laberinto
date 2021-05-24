#include <stdio.h>
#include <math.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Funciones_principales.h"
#include <sys/time.h>
#include <stdlib.h>

void mapa_multijugador(variables_barrera barrera[], int numero_barrera, SDL_Renderer *escenario, variables_jugador jugador[], int numero_jugador)
{
    hacer_muro(50,50,50,10,8,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(500,500,20,20,5,'v',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(200,630,15,80,3,'v',barrera,numero_barrera,escenario,jugador,numero_jugador);
}

void cargar_muro (variables_barrera barrera[], int numero_barrera, SDL_Renderer *escenario, char ruta_muro[50], char ruta_mina[50])
{
  int alto_muro,ancho_muro;
  int alto_mina,ancho_mina;

  barrera[numero_barrera].muro=cargar_texturas(ruta_muro,escenario);
  barrera[numero_barrera].mina=cargar_texturas(ruta_mina,escenario);
  barrera[numero_barrera].explosion=cargar_texturas("Explosion.png",escenario);

  SDL_QueryTexture(barrera[numero_barrera].muro,NULL,NULL,&ancho_muro,&alto_muro);
  SDL_QueryTexture(barrera[numero_barrera].mina,NULL,NULL,&ancho_mina,&alto_mina);

  barrera[numero_barrera].recortar_muro.x=barrera[numero_barrera].recortar_muro.y=0;
  barrera[numero_barrera].recortar_muro.w=ancho_muro;
  barrera[numero_barrera].recortar_muro.h=alto_muro;

  barrera[numero_barrera].recortar_mina.x=barrera[numero_barrera].recortar_mina.y=0;
  barrera[numero_barrera].recortar_mina.w=ancho_mina;
  barrera[numero_barrera].recortar_mina.h=alto_mina;
  barrera[numero_barrera].posicion_mina.h=barrera[numero_barrera].posicion_mina.w=50;
}
void hacer_muro (int x,int y,int w, int h, int n, char direccion_muro,variables_barrera barrera[],int numero_barrera,
                 SDL_Renderer *escenario,variables_jugador jugador[], int numero_jugador)
{
    int velocidad_movimiento=2;
    int i,j;

    barrera[numero_barrera].posicion_muro.x=x;
    barrera[numero_barrera].posicion_muro.y=y;
    barrera[numero_barrera].posicion_muro.w=w;
    barrera[numero_barrera].posicion_muro.h=h;

    int bar_x_1=x,bar_y_1=y;
    int bar_x_2=x,bar_y_2=y;

    if (direccion_muro=='v')
    {
        bar_x_2+=barrera[numero_barrera].posicion_muro.w;
        for(i=0;i<n;i++)
          {
            SDL_RenderCopy(escenario,barrera[numero_barrera].muro,&barrera[numero_barrera].recortar_muro,&barrera[numero_barrera].posicion_muro);
            barrera[numero_barrera].posicion_muro.y+=barrera[numero_barrera].posicion_muro.h;
            bar_y_2+=barrera[numero_barrera].posicion_muro.h;
          }
    }

    if (direccion_muro=='h')
    {
        bar_y_2+=barrera[numero_barrera].posicion_muro.h;
        for(i=0;i<n;i++)
          {
            SDL_RenderCopy(escenario,barrera[numero_barrera].muro,&barrera[numero_barrera].recortar_muro,&barrera[numero_barrera].posicion_muro);
            barrera[numero_barrera].posicion_muro.x+=barrera[numero_barrera].posicion_muro.w;
            bar_x_2+=barrera[numero_barrera].posicion_muro.w;
          }
    }

    for (j=0;j<2;j++)
   {
    int jug_x_1=jugador[j].posicion_animacion.x,jug_y_1=jugador[j].posicion_animacion.y;
    int jug_x_2=jugador[j].posicion_animacion.x+jugador[j].posicion_animacion.w,jug_y_2=jugador[j].posicion_animacion.y+jugador[j].posicion_animacion.h;
    int bala_x_1=jugador[j].posicion_bala.x,bala_y_1=jugador[j].posicion_bala.y;
    int bala_x_2=jugador[j].posicion_bala.x+jugador[j].posicion_bala.w,bala_y_2=jugador[j].posicion_bala.y+jugador[j].posicion_bala.h;
    if (jug_x_2<bar_x_1||bar_x_2<jug_x_1||jug_y_2<bar_y_1||bar_y_2<jug_y_1);
    else
    {
        if (jug_x_2==bar_x_1||bar_x_1==jug_x_2-1)
            jugador[j].posicion_animacion.x-=velocidad_movimiento;
        else if (bar_x_2==jug_x_1||bar_x_2==jug_x_1+1)
            jugador[j].posicion_animacion.x+=velocidad_movimiento;
        else if (jug_y_2==bar_y_1||bar_y_1==jug_y_2-1)
            jugador[j].posicion_animacion.y-=velocidad_movimiento;
        else if (bar_y_2==jug_y_1||bar_y_2==jug_y_1+1)
            jugador[j].posicion_animacion.y+=velocidad_movimiento;
    }

    if (bala_x_2<bar_x_1||bar_x_2<bala_x_1||bala_y_2<bar_y_1||bar_y_2<bala_y_1);
    else
    {
    SDL_DestroyTexture(jugador[j].bala);
    jugador[j].bala_existe=0;
    jugador[j].posicion_bala.x=-300;
    }
   }
}


SDL_Texture *cargar_texturas (char ruta[50],SDL_Renderer *render)//Crea una textura a traves de una imagen (necesaria la ruta)
{
    SDL_Surface *superficie= IMG_Load(ruta);//Necesita una superficie y un render para crear la textura (SDL_CreateTextureFromSurface lo requiere asi)
    SDL_Texture *imagen= SDL_CreateTextureFromSurface(render,superficie);

    SDL_FreeSurface(superficie);//Liberamos la memoria que ocupa la superfice

    return imagen;//Devuelve la textura
}

void you_win(SDL_Rect *posicion_texto, int numero_vidas, SDL_Renderer *escenario, SDL_Texture *texto)//Se muestra un texto al finalizar la partida
{
    for (int i=0;i<100;i++)
    {
        posicion_texto->w+=5;//El tamaño del texto aumenta progresivamente
        posicion_texto->h+=2;
        SDL_RenderCopy(escenario,texto,NULL,&posicion_texto);
        SDL_RenderPresent(escenario);
    }
}

void movimiento_jugador(variables_jugador jugador[], int numero_jugador, int *tiempo)//Permite al usuario interactuar con su jugador
{
    const Uint8 *captura=SDL_GetKeyboardState(NULL);//Necesario para poder usar SDL_Scancode
    int velocidad_movimiento=2;
    SDL_Scancode teclas[4];

    if(numero_jugador==0)//En funcion del jugador en cuestion usara las teclas asdw o las flechas
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

    if(captura[teclas[0]])//Detecta si el una tecla esta pulsada, entoces se ejecuta la condicion
        {
            jugador[numero_jugador].recortar_animacion.y=jugador[numero_jugador].alto_animacion/4;
            jugador[numero_jugador].posicion_animacion.x+=velocidad_movimiento;//Mueve la animacion por el plano de la pantalla
            *tiempo+=1;
            if(*tiempo>=5)//Este if sirve para crear la animacion, el tiempo simplemente sirve para que no la ejecute demasiado rapido
            {
                jugador[numero_jugador].recortar_animacion.x+=jugador[numero_jugador].ancho_animacion/5;//Pasa a recortar la siguiente fase de la animacion
                if(jugador[numero_jugador].recortar_animacion.x>=jugador[numero_jugador].ancho_animacion)
                    jugador[numero_jugador].recortar_animacion.x=0;//Cuando llega a la ultima fase de la animacion vuelve a la primera fase
                *tiempo=0;
            }
        }
       if (captura[teclas[1]])//Se repite lo mismo para el resto de teclas
        {
            jugador[numero_jugador].recortar_animacion.y=0;
            jugador[numero_jugador].posicion_animacion.x-=velocidad_movimiento;
            *tiempo+=1;
            if(*tiempo>=5)
            {
                jugador[numero_jugador].recortar_animacion.x-=jugador[numero_jugador].ancho_animacion/5;
                if(jugador[numero_jugador].recortar_animacion.x<=0)
                    jugador[numero_jugador].recortar_animacion.x=jugador[numero_jugador].ancho_animacion*4/5;
                *tiempo=0;
            }
        }
        if (captura[teclas[2]])
        {
            jugador[numero_jugador].recortar_animacion.y=jugador[numero_jugador].alto_animacion/2;
            jugador[numero_jugador].posicion_animacion.y-=2;
            *tiempo+=1;
            if(*tiempo>=5)
            {
                jugador[numero_jugador].recortar_animacion.x+=jugador[numero_jugador].ancho_animacion/5;
                if(jugador[numero_jugador].recortar_animacion.x>=jugador[numero_jugador].ancho_animacion)
                    jugador[numero_jugador].recortar_animacion.x=0;
                *tiempo=0;
            }
        }
        if (captura[teclas[3]])
        {
            jugador[numero_jugador].recortar_animacion.y=jugador[numero_jugador].alto_animacion*3/4;
            jugador[numero_jugador].posicion_animacion.y+=2;
            *tiempo+=1;
            if(*tiempo>=5)
            {
                jugador[numero_jugador].recortar_animacion.x+=jugador[numero_jugador].ancho_animacion/5;
                if(jugador[numero_jugador].recortar_animacion.x>=jugador[numero_jugador].ancho_animacion)
                    jugador[numero_jugador].recortar_animacion.x=0;
                *tiempo=0;
            }
        }
}
void limites_mapa(variables_jugador jugador[],int numero_jugador)//Limita el movimiento del jugador al plano de la pantalla
{
    const int velocidad_movimiento=2;

    if(jugador[numero_jugador].posicion_animacion.x>=700)//Si el jugador llega a la posicion en cuestion avanzara 2 ya que se esta moviendo, pero retrocedera 2 al haber llegado al limite
        jugador[numero_jugador].posicion_animacion.x-=velocidad_movimiento;//En consecuencia el jugador no se mueve

    if (jugador[numero_jugador].posicion_animacion.x<=0)//Repetimos lo mismo en los lugares que nos interesan para definir el mapa
        jugador[numero_jugador].posicion_animacion.x+=velocidad_movimiento;

    if(jugador[numero_jugador].posicion_animacion.y<=0)
        jugador[numero_jugador].posicion_animacion.y+=velocidad_movimiento;

    if(jugador[numero_jugador].posicion_animacion.y>=400)
        jugador[numero_jugador].posicion_animacion.y-=velocidad_movimiento;

}
void disparar (variables_jugador jugador[], int numero_jugador, variables_jugador victima[], int numero_victima, SDL_Renderer *escenario, int *distx, int *disty)//Dispara una bala
{
    float x,y,cos,sin,distancia;

    jugador[numero_jugador].posicion_bala.x=jugador[numero_jugador].posicion_animacion.x+jugador[numero_jugador].posicion_animacion.w;//Establece la bala en una posicion inicial
    jugador[numero_jugador].posicion_bala.y=jugador[numero_jugador].posicion_animacion.y+jugador[numero_jugador].posicion_animacion.h/2;
    jugador[numero_jugador].posicion_bala.w=jugador[numero_jugador].posicion_bala.h=50;
    jugador[numero_jugador].recargando=1;//La bala existe y el jugador empieza a recargar la siguiente
    jugador[numero_jugador].bala_existe=1;
    jugador[numero_jugador].contador_bala++;//Lleva registro de cuantas balas se han disparado

    distancia=sqrt(pow(victima[numero_victima].posicion_animacion.x-jugador[numero_jugador].posicion_animacion.x,2)
                         +pow(victima[numero_victima].posicion_animacion.y-jugador[numero_jugador].posicion_animacion.y,2));

    x=victima[numero_victima].posicion_animacion.x-jugador[numero_jugador].posicion_animacion.x;
    y=victima[numero_victima].posicion_animacion.y-jugador[numero_jugador].posicion_animacion.y;

    cos=x/distancia;
    sin=y/distancia;

    *distx=6*cos;
    *disty=6*sin;
}

void recargar_y_movimiento(variables_jugador jugador[], int numero_jugador, int *tiempo_recarga, int distx, int disty)//Recarga la municion y mueve la bala por el plano
{

    if (jugador[numero_jugador].bala_existe==1)//Si la bala existe se movera por el plano de la pantalla
    {
        jugador[numero_jugador].posicion_bala.x+=distx;
        jugador[numero_jugador].posicion_bala.y+=disty;
    }
    if ((jugador[numero_jugador].posicion_bala.x>700||jugador[numero_jugador].posicion_bala.x<0) && jugador[numero_jugador].bala_existe==1)//Si la bala llega a los limites definidos se destruye
    {
        jugador[numero_jugador].posicion_bala.x=1300;
        jugador[numero_jugador].bala_existe=0;//La bala ya no existe
    }

    if (jugador[numero_jugador].recargando)//Si esta recargando se ejecuta el if
    {
    *tiempo_recarga+=1;//Para que no recargue demasiado rapido
       if (jugador[numero_jugador].recortar_municion.x>=50/*jugador[numero_jugador].ancho_municion/4*/)//Recorta la imagen desde el principio cuando esta se ha recortado por completo
        {
            jugador[numero_jugador].recortar_municion.x=0;
            jugador[numero_jugador].posicion_municion.w=100;
            jugador[numero_jugador].recargando=0;
        }


        if (*tiempo_recarga==2)
        {
            jugador[numero_jugador].recortar_municion.x+=1;//Efecto de recarga, cada vez queda menos para que termine (cuando recorte la imagen al completo finaliza la recarga)
            jugador[numero_jugador].posicion_municion.w-=1;
            *tiempo_recarga=0;
        }
    }
}
void interseccion(variables_jugador jugador[], int numero_jugador, variables_jugador victima[], int numero_victima)//Si intersecan 2 objetos
{
    float distancia=sqrt(pow(victima[numero_victima].posicion_animacion.x-jugador[numero_jugador].posicion_bala.x,2)
                         +pow(victima[numero_victima].posicion_animacion.y-jugador[numero_jugador].posicion_bala.y,2));//Pitagoras para saber la distancia entre la bala y el jugador

    if(distancia>50)//No intersecan
        victima[numero_victima].intersecan=0;//Si no intersecan devuelve 0

    else if (distancia<50)//Distancia corta, intersecan
    {
        victima[numero_victima].numero_vidas--;//La victima pierde una vida
        victima[numero_victima].intersecan=1;//Como intersecan devuelve 1
        //Destruye la bala
        jugador[numero_jugador].bala_existe=0;//La bala no existe
        jugador[numero_jugador].posicion_bala.x=1300;//La funcion calcula la posicion de la bala, pero al destruirla no resetea la posicion
    }                                                  //Parecería que esta intersecando continuamente, asi que asignamos a la bala una posicion fuera de la pantalla

}

void vidas_restantes(variables_jugador victima[], int numero_victima)//Animacion para indicar el numero de vidas restantes
{
    switch(victima[numero_victima].numero_vidas)//En funcion del numero de vidas recortara un trozo de la imagen y le asignara una posicion
    {
    case 3:
        SDL_SetTextureColorMod(victima[numero_victima].animacion,255,255,255);
        break;
    case 2:
        SDL_SetTextureColorMod(victima[numero_victima].animacion,0,255,0);
        victima[numero_victima].recortar_vidas.x+=victima[numero_victima].ancho_vida/3;
        victima[numero_victima].recortar_vidas.y=0;
        victima[numero_victima].posicion_vidas.w-=33;
        break;
    case 1:
        SDL_SetTextureColorMod(victima[numero_victima].animacion,255,0,0);
        victima[numero_victima].recortar_vidas.x+=victima[numero_victima].ancho_vida/3;
        victima[numero_victima].posicion_vidas.w-=33;
        break;
    case 0:
        break;
    }
}

void generar_jugador(variables_jugador jugador[], int numero_jugador, SDL_Renderer *escenario, _Bool cargar)//Establece valores predeterminados al jugador indicado
{
    int posicion_animacion,posicion_vidas,posicion_municion;
    if (numero_jugador==0) //En funcion del jugador aparecera en un lugar u otro de la pantalla
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

    jugador[numero_jugador].vidas=cargar_texturas("Vida.png",escenario); //Genera las texturas a traves de la funcion cargar_texturas
    jugador[numero_jugador].municion=cargar_texturas("Zanahoria.png",escenario);
    jugador[numero_jugador].animacion=cargar_texturas("Animation.png",escenario);
    jugador[numero_jugador].bala=cargar_texturas("Estrella.png",escenario);
    jugador[numero_jugador].trampa=cargar_texturas("Trampa.png",escenario);

    SDL_QueryTexture(jugador[numero_jugador].vidas,NULL,NULL,&jugador[numero_jugador].ancho_vida,&jugador[numero_jugador].alto_vida);//Mide el tamaño de una textura y le asigna el ancho y el alto a las variables indicadas
    SDL_QueryTexture(jugador[numero_jugador].municion,NULL,NULL,&jugador[numero_jugador].ancho_municion,&jugador[numero_jugador].alto_municion);
    SDL_QueryTexture(jugador[numero_jugador].animacion,NULL,NULL,&jugador[numero_jugador].ancho_animacion,&jugador[numero_jugador].alto_animacion);

    jugador[numero_jugador].recortar_animacion.x=jugador[numero_jugador].recortar_animacion.y=0; //Indica donde comenzara a recortarse la animacion
    jugador[numero_jugador].recortar_animacion.w=jugador[numero_jugador].ancho_animacion/5;
    jugador[numero_jugador].recortar_animacion.h=jugador[numero_jugador].alto_animacion/4;
    jugador[numero_jugador].posicion_animacion.x=jugador[numero_jugador].posicion_animacion.y=posicion_animacion;//Posicion inicial de la animacion
    jugador[numero_jugador].posicion_animacion.w=jugador[numero_jugador].posicion_animacion.h=100;

    jugador[numero_jugador].recortar_vidas.x=jugador[numero_jugador].recortar_vidas.y=0;//Indica donde comenzara a recortarse las vidas
    jugador[numero_jugador].recortar_vidas.w=jugador[numero_jugador].ancho_vida;
    jugador[numero_jugador].recortar_vidas.h=jugador[numero_jugador].alto_vida;
    jugador[numero_jugador].posicion_vidas.x=posicion_vidas;//Posicion inicial de las vidas
    jugador[numero_jugador].posicion_vidas.y=0;
    jugador[numero_jugador].posicion_vidas.w=100;
    jugador[numero_jugador].posicion_vidas.h=50;

    jugador[numero_jugador].recortar_municion.x=jugador[numero_jugador].recortar_municion.y=0; //Indica donde comenzara a recortarse la municion
    jugador[numero_jugador].recortar_municion.w=jugador[numero_jugador].ancho_municion;
    jugador[numero_jugador].recortar_municion.h=jugador[numero_jugador].alto_municion;
    jugador[numero_jugador].posicion_municion.x=posicion_municion;//Posicion inicial de la municion
    jugador[numero_jugador].posicion_municion.y=0;
    jugador[numero_jugador].posicion_municion.w=100;
    jugador[numero_jugador].posicion_municion.h=50;

    jugador[numero_jugador].posicion_trampa.w=50;
    jugador[numero_jugador].posicion_trampa.h=50;
    jugador[numero_jugador].posicion_trampa.x=1300;
    jugador[numero_jugador].posicion_trampa.y=1300;

    jugador[numero_jugador].numero_vidas=3; //Numero de vidas inicial
    jugador[numero_jugador].intersecan=0; //Valores predeterminados para los parametros restantes
    jugador[numero_jugador].recargando=0;
    jugador[numero_jugador].bala_existe=0;
    jugador[numero_jugador].contador_bala=0;
    jugador[numero_jugador].trampa_cargada=1;
}
void copiar_atributos(variables_jugador jugador[], int numero_jugador, SDL_Renderer *escenario)//Copia los atributos de un jugador sobre el render
{
    SDL_RenderCopy(escenario,jugador[numero_jugador].animacion,&jugador[numero_jugador].recortar_animacion,&jugador[numero_jugador].posicion_animacion);
    SDL_RenderCopy(escenario,jugador[numero_jugador].vidas,&jugador[numero_jugador].recortar_vidas,&jugador[numero_jugador].posicion_vidas);
    SDL_RenderCopy(escenario,jugador[numero_jugador].municion,&jugador[numero_jugador].recortar_municion,&jugador[numero_jugador].posicion_municion);
    SDL_RenderCopy(escenario,jugador[numero_jugador].bala,NULL,&jugador[numero_jugador].posicion_bala);
    SDL_RenderCopy(escenario,jugador[numero_jugador].trampa,NULL,&jugador[numero_jugador].posicion_trampa);
}

void destruir_atributos(variables_jugador jugador[], int numero_jugador)//Destruye los atributos de un jugador
{
    SDL_DestroyTexture(jugador[numero_jugador].vidas);
    SDL_DestroyTexture(jugador[numero_jugador].animacion);
    SDL_DestroyTexture(jugador[numero_jugador].municion);
    SDL_DestroyTexture(jugador[numero_jugador].bala);
}

void fichero (variables_jugador jugador[], int numero_jugador, char nombre_partida[])
{
    FILE *datos_partida;
    int i;

    datos_partida=fopen(nombre_partida,"w");

    if (datos_partida==NULL)
    {
        printf("Error al guardar el juego");
    }

    else
    {
        for (i=0; i<=1;i++)
        fprintf(datos_partida,"%i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i ",
                jugador[i].posicion_animacion.x,jugador[i].posicion_animacion.y,jugador[i].posicion_animacion.w,jugador[i].posicion_animacion.h,
                jugador[i].recortar_animacion.x,jugador[i].recortar_animacion.y,jugador[i].recortar_animacion.w,jugador[i].recortar_animacion.h,
                jugador[i].posicion_vidas.x,jugador[i].posicion_vidas.y,jugador[i].posicion_vidas.w,jugador[i].posicion_vidas.h,
                jugador[i].recortar_vidas.x,jugador[i].recortar_vidas.y,jugador[i].recortar_vidas.w,jugador[i].recortar_vidas.h,
                jugador[i].numero_vidas,jugador[i].contador_bala);

        fprintf(datos_partida,"\n\n");

        for (i=0;i<=1;i++)
        {
        fprintf(datos_partida,"Numero de jugador %i\n\n",i);

        fprintf(datos_partida,"Numero de vidas: %i\n",jugador[i].numero_vidas);
        fprintf(datos_partida,"Balas usadas: %i\n",jugador[i].contador_bala);

        fprintf(datos_partida,"Recargando, intersecan, balas existe: %i %i %i\n",jugador[i].recargando,jugador[i].intersecan,jugador[i].bala_existe);

        fprintf(datos_partida,"Posicion bala: x:%i y:%i w:%i h:%i\n",jugador[i].posicion_bala.x,jugador[i].posicion_bala.y,jugador[i].posicion_bala.w,jugador[i].posicion_bala.h);

        fprintf(datos_partida,"Posicion animacion: x:%i y:%i w:%i h:%i\n",jugador[i].posicion_animacion.x,jugador[i].posicion_animacion.y,jugador[i].posicion_animacion.w,jugador[i].posicion_animacion.h);
        fprintf(datos_partida,"Recortar animacion: x:%i y:%i w:%i h:%i\n",jugador[i].recortar_animacion.x,jugador[i].recortar_animacion.y,jugador[i].recortar_animacion.w,jugador[i].recortar_animacion.h);

        fprintf(datos_partida,"Posicion municion: x:%i y:%i w:%i h:%i\n",jugador[i].posicion_municion.x,jugador[i].posicion_municion.y,jugador[i].posicion_municion.w,jugador[i].posicion_municion.h);
        fprintf(datos_partida,"Recortar municion: x:%i y:%i w:%i h:%i\n",jugador[i].recortar_municion.x,jugador[i].recortar_municion.y,jugador[i].recortar_municion.w,jugador[i].recortar_municion.h);

        fprintf(datos_partida,"Posicion vidas: x:%i y:%i w:%i h:%i\n",jugador[i].posicion_vidas.x,jugador[i].posicion_vidas.y,jugador[i].posicion_vidas.w,jugador[i].posicion_vidas.h);
        fprintf(datos_partida,"Recortar vidas: x:%i y:%i w:%i h:%i\n",jugador[i].recortar_vidas.x,jugador[i].recortar_vidas.y,jugador[i].recortar_vidas.w,jugador[i].recortar_vidas.h);

        fprintf(datos_partida,"Trampa cargada: %i\n",jugador[i].interseca_trampa);

        fprintf(datos_partida,"\n\n");
        }
    }

    fclose(datos_partida);
}

void cargar_partida(variables_jugador jugador[], int numero_jugador, _Bool cargar, SDL_Renderer *escenario, char nombre_partida[])
{
    FILE *puntero_datos;
    int i=0;

    if (cargar)
    {
    puntero_datos=fopen(nombre_partida,"r");
    for (i=0;i<2;i++)
    fscanf(puntero_datos,"%i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i ",
            &jugador[i].posicion_animacion.x,&jugador[i].posicion_animacion.y,&jugador[i].posicion_animacion.w,&jugador[i].posicion_animacion.h,
            &jugador[i].recortar_animacion.x,&jugador[i].recortar_animacion.y,&jugador[i].recortar_animacion.w,&jugador[i].recortar_animacion.h,
            &jugador[i].posicion_vidas.x,&jugador[i].posicion_vidas.y,&jugador[i].posicion_vidas.w,&jugador[i].posicion_vidas.h,
            &jugador[i].recortar_vidas.x,&jugador[i].recortar_vidas.y,&jugador[i].recortar_vidas.w,&jugador[i].recortar_vidas.h,
            &jugador[i].numero_vidas,&jugador[i].contador_bala);

    fclose(puntero_datos);
    }
}

void datos_partida(char nombre_partida[50])
{
    FILE *puntero_datos;

    char aux;
    char funciona=1;

    puntero_datos=fopen(nombre_partida,"r");

    fseek(puntero_datos,0,SEEK_SET);
    while(fscanf(puntero_datos,"%c",&aux)!=EOF && funciona)
        if (aux=='\n')
        funciona=0;

    while(fscanf(puntero_datos,"%c",&aux)!=EOF)
        printf("%c",aux);


    fclose(puntero_datos);
}

void mina (variables_barrera barrera[],int numero_barrera,SDL_Renderer *escenario,variables_jugador jugador[], int numero_jugador, int *tiempo_mina)
{

    int aleatorio;
    _Bool intersecan=1;
    float dist;

    do
    {
    aleatorio=rand()%20;
    aleatorio++;

    switch(aleatorio)
        {
            case 1:
            barrera[numero_barrera].posicion_mina.x=300;
            barrera[numero_barrera].posicion_mina.y=127;
            break;
            case 2:
            barrera[numero_barrera].posicion_mina.x=400;
            barrera[numero_barrera].posicion_mina.y=128;
            break;
            case 3:
            barrera[numero_barrera].posicion_mina.x=500;
            barrera[numero_barrera].posicion_mina.y=129;
            break;
            case 4:
            barrera[numero_barrera].posicion_mina.x=600;
            barrera[numero_barrera].posicion_mina.y=130;
            break;
            case 5:
            barrera[numero_barrera].posicion_mina.x=700;
            barrera[numero_barrera].posicion_mina.y=131;
            break;
            case 6:
            barrera[numero_barrera].posicion_mina.x=800;
            barrera[numero_barrera].posicion_mina.y=132;
            break;
            case 7:
            barrera[numero_barrera].posicion_mina.x=900;
            barrera[numero_barrera].posicion_mina.y=133;
            break;
            case 8:
            barrera[numero_barrera].posicion_mina.x=350;
            barrera[numero_barrera].posicion_mina.y=134;
            break;
            case 9:
            barrera[numero_barrera].posicion_mina.x=450;
            barrera[numero_barrera].posicion_mina.y=135;
            break;
            case 10:
            barrera[numero_barrera].posicion_mina.x=550;
            barrera[numero_barrera].posicion_mina.y=136;
            break;
            case 11:
            barrera[numero_barrera].posicion_mina.x=650;
            barrera[numero_barrera].posicion_mina.y=137;
            break;
            case 12:
            barrera[numero_barrera].posicion_mina.x=750;
            barrera[numero_barrera].posicion_mina.y=138;
            break;
            case 13:
            barrera[numero_barrera].posicion_mina.x=850;
            barrera[numero_barrera].posicion_mina.y=139;
            break;
            case 14:
            barrera[numero_barrera].posicion_mina.x=950;
            barrera[numero_barrera].posicion_mina.y=140;
            break;
            case 15:
            barrera[numero_barrera].posicion_mina.x=300;
            barrera[numero_barrera].posicion_mina.y=141;
            break;
            case 16:
            barrera[numero_barrera].posicion_mina.x=300;
            barrera[numero_barrera].posicion_mina.y=142;
            break;
            case 17:
            barrera[numero_barrera].posicion_mina.x=300;
            barrera[numero_barrera].posicion_mina.y=143;
            break;
            case 18:
            barrera[numero_barrera].posicion_mina.x=300;
            barrera[numero_barrera].posicion_mina.y=147;
            break;
            case 19:
            barrera[numero_barrera].posicion_mina.x=300;
            barrera[numero_barrera].posicion_mina.y=144;
            break;
            case 20:
            barrera[numero_barrera].posicion_mina.x=300;
            barrera[numero_barrera].posicion_mina.y=145;
            break;
        }
        dist=sqrt(pow(barrera[numero_barrera].posicion_mina.x-jugador[numero_jugador].posicion_animacion.x,2)
                         +pow(barrera[numero_barrera].posicion_mina.y-jugador[numero_jugador].posicion_animacion.y,2));
        if (dist>50)
            intersecan=0;
    }
    while(intersecan);
}

void interseccion_mina(variables_jugador jugador[], int numero_jugador,variables_barrera barrera[], int numero_barrera)
{
    float distancia=sqrt(pow(barrera[numero_barrera].posicion_mina.x-jugador[numero_jugador].posicion_animacion.x,2)
                         +pow(barrera[numero_barrera].posicion_mina.y-jugador[numero_jugador].posicion_animacion.y,2));//Pitagoras para saber la distancia entre la bala y el jugador

    if(distancia>50)//No intersecan
        jugador[numero_jugador].interseca_mina=0;//Si no intersecan devuelve 0

    else if (distancia<50)//Distancia corta, intersecan
    {
        jugador[numero_jugador].numero_vidas--;//La victima pierde una vida
        jugador[numero_jugador].interseca_mina=1;//Como intersecan devuelve 1
        barrera[numero_barrera].mina_existe=0;
        barrera[numero_barrera].posicion_mina.x=1400;
    }
}

void explosion_mina(variables_jugador jugador[], int numero_jugador, variables_barrera barrera[],int numero_barrera)
{
    float distancia=sqrt(pow(barrera[numero_barrera].posicion_mina.x-jugador[numero_jugador].posicion_bala.x,2)
                         +pow(barrera[numero_barrera].posicion_mina.y-jugador[numero_jugador].posicion_bala.y,2));

    _Bool explota=0;

    if (distancia<50)
    {
        barrera[numero_barrera].posicion_explosion.x=barrera[numero_barrera].posicion_mina.x+barrera[numero_barrera].posicion_mina.w;
        barrera[numero_barrera].posicion_explosion.y=barrera[numero_barrera].posicion_mina.y+barrera[numero_barrera].posicion_mina.h;
        barrera[numero_barrera].posicion_explosion.w=barrera[numero_barrera].posicion_explosion.h=20;

        explota=1;
        barrera[numero_barrera].posicion_mina.x=1500;
        barrera[numero_barrera].mina_existe=0;
        jugador[numero_jugador].posicion_bala.x=1300;
        jugador[numero_jugador].bala_existe=0;
        barrera[numero_barrera].explota=1;

    }

    if (explota)
    {
        for (int i=0;i<2;i++)
        {
        if (sqrt(pow(barrera[numero_barrera].posicion_explosion.x-jugador[i].posicion_animacion.x,2)
                         +pow(barrera[numero_barrera].posicion_explosion.y-jugador[i].posicion_animacion.y,2))<100)
        {
            jugador[i].interseca_mina=1;
            jugador[i].numero_vidas--;
        }
        }
    }

}

void interseccion_trampa(variables_jugador jugador[], int numero_jugador, variables_jugador victima[], int numero_victima)
{
    float distancia=sqrt(pow(jugador[numero_jugador].posicion_trampa.x-victima[numero_victima].posicion_animacion.x,2)+
                         pow(jugador[numero_jugador].posicion_trampa.y-victima[numero_victima].posicion_animacion.y,2));

    if(distancia<50)
    {
        victima[numero_victima].numero_vidas--;
        jugador[numero_jugador].posicion_trampa.x=1300;
        victima[numero_victima].interseca_trampa=1;
    }
    else
        victima[numero_victima].interseca_trampa=0;
}

void multijugador(_Bool cargar, char nombre_partida[])
{
    int control=0;
    double segma;
    int chocan;
    long int seconds;
    long int microseconds;
    double elapsed=0;
    struct timeval begin,end;
    int segundos;
    int tiempo_explosion=0;
    int tiempo_mina=0;
    int tiempo_estructura=0;
    int tiempo_recarga_estructura=0;
    int tiempo_jugador2=0;
    int tiempo_jugador=0;
    int distx1=0,distx2=0,disty1=0,disty2=0;
    int ancho,alto,incremento;
    _Bool trampa_cargada=0;


    SDL_Window *ventanaprincipal=NULL;//Ventana donde se ejecuta el juego
    SDL_Surface *superficieprincipal=NULL;//Superficie para la ventana, como si fuera un lienzo
    SDL_Renderer *escenario=NULL;//Representa cosas sobre la superficie, como si fuese la pintura


    SDL_Event evento; //Pulsar una tecla, mover el mouse... son eventos
    _Bool ejecutando=1; //Si el programa esta en proceso

    SDL_Init(SDL_INIT_EVERYTHING);//Inicializa la biblioteca SDL (no vamos a hacer comprobaciones de errores, por ahora)

    ventanaprincipal=SDL_CreateWindow("Juego laberinto",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,960,720,NULL);//Crea una ventana, centrada, de dimensiones 960x720
    superficieprincipal=SDL_GetWindowSurface(ventanaprincipal);//Aporta una superficie a la ventana
    escenario=SDL_CreateRenderer(ventanaprincipal,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);//Crea un render (necesario definirlo de esta forma para que funcione bien)

SDL_Texture *texto_ganador=NULL;
SDL_Rect posicion_texto; //La posicion en la que estara el texto al finalizar el programa
posicion_texto.x=300;
posicion_texto.y=150;
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
    generar_jugador(jugador,0,escenario,cargar);
    generar_jugador(jugador,1,escenario,cargar);
    cargar_partida(jugador,0,cargar,escenario,nombre_partida);//Si cargamos partida carga los valores guardados sobre la estructura jugador
}

variables_barrera *barrera;

barrera=malloc(sizeof(variables_barrera));

if (barrera==NULL)
{
    SDL_Log("ERROR");
    exit(-1);
}

else
{
    cargar_muro(barrera,0,escenario,"Barrera.png","Texto.png");
}

if (cargar) //Al cargar la partida el color de los jugadores se resetea; es necesario comprobar el numero de vidas restantes
{
    for (int i=0;i<2;i++)
    {
        if (jugador[i].numero_vidas==3)
            SDL_SetTextureColorMod(jugador[i].animacion,255,255,255);
        else if (jugador[i].numero_vidas==2)
            SDL_SetTextureColorMod(jugador[i].animacion,0,255,0);
        else
            SDL_SetTextureColorMod(jugador[i].animacion,255,0,0);
    }
}
barrera[0].mina_existe=1;
barrera[0].explota=0;

   while(ejecutando)//El programa principal es un bucle que se reproduce infinitamente hasta que cambiemos el valor de ejecutando
    {
        gettimeofday(&begin, 0);
        tiempo_mina++;

        while(SDL_PollEvent(&evento)!=0)//Procesa los eventos que se producen cada vez que se produce el bucle
        {                               //Finaliza el bucle cuando no queden eventos por procesar
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

                if (evento.key.keysym.sym==SDLK_m)
                    {
                        if (jugador[0].trampa_cargada==1)
                        {
                        jugador[0].trampa_cargada=0;
                        jugador[0].posicion_trampa.x=jugador[0].posicion_animacion.x;
                        jugador[0].posicion_trampa.y=jugador[0].posicion_animacion.y;
                        }
                    }
                if (evento.key.keysym.sym==SDLK_e)
                    {
                        if (jugador[1].trampa_cargada==1)
                        {
                        jugador[1].trampa_cargada=0;
                        jugador[1].posicion_trampa.x=jugador[1].posicion_animacion.x;
                        jugador[1].posicion_trampa.y=jugador[1].posicion_animacion.y;
                        }
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

        if (tiempo_mina>=200)
        {
            mina(barrera,0,escenario,jugador,0,&tiempo_mina);
            mina(barrera,0,escenario,jugador,1,&tiempo_mina);
            tiempo_mina=0;
        }

        interseccion_mina(jugador,0,barrera,0);
        interseccion_mina(jugador,1,barrera,0);

        interseccion_trampa(jugador,0,jugador,1);
        interseccion_trampa(jugador,1,jugador,0);

        explosion_mina(jugador,0,barrera,0);
        explosion_mina(jugador,1,barrera,0);

        if(jugador[1].intersecan||jugador[1].interseca_mina || jugador[1].interseca_trampa)//Si la bala 0 interseca con el jugador 1
                                                            //llama a la funcion vidas restantes
        {
            vidas_restantes(jugador,1);
        }

        if(jugador[0].intersecan||jugador[0].interseca_mina || jugador[0].interseca_trampa)
        {
            vidas_restantes(jugador,0);
        }

        SDL_RenderClear(escenario);//Limpia lo que haya en el escenario
        copiar_atributos(jugador,0,escenario); //Pega en el escenario las caracteristicas de cada jugador tras acabar el bucle
        copiar_atributos(jugador,1,escenario);
        SDL_RenderCopy(escenario,barrera[0].mina,&barrera[0].recortar_mina,&barrera[0].posicion_mina);

        if(barrera[0].explota)
        {
            tiempo_explosion++;
            SDL_RenderCopy(escenario,barrera[0].explosion,NULL,&barrera[0].posicion_explosion);
            if (tiempo_explosion>=50)
            {
                barrera[0].explota=0;
                barrera[0].posicion_explosion.x=1500;
                tiempo_explosion=0;
            }
        }
        SDL_RenderPresent(escenario);//Presenta el render sobre la ventana principal

        gettimeofday(&end, 0);
        seconds = end.tv_sec - begin.tv_sec;
        microseconds = end.tv_usec - begin.tv_usec;
        elapsed += seconds + microseconds*1e-6;

        if (elapsed>100.0)
            elapsed=0.0;

        if (jugador[0].numero_vidas==0||jugador[1].numero_vidas==0)
        {
            if (jugador[0].numero_vidas==0)
                texto_ganador=cargar_texturas("Player2 wins.png", escenario);
            if (jugador[1].numero_vidas==0)
                texto_ganador=cargar_texturas("Player1 wins.png",escenario);

            SDL_RenderClear(escenario);
            for (int i=0;i<300;i++)
            {
                control++;
                posicion_texto.h++;
                posicion_texto.w++;
                switch(control)
                {
                case 2:
                    posicion_texto.x+=20;
                    break;
                case 4:
                    posicion_texto.y+=20;
                    break;
                case 6:
                    posicion_texto.x-=20;
                    break;
                case 8:
                    posicion_texto.y-=20;
                    break;
                case 10:
                    control=0;
                    break;
                }

                SDL_RenderCopy(escenario,texto_ganador,NULL,&posicion_texto);
                SDL_RenderPresent(escenario);
            }
                ejecutando=0;
        }

    }//Fin del bucle principal y por tanto de la partida


    fichero(jugador,0,nombre_partida);

    free(barrera);
    free(jugador);//Libera lo reservado con malloc anteriormente
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
}


