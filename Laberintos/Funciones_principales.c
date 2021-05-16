#include <stdio.h>
#include <math.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Funciones_principales.h"
#include <sys/time.h>

void cargar_muro (variables_barrera barrera[],SDL_Renderer *escenario,int numero_barrera, int w, int h)
{
  int alto,ancho;
  barrera[numero_barrera].muro=cargar_texturas("Barrera.png",escenario);
  SDL_QueryTexture(barrera[numero_barrera].muro,NULL,NULL,&ancho,&alto);
  barrera[numero_barrera].recortar_muro.x=barrera[numero_barrera].recortar_muro.y=0;
  barrera[numero_barrera].recortar_muro.w=ancho;
  barrera[numero_barrera].recortar_muro.h=alto;
  barrera[numero_barrera].posicion_muro.w=w;
  barrera[numero_barrera].posicion_muro.h=h;
}
void hacer_muro (int x,int y,int n,variables_barrera barrera[],int numero_barrera,int direccion_muro,SDL_Renderer *escenario,variables_jugador jugador[])
{

    int velocidad_movimiento=2;
    int i,j;
    barrera[numero_barrera].posicion_muro.x=x;
    barrera[numero_barrera].posicion_muro.y=y;
    int bar_x_1=x,bar_y_1=y;
    int bar_x_2=x,bar_y_2=y;

    if (direccion_muro==0)
    {
    bar_x_2+=barrera[numero_barrera].posicion_muro.w;
    for(i=0;i<n;i++)
      {
        SDL_RenderCopy(escenario,barrera[numero_barrera].muro,&barrera[numero_barrera].recortar_muro,&barrera[numero_barrera].posicion_muro);
        barrera[numero_barrera].posicion_muro.y+=barrera[numero_barrera].posicion_muro.h;
        bar_y_2+=barrera[numero_barrera].posicion_muro.h;
      }
    }

    if (direccion_muro==1)
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
    if (numero_vidas==0)
        {
            posicion_texto->w+=5;//El tamaño del texto aumenta progresivamente
            posicion_texto->h+=2;
            SDL_RenderCopy(escenario,texto,NULL,posicion_texto);
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
            jugador[numero_jugador].recortar_animacion.y=0;
            jugador[numero_jugador].posicion_animacion.x+=velocidad_movimiento;//Mueve la animacion por el plano de la pantalla
            *tiempo+=1;
            if(*tiempo>=5)//Este if sirve para crear la animacion, el tiempo simplemente sirve para que no la ejecute demasiado rapido
            {
                jugador[numero_jugador].recortar_animacion.x+=jugador[numero_jugador].ancho_animacion/8;//Pasa a recortar la siguiente fase de la animacion
                if(jugador[numero_jugador].recortar_animacion.x>=jugador[numero_jugador].ancho_animacion)
                    jugador[numero_jugador].recortar_animacion.x=0;//Cuando llega a la ultima fase de la animacion vuelve a la primera fase
                *tiempo=0;
            }
        }
       if (captura[teclas[1]])//Se repite lo mismo para el resto de teclas
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

    jugador[numero_jugador].bala=cargar_texturas("Estrella.png",escenario);//Crea la bala
    jugador[numero_jugador].posicion_bala.x=jugador[numero_jugador].posicion_animacion.x+jugador[numero_jugador].posicion_animacion.w;//Establece la bala en una posicion inicial
    jugador[numero_jugador].posicion_bala.y=jugador[numero_jugador].posicion_animacion.y+jugador[numero_jugador].posicion_animacion.h/2;
    jugador[numero_jugador].posicion_bala.w=jugador[numero_jugador].posicion_bala.h=50;
    jugador[numero_jugador].recargando=1;//La bala existe y el jugador empieza a recargar la siguiente
    jugador[numero_jugador].bala_existe=1;
    jugador[numero_jugador].contador_bala++;//Lleva regustro de cuantas balas se han disparado

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
        SDL_DestroyTexture(jugador[numero_jugador].bala);
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
        switch(victima[numero_victima].numero_vidas)//En funcion de las vidas restantes el jugador tendra un color u otro
        {
            case 3:
                SDL_SetTextureColorMod(victima[numero_victima].animacion,255,255,255);//Asigna un color al jugador
                break;
            case 2:
                SDL_SetTextureColorMod(victima[numero_victima].animacion,0,255,0);
                break;
            case 1:
                SDL_SetTextureColorMod(victima[numero_victima].animacion,255,0,0);
                break;
        }
        victima[numero_victima].intersecan=1;//Como intersecan devuelve 1
        SDL_DestroyTexture(jugador[numero_jugador].bala);//Destruye la bala
        jugador[numero_jugador].bala_existe=0;//La bala no existe
        jugador[numero_jugador].posicion_bala.x=1300;//La funcion calcula la posicion de la bala, pero al destruirla no resetea la posicion
    }                                                  //Parecería que esta intersecando continuamente, asi que asignamos a la bala una posicion fuera de la pantalla

}

int vidas_restantes(variables_jugador victima[], int numero_victima)//Animacion para indicar el numero de vidas restantes
{
    switch(victima[numero_victima].numero_vidas)//En funcion del numero de vidas recortara un trozo de la imagen y le asignara una posicion
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
    return victima[numero_victima].numero_vidas;//Devuelve el numero de vidas restantes
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
    jugador[numero_jugador].animacion=cargar_texturas("Animacion.png",escenario);

    SDL_QueryTexture(jugador[numero_jugador].vidas,NULL,NULL,&jugador[numero_jugador].ancho_vida,&jugador[numero_jugador].alto_vida);//Mide el tamaño de una textura y le asigna el ancho y el alto a las variables indicadas
    SDL_QueryTexture(jugador[numero_jugador].municion,NULL,NULL,&jugador[numero_jugador].ancho_municion,&jugador[numero_jugador].alto_municion);
    SDL_QueryTexture(jugador[numero_jugador].animacion,NULL,NULL,&jugador[numero_jugador].ancho_animacion,&jugador[numero_jugador].alto_animacion);

    jugador[numero_jugador].recortar_animacion.x=jugador[numero_jugador].recortar_animacion.y=0; //Indica donde comenzara a recortarse la animacion
    jugador[numero_jugador].recortar_animacion.w=jugador[numero_jugador].ancho_animacion/8;
    jugador[numero_jugador].recortar_animacion.h=jugador[numero_jugador].alto_animacion/2;
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

    jugador[numero_jugador].numero_vidas=3; //Numero de vidas inicial
    jugador[numero_jugador].intersecan=0; //Valores predeterminados para los parametros restantes
    jugador[numero_jugador].recargando=0;
    jugador[numero_jugador].bala_existe=0;
    jugador[numero_jugador].contador_bala=0;
}
void copiar_atributos(variables_jugador jugador[], int numero_jugador, SDL_Renderer *escenario)//Copia los atributos de un jugador sobre el render
{
    SDL_RenderCopy(escenario,jugador[numero_jugador].animacion,&jugador[numero_jugador].recortar_animacion,&jugador[numero_jugador].posicion_animacion);
    SDL_RenderCopy(escenario,jugador[numero_jugador].vidas,&jugador[numero_jugador].recortar_vidas,&jugador[numero_jugador].posicion_vidas);
    SDL_RenderCopy(escenario,jugador[numero_jugador].municion,&jugador[numero_jugador].recortar_municion,&jugador[numero_jugador].posicion_municion);

    if (jugador[numero_jugador].bala_existe)//Solamente copiara la bala si existe
    SDL_RenderCopy(escenario,jugador[numero_jugador].bala,NULL,&jugador[numero_jugador].posicion_bala);
}

void destruir_atributos(variables_jugador jugador[], int numero_jugador)//Destruye los atributos de un jugador
{
    SDL_DestroyTexture(jugador[numero_jugador].vidas);
    SDL_DestroyTexture(jugador[numero_jugador].animacion);
    SDL_DestroyTexture(jugador[numero_jugador].municion);
    SDL_DestroyTexture(jugador[numero_jugador].bala);
}

void fichero (variables_jugador jugador[], int numero_jugador)
{
    FILE *datos_partida;
    int i;

    datos_partida=fopen("Nombre partida.txt","w");

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

        fprintf(datos_partida,"\n");

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

        fprintf(datos_partida,"\n\n");
        }
    }

    fclose(datos_partida);
}

void cargar_partida(variables_jugador jugador[], int numero_jugador, _Bool cargar, SDL_Renderer *escenario)
{
    FILE *puntero_datos;
    int aux;
    int i=0,j=0;

    if (cargar)
    {
    puntero_datos=fopen("Nombre partida.txt","r");
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
void datos_partida(_Bool estadisticas)
{
    FILE *puntero_datos;

    char aux;

    puntero_datos=fopen("Nombre partida.txt","r");

    if (estadisticas==1)
    {
        fseek(puntero_datos,0,SEEK_SET);
        while(fscanf(puntero_datos,"%c",&aux)!=EOF)
            printf("%c",aux);
    }

    fclose(puntero_datos);
}

void multijugador(_Bool cargar)
{
    int tiempo_estructura=0;
    int tiempo_recarga_estructura=0;
    int tiempo_jugador2=0;
    int tiempo_jugador=0;
    int distx1=0,distx2=0,disty1=0,disty2=0;

    SDL_Window *ventanaprincipal=NULL;//Ventana donde se ejecuta el juego
    SDL_Surface *superficieprincipal=NULL;//Superficie para la ventana, como si fuera un lienzo
    SDL_Renderer *escenario=NULL;//Representa cosas sobre la superficie, como si fuese la pintura

    SDL_Texture *texto_ganador=NULL;
    SDL_Event evento; //Pulsar una tecla, mover el mouse... son eventos
    _Bool ejecutando=1; //Si el programa esta en proceso

    SDL_Init(SDL_INIT_EVERYTHING);//Inicializa la biblioteca SDL (no vamos a hacer comprobaciones de errores, por ahora)

    ventanaprincipal=SDL_CreateWindow("Juego laberinto",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,960,720,NULL);//Crea una ventana, centrada, de dimensiones 960x720
    superficieprincipal=SDL_GetWindowSurface(ventanaprincipal);//Aporta una superficie a la ventana
    escenario=SDL_CreateRenderer(ventanaprincipal,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);//Crea un render (necesario definirlo de esta forma para que funcione bien)


SDL_Rect posicion_texto; //La posicion en la que estara el texto al finalizar el programa
posicion_texto.x=posicion_texto.y=250;
posicion_texto.w=posicion_texto.h=0;

SDL_Texture *muro;
SDL_Rect pos;
pos.x=pos.y=0;
pos.w=pos.h=50;

SDL_Rect pos1;
pos1.x=pos1.y=30;
pos1.w=pos1.h=50;

muro=cargar_texturas("Muro.png",escenario);


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
    cargar_partida(jugador,0,cargar,escenario);//Si cargamos partida carga los valores guardados sobre la estructura jugador
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

   while(ejecutando)//El programa principal es un bucle que se reproduce infinitamente hasta que cambiemos el valor de ejecutando
    {

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

        if(jugador[1].intersecan)//Si la bala 0 interseca con el jugador 1 llama a la funcion vidas restantes
        {
            vidas_restantes(jugador,1);
        }

        if(jugador[0].intersecan)
        {
            vidas_restantes(jugador,0);
        }

        SDL_RenderClear(escenario);//Limpia lo que haya en el escenario
        copiar_atributos(jugador,0,escenario); //Pega en el escenario las caracteristicas de cada jugador tras acabar el bucle
        copiar_atributos(jugador,1,escenario);
        SDL_RenderPresent(escenario);//Presenta el render sobre la venana principal

    }//Fin del bucle principal y por tanto de la partida

    fichero(jugador,0);

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


