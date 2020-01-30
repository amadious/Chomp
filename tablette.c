/************************************************
 * BINOME 1: OUKSILI SMAIL                      *
 * BINOME 2: SAKHO MAMADOU                      *
 * Dernière modification : 19/02/2019 (OUKSILI )*
*************************************************/
#include "tablette.h"


Tablette creer_tablette(void){
    Tablette t;
    int i,j;

    for (i = 0; i < N; ++i){
        j = 0 ;
        for(;j < M ; ++j) {
            t.tab[i][j] = 1;
        }
    }
    return t;
}