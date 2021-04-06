#include <stdio.h>
#include <string.h>

int main ()
{

    int elegir[10];
    char usuario[100]; //Si se puede almacenar en un vector de vectores o en una estructura mejor
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
                do
                {
                printf("1-<Configuracion de la partida>\n");
                printf("2-<Salir>\n");
                scanf("%i",&elegir[1]);
                    if (elegir[1]==1)
                    {
                        printf("1-<Individual>\n");
                        printf("2-<Multijugador>\n");
                        scanf("%i",&elegir[2]);
                        if (elegir[2]==1)
                        {
                            printf("Nombre de usuario (la partida se guardara con el mismo nombre): \n"); //Crear función que realice esto
                            scanf(" %[^\n]",usuario);
                            strcpy(nombre_partida,usuario);
                            printf("Modo de juego:\n");
                            printf("1-<Modo 1>\n");
                            printf("2-<Modo 2>\n");
                            printf("3-<Modo 3>\n");
                            scanf("%i",&elegir[3]);
                            printf("Iniciando partida...\n");
                            bucle[1]=0;
                        }
                        else if (elegir[2]==2)
                        {
                            printf("Nombre de la partdia: ");
                            scanf(" %[^\n]",nombre_partida);
                            printf("Numero de jugadores (2 o 3): \n");
                            scanf("%i",&elegir[3]);
                            switch (elegir[3])
                            {
                                case 2:
                                    printf("Nombre usuario 1: ");
                                    scanf(" %[^\n]",usuario1);
                                    printf("\n Nmbre usuario 2: ");
                                    scanf(" %[^\n]",usuario2);
                                    printf("Modo de juego:\n");
                                    printf("1-<Modo 1>\n");
                                    printf("2-<Modo 2>\n");
                                    printf("3-<Modo 3>\n");
                                    scanf("%i",&elegir[3]);
                                    printf("Iniciando partida...\n");
                                    break;

                                case 3:
                                    printf("Nombre usuario 1: ");
                                    scanf(" %[^\n]",usuario1);
                                    printf("\nNmbre usuario 2: ");
                                    scanf(" %[^\n]",usuario2);
                                    printf("\nNombre usuario 3: ");
                                    scanf(" %[^\n]",usuario3);
                                    printf("Modo de juego:\n");
                                    printf("1-<Modo 1>\n");
                                    printf("2-<Modo 2>\n");
                                    printf("3-<Modo 3>\n");
                                    scanf("%i",&elegir[3]);
                                    printf("Iniciando partida...\n");
                                    break;

                                default:
                                    printf("Error!\n");
                                    break;

                            }
                        }
                        else
                            printf("Error!\n");
                    }
                    else if (elegir[1]=2)
                        bucle[1]=bucle[0]=0;
                    else
                        printf("Error!\n");
                }
                while(bucle[1]);
                break;

            case 2:
                printf("1-<Nombre de la partida>\n");
                printf("2-<Salir>\n");
                scanf("%i",&elegir[1]);
                if (elegir[1]==1)
                    printf("Cargando partida...");
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
                printf("Una vez tengamos en programa listo rellenaremos este campo\n");
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

    return 0;
}
