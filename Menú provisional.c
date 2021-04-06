#include <stdio.h>
#include <string.h>

int main ()
{

    int elegir[10];
    char usuario[100];
    _Bool bucle[10]={1,1,1,1,1,1,1,1};

    printf ("Juego Laberinto\n\n");

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
                printf("1-<Nombre de usuario>\n");
                printf("2-<Salir>\n");
                scanf("%i",&elegir[1]);
                    if (elegir[1]==1)
                    {
                        printf("Ingresa nombre de usuario: \n");
                        scanf("%[^\n]",usuario);
                    }
                    else
                        bucle[1]=0;
                }
                while(bucle[1]);
                break;

            case 2:
                printf("1-<Nombre de usuario>\n");
                printf("2-<Salir>\n");
                printf("Usa ficheros, por ahora no sabemos\n");
                break;

            case 3:
                printf("Usa ficheros, por ahora no sabemos\n");
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
