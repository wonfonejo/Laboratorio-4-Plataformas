#include <stdio.h>
#include "estructuras.h"

void mostrar_cancha(const Cancha *cancha) {
    printf("    ");
    for (int j = 0; j < COLUMNAS; j++) printf("%3d", j);
    printf("\n");
    for (int i = 0; i < FILAS; i++) {
        printf("%3d|", i);
        for (int j = 0; j < COLUMNAS; j++) {
            if (cancha->Espacio[i][j][0] == '\0')
                printf("%3s", "");
            else
                printf("%3s", cancha->Espacio[i][j]);
        }
        printf("|\n");
    }
}
