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
    \tJugador 1: usara las flechas de control para moverse y la barra espaciadora para disparar.\nUsar 'm' para desplegar trampa.\n\
    \tJugador 2: usara las teclas 'a', 'w', 's', 'd' para moverse y la letra 'f' para disparar.\nUsar 'e' para desplegar trampa.\n\n\
    La partida se guardara con el nombre que se introduzca durante la configuracion.\n\
    Una vez finalizada la partida selecciona <<Salir>> en caso de haber terminado el juego\n\
    o <<Continuar partida>> si desea seguir jugando.\n\n\
    Si selecciona <<Salir>> se le preguntara si quiere ver las estadisticas de la partida\n\
    Introduce '1' para verlos o '0' para finalizar el juego definitivamente.\n\n";

    _Bool atras=0;
    _Bool revancha=1;
    _Bool partida_on=0;
    char elegir[20][10];
    char usuario[100];
    char usuario1[100];
    char usuario2[100];
    char nombre_partida[100];
    char comprobacion_nombre[100];
    char aux;
    int numero_mapa;
    double tiempo=0;
    _Bool bucle[10]={1,1,1,1,1,1,1,1};
    FILE *registro_partidas;
    FILE *partida;
    int victorias[2]={0};
    _Bool fichero_revancha=0;

    registro_partidas=fopen("Registro de las partidas.txt","a");
    fclose(registro_partidas);
    partida=fopen("Puntuaciones.txt","a");
    fclose(partida);
    partida=fopen("Puntuaciones individuales.txt","a");
    fclose(partida);

    printf("Juego del laberinto\n\n");

    do
    {
        atras=0;
        printf("1-<Nueva partida>\n");
        printf("2-<Cargar partida>\n");
        printf("3-<Puntuaciones>\n");
        printf("4-<Puntuaciones individuales>\n");
        printf("5-<Instrucciones>\n");
        printf("6-<Salir>\n");

        scanf(" %s",&elegir[20][0]);
        printf("\n");

        switch(elegir[20][0])
        {
            case '1':
                while(atras==0)
                {
                printf("1-<Configuracion de la partida>\n");
                printf("2-<Salir>\n");
                scanf(" %s",&elegir[20][1]);
                    if (elegir[20][1]=='1')
                    {
                        printf("1-<Individual>\n");
                        printf("2-<Multijugador (2 jugadores)>\n");
                        printf("En el modo multijugador se guardan los datos de la partida, en el individual el tiempo\n");
                        scanf(" %s",&elegir[20][2]);
                        if (elegir[20][2]=='1')
                        {
                            printf("Nombre de la partida:\n");
                            scanf(" %[^\n]",nombre_partida);
                            strcat(nombre_partida,".txt");
                            printf("Nombre de usuario: \n");
                            scanf(" %[^\n]",usuario);
                            printf("Modo de juego\n");
                            printf("1-<Mapa 1>\n2-<Modo 2>\n3-<Modo 3>\n4-<Modo 4>\n");
                            scanf(" %i",&numero_mapa);
                            printf("Iniciando...");
                            switch(numero_mapa)
                            {
                            case 1:
                                individual(nombre_partida,1,&tiempo);
                                break;
                            case 2:
                                individual(nombre_partida,2,&tiempo);
                                break;
                            case 3:
                                individual(nombre_partida,3,&tiempo);
                                break;
                            case 4:
                                individual(nombre_partida,4,&tiempo);
                                break;
                            default:
                                printf("Error");
                                break;
                            }
                            partida=fopen("Puntuaciones individuales.txt","a");
                            fprintf(partida,"%s: %lf s\n",nombre_partida,tiempo);
                            fclose(partida);
                            atras=1;
                            bucle[0]=0;
                        }
                        else if (elegir[20][2]=='2')
                        {
                            printf("1-<Con revancha>\n2-<Sin revancha>\nEl modo con revancha solamente guardara las victorias y derrotas\n");
                            scanf(" %s",&elegir[20][5]);
                            if (elegir[20][5]=='2')
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
                                        scanf(" %c",&elegir[20][3]);

                                        if (elegir[20][3]=='1')
                                        {
                                            printf("Nombre de la partida: ");
                                            scanf(" %[^\n]",nombre_partida);
                                            strcat(nombre_partida,".txt");
                                            fseek(registro_partidas,0,SEEK_SET);
                                        }
                                }
                            }
                            if (elegir[20][3]=='2')
                                multijugador(1,nombre_partida,victorias,0,0,0);


                            else
                            {
                            fclose(registro_partidas);
                            registro_partidas = fopen("Registro de las partidas.txt","a");
                            fprintf(registro_partidas,"%s\n",nombre_partida);
                            fclose(registro_partidas);

                            printf("Iniciando partida...\n");
                            multijugador(0,nombre_partida,victorias,0,0,0);
                            }
                            bucle[0]=0;
                            partida_on=1;
                            atras=1;
                            }
                            else if (elegir[20][5]=='1')
                            {
                                printf("Nombre de la partida:\n");
                                scanf(" %[^\n]",nombre_partida);
                                printf("Nombre usuario 1: ");
                                scanf(" %[^\n]",usuario1);
                                printf("\nNmbre usuario 2: ");
                                scanf(" %[^\n]",usuario2);
                                printf("Modo de juego:\n0-<Modo 1>\n1-<Modo 2>\n");
                                scanf(" %i",&numero_mapa);


                                while(revancha==1)
                                {
                                    fichero_revancha=1;
                                    multijugador(0,nombre_partida,victorias,0,1,numero_mapa);
                                    printf("Revancha?\n");
                                    scanf(" %i",&revancha);
                                    if (revancha==0)
                                    {
                                        atras=1;
                                        bucle[0]=0;
                                    }
                                }


                            }
                            else
                                printf("Error!");
                        }
                        else
                            printf("Error!\n");
                    }
                    else if (elegir[20][1]=='2')
                        {
                            bucle[0]=0;
                            exit(-1);
                        }
                    else
                        printf("Error!\n");
                }
                break;

            case '2':
                printf("Se cargan partidas multijugador inciadas anteriormente.\nSi la partida estaba finalizada saltara el mesaje de salida.\n");
                while(atras==0)
                {
                printf("1-<Nombre de la partida>\n");
                printf("2-<Salir>\n");
                scanf(" %s",&elegir[20][1]);

                if (elegir[20][1]=='1')
                {
                    printf("Nombre de la partida: \n");
                    scanf(" %[^\n]",nombre_partida);
                    strcat(nombre_partida,".txt");
                    registro_partidas=fopen("Registro de las partidas.txt","r");
                    while(partida_on==0)
                    {
                    while (feof(registro_partidas)==0)
                    {
                        fscanf(registro_partidas,"%[^\n]\n",comprobacion_nombre);

                        if (strcmp(nombre_partida,comprobacion_nombre)==0)
                        {
                             multijugador(1,nombre_partida,victorias,0,0,0);
                             atras=1;
                             bucle[0]=0;
                             partida_on=1;
                        }

                    }
                    if (partida_on==0)
                    {
                        printf("No existe el nombre de la partida\n");
                        printf("1-<Usar otro nombre>\n2-<Menu principal>\n");
                        scanf(" %[^\n]",&elegir[20][3]);
                        if (elegir[20][3]=='1')
                        {
                            printf("Nombre de la partida:\n");
                            scanf(" %[^\n]",nombre_partida);
                            fseek(registro_partidas,0,SEEK_SET);
                        }

                        if (elegir[20][3]=='2')
                        {
                            atras=1;
                            partida_on=1;
                        }
                    }
                    }
                    fclose(registro_partidas);
                }
                else if (elegir[20][1]=='2')
                    {
                        bucle[0]=0;
                        exit(-1);
                    }
                else
                    printf("Error!\n");
                }
                break;

            case '3':
                partida=fopen("Puntuaciones.txt","r");
                while(fscanf(partida,"%c",&aux)!=EOF)
                    printf("%c",aux);
                fclose(partida);
                printf("\n");
                break;

            case '4':

                partida=fopen("Puntuaciones individuales.txt","r");

                while(fscanf(partida,"%c",&aux)!=EOF)
                    printf("%c",aux);

                fclose(partida);
                break;

            case '5':
                printf("%s",instrucciones);
                break;

            case '6':
                printf("Saliendo...");
                exit(-1);
                break;

            default:
                printf("Error!\n");
                printf("Introduce un valor comprendido entre 1 y 5\n");
                break;
        }

    }
    while(bucle[0]);

    printf("%f",tiempo);

    if (fichero_revancha==1)
    {
        partida=fopen("Puntuaciones.txt","a");
        fprintf(partida,"%s: %i victorias de %s, %i victorias de %s",nombre_partida,victorias[0],usuario1,victorias[1],usuario2);
        fclose(partida);
    }

    if (partida_on)
    {
        printf("\nTeclea <1> para ver los datos de la partida\n");
        scanf("%s",&elegir[20][4]);
        if (elegir[20][4]=='1')
            datos_partida(nombre_partida);
    }
    return 0;
}


