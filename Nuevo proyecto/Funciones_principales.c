#include <stdio.h>
#include <math.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Funciones_principales.h"


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

    if(jugador[numero_jugador].posicion_animacion.x>=550)//Si el jugador llega a la posicion en cuestion avanzara 2 ya que se esta moviendo, pero retrocedera 2 al haber llegado al limite
        jugador[numero_jugador].posicion_animacion.x-=velocidad_movimiento;//En consecuencia el jugador no se mueve

    if (jugador[numero_jugador].posicion_animacion.x<=0)//Repetimos lo mismo en los lugares que nos interesan para definir el mapa
        jugador[numero_jugador].posicion_animacion.x+=velocidad_movimiento;

    if(jugador[numero_jugador].posicion_animacion.y<=0)
        jugador[numero_jugador].posicion_animacion.y+=velocidad_movimiento;

    if(jugador[numero_jugador].posicion_animacion.y>=400)
        jugador[numero_jugador].posicion_animacion.y-=velocidad_movimiento;
}
void disparar (variables_jugador jugador[], int numero_jugador, SDL_Renderer *escenario)//Dispara una bala
{
    jugador[numero_jugador].bala=cargar_texturas("Bala.png",escenario);//Crea la bala
    jugador[numero_jugador].posicion_bala.x=jugador[numero_jugador].posicion_animacion.x+jugador[numero_jugador].posicion_animacion.w;//Establece la bala en una posicion inicial
    jugador[numero_jugador].posicion_bala.y=jugador[numero_jugador].posicion_animacion.y+jugador[numero_jugador].posicion_animacion.h/2;
    jugador[numero_jugador].posicion_bala.w=jugador[numero_jugador].posicion_bala.h=50;
    jugador[numero_jugador].recargando=1;//La bala existe y el jugador empieza a recargar la siguiente
    jugador[numero_jugador].bala_existe=1;
    jugador[numero_jugador].contador_bala++;//Lleva regustro de cuantas balas se han disparado
}

void recargar_y_movimiento(variables_jugador jugador[], int numero_jugador, int *tiempo_recarga)//Recarga la municion y mueve la bala por el plano
{
    if (jugador[numero_jugador].bala_existe==1)//Si la bala existe se movera por el plano de la pantalla
    {
        jugador[numero_jugador].posicion_bala.x+=6;
    }
    if (jugador[numero_jugador].posicion_bala.x>700 && jugador[numero_jugador].bala_existe==1)//Si la bala llega a los limites definidos se destruye
    {
        SDL_DestroyTexture(jugador[0].bala);
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
            case 2:
                SDL_SetTextureColorMod(victima[numero_victima].animacion,255,0,0);//Asigna un color al jugador
                break;
            case 1:
                SDL_SetTextureColorMod(victima[numero_victima].animacion,0,255,0);
                break;
        }
        victima[numero_victima].intersecan=1;//Como intersecan devuelve 1
        SDL_DestroyTexture(jugador[numero_jugador].bala);//Destruye la bala
        jugador[numero_jugador].bala_existe=0;//La bala no existe
        jugador[numero_jugador].posicion_bala.x=1000;//La funcion calcula la posicion de la bala, pero al destruirla no resetea la posicion
    }                                                  //Parecería que esta intersecando continuamente, asi que asignamos a la bala una posicion fuera de la pantalla

}

int vidas_restantes(variables_jugador victima[], int numero_victima, variables_jugador shooter[], int numero_shooter)//Animacion para indicar el numero de vidas restantes
{
    if (victima[numero_victima].intersecan==1 )//Solo se ejecuta si intersecan
    {                                           //Como antes hemos cambiado la posicion de la bala a 1000, solo intersecaran una vez (la funcion principal es un bucle)

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
    }
    return victima[numero_victima].numero_vidas;//Devuelve el numero de vidas restantes
}

void generar_jugador(variables_jugador jugador[], int numero_jugador, SDL_Renderer *escenario)//Establece valores predeterminados al jugador indicado
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

    datos_partida=fopen("Nombre partida.txt","w");

    if (datos_partida==NULL)
    {
        printf("Error al guardar el juego");
    }

    else
    {
        for (int i=0;i<=1;i++)
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

