/************************************************
 * BINOME 1: OUKSILI SMAIL                      *
 * BINOME 2: SAKHO MAMADOU                      *
 * Dernière modification : 19/02/2019 (OUKSILI )*
*************************************************/
#include "affichage.h"


void afficher_position(Position *pos){
    int i = 0 ;
    int j = 0 ;

    MLV_Image *image = MLV_load_image( "../chocolat.jpeg" );
    MLV_resize_image (image ,(WIDTH-50)/M,(HEIGHT-400)/N );
    MLV_clear_window(MLV_COLOR_BLACK);
    for (; i < N ; i++){
        for (j = 0; j < M; j++){
            if (pos->tab.tab[i][j] == 1)
                MLV_draw_image( image, 2*j + ((WIDTH-50)/M)*j,2*i +((HEIGHT-400)/N)*i );
        }
    } 

    if (pos->j == J1)
        MLV_draw_text   (300 ,HEIGHT - 100 ,"Joueur 1",MLV_COLOR_YELLOW );
    if (pos->j == J2)
        MLV_draw_text   (150 ,HEIGHT - 100 ,"Joueur 2",MLV_COLOR_YELLOW );
    
    MLV_actualise_window();


}


Coup lire_coup(Position  *pos){
    int mousex,mousey ;
    Coup c ;
    
    assert(pos != NULL);

    MLV_wait_mouse 	( &mousex,&mousey ) ;	
    c.x = mousex /(2 + (WIDTH-50)/M) ;
    c.y = mousey /(2 +((HEIGHT-400)/N)) ;
    
    return c ;
}








/*cette fonction prend recois une chaine de caractère et calcul sa taille pour verifier arés qu'elle est valide  
 */
int verifier_nb_valide(char  * text){

	int taille = strlen (text);
	int i = 0 ;
	
    assert(text != NULL) ;

	while (i < taille){
		if ((text [i] >= 'a' && text [i] <= 'z' )|| 
		(text [i] >= 'A' && text [i] <= 'Z'))
			i += 1 ;
		else
			return 0 ;
	}
	return 1 ;
}


/*une fonction qu'on va utiliser dans la suite de programme elle renvoie 
 * un entier ( 10^n avec n l'entier passé en argument ) 
*/
int puissance (int a){
	assert( a >= 0 );

    if (a == 0)
		return 1;
	return 10* puissance(a-1);
}


/* Avec cette fonction on demande aux joueurs d'entrer chacun le 
 * nombre de partie voulus et renvoie la moyenne des nombre de parties 
 */

int demander_nb_parties(char *Joueur){
	int i = 0 ;
    int a = 0 ;
    int taille = 0;
    char * text ;
    char  chaine[40] = "entrez le nombre de parties " ;

    assert(Joueur != NULL);
    
    strcat(chaine,Joueur);
    strcat(chaine,":") ;
    do {
    	MLV_wait_input_box(150,150,340,340,
        	MLV_COLOR_RED, MLV_COLOR_GREEN, MLV_COLOR_BLACK,
        	chaine,&text);
    }while(verifier_nb_valide(text) != 0);
    taille = strlen(text);
  	
    while ( i < taille ){
    	a += ((text[i] - 48)*puissance(taille-i-1));
    	i += 1 ;
    }
	return a;     

}
