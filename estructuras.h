#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

#define FILAS 38
#define COLUMNAS 42

typedef struct {
    char name[25];
    char surname[25];
    char number[3];
   
} PLAYER;

typedef struct {
    char nameofteam[25];
    int numberofplayers;
    PLAYER *players;

} TEAM;

typedef struct {
    int x;
    int y;
} COORDENADA;

typedef struct {
    COORDENADA posicion;
}Balon;

typedef struct {
    TEAM equipos[2];
    Balon balon;
    char Espacio[38][42][3];
} Cancha;

#endif
