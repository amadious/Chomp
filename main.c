/************************************************
 * BINOME 1: OUKSILI SMAIL                      *
 * BINOME 2: SAKHO MAMADOU                      *
 * Dernière modification : 19/02/2019 (OUKSILI )*
*************************************************/
#include "affichage.h"


int main(int argc, char const *argv[]){
    Position Pos ;
    Joueur Joueur_gagnant;
    Coup coup ;
    int nbParties ;
    int nbPartieGagneJ1 = 0;
    int CptParties = 0;
    
    
    
    MLV_create_window("CHOMP","TP2",WIDTH,HEIGHT);
    
    nbParties = demander_nb_parties("Joueur 1");
    nbParties = (nbParties + demander_nb_parties("Joueur 2")) / 2;
    
    do{       
        Pos.tab = creer_tablette();
        do{ 
            afficher_position(&Pos);

            do{
                coup = lire_coup(&Pos);
            }while(!est_legal(&Pos,&coup));
            jouer_coup(&Pos,&coup);
            
        }while(!est_jeu_termine(&Pos,&Joueur_gagnant))    ;

        MLV_clear_window(MLV_COLOR_BLACK);
        if (Joueur_gagnant == J1){
            MLV_draw_text   (WIDTH / 2,HEIGHT / 2 ,"Joueur 1 a gagné la partie",MLV_COLOR_YELLOW );
            nbPartieGagneJ1 ++ ;
        }
        
        else 
            MLV_draw_text   (WIDTH / 2,HEIGHT / 2 ,"Joueur 2 a gagné la partie  ",MLV_COLOR_YELLOW );
        MLV_actualise_window();
        MLV_wait_seconds(2);

        CptParties ++ ;
    }while(CptParties < nbParties);
    
    MLV_clear_window(MLV_COLOR_BLACK);
    if (nbPartieGagneJ1 == nbParties / 2 )
        MLV_draw_text   (WIDTH / 2,HEIGHT / 2 ,"le score est nul  ",MLV_COLOR_YELLOW );
    if (nbPartieGagneJ1 > nbParties / 2 )
        MLV_draw_text   (WIDTH / 2,HEIGHT / 2 ,"le joueur 1 a gagné !!!  ",MLV_COLOR_YELLOW );
    if (nbPartieGagneJ1 < nbParties / 2 )
        MLV_draw_text   (WIDTH / 2,HEIGHT / 2 ,"le joueur 2 a gagné !!!  ",MLV_COLOR_YELLOW );

    MLV_actualise_window();
    MLV_wait_seconds(5);
   
    MLV_free_window();
    return 0;
}
