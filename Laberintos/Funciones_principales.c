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
    hacer_muro(50,50,10,10,110,'h',barrera,0,escenario,jugador,0); //Empleamos la funcion hacer muro para crear los mapas
    hacer_muro(50,670,10,10,110,'h',barrera,0,escenario,jugador,0);
    hacer_muro(50,50,10,10,62,'v',barrera,0,escenario,jugador,0);
    hacer_muro(1150,50,10,10,63,'v',barrera,0,escenario,jugador,0);

    hacer_muro(150,570,10,10,20,'h',barrera,0,escenario,jugador,0);
    hacer_muro(150,500,10,10,7,'v',barrera,0,escenario,jugador,0);
    hacer_muro(350,390,10,10,19,'v',barrera,0,escenario,jugador,0);
    hacer_muro(50,370,10,10,10,'h',barrera,0,escenario,jugador,0);
    hacer_muro(150,150,10,10,27,'v',barrera,0,escenario,jugador,0);
    hacer_muro(250,410,10,10,10,'v',barrera,0,escenario,jugador,0);
    hacer_muro(150,410,10,10,20,'h',barrera,0,escenario,jugador,0);

    hacer_muro(150,150,10,10,10,'h',barrera,0,escenario,jugador,0);
    hacer_muro(240,150,10,10,7,'v',barrera,0,escenario,jugador,0);
    hacer_muro(240,220,10,10,60,'h',barrera,0,escenario,jugador,0);
    hacer_muro(320,50,10,10,7,'v',barrera,0,escenario,jugador,0);
    hacer_muro(320,120,10,10,20,'h',barrera,0,escenario,jugador,0);
    hacer_muro(700,50,10,10,10,'v',barrera,0,escenario,jugador,0);
    hacer_muro(630,50,10,10,10,'v',barrera,0,escenario,jugador,0);
    hacer_muro(830,150,10,10,15,'v',barrera,0,escenario,jugador,0);
    hacer_muro(830,150,10,10,12,'h',barrera,0,escenario,jugador,0);
    hacer_muro(950,150,10,10,10,'v',barrera,0,escenario,jugador,0);
    hacer_muro(950,250,10,10,9,'h',barrera,0,escenario,jugador,0);

    hacer_muro(950,350,10,10,20,'h',barrera,0,escenario,jugador,0);
    hacer_muro(950,350,10,10,10,'v',barrera,0,escenario,jugador,0);
    hacer_muro(950,530,10,10,14,'v',barrera,0,escenario,jugador,0);
    hacer_muro(1050,480,10,10,10,'h',barrera,0,escenario,jugador,0);
    hacer_muro(1050,430,10,10,17,'v',barrera,0,escenario,jugador,0);

    hacer_muro(470,570,10,10,22,'h',barrera,0,escenario,jugador,0);
    hacer_muro(470,300,10,10,28,'v',barrera,0,escenario,jugador,0);
    hacer_muro(250,300,10,10,40,'h',barrera,0,escenario,jugador,0);
    hacer_muro(250,300,10,10,5,'v',barrera,0,escenario,jugador,0);
    hacer_muro(800,600,10,10,7,'v',barrera,0,escenario,jugador,0);
    hacer_muro(800,600,10,10,5,'h',barrera,0,escenario,jugador,0);
    hacer_muro(850,480,10,10,13,'v',barrera,0,escenario,jugador,0);
    hacer_muro(570,480,10,10,28,'h',barrera,0,escenario,jugador,0);
    hacer_muro(650,430,10,10,5,'v',barrera,0,escenario,jugador,0);
    hacer_muro(650,300,10,10,3,'v',barrera,0,escenario,jugador,0);
    hacer_muro(650,330,10,10,9,'h',barrera,0,escenario,jugador,0);
    hacer_muro(740,330,10,10,8,'v',barrera,0,escenario,jugador,0);
    hacer_muro(480,380,10,10,7,'h',barrera,0,escenario,jugador,0);
    hacer_muro(750,400,10,10,20,'h',barrera,0,escenario,jugador,0);

    hacer_muro(1050,170,10,10,10,'h',barrera,0,escenario,jugador,0);
}
void mapa_multijugador_teletransporte(variables_barrera barrera[], int numero_barrera, SDL_Renderer *escenario, variables_jugador jugador[], int numero_jugador)
{
    hacer_muro(500,250,10,10,15,'h',barrera,0,escenario,jugador,0);//M??s mapas con la funcion hacer muro
    hacer_muro(500,500,10,10,15,'h',barrera,0,escenario,jugador,0);
    hacer_muro(500,250,10,10,7,'v',barrera,0,escenario,jugador,0);
    hacer_muro(650,250,10,10,7,'v',barrera,0,escenario,jugador,0);
    hacer_muro(500,450,10,10,6,'v',barrera,0,escenario,jugador,0);
    hacer_muro(650,450,10,10,6,'v',barrera,0,escenario,jugador,0);

    hacer_muro(496,330,20,10,11,'v',barrera,1,escenario,jugador,0);
    hacer_muro(646,330,20,10,11,'v',barrera,1,escenario,jugador,0);

    hacer_muro(50,600,10,10,20,'h',barrera,0,escenario,jugador,0);
    hacer_muro(50,700,10,10,20,'h',barrera,0,escenario,jugador,0);
    hacer_muro(50,600,10,10,10,'v',barrera,0,escenario,jugador,0);
    hacer_muro(250,600,10,10,11,'v',barrera,0,escenario,jugador,0);

    hacer_muro(900,100,10,10,20,'h',barrera,0,escenario,jugador,0);
    hacer_muro(900,400,10,10,20,'h',barrera,0,escenario,jugador,0);
    hacer_muro(900,100,10,10,30,'v',barrera,0,escenario,jugador,0);
    hacer_muro(1100,100,10,10,31,'v',barrera,0,escenario,jugador,0);

}

void mapa_1(variables_barrera barrera[], int numero_barrera, SDL_Renderer *escenario, variables_jugador jugador[], int numero_jugador)
{
    hacer_muro(0,300,10,10,10,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);//Mapa 1 modo individual
    hacer_muro(0,415,33,10,10,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(100,50,10,26,10,'v',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(100,50,12,10,10,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(215,50,10,22,10,'v',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(220,150,26,10,10,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(325,265,10,16,10,'v',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(325,265,10,10,10,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(475,50,10,48,10,'v',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(215,530,27,10,10,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(100,415,10,24,10,'v',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(100,650,88,10,10,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(595,150,10,51,10,'v',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(475,50,24,10,10,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(715,50,10,48,10,'v',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(720,520,13,10,10,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(825,415,38,10,10,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(975,425,10,23,10,'v',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(825,200,10,22,10,'v',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(725,100,21,10,10,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(935,100,10,19,10,'v',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(935,290,30,10,10,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);

}

    void mapa_2(variables_barrera barrera[], int numero_barrera, SDL_Renderer *escenario, variables_jugador jugador[], int numero_jugador)
{
    hacer_muro(0,295,10,10,10,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);//Mapa 2 modo individual
    hacer_muro(0,415,10,10,10,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(100,50,10,28,10,'v',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(100,50,33,10,10,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(425,50,10,25,10,'v',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(215,150,10,10,10,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(215,150,10,35,10,'v',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(330,265,10,10,10,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(100,415,10,19,10,'v',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(100,600,22,10,10,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(215,490,10,10,10,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(330,265,10,10,10,'v',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(315,600,10,10,10,'v',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(315,700,48,10,10,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(675,280,10,31,10,'v',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(685,413,10,10,10,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(445,380,10,20,10,'v',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(445,580,23,10,10,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(560,160,10,31,10,'v',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(425,150,36,10,10,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(785,150,10,15,10,'v',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(785,295,42,10,10,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(785,412,10,30,10,'v',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(905,300,10,24,10,'v',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(785,650,25,10,10,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(1035,430,10,23,10,'v',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(1035,430,20,10,10,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);
 }

    void mapa_3(variables_barrera barrera[], int numero_barrera, SDL_Renderer *escenario, variables_jugador jugador[], int numero_jugador)
{
    hacer_muro(0,50,40,25,10,'v',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(0,400,40,35,10,'v',barrera,numero_barrera,escenario,jugador,numero_jugador);//Mapa 3 modo individual
    hacer_muro(39,50,90,35,10,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(39,710,90,40,10,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(920,430,40,35,10,'v',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(920,50,40,25,10,'v',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(145,160,45,35,10,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(695,160,12,35,10,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(145,565,22,35,10,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(475,565,34,35,10,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(145,195,35,37,10,'v',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(780,195,35,13,10,'v',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(780,437,35,13,10,'v',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(725,80,40,8,10,'v',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(815,495,11,35,10,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(290,298,30,17,10,'v',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(320,298,10,30,10,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(475,298,34,30,10,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(320,437,37,30,10,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(580,464,40,11,10,'v',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(180,370,11,40,10,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(920,295,50,40,10,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(920,430,50,40,10,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);

}
void mapa_4(variables_barrera barrera[], int numero_barrera, SDL_Renderer *escenario, variables_jugador jugador[], int numero_jugador)
{
    hacer_muro(0,50,20,10,25,'v',barrera,numero_barrera,escenario,jugador,numero_jugador);//Mapa 4 modo individual
    hacer_muro(0,405,20,33,10,'v',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(0,50,96,20,10,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(0,730,96,20,10,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(950,415,20,33,10,'v',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(950,50,20,25,10,'v',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(20,280,11,20,10,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(110,145,20,15,10,'v',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(100,405,14,20,10,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(225,250,20,36,10,'v',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(110,135,25,20,10,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(115,595,13,20,10,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(115,520,20,8,10,'v',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(450,50,20,31,10,'v',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(345,360,12,20,10,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(345,370,20,23,10,'v',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(345,595,13,20,10,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(460,475,20,14,10,'v',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(470,520,22,20,10,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(575,635,20,10,10,'v',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(685,520,20,9,10,'v',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(690,590,15,20,10,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(600,405,60,20,10,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(460,285,15,20,10,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(575,170,26,20,10,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(725,130,20,29,10,'v',barrera,numero_barrera,escenario,jugador,numero_jugador);
    hacer_muro(845,285,50,20,10,'h',barrera,numero_barrera,escenario,jugador,numero_jugador);
}

void cargar_muro (variables_barrera barrera[], int numero_barrera, SDL_Renderer *escenario, char ruta_muro[50], char ruta_mina[50],_Bool modo_individual)
{//Esta funci??n se encarga de cargar las variables de la estructura variables barrera
  int alto_muro,ancho_muro;
  int alto_mina,ancho_mina;
  int ancho_portal,alto_portal;

  barrera[numero_barrera].muro=cargar_texturas(ruta_muro,escenario);//Cargamos las texturas con la funci??n cargar texturas
  barrera[numero_barrera].mina=cargar_texturas(ruta_mina,escenario);
  barrera[numero_barrera].explosion=cargar_texturas("Explosion.png",escenario);
  barrera[numero_barrera].portal=cargar_texturas("Portal.png",escenario);

  SDL_QueryTexture(barrera[numero_barrera].muro,NULL,NULL,&ancho_muro,&alto_muro);//Buscamos el alto y el ancho de las texturas que hemos inicializado
  SDL_QueryTexture(barrera[numero_barrera].mina,NULL,NULL,&ancho_mina,&alto_mina);
  SDL_QueryTexture(barrera[numero_barrera].portal,NULL,NULL,&ancho_portal,&alto_portal);

  barrera[numero_barrera].recortar_muro.x=barrera[numero_barrera].recortar_muro.y=0;//Indicamos donde queremos que comience a recortarse la textura
  barrera[numero_barrera].recortar_muro.w=ancho_muro;
  barrera[numero_barrera].recortar_muro.h=alto_muro;

  barrera[numero_barrera].recortar_mina.w=ancho_mina;
  barrera[numero_barrera].recortar_mina.h=alto_mina;

  if (modo_individual==0)//Si estamos en modo multijugador le damos un ancho y alto de 20 a la mina
  barrera[numero_barrera].posicion_mina.h=barrera[numero_barrera].posicion_mina.w=20;

  else if (modo_individual==1)//En modo individual no hay minas asi que le damos una dimensiones de 0
  {
      barrera[numero_barrera].posicion_mina.h=barrera[numero_barrera].posicion_mina.w=0;
      barrera[numero_barrera].posicion_mina.x=barrera[numero_barrera].posicion_mina.y=-20;
  }

  barrera[numero_barrera].recortar_portal.x=barrera[numero_barrera].recortar_portal.y=0;//Lo mismo para los transportadores
  barrera[numero_barrera].recortar_portal.w=ancho_portal;
  barrera[numero_barrera].recortar_portal.h=alto_portal;
  barrera[numero_barrera].posicion_portal.h=barrera[numero_barrera].posicion_portal.w=50;
  barrera[numero_barrera].rojo_activo=1;
  barrera[numero_barrera].verde_activo=1;
  barrera[numero_barrera].azul_activo=1;
  barrera[numero_barrera].posicion_aleatoria[0]=0;
  barrera[numero_barrera].posicion_aleatoria[1]=1;
  barrera[numero_barrera].posicion_aleatoria[2]=2;
}
void hacer_muro (int x,int y,int w, int h, int n, char direccion_muro,variables_barrera barrera[],int numero_barrera,
                 SDL_Renderer *escenario,variables_jugador jugador[], int numero_jugador)
{//Esta funci??n busca generar de forma sencilla un numero de muros concreto en pantalla con unas dimensiones determinadas
    int velocidad_movimiento=2;
    int i,j;

    barrera[numero_barrera].posicion_muro.x=x;//Indicamos donde queremos que comience a imprimirse el muro
    barrera[numero_barrera].posicion_muro.y=y;
    barrera[numero_barrera].posicion_muro.w=w;//Indicamos el ancho y el alto que tendr?? el muro
    barrera[numero_barrera].posicion_muro.h=h;

    int bar_x_1=x,bar_y_1=y; //Asignamos los valores x e y a las variables bar_x_1,bar_x_2,... para mejorar la legibilidad
    int bar_x_2=x,bar_y_2=y;

    if (direccion_muro=='v') //Si la direcci??n del muro es vertical
    {                       //La posici??n en x permanecer?? fija mientras que en y ser?? variable
        bar_x_2+=barrera[numero_barrera].posicion_muro.w;
        for(i=0;i<n;i++)
          {
            SDL_RenderCopy(escenario,barrera[numero_barrera].muro,&barrera[numero_barrera].recortar_muro,&barrera[numero_barrera].posicion_muro);
            barrera[numero_barrera].posicion_muro.y+=barrera[numero_barrera].posicion_muro.h;
            bar_y_2+=barrera[numero_barrera].posicion_muro.h;
          }
    }

    if (direccion_muro=='h')//Si es horizontal
    {                       //La posici??n en y ser?? fija mientras que en x ser?? variable
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
    else if (numero_barrera!=1)
    {
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
        posicion_texto->w+=5;//El tama??o del texto aumenta progresivamente
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
        if (captura[teclas[2]])//Se repite lo mismo para ir hacia arriba
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
        if (captura[teclas[3]])//Se repite lo mismo para ir hacia abajo
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

    if(jugador[numero_jugador].posicion_animacion.x>=1200)//Si el jugador llega a la posicion en cuestion avanzara 2 ya que se esta moviendo, pero retrocedera 2 al haber llegado al limite
        jugador[numero_jugador].posicion_animacion.x-=velocidad_movimiento;//En consecuencia el jugador no se mueve

    if (jugador[numero_jugador].posicion_animacion.x<=0)//Repetimos lo mismo en los lugares que nos interesan para definir el mapa
        jugador[numero_jugador].posicion_animacion.x+=velocidad_movimiento;

    if(jugador[numero_jugador].posicion_animacion.y<=0)
        jugador[numero_jugador].posicion_animacion.y+=velocidad_movimiento;

    if(jugador[numero_jugador].posicion_animacion.y>=750)
        jugador[numero_jugador].posicion_animacion.y-=velocidad_movimiento;

}
void disparar (variables_jugador jugador[], int numero_jugador, variables_jugador victima[], int numero_victima, SDL_Renderer *escenario, int *distx, int *disty)//Dispara una bala
{
    float x,y,cos,sin,distancia;

    jugador[numero_jugador].posicion_bala.x=jugador[numero_jugador].posicion_animacion.x+jugador[numero_jugador].posicion_animacion.w;//Establece la bala en una posicion inicial
    jugador[numero_jugador].posicion_bala.y=jugador[numero_jugador].posicion_animacion.y+jugador[numero_jugador].posicion_animacion.h/2;
    jugador[numero_jugador].posicion_bala.w=jugador[numero_jugador].posicion_bala.h=20;
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
    if ((jugador[numero_jugador].posicion_bala.x>1200||jugador[numero_jugador].posicion_bala.x<0
         ||jugador[numero_jugador].posicion_bala.y>750||jugador[numero_jugador].posicion_bala.y<0) && jugador[numero_jugador].bala_existe==1)//Si la bala llega a los limites definidos se destruye
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
    }                                                  //Parecer??a que esta intersecando continuamente, asi que asignamos a la bala una posicion fuera de la pantalla

}

void vidas_restantes(variables_jugador victima[], int numero_victima)//Animacion para indicar el numero de vidas restantes
{
    switch(victima[numero_victima].numero_vidas)//En funcion del numero de vidas recortara un trozo de la imagen y le asignara una posicion
    {
    case 3:
        SDL_SetTextureColorMod(victima[numero_victima].animacion,255,255,255);
        break;
    case 2:
        SDL_SetTextureColorMod(victima[numero_victima].animacion,50,255,50);
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

void generar_jugador(variables_jugador jugador[], int numero_jugador, SDL_Renderer *escenario, _Bool cargar,_Bool bindividual)//Establece valores predeterminados al jugador indicado
{
    int posicion_animacion,posicion_vidas,posicion_municion;
    if (numero_jugador==0) //En funcion del jugador aparecera en un lugar u otro de la pantalla
    {
        posicion_animacion=510;
        posicion_vidas=700;
        posicion_municion=600;
    }
    else
    {
        posicion_animacion=310;
        posicion_vidas=200;
        posicion_municion=100;
    }

    jugador[numero_jugador].vidas=cargar_texturas("Vida.png",escenario); //Genera las texturas a traves de la funcion cargar_texturas
    jugador[numero_jugador].municion=cargar_texturas("Zanahoria.png",escenario);
    jugador[numero_jugador].animacion=cargar_texturas("Animation.png",escenario);
    jugador[numero_jugador].bala=cargar_texturas("Estrella.png",escenario);
    jugador[numero_jugador].trampa=cargar_texturas("Trampa.png",escenario);

    SDL_QueryTexture(jugador[numero_jugador].vidas,NULL,NULL,&jugador[numero_jugador].ancho_vida,&jugador[numero_jugador].alto_vida);//Mide el tama??o de una textura y le asigna el ancho y el alto a las variables indicadas
    SDL_QueryTexture(jugador[numero_jugador].municion,NULL,NULL,&jugador[numero_jugador].ancho_municion,&jugador[numero_jugador].alto_municion);
    SDL_QueryTexture(jugador[numero_jugador].animacion,NULL,NULL,&jugador[numero_jugador].ancho_animacion,&jugador[numero_jugador].alto_animacion);

    if (bindividual)
    {
        jugador[numero_jugador].posicion_animacion.x=50;
        jugador[numero_jugador].posicion_animacion.y=350;
    }
    else
        jugador[numero_jugador].posicion_animacion.x=jugador[numero_jugador].posicion_animacion.y=posicion_animacion;//Posicion inicial de la animacion

    jugador[numero_jugador].recortar_animacion.x=jugador[numero_jugador].recortar_animacion.y=0; //Indica donde comenzara a recortarse la animacion
    jugador[numero_jugador].recortar_animacion.w=jugador[numero_jugador].ancho_animacion/5;
    jugador[numero_jugador].recortar_animacion.h=jugador[numero_jugador].alto_animacion/4;

    jugador[numero_jugador].posicion_animacion.w=jugador[numero_jugador].posicion_animacion.h=50;

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
    FILE *datos_partida;//Abre un fichero en el que se guardar??n los datos de la partida
    int i;

    datos_partida=fopen(nombre_partida,"w");

    if (datos_partida==NULL)
    {
        printf("Error al guardar el juego");
    }

    else
    {
        for (i=0; i<=1;i++)//Esta l??nea simplemente sirve para que luego carguemos la partida f??cilmente sin tener que leer el fichero entero
        fprintf(datos_partida,"%i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i ",
                jugador[i].posicion_animacion.x,jugador[i].posicion_animacion.y,jugador[i].posicion_animacion.w,jugador[i].posicion_animacion.h,
                jugador[i].recortar_animacion.x,jugador[i].recortar_animacion.y,jugador[i].recortar_animacion.w,jugador[i].recortar_animacion.h,
                jugador[i].posicion_vidas.x,jugador[i].posicion_vidas.y,jugador[i].posicion_vidas.w,jugador[i].posicion_vidas.h,
                jugador[i].recortar_vidas.x,jugador[i].recortar_vidas.y,jugador[i].recortar_vidas.w,jugador[i].recortar_vidas.h,
                jugador[i].numero_vidas,jugador[i].contador_bala);

        fprintf(datos_partida,"\n\n");

        for (i=0;i<=1;i++)//Escribimos los datos de la partida (variables del jugador) para luego sean utilizadas
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
    FILE *puntero_datos;//Est?? funci??n se encargar?? de cargar la partida
    int i=0;            //Leer?? los datos almacenados anteriormente en el fichero y se los asignar?? a los jugadores en el caso de cargar la partida

    if (cargar)
    {
    puntero_datos=fopen(nombre_partida,"r");
    for (i=0;i<2;i++)//La primera linea es la unica que nos interesa ya que contiene los datos imprescindibles
    fscanf(puntero_datos,"%i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i ",
            &jugador[i].posicion_animacion.x,&jugador[i].posicion_animacion.y,&jugador[i].posicion_animacion.w,&jugador[i].posicion_animacion.h,
            &jugador[i].recortar_animacion.x,&jugador[i].recortar_animacion.y,&jugador[i].recortar_animacion.w,&jugador[i].recortar_animacion.h,
            &jugador[i].posicion_vidas.x,&jugador[i].posicion_vidas.y,&jugador[i].posicion_vidas.w,&jugador[i].posicion_vidas.h,
            &jugador[i].recortar_vidas.x,&jugador[i].recortar_vidas.y,&jugador[i].recortar_vidas.w,&jugador[i].recortar_vidas.h,
            &jugador[i].numero_vidas,&jugador[i].contador_bala);

    fclose(puntero_datos);
    }
}

void datos_partida(char nombre_partida[50])//Se encargar?? de imprimir los resultados de la partida en el caso de que se lo indiquemos
{
    FILE *puntero_datos;

    char aux;
    char funciona=1;

    puntero_datos=fopen(nombre_partida,"r");//Simplemente realiza una operaci??n de leer fichero

    fseek(puntero_datos,0,SEEK_SET);
    while(fscanf(puntero_datos,"%c",&aux)!=EOF && funciona)
        if (aux=='\n')
        funciona=0;

    while(fscanf(puntero_datos,"%c",&aux)!=EOF)
        printf("%c",aux);


    fclose(puntero_datos);
}

void mina (variables_barrera barrera[],int numero_barrera,SDL_Renderer *escenario,variables_jugador jugador[], int numero_jugador, int numero_mapa)
{

    int aleatorio;
    _Bool intersecan=1;
    float dist;

    do
    {
    aleatorio=rand()%10;
    aleatorio++;

    if (numero_mapa==0)
    {
    switch(aleatorio)
        {
            case 1:
            barrera[numero_barrera].posicion_mina.x=200;
            barrera[numero_barrera].posicion_mina.y=100;
            break;
            case 2:
            barrera[numero_barrera].posicion_mina.x=800;
            barrera[numero_barrera].posicion_mina.y=100;
            break;
            case 3:
            barrera[numero_barrera].posicion_mina.x=800;
            barrera[numero_barrera].posicion_mina.y=100;
            break;
            case 4:
            barrera[numero_barrera].posicion_mina.x=850;
            barrera[numero_barrera].posicion_mina.y=350;
            break;
            case 5:
            barrera[numero_barrera].posicion_mina.x=870;
            barrera[numero_barrera].posicion_mina.y=450;
            break;
            case 6:
            barrera[numero_barrera].posicion_mina.x=380;
            barrera[numero_barrera].posicion_mina.y=450;
            break;
            case 7:
            barrera[numero_barrera].posicion_mina.x=170;
            barrera[numero_barrera].posicion_mina.y=500;
            break;
            case 8:
            barrera[numero_barrera].posicion_mina.x=750;
            barrera[numero_barrera].posicion_mina.y=600;
            break;
            case 9:
            barrera[numero_barrera].posicion_mina.x=450;
            barrera[numero_barrera].posicion_mina.y=270;
            break;
            case 10:
            barrera[numero_barrera].posicion_mina.x=200;
            barrera[numero_barrera].posicion_mina.y=270;
            break;

        }
    }
        else if (numero_mapa==1)
        {
            switch(aleatorio)
            {
            case 1:
            barrera[numero_barrera].posicion_mina.x=200;
            barrera[numero_barrera].posicion_mina.y=100;
            break;
            case 2:
            barrera[numero_barrera].posicion_mina.x=100;
            barrera[numero_barrera].posicion_mina.y=250;
            break;
            case 3:
            barrera[numero_barrera].posicion_mina.x=150;
            barrera[numero_barrera].posicion_mina.y=350;
            break;
            case 4:
            barrera[numero_barrera].posicion_mina.x=300;
            barrera[numero_barrera].posicion_mina.y=400;
            break;
            case 5:
            barrera[numero_barrera].posicion_mina.x=350;
            barrera[numero_barrera].posicion_mina.y=550;
            break;
            case 6:
            barrera[numero_barrera].posicion_mina.x=450;
            barrera[numero_barrera].posicion_mina.y=550;
            break;
            case 7:
            barrera[numero_barrera].posicion_mina.x=950;
            barrera[numero_barrera].posicion_mina.y=250;
            break;
            case 8:
            barrera[numero_barrera].posicion_mina.x=800;
            barrera[numero_barrera].posicion_mina.y=600;
            break;
            case 9:
            barrera[numero_barrera].posicion_mina.x=800;
            barrera[numero_barrera].posicion_mina.y=280;
            break;
            case 10:
            barrera[numero_barrera].posicion_mina.x=650;
            barrera[numero_barrera].posicion_mina.y=150;
            break;
        }
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

void posicion_portal(variables_barrera barrera[],int numero_barrera)
{
int i;

for(i=0;i<3;i++)
{
    if(i==0)
    barrera[numero_barrera].posicion_aleatoria[i]=rand()%3;

    if(i==1)
    {
    barrera[numero_barrera].posicion_aleatoria[i]=rand()%3;
    if(barrera[numero_barrera].posicion_aleatoria[i]==barrera[numero_barrera].posicion_aleatoria[i-1])
        i=0;
    }

    if(i==2)
    {
    barrera[numero_barrera].posicion_aleatoria[i]=rand()%3;

    if(barrera[numero_barrera].posicion_aleatoria[i]==barrera[numero_barrera].posicion_aleatoria[i-2]
       ||barrera[numero_barrera].posicion_aleatoria[i]==barrera[numero_barrera].posicion_aleatoria[i-1])
        i=1;

    }
}
barrera[numero_barrera].rojo_activo=1;
barrera[numero_barrera].verde_activo=1;
barrera[numero_barrera].azul_activo=1;
}

void portal(variables_barrera barrera[],int numero_barrera,variables_jugador jugador[],SDL_Renderer *escenario, int numero_mapa)
{
    int i,j=1;
    int portal_x[6];
    int portal_y[6];
    int portal_w[6];
    int portal_h[6];
    int jug_x[2];
    int jug_y[2];
    int jug_w[2];
    int jug_h[2];
    int bal_x[2];
    int bal_y[2];
    int bal_w[2];
    int bal_h[2];

        for(i=0;i<2;i++)
        {
            jug_x[i]=jugador[i].posicion_animacion.x;
            jug_w[i]=jugador[i].posicion_animacion.x+jugador[i].posicion_animacion.w;
            jug_y[i]=jugador[i].posicion_animacion.y;
            jug_h[i]=jugador[i].posicion_animacion.y+jugador[i].posicion_animacion.h;
            bal_x[i]=jugador[i].posicion_bala.x;
            bal_w[i]=jugador[i].posicion_bala.x+jugador[i].posicion_bala.w;
            bal_y[i]=jugador[i].posicion_bala.y;
            bal_h[i]=jugador[i].posicion_bala.y+jugador[i].posicion_bala.h;
        }

        for(i=0;i<3;i++)
        {
            if (i==0)
            {
            if(barrera[numero_barrera].rojo_activo)
            SDL_SetTextureColorMod(barrera[numero_barrera].portal,255,50,50);
            else
            SDL_SetTextureColorMod(barrera[numero_barrera].portal,50,5,5);

            if (numero_mapa==0)
            {
            barrera[numero_barrera].posicion_portal.x=portal_x[0]=100;
            barrera[numero_barrera].posicion_portal.y=portal_y[0]=70;
            }
            else if (numero_mapa==1)
            {
            barrera[numero_barrera].posicion_portal.x=portal_x[0]=555;
            barrera[numero_barrera].posicion_portal.y=portal_y[0]=270;
            }
            portal_w[0]=portal_x[0]+barrera[numero_barrera].posicion_portal.w;
            portal_h[0]=portal_y[0]+barrera[numero_barrera].posicion_portal.h;
            SDL_RenderCopy(escenario,barrera[numero_barrera].portal,&barrera[numero_barrera].recortar_portal,&barrera[numero_barrera].posicion_portal);
            }
            else if (i==1)
            {
            if(barrera[numero_barrera].verde_activo)
            SDL_SetTextureColorMod(barrera[numero_barrera].portal,50,255,50);
            else
            SDL_SetTextureColorMod(barrera[numero_barrera].portal,5,50,5);

            if (numero_mapa==0)
            {
            barrera[numero_barrera].posicion_portal.x=portal_x[2]=1000;
            barrera[numero_barrera].posicion_portal.y=portal_y[2]=600;
            }
            else if (numero_mapa==1)
            {
            barrera[numero_barrera].posicion_portal.x=portal_x[2]=1000;
            barrera[numero_barrera].posicion_portal.y=portal_y[2]=600;
            }

            portal_w[2]=portal_x[2]+barrera[numero_barrera].posicion_portal.w;
            portal_h[2]=portal_y[2]+barrera[numero_barrera].posicion_portal.h;
            SDL_RenderCopy(escenario,barrera[numero_barrera].portal,&barrera[numero_barrera].recortar_portal,&barrera[numero_barrera].posicion_portal);
            }
            else if (i==2)
            {
            if(barrera[numero_barrera].azul_activo)
            SDL_SetTextureColorMod(barrera[numero_barrera].portal,50,50,255);
            else
            SDL_SetTextureColorMod(barrera[numero_barrera].portal,5,5,50);

            if (numero_mapa==0)
            {
                barrera[numero_barrera].posicion_portal.x=portal_x[4]=490;
                barrera[numero_barrera].posicion_portal.y=portal_y[4]=320;
            }
            else if (numero_mapa==1)
            {
                barrera[numero_barrera].posicion_portal.x=portal_x[4]=70;
                barrera[numero_barrera].posicion_portal.y=portal_y[4]=630;
            }

            portal_w[4]=portal_x[4]+barrera[numero_barrera].posicion_portal.w;
            portal_h[4]=portal_y[4]+barrera[numero_barrera].posicion_portal.h;
            SDL_RenderCopy(escenario,barrera[numero_barrera].portal,&barrera[numero_barrera].recortar_portal,&barrera[numero_barrera].posicion_portal);
            }
            switch(barrera[numero_barrera].posicion_aleatoria[i])
            {
            case 0:
            if (numero_mapa==0)
            {
                barrera[numero_barrera].posicion_portal.x=portal_x[i+j]=875;
                barrera[numero_barrera].posicion_portal.y=portal_y[i+j]=180;
            }
            else if (numero_mapa==1)
            {
                barrera[numero_barrera].posicion_portal.x=portal_x[i+j]=980;
                barrera[numero_barrera].posicion_portal.y=portal_y[i+j]=120;
            }
            portal_w[i+j]=portal_x[i+j]+barrera[numero_barrera].posicion_portal.w;
            portal_h[i+j]=portal_y[i+j]+barrera[numero_barrera].posicion_portal.h;
            SDL_RenderCopy(escenario,barrera[numero_barrera].portal,&barrera[numero_barrera].recortar_portal,&barrera[numero_barrera].posicion_portal);
            break;
            case 1:
            if (numero_mapa==0)
            {
                barrera[numero_barrera].posicion_portal.x=portal_x[i+j]=280;
                barrera[numero_barrera].posicion_portal.y=portal_y[i+j]=430;
            }
            else if (numero_mapa==1)
            {
                barrera[numero_barrera].posicion_portal.x=portal_x[i+j]=70;
                barrera[numero_barrera].posicion_portal.y=portal_y[i+j]=70;
            }

            portal_w[i+j]=portal_x[i+j]+barrera[numero_barrera].posicion_portal.w;
            portal_h[i+j]=portal_y[i+j]+barrera[numero_barrera].posicion_portal.h;
            SDL_RenderCopy(escenario,barrera[numero_barrera].portal,&barrera[numero_barrera].recortar_portal,&barrera[numero_barrera].posicion_portal);
            break;
            case 2:
            if (numero_mapa==0)
            {
                barrera[numero_barrera].posicion_portal.x=portal_x[i+j]=1070;
                barrera[numero_barrera].posicion_portal.y=portal_y[i+j]=70;
            }
            else if (numero_mapa==1)
            {
                barrera[numero_barrera].posicion_portal.x=portal_x[i+j]=980;
                barrera[numero_barrera].posicion_portal.y=portal_y[i+j]=330;
            }

            portal_w[i+j]=portal_x[i+j]+barrera[numero_barrera].posicion_portal.w;
            portal_h[i+j]=portal_y[i+j]+barrera[numero_barrera].posicion_portal.h;
            SDL_RenderCopy(escenario,barrera[numero_barrera].portal,&barrera[numero_barrera].recortar_portal,&barrera[numero_barrera].posicion_portal);
            break;
            }
        ++j;
        }
    j=1;
    for(i=0;i<6;i++)
    {
     for(j=0;j<2;j++)
     {
         if(jug_w[j]<portal_x[i]||portal_w[i]<jug_x[j]||jug_h[j]<portal_y[i]||portal_h[i]<jug_y[j]);
         else
         {
            if (i==0&&barrera[numero_barrera].rojo_activo)
            {
            jugador[j].posicion_animacion.x=portal_x[1];
            jugador[j].posicion_animacion.y=portal_y[1];
            barrera[numero_barrera].rojo_activo=0;
            }
            if(i==1&&barrera[numero_barrera].rojo_activo)
            {
            jugador[j].posicion_animacion.x=portal_x[0];
            jugador[j].posicion_animacion.y=portal_y[0];
            barrera[numero_barrera].rojo_activo=0;
            }
            if(i==2&&barrera[numero_barrera].verde_activo)
            {
            jugador[j].posicion_animacion.x=portal_x[3];
            jugador[j].posicion_animacion.y=portal_y[3];
            barrera[numero_barrera].verde_activo=0;
            }
            if(i==3&&barrera[numero_barrera].verde_activo)
            {
            jugador[j].posicion_animacion.x=portal_x[2];
            jugador[j].posicion_animacion.y=portal_y[2];
            barrera[numero_barrera].verde_activo=0;
            }
            if(i==4&&barrera[numero_barrera].azul_activo)
            {
            jugador[j].posicion_animacion.x=portal_x[5];
            jugador[j].posicion_animacion.y=portal_y[5];
            barrera[numero_barrera].azul_activo=0;
            }
            if(i==5&&barrera[numero_barrera].azul_activo)
            {
            jugador[j].posicion_animacion.x=portal_x[4];
            jugador[j].posicion_animacion.y=portal_y[4];
            barrera[numero_barrera].azul_activo=0;
            }
         }
        }
    }
}

void multijugador(_Bool cargar, char nombre_partida[], int victorias[],int numero_victoria, _Bool revancha, int numero_mapa)
{
    int control=0;
    long int segundos;
    long int microsegundos;
    struct timeval begin,end;
    int tiempo_explosion=0;
    double tiempo_mina=0;
    double tiempo_portal=0;
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

    ventanaprincipal=SDL_CreateWindow("Juego laberinto",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1200,750,NULL);//Crea una ventana, centrada, de dimensiones 960x720
    superficieprincipal=SDL_GetWindowSurface(ventanaprincipal);//Aporta una superficie a la ventana
    escenario=SDL_CreateRenderer(ventanaprincipal,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);//Crea un render (necesario definirlo de esta forma para que funcione bien)

SDL_Texture *texto_ganador=NULL;
SDL_Texture *fondo=NULL;
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
    generar_jugador(jugador,0,escenario,cargar,0);
    generar_jugador(jugador,1,escenario,cargar,0);
    cargar_partida(jugador,0,cargar,escenario,nombre_partida);//Si cargamos partida carga los valores guardados sobre la estructura jugador
}

variables_barrera *barrera;

barrera=malloc(sizeof(variables_barrera)*2);

if (barrera==NULL)
{
    SDL_Log("ERROR");
    exit(-1);
}

else
{
    cargar_muro(barrera,0,escenario,"Hierba.jpg","Texto.png",0);
    cargar_muro(barrera,1,escenario,"Rayo.png","Texto.png",0);
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
fondo=cargar_texturas("Fondo_multi.jpg",escenario);
SDL_SetTextureColorMod(fondo,50,50,50);

   while(ejecutando)//El programa principal es un bucle que se reproduce infinitamente hasta que cambiemos el valor de ejecutando
    {
        gettimeofday(&begin, 0);

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

        if (tiempo_mina>=5.0)
        {
            mina(barrera,0,escenario,jugador,0,numero_mapa);
            mina(barrera,0,escenario,jugador,1,numero_mapa);
            tiempo_mina=0;
            posicion_portal(barrera,0);
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
        SDL_RenderCopy(escenario,fondo,NULL,NULL);

        if (numero_mapa==0)
            mapa_multijugador(barrera,0,escenario,jugador,0);

        else if (numero_mapa==1)
            mapa_multijugador_teletransporte(barrera,0,escenario,jugador,0);

        copiar_atributos(jugador,0,escenario); //Pega en el escenario las caracteristicas de cada jugador tras acabar el bucle
        copiar_atributos(jugador,1,escenario);
        portal(barrera,0,jugador,escenario,numero_mapa);
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
        segundos = end.tv_sec - begin.tv_sec;
        microsegundos = end.tv_usec - begin.tv_usec;
        tiempo_mina+= segundos + microsegundos*1e-6;

        if (jugador[0].numero_vidas==0 || jugador[1].numero_vidas==0)
        {
            if (jugador[0].numero_vidas==0)
            {
                texto_ganador=cargar_texturas("Player2 wins.png", escenario);
                victorias[1]++;
            }

            if (jugador[1].numero_vidas==0)
            {
               texto_ganador=cargar_texturas("Player1 wins.png",escenario);
               victorias[0]++;
            }

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

    if (revancha==0)
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

void datos_fantasma(variables_jugador jugador[], int numero_jugador, SDL_Renderer *escenario)
{
 int ancho_fantasma;
 int alto_fantasma;
 jugador[numero_jugador].fantasma=cargar_texturas("Fantasma.png",escenario);
 SDL_QueryTexture(jugador[numero_jugador].fantasma,NULL,NULL,&ancho_fantasma,&alto_fantasma);
 jugador[numero_jugador].recortar_fantasma.x=jugador[numero_jugador].recortar_fantasma.y=0;
 jugador[numero_jugador].recortar_fantasma.w=ancho_fantasma;
 jugador[numero_jugador].recortar_fantasma.h=alto_fantasma;
 jugador[numero_jugador].posicion_fantasma.w=jugador[numero_jugador].posicion_fantasma.h=30;
jugador[numero_jugador].muerto[0]=jugador[numero_jugador].muerto[1]=jugador[numero_jugador].muerto[2]=0;
jugador[numero_jugador].existe[0]=jugador[numero_jugador].existe[1]=jugador[numero_jugador].existe[2]=0;
jugador[numero_jugador].tiempo_muerto[0]=jugador[numero_jugador].tiempo_muerto[1]=jugador[numero_jugador].tiempo_muerto[2]=0;
}

void hacer_fantasma(variables_jugador jugador[],int numero_jugador,variables_jugador fantasma[],int numero_fantasma,SDL_Renderer *escenario,double tiempo)
{
    int i;
    int jug_x=jugador[numero_jugador].posicion_animacion.x;
    int jug_w=jugador[numero_jugador].posicion_animacion.x+jugador[numero_jugador].posicion_animacion.w;
    int jug_y=jugador[numero_jugador].posicion_animacion.y;
    int jug_h=jugador[numero_jugador].posicion_animacion.y+jugador[numero_jugador].posicion_animacion.h;
    int bal_x=jugador[numero_jugador].posicion_bala.x;
    int bal_w=jugador[numero_jugador].posicion_bala.x+jugador[numero_jugador].posicion_bala.w;
    int bal_y=jugador[numero_jugador].posicion_bala.y;
    int bal_h=jugador[numero_jugador].posicion_bala.y+jugador[numero_jugador].posicion_bala.h;
    float x,y,cos,sin,distancia;
    double desarrollo;
    int dis_x, dis_y;
    for(i=0;i<3;i++)
    {
        if (fantasma[numero_fantasma].existe[i]==0&&fantasma[numero_fantasma].muerto[i]==0)
        {
           if(i==0)
            fantasma[numero_fantasma].aleatorio_fantasma[i]=rand()%10;
            if(i==1)
            {
            fantasma[numero_fantasma].aleatorio_fantasma[i]=rand()%10;
            if(fantasma[numero_fantasma].aleatorio_fantasma[i]==fantasma[numero_fantasma].aleatorio_fantasma[i-1])
            i=0;
            }
            if(i==2)
            {
            fantasma[numero_fantasma].aleatorio_fantasma[i]=rand()%10;
            if(fantasma[numero_fantasma].aleatorio_fantasma[i]==fantasma[numero_fantasma].aleatorio_fantasma[i-2]
            ||fantasma[numero_fantasma].aleatorio_fantasma[i]==fantasma[numero_fantasma].aleatorio_fantasma[i-1])
            i=1;
            }
            fantasma[numero_fantasma].existe[i]=1;
            switch(fantasma[numero_fantasma].aleatorio_fantasma[i])
        {
            case 0:
            fantasma[numero_fantasma].fas_x[i]=300;
            fantasma[numero_fantasma].fas_y[i]=127;
            break;
            case 1:
            fantasma[numero_fantasma].fas_x[i]=400;
            fantasma[numero_fantasma].fas_y[i]=128;
            break;
            case 2:
            fantasma[numero_fantasma].fas_x[i]=500;
            fantasma[numero_fantasma].fas_y[i]=129;
            break;
            case 3:
            fantasma[numero_fantasma].fas_x[i]=600;
            fantasma[numero_fantasma].fas_y[i]=130;
            break;
            case 4:
            fantasma[numero_fantasma].fas_x[i]=700;
            fantasma[numero_fantasma].fas_y[i]=131;
            break;
            case 5:
            fantasma[numero_fantasma].fas_x[i]=800;
            fantasma[numero_fantasma].fas_y[i]=132;
            break;
            case 6:
            fantasma[numero_fantasma].fas_x[i]=900;
            fantasma[numero_fantasma].fas_y[i]=133;
            break;
            case 7:
            fantasma[numero_fantasma].fas_x[i]=350;
            fantasma[numero_fantasma].fas_y[i]=134;
            break;
            case 8:
            fantasma[numero_fantasma].fas_x[i]=450;
            fantasma[numero_fantasma].fas_y[i]=135;
            break;
            case 9:
            fantasma[numero_fantasma].fas_x[i]=550;
            fantasma[numero_fantasma].fas_y[i]=136;
            break;
        }
    }

     fantasma[numero_fantasma].fas_w[i]=fantasma[numero_fantasma].fas_x[i]+fantasma[numero_fantasma].posicion_fantasma.w;
     fantasma[numero_fantasma].fas_h[i]=fantasma[numero_fantasma].fas_y[i]+fantasma[numero_fantasma].posicion_fantasma.h;
distancia=sqrt(pow(jugador[numero_jugador].posicion_animacion.x-fantasma[numero_fantasma].fas_x[i],2)
                         +pow(jugador[numero_jugador].posicion_animacion.y-fantasma[numero_fantasma].fas_y[i],2));

    x=jugador[numero_jugador].posicion_animacion.x-fantasma[numero_fantasma].fas_x[i];
    y=jugador[numero_jugador].posicion_animacion.y-fantasma[numero_fantasma].fas_y[i];

    cos=x/distancia;
    sin=y/distancia;

    dis_x=2*cos;
    dis_y=2*sin;

    if((jug_w<fantasma[numero_fantasma].fas_x[i])||(fantasma[numero_fantasma].fas_w[i]<jug_x)
       ||(jug_h<fantasma[numero_fantasma].fas_y[i])||(fantasma[numero_fantasma].fas_h[i]<jug_y));
    else
    {
    jugador[numero_jugador].numero_vidas--;
    vidas_restantes(jugador,0);
    fantasma[numero_fantasma].posicion_fantasma.x=-300;
    fantasma[numero_fantasma].fas_x[i]=-300;
    fantasma[numero_fantasma].muerto[i]=1;
    fantasma[numero_fantasma].existe[i]=0;
    fantasma[numero_fantasma].tiempo_muerto[i]=tiempo;
    }
    if(bal_w<fantasma[numero_fantasma].fas_x[i]||fantasma[numero_fantasma].fas_w[i]<bal_x
       ||bal_h<fantasma[numero_fantasma].fas_y[i]||fantasma[numero_fantasma].fas_h[i]<bal_y);
    else
    {
    fantasma[numero_fantasma].posicion_fantasma.x=-300;
    fantasma[numero_fantasma].fas_x[i]=-300;
    jugador[numero_jugador].posicion_bala.x=-500;
    fantasma[numero_fantasma].muerto[i]=1;
    fantasma[numero_fantasma].existe[i]=0;
    fantasma[numero_fantasma].tiempo_muerto[i]=tiempo;

    }
    if (fantasma[numero_fantasma].muerto[i]==1)
    {
        if (tiempo-fantasma[numero_fantasma].tiempo_muerto[i]>5.0)
        {
        fantasma[numero_fantasma].tiempo_muerto[i]=0;
        fantasma[numero_fantasma].muerto[i]=0;
        }
        else;
    }
    else
    {
    fantasma[numero_fantasma].fas_x[i]+=dis_x;
    fantasma[numero_fantasma].fas_y[i]+=dis_y;
    }
    fantasma[numero_fantasma].posicion_fantasma.x=fantasma[numero_fantasma].fas_x[i];
    fantasma[numero_fantasma].posicion_fantasma.y=fantasma[numero_fantasma].fas_y[i];
    SDL_RenderCopy(escenario,fantasma[numero_fantasma].fantasma,&fantasma[numero_fantasma].recortar_fantasma,&fantasma[numero_fantasma].posicion_fantasma);
}
}
void disparar_individual (variables_jugador jugador[], int numero_jugador, variables_jugador victima[], int numero_victima, SDL_Renderer *escenario, int *distx, int *disty)//Dispara una bala
{

    float x,y,cos,sin,distancia,menor;
    int i,imenor;

    jugador[numero_jugador].posicion_bala.x=jugador[numero_jugador].posicion_animacion.x+jugador[numero_jugador].posicion_animacion.w;//Establece la bala en una posicion inicial
    jugador[numero_jugador].posicion_bala.y=jugador[numero_jugador].posicion_animacion.y+jugador[numero_jugador].posicion_animacion.h/2;
    jugador[numero_jugador].posicion_bala.w=jugador[numero_jugador].posicion_bala.h=20;
    jugador[numero_jugador].recargando=1;//La bala existe y el jugador empieza a recargar la siguiente
    jugador[numero_jugador].bala_existe=1;
    jugador[numero_jugador].contador_bala++;//Lleva registro de cuantas balas se han disparado

    for(i=0;i<3;i++)
    {
    distancia=sqrt(pow(victima[numero_victima].fas_x[i]-jugador[numero_jugador].posicion_animacion.x,2)
                   +pow(victima[numero_victima].fas_y[i]-jugador[numero_jugador].posicion_animacion.y,2));
        if(i==0)
        {
        imenor=i;
        menor=distancia;
        }
        if (distancia<menor)
        {
        imenor=i;
        menor=distancia;
        }

    }

    x=victima[numero_victima].fas_x[imenor]-jugador[numero_jugador].posicion_animacion.x;
    y=victima[numero_victima].fas_y[imenor]-jugador[numero_jugador].posicion_animacion.y;

    cos=x/menor;
    sin=y/menor;

    *distx=6*cos;
    *disty=6*sin;

}

void individual(char nombre_partida[], int numero_mapa, double *tiempo)
{
    int control=0;
    long int segundos;
    long int microsegundos;
    struct timeval begin,end;
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

    ventanaprincipal=SDL_CreateWindow("Juego laberinto",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1200,750,NULL);//Crea una ventana, centrada, de dimensiones 960x720
    superficieprincipal=SDL_GetWindowSurface(ventanaprincipal);//Aporta una superficie a la ventana
    escenario=SDL_CreateRenderer(ventanaprincipal,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);//Crea un render (necesario definirlo de esta forma para que funcione bien)

SDL_Texture *texto_ganador=NULL;
SDL_Texture *fondo=NULL;
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
    generar_jugador(jugador,0,escenario,0,1);
    datos_fantasma(jugador,1,escenario);
    cargar_partida(jugador,0,0,escenario,nombre_partida);//Si cargamos partida carga los valores guardados sobre la estructura jugador

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
    cargar_muro(barrera,0,escenario,"Muro.png","Texto.png",1);
}

fondo=cargar_texturas("Fondo.jpg",escenario);
SDL_SetTextureColorMod(fondo,100,100,100);
   while(ejecutando)//El programa principal es un bucle que se reproduce infinitamente hasta que cambiemos el valor de ejecutando
    {
        gettimeofday(&begin, 0);

        while(SDL_PollEvent(&evento)!=0)//Procesa los eventos que se producen cada vez que se produce el bucle
        {                               //Finaliza el bucle cuando no queden eventos por procesar
            if(evento.type==SDL_QUIT)//Si el evento es quit (darle a la cruz roja) se sale del bucle y termina el juego
            {
                ejecutando=0;
            }
             if (evento.type==SDL_KEYDOWN)
             {
                 if (evento.key.keysym.sym==SDLK_SPACE)
                    disparar_individual(jugador,0,jugador,1,escenario,&distx1,&disty1);
             }

        }

        recargar_y_movimiento(jugador,0,&tiempo_estructura,distx1,disty1);//Mueve la bala y recarga la municion


        movimiento_jugador(jugador,0,&tiempo_jugador);//Para mover los jugadores


        limites_mapa(jugador,0);//Donde se pueden mover


        if(jugador[0].intersecan || jugador[0].interseca_trampa)
        {
            vidas_restantes(jugador,0);
        }

        SDL_RenderClear(escenario);//Limpia lo que haya en el escenario

        SDL_RenderCopy(escenario,fondo,NULL,NULL);
        switch(numero_mapa)
        {
        case 1:
            mapa_1(barrera,0,escenario,jugador,0);
            break;
        case 2:
            mapa_2(barrera,0,escenario,jugador,0);
            break;
        case 3:
            mapa_3(barrera,0,escenario,jugador,0);
            break;
        case 4:
            mapa_4(barrera,0,escenario,jugador,0);
            break;
        }

        hacer_fantasma(jugador,0,jugador,1,escenario,*tiempo);
        copiar_atributos(jugador,0,escenario); //Pega en el escenario las caracteristicas de cada jugador tras acabar el bucle
        SDL_RenderCopy(escenario,barrera[0].mina,&barrera[0].recortar_mina,&barrera[0].posicion_mina);

        SDL_RenderPresent(escenario);//Presenta el render sobre la ventana principal

        gettimeofday(&end, 0);
        segundos = end.tv_sec - begin.tv_sec;
        microsegundos = end.tv_usec - begin.tv_usec;
        *tiempo+=segundos+microsegundos*pow(10,-6);

        if (jugador[0].numero_vidas==0 || *tiempo>=40.0)
        {
            if (jugador[0].numero_vidas==0)
            texto_ganador=cargar_texturas("Game over.png",escenario);

            if (*tiempo>=40.0)
            texto_ganador=cargar_texturas("Texto.png",escenario);


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
