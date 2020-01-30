/************************************************
 * BINOME 1: OUKSILI SMAIL                      *
 * BINOME 2: SAKHO MAMADOU                      *
 * Dernière modification : 19/02/2019 (OUKSILI )*
*************************************************/
#include "jouer.h"
#include <MLV/MLV_all.h>

#define WIDTH 700 
#define HEIGHT 600


Coup lire_coup(Position *pos);
void afficher_position(Position *pos);

int verifier_nb_valide(char  * text);
int puissance (int a);
int demander_nb_parties(char *Joueur);