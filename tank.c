#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/* STRUCT */

typedef struct tank TANK;
struct tank {

	char direction_tank;	 //N=nord, S=sud, E=est, O=ouest
	char direction_canon;	 //N=nord, S=sud, E=est, O=ouest
	int posX;		 //position du tank en abscisse (coin superieur gauche)
	int posY;		 //posotion du tank en ordonnee (coin superieur gauche)
	int blindage;		 //niveau de blindage du tank (de 0 à 2)

	int blindage_origine;	
	int touches;		 //nombre de fois que le tank est touché
	char carrosserie[5][28]; //affichage graphique du tank

	char type;		 //J=joueur, E=ennemi
	int etat;		 //1=actif, 2=en destruction, 3=inactif (A VOIR SI ON GARDE)
	
	int mise_a_jour;	 //utile pour la suppression du tank en tenant compte d'un delay (A VOIR SI ON GARDE)

	struct tank * NEXT;	 //pointeur vers un prochain tank
};

/* FONCTIONS ET PROCEDURES */




/* MAIN *

int main (int argc, char * argv[]) {


}

/**/
