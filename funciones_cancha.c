#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"

void inicializar_cancha(Cancha *cancha) {
    
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            strcpy(cancha->Espacio[i][j], "");
        }
    }
}
