#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"
#include "mostrar_cancha.c"
#include "funciones_equipo.c"
#include "funciones_cancha.c"
#include "funcion_Balon.c"

void inicializar_cancha(Cancha *cancha);
void asignar_equipo(TEAM *equipo, const char *nombre, PLAYER Equipo[], int cantidad);
void posicionar_equipo(Cancha *cancha, int equipoIndex);
void mostrar_cancha(const Cancha *cancha);
void InicializarBalon(Cancha *cancha);
void MoverBalon(Cancha *cancha, int nuevaX, int nuevaY);
void Mover_Jugadores(Cancha *cancha, int equipoIndex, int jugadorIndex, int nuevaX, int nuevaY);

int main() {
    Cancha cancha;

    PLAYER Equipo1[11] = {
        {"Memo", "Ochoa", "1"}, {"Lucas", "Hernandez", "2"}, {"Dani", "Alves", "3"}, {"Sergio", "Ramos", "4"}, {"Ronald", "Matarrita", "5"},
        {"Xavi", "Hernandez", "6"}, {"Andres", "Iniesta", "7"}, {"Cesc", "Fabregas", "8"},
        {"David", "Villa", "9"}, {"Samuel", "Etoo", "10"}, {"Thierry", "Henry", "11"}
    };

    PLAYER Equipo2[11] = {
        {"Keylor", "Navas", "1"}, {"Kendall", "Waston", "2"}, {"Ronald", "Araujo", "3"}, {"Dani", "Carvajal", "4"}, {"Arda", "Guler", "5"},
        {"Toni", "Kroos", "6"}, {"Luka", "Modric", "7"}, {"Isco", "Alarcon", "8"},
        {"Karim", "Benzema", "9"}, {"Eden", "Hazard", "10"}, {"Vinicius", "Jr", "11"}
    };

    inicializar_cancha(&cancha);
    InicializarBalon(&cancha);
    
    asignar_equipo(&cancha.equipos[0], "America", Equipo1, 11);
    asignar_equipo(&cancha.equipos[1], "Madrid", Equipo2, 11);
    posicionar_equipo(&cancha, 0);  
    posicionar_equipo(&cancha, 1);
    //printf("El 10 del America es  %s\n", cancha.equipos[0].players[9].name);
    //printf("El 10 del Madrid es %s\n", cancha.equipos[1].players[9].name);

    
    

    //mostrar_cancha(&cancha); 
    printf("\n");

    //Mover_Jugadores(&cancha, 0, 9, 5, 5);
    Mover_Jugadores(&cancha, 1, 9, 18, 20);
    MoverBalon(&cancha, 5, 5);
    mostrar_cancha(&cancha);

    free(cancha.equipos[0].players);
    free(cancha.equipos[1].players);

    return 0;
}

// La parte de la cancha se hara en base a el codigo de los laboratorios de ajedrez (coordenas).

// Una persona se encarga de campo de juego,equipos y jugadores; otra de colocar los 11 jugadores en un campo y la ultima de crear el balon y moverlo por el campo

// la cancha debe ser de 38 y 42 metros. Las coordenadas de los jugadores en la cancha funcionan recorriendo un espacio en x,y de 1 m. ]

// 2 idas para mover la bola, ambas con coordenas del campo de juego. La primera es tipo "futbolin", en donde la bola verifica que la en la casilla de la cancha haya un jugador para que el movimiento sea valido; y la otra es tipo "clasico", en donde solo tiene que estar en el la cancha (la matriz de 38x42)

// el main incluye colocar 11 jugadores por equipo en un campo de juego, una funcion que reciba coordenadas para mover los jugadores y una que reciba coordenadas para mover el balon.

//El programa debe tener: formas de crear los 11 jugadores: atributos de equipo y posicion (portero y jugador de campo). Un campo definido como una matriz 38 por 42, formas de asignar jugadores al campo, inicializarlos y moverlos en los terminos de este.

