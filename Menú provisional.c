#include <stdio.h>
#include <string.h>

#define N 100

void menu ();
void cargar_o_nueva();
void nueva();
void registrar();

typedef struct
{
    char nombre_usuario[N];
    char contrasena[N];
    char confirmar_contrasena[N];
}registro;

int main ()
{
   menu();
   return 0;

}

void menu ()
{
    int constante;
    printf ("Juego Laberinto\n\n");
    cargar_o_nueva();


}
void cargar_o_nueva()
{
    int selecciona;
    printf("1-<Nueva partida>\n");
    printf("2-<Cargar partida>\n\n");
    scanf("%i",&selecciona);
    printf("\n");
    if (selecciona==1)
        nueva();
}

void nueva()
{
    int selecciona;
    printf("1-<Registrarse>\n");
    printf("2-<Iniciar sesion>\n");
    printf("3-<Atras>\n");
    printf("4-<Salir>\n\n");
    scanf("%i",&selecciona);
    printf("\n");
    if(selecciona==1)
        registrar();
    else if (selecciona==3)
        cargar_o_nueva();
    else if (selecciona==4)
        exit(-1);
}
void registrar()
{
    registro usuario;
    int contador=0;
    _Bool exito=0;

    printf("Nombre de usuario: ");
    scanf("%s",usuario.nombre_usuario);
    printf("\nContrasena: ");
    scanf("%s",usuario.contrasena);
    printf("\nConfirmar contrasena: ");

    while(contador<=3 && exito==0)
    {
        scanf("%s",usuario.confirmar_contrasena);
        if(strcmp(usuario.confirmar_contrasena,usuario.contrasena)!=0)
            {
            printf("Contrasena incorrecta\n\n");
            contador++;
            if (contador>3)
               {
                   printf("\n");
                   registrar();
               }
            else
                {
                printf("Confirme contrasena: ");
                }

            }
        else
            {
                printf("\nRegistrando...");
                exito=1;
            }
    }
}
