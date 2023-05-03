#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


int main(void) {
  srand(time(NULL));
  int num_columnas_filas;
  int Game_tries = 0;
  printf("INGRESE EL NUMERO DE FILAS Y COLUMNAS QUE TENDRA EL TABLERO DEL JUEGO PIRATA: ");
  scanf("%d", &num_columnas_filas);
  printf("\n");
  int isla[num_columnas_filas][num_columnas_filas];
  int i, j, q, opcion_menu, pirateX, pirateY, treasureX, treasureY;
  printf("LOS PASOS A SEGUIR PARA JUGAR EL JUEGO DE FORMA CORRECTA.\nPRIMERO INICIALIZAR EL TABLERO CON EL NUMERO 1.\n2.LUEGO DIBUJAR EL TABLERO INGRESANDO EL NUMERO 2\n3.INGRESAR A LA BUSQUEDA DEL TESORO CON EL 3.\nSI SE DESEA SALIR DEL JUEGO, SE PRESIONA 4 CUANDO EL MENU ESTE PRESENTE.");
  printf("\n");
  while(opcion_menu != 4) {
    printf("MENU JUEGO PIRATA\n 1.INICIALIZAR EL TABLERO\n 2.DIBUJAR TABLERO\n 3.BUSCAR TESORO\n 4.SALIR\n");
    scanf("%d", &opcion_menu);
    switch (opcion_menu) {
      case 1: pirateX = rand () % (num_columnas_filas - 2) + 1;
        pirateY = rand () % (num_columnas_filas - 2) + 1;
        treasureX = rand () % (num_columnas_filas - 2) + 1;
        treasureY = rand () % (num_columnas_filas - 2) + 1;
        while (treasureX == pirateX && treasureY == pirateY) {
          srand(time(NULL));
          treasureX = rand () % (num_columnas_filas - 2) + 1;
          treasureY = rand () % (num_columnas_filas - 2) + 1;
        }
        break;
      case 2: printf("\n");
        for ( i = 0; i < num_columnas_filas; i++) {
          for ( j = 0; j < num_columnas_filas; j++) {
            if (i == pirateY && j == pirateX) printf("01 ");
            else if (i == 0 && j == num_columnas_filas - 1 || i == num_columnas_filas - 1 && j == 0) printf("PU ");
            else if (i == 0 || i == num_columnas_filas -1 || j == num_columnas_filas -1 || j == 0) {
              printf("AG ");
            } else {
              printf("00 ");
            }
          }
          printf("\n");
        }
        printf("\n");
        break;
      case 3:
        printf("EL JUEGO TERMINA CUANDO EL PIRATA ENCUENTRA EL TESORO, SE VA AL AGUA O AL PUENTE O CUANDO EL NUMERO DE INTENTOS SUPERA 25.\nMUEVA EL PIRATA SENALADO CON EL NUMERO 01 MEDIANTE LAS SIGUIENTES LETRAS\n's': sur, mueve 1 hacia abajo\n'n': norte, mueve 1 hacia arriba\n'e': este, mueve 1 hacia la derecha\n'o': oeste, mueve 1 hacia la izquierda.");
        printf("\n");
         for (q = 0; Game_tries < 50; q++) {
           for ( i = 0; i < num_columnas_filas; i++) {
             for ( j = 0; j < num_columnas_filas; j++) {
               if (i == pirateY && j == pirateX) printf("01 ");
               else if (i == 0 && j == num_columnas_filas - 1 || i == num_columnas_filas - 1 && j == 0) printf("PU ");
               else if (i == 0 || i == num_columnas_filas -1 || j == num_columnas_filas -1 || j == 0) {
                 printf("AG ");
               } else {
                 printf("00 ");
               }
             }
             printf("\n");
           }
           printf("\n");
          if (pirateX == 0 || pirateY == 0 ||  pirateY == num_columnas_filas -1 || pirateX == num_columnas_filas -1 || Game_tries == 50) {
            printf("You went off the borders, you lost.\n");
            return 1;
          }
          if (pirateX == treasureX && pirateY == pirateY) {
            printf("YOU FOUND THE TREASURE, YOU WON.\n");
            return 2;
          }
          char Actual_position = 'w';
          scanf("%c", &Actual_position);
          switch(Actual_position) {
            case 'o': pirateX -= 1;
              break;
            case 'O': pirateX -= 1;
              break;
            case 'e': pirateX += 1;
              break;
            case 'E': pirateX += 1;
              break;
            case 'n': pirateY -= 1;
              break;
            case 'N': pirateY -= 1;
              break;
            case 's': pirateY += 1;
              break;
            case 'S': pirateY += 1;
              break;
          }
          Game_tries += 1;
      	}
      	break;
      case 4:
        return 1;
        break;
      default:
        printf("Elija una opcion dentro del menu\n");
        break;
    }
  }
  return 0;
}
