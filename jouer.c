/************************************************
 * BINOME 1: OUKSILI SMAIL                      *
 * BINOME 2: SAKHO MAMADOU                      *
 * Dernière modification : 19/02/2019 (OUKSILI )*
*************************************************/
#include"jouer.h"


void manger(Tablette *t, int x, int y){
    int i , j ;

    assert(t != NULL);
    assert ((y >= 0) && (y < N));
    assert ((x >= 0) && (x < M));

    for(i = y ; i < N ; ++i){
        j = x ;
        for(;j < M ; ++j){
            if ((i >= y) && (j >= x))
                t->tab[i][j] = 0 ;
        }

    }
}


int est_legal(Position *p, Coup *coup){
    assert(p != NULL);
    assert(coup != NULL);

    if ((p->tab.tab[coup->y][coup->x] == 1 ) && (coup->y < N ) && (coup->y >= 0) && (coup->x < M) && (coup->x >= 0)){
        return 1 ;
    }

    return 0 ;
}


int est_jeu_termine(Position *pos, Joueur *joueur_gagnant){
    assert (pos != NULL);
    assert(joueur_gagnant != NULL);
 
    if (pos->tab.tab[0][0] == 0){
        if (pos->j == J1 )
            *joueur_gagnant = J1 ;
        else 
            *joueur_gagnant = J2 ;
        return 1 ;
    }
    return 0 ;
}


void jouer_coup(Position *pos, Coup *coup){
    assert(pos != NULL);
    assert(coup != NULL);
 
    manger(&(pos->tab),coup->x,coup->y); 
    if (pos->j == J1 )
        pos->j = J2 ;
    else 
        pos->j = J1 ;
}



