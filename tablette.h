/************************************************
 * BINOME 1: OUKSILI SMAIL                      *
 * BINOME 2: SAKHO MAMADOU                      *
 * Dernière modification : 19/02/2019 (OUKSILI )*
*************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define N 8
#define M 16

typedef struct tab {
    int tab[N][M];
}Tablette;


Tablette creer_tablette(void);