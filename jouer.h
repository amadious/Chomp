/************************************************
 * BINOME 1: OUKSILI SMAIL                      *
 * BINOME 2: SAKHO MAMADOU                      *
 * Dernière modification : 19/02/2019 (OUKSILI )*
*************************************************/
#include "tablette.h"

typedef enum {
    J1,
    J2
}Joueur;

typedef struct pos {
    Tablette tab;
    Joueur j;
}Position;

typedef struct coup {
    int x;
    int y;
}Coup;

int est_legal(Position *p, Coup *coup);
void manger(Tablette *t, int x, int y);
int est_jeu_termine(Position *pos, Joueur *joueur_gagnant);
void jouer_coup(Position *pos, Coup *coup);