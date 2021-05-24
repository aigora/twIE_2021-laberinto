#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Funciones_principales.h"
#include <stdlib.h>


int main (int argc, char *argv[])
{
    char instrucciones[]="Bienvenido a las instrucciones del juego!!\n\n\
    Selecciona la opcion <<Nueva partida>> para iniciar el juego, \n\
    <<Cargar partida>> para continuar una partida anterior\ o <<Salir>> para salir del programa.\n\n\
    Si has seleccionado <<Cargar partida>> se reanudara la partida anterior.\n\n\
    Si has seleccionado  <<Nueva partida>> dirigete a \n\
    <<Configurar partida>> para determinar las caracteristicas de la partida.\n\n\
    En <<Configuracion partida>> el siguiente paso es escoger el modo de juego:\n\n\
    <<Individual>> o \n\
    <<Multijugador>>\n\n\
    Modo individual: <<Meter descripcion>>\n\
    \tEl movimiento sera mediante las flechas de control.\n\n\
    Modo multijugador: se enfrentaran 2 jugadores. Cada jugador tiene 3 vidas.\n\
    \tPierde el jugador al que se le acaben las vidas.\n\
    \tEl movimiento se realizara mediante:\n\n\
    \tJugador 1: usara las flechas de control para moverse y la barra espaciadora para disparar.\n\
    \tJugador 2: usara las teclas 'a', 'w', 's', 'd' para moverse y la letra 'f' para disparar.\n\n\
    La partida se guardara con el nombre que se introduzca durante la configuracion.\n\
    Una vez finalizada la partida selecciona <<Salir>> en caso de haber terminado el juego\n\
    o <<Continuar partida>> si desea seguir jugando.\n\n\
    Si selecciona <<Salir>> se le preguntara si quiere ver las estadisticas de la partida\n\
    Introduce '1' para verlos o '0' para finalizar el juego definitivamente.\n\n";

    _Bool atras=0;
    char elegir[10];
    char usuario[100];
    char usuario1[100];
    char usuario2[100];
    char nombre_partida[100];
    char comprobacion_nombre[100];
    _Bool bucle[10]={1,1,1,1,1,1,1,1};
    FILE *registro_partidas;

    registro_partidas=fopen("Registro de las partidas.txt","a");
    fclose(registro_partidas);

    printf("Juego del laberinto\n\n");

    do
    {
        printf("1-<Nueva partida>\n");
        printf("2-<Cargar partida>\n");
        printf("3-<Puntuaciones>\n");
        printf("4-<Instrucciones>\n");
        printf("5-<Salir>\n");

        scanf(" %c",&elegir[0]);
        printf("\n");

        switch(elegir[0])
        {
            case '1':
                do
                {
                printf("1-<Configuracion de la partida>\n");
                printf("2-<Salir>\n");
                scanf(" %c",&elegir[1]);
                    if (elegir[1]=='1')
                    {
                        printf("1-<Individual>\n");
                        printf("2-<Multijugador (2 jugadores)>\n");
                        scanf(" %c",&elegir[2]);
                        if (elegir[2]=='1')
                        {
                            printf("Nombre de usuario (la partida se guardara con el mismo nombre): \n");
                            scanf(" %[^\n]",usuario);
                            strcpy(nombre_partida,usuario);
                            printf("Iniciando partida...\n");

                        }
                        else if (elegir[2]=='2')
                        {
                            printf("Nombre de la partida: ");
                            scanf(" %[^\n]",nombre_partida);
                            strcat(nombre_partida,".txt");

                            registro_partidas=fopen("Registro de las partidas.txt","r");

                            while (feof(registro_partidas)==0)
                            {
                                fscanf(registro_partidas,"%[^\n]\n",comprobacion_nombre);

                                if(strcmp(nombre_partida,comprobacion_nombre)==0)
                                {
                                        printf("Ya existe una partida con ese nombre\n");
                                        printf("1-<Usar otro nombre>\n2-<Cargar partida>\n");
                                        scanf(" %c",&elegir[3]);

                                        if (elegir[3]=='1')
                                        {
                                            printf("Nombre de la partida: ");
                                            scanf(" %[^\n]",nombre_partida);
                                            strcat(nombre_partida,".txt");
                                            fseek(registro_partidas,0,SEEK_SET);
                                        }
                                }
                            }
                            if (elegir[3]=='2')
                                multijugador(1,nombre_partida);

                            else
                            {
                            fclose(registro_partidas);
                            registro_partidas = fopen("Registro de las partidas.txt","a");
                            fprintf(registro_partidas,"%s\n",nombre_partida);
                            fclose(registro_partidas);

                            printf("Nombre usuario 1: ");
                            scanf(" %[^\n]",usuario1);
                            printf("\nNmbre usuario 2: ");
                            scanf(" %[^\n]",usuario2);

                            printf("Iniciando partida...\n");
                            multijugador(0,nombre_partida);
                            }

                        }
                        else
                            printf("Error!\n");
                    }
                    else if (elegir[1]='2')
                        bucle[0]=0;
                    else
                        printf("Error!\n");
                }while (elegir[1]!='1' || elegir[1]!='2');
                break;

            case '2':
                do
                {
                printf("1-<Nombre de la partida>\n");
                printf("2-<Salir>\n");
                scanf(" %c",&elegir[1]);

                if (elegir[1]=='1')
                {
                    printf("Nombre de la partida: \n");
                    scanf(" %[^\n]",nombre_partida);
                    strcat(nombre_partida,".txt");
                    registro_partidas=fopen("Registro de las partidas.txt","r");
                    while (feof(registro_partidas)==0 && atras==0)
                    {
                        fscanf(registro_partidas,"%[^\n]\n",comprobacion_nombre);

                        if(strcmp(nombre_partida,comprobacion_nombre)==1 || strcmp(nombre_partida,comprobacion_nombre)==-1)
                        {
                            if (feof(registro_partidas)!=0)
                            {
                                printf("No existe una partida con ese nombre\n");
                                printf("1-<Usar otro nombre>\n2-<Menu principal>\n");
                                scanf(" %c",&elegir[3]);

                                if (elegir[3]=='1')
                                {
                                    printf("Nombre de la partida: ");
                                    scanf(" %[^\n]",nombre_partida);
                                    strcat(nombre_partida,".txt");
                                    fseek(registro_partidas,0,SEEK_SET);
                                }
                            }
                        }

                        else if (strcmp(nombre_partida,comprobacion_nombre)==0)
                        {
                             multijugador(1,nombre_partida);
                             atras=1;
                        }

                    }
                    fclose(registro_partidas);
                    atras=0;
                }

                else if (elegir[1]=='2')
                    bucle[0]=0;
                else
                    printf("Error!\n");
                }while(elegir[1]!='1'||elegir[1]!='2');
                break;

            case '3':
                printf("No hay puntuaciones!\n");
                break;

            case '4':
                printf("%s",instrucciones);
                break;

            case '5':
                printf("Saliendo...");
                bucle[0]=0;
                break;

            default:
                printf("Error!\n");
                printf("Introduce un valor comprendido entre 1 y 5\n");
                break;
        }

    }
    while(bucle[0]);

    printf("\nMostrar datos de la partida?\n");
    scanf("%i",&elegir[4]);
    datos_partida(elegir[4]);

    return 0;
}


