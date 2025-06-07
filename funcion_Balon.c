#include "estructuras.h"

void InicializarBalon(Cancha *cancha) {
   
    cancha->balon.posicion.x = 18; 
    cancha->balon.posicion.y = 21; 
    strcpy(cancha->Espacio[cancha->balon.posicion.x][cancha->balon.posicion.y], "O");
}

void MoverBalon(Cancha *cancha, int nuevaX, int nuevaY) {
    
    if (nuevaX < 0 || nuevaX >= FILAS || nuevaY < 0 || nuevaY >= COLUMNAS) {
        printf("Valor incorrecto porfavor elija otra posicion\n");
        return;
    }

    if ((strcmp(cancha->Espacio[cancha->balon.posicion.x-1][cancha->balon.posicion.y-1], "") == 0) && (strcmp(cancha->Espacio[cancha->balon.posicion.x-1][cancha->balon.posicion.y], "") == 0) && (strcmp(cancha->Espacio[cancha->balon.posicion.x-1][cancha->balon.posicion.y+1], "") == 0) && (strcmp(cancha->Espacio[cancha->balon.posicion.x][cancha->balon.posicion.y-1], "") == 0) && (strcmp(cancha->Espacio[cancha->balon.posicion.x][cancha->balon.posicion.y+1], "") == 0) && (strcmp(cancha->Espacio[cancha->balon.posicion.x+1][cancha->balon.posicion.y-1], "") == 0) && (strcmp(cancha->Espacio[cancha->balon.posicion.x+1][cancha->balon.posicion.y], "") == 0) && (strcmp(cancha->Espacio[cancha->balon.posicion.x+1][cancha->balon.posicion.y+1], "") == 0) ) 
    {
        printf("No hay ningun jugador para poder patear el balon\n");
        return;
    }

    
    if (strcmp(cancha->Espacio[nuevaX][nuevaY], "") != 0) {
        printf("Movimiento incorrecto hay un jugador en la posicion (%d, %d).\n", nuevaX, nuevaY);
        return;
    }


    strcpy(cancha->Espacio[cancha->balon.posicion.x][cancha->balon.posicion.y], "");
    cancha->balon.posicion.x = nuevaX;
    cancha->balon.posicion.y = nuevaY;
    strcpy(cancha->Espacio[cancha->balon.posicion.x][cancha->balon.posicion.y], "O");
}