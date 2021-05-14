#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Funciones_principales.h"

int main (int argc, char *argv[])
{
    char instrucciones[]="Bienvenido a las instrucciones del juego!!\n\n\
    Selecciona la opcion <<Nueva partida>> para iniciar el juego, <<Cargar partida>> para continuar una partida anterior\
    o <<Salir>> para salir del programa\n\n\
    Si has seleccionado  <<Nueva partida>> dirigete a <<Configurar partida>> para determinar las caracteristicas de la partida\
    En <<Configuracion partida>> el siguiente paso es escoger el modo de juego:\n\
    <<Individual>> o \n\
    <<Multijugador>>\n\n\
    Modo individual: <<Meter descripcion>>\n\
    \tEl movimiento sera mediante las flechas de control:\n\n\
    Modo multijugador: se enfrentaran 2 jugadores. Cada jugador tiene 3 vidas. Pierde el jugador al que se le acaben las vidas\n\
    \tEl movimiento se realizara mediante:\n\n\
    \tJugador 1: usara las flechas de control para moverse y la barra espaciadora para disparar\n\
    \tJugador 2: usara las teclas 'a', 'w', 's', 'd' para moverse y la letra 'f' para disparar\n\n\
    La partida se guardara con el nombre que se introduzca durante la configuracion.\n\
    Una vez finalizada la partida selecciona <<Salir>> en caso de haber terminado el juego o <<Continuar partida>> si desea seguir jugando\n\
    Si selecciona <<Salir>> se le preguntara si quiere ver las estadisticas de la partida\
    Introduce '1' para verlos o '0' para finalizar el juego definitivamente.\n\n\
        ";

    int elegir[10];
    char usuario[100];
    char usuario1[100];
    char usuario2[100];
    char usuario3[100];
    char nombre_partida[100];
    _Bool bucle[10]={1,1,1,1,1,1,1,1};

    printf("Juego del laberinto\n\n");

    do
    {
        printf("1-<Nueva partida>\n");
        printf("2-<Cargar partida>\n");
        printf("3-<Puntuaciones>\n");
        printf("4-<Instrucciones>\n");
        printf("5-<Salir>\n");

        scanf("%i",&elegir[0]);
        printf("\n");

        switch(elegir[0])
        {
            case 1:
                printf("1-<Configuracion de la partida>\n");
                printf("2-<Salir>\n");
                scanf("%i",&elegir[1]);
                    if (elegir[1]==1)
                    {
                        printf("1-<Individual>\n");
                        printf("2-<Multijugador (2 jugadores)>\n");
                        scanf("%i",&elegir[2]);
                        if (elegir[2]==1)
                        {
                            printf("Nombre de usuario (la partida se guardara con el mismo nombre): \n");
                            scanf(" %[^\n]",usuario);
                            strcpy(nombre_partida,usuario);
                            printf("Modo de juego:\n");
                            printf("1-<Modo 1>\n");
                            printf("2-<Modo 2>\n");
                            printf("3-<Modo 3>\n");
                            scanf("%i",&elegir[3]);
                            printf("Iniciando partida...\n");

                        }
                        else if (elegir[2]==2)
                        {
                            printf("Nombre de la partida: ");
                            scanf(" %[^\n]",nombre_partida);
                            printf("Nombre usuario 1: ");
                            scanf(" %[^\n]",usuario1);
                            printf("\nNmbre usuario 2: ");
                            scanf(" %[^\n]",usuario2);
                            printf("Modo de juego:\n");
                            printf("1-<Modo 1>\n");
                            printf("2-<Modo 2>\n");
                            printf("3-<Modo 3>\n");
                            scanf("%i",&elegir[3]);
                            printf("Iniciando partida...\n");
                            if (elegir[3]==1)
                                multijugador(0);

                        }
                        else
                            printf("Error!\n");
                    }
                    else if (elegir[1]=2)
                        bucle[0]=0;
                    else
                        printf("Error!\n");
                break;

            case 2:
                printf("1-<Nombre de la partida>\n");
                printf("2-<Salir>\n");
                scanf("%i",&elegir[1]);
                if (elegir[1]==1)
                {
                    printf("Cargando partida...");
                    multijugador(1);
                }
                else if (elegir[1]==2)
                    bucle[0]=0;
                else
                    printf("Error!\n");
                    printf("Usa ficheros, por ahora no sabemos\n");
                break;

            case 3:
                printf("No hay puntuaciones!\n");
                break;

            case 4:
                printf("%s",instrucciones);
                break;

            case 5:
                printf("Saliendo...");
                bucle[0]=0;
                break;

            default:
                printf("Error!\n");
                printf("Introduce un valor comprendido entre 1 y 5");
                break;
        }

    }
    while(bucle[0]);

    printf("\nMostrar datos de la partida?\n");
    scanf("%i",&elegir[4]);
    datos_partida(elegir[4]);

    return 0;
}


