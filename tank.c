#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NB_L_TANK 5
#define NB_C_TANK 28
/*
#define NB_L_MAP
#define NB_C_MAP
*/

/* STRUCT */

typedef struct tank TANK;
struct tank {

	char direction_tank;		//N=nord, S=sud, E=est, O=ouest
	char direction_canon;		//N=nord, S=sud, E=est, O=ouest
	int posX;		//position du tank en abscisse (coin superieur gauche)
	int posY;		//posotion du tank en ordonnee (coin superieur gauche)
	int blindage;		//niveau de blindage du tank (de 0 à 2)

	int blindage_origine;	
	int touches;		//nombre de fois que le tank est touché
	char carrosserie[5][28];		//affichage graphique du tank

	char type;		//J=joueur, E=ennemi
	int etat;		//1=actif, 2=en destruction, 3=inactif (A VOIR SI ON GARDE)
	
	int mise_a_jour;		//utile pour la suppression du tank en tenant compte d'un delay (A VOIR SI ON GARDE)

	struct tank * NEXT;		//pointeur vers un prochain tank
};

/* FONCTIONS ET PROCEDURES */

char ** charger_carrosserie (char * chemin) {
	return lecture_ficher_mat(chemin, NB_L_TANK, NB_C_TANK);
}

/*
char ** charger_map (char * chemin) {
	return lecture_ficher_mat(chemin, NB_L_MAP, NB_C_MAP);
}
*/

void affecter_carrosserie (tank tank1) {
	//TODO
}

void afficher_tank (tank tank1) {
	//TODO
}

/* MAIN *

int main (int argc, char * argv[]) {


}

/**/
