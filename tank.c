#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* GLOBAL VARIABLES */
char tank1NN[5][28] = charger_carrosserie ("tanks/tank1_N_N.txt");
char tank1NO[5][28] = charger_carrosserie ("tanks/tank1_N_O.txt");
char tank1NE[5][28] = charger_carrosserie ("tanks/tank1_N_E.txt");
char tank1NS[5][28] = charger_carrosserie ("tanks/tank1_N_S.txt");
char tank1ON[5][28] = charger_carrosserie ("tanks/tank1_O_N.txt");
char tank1OO[5][28] = charger_carrosserie ("tanks/tank1_O_O.txt");
char tank1OE[5][28] = charger_carrosserie ("tanks/tank1_O_E.txt");
char tank1OS[5][28] = charger_carrosserie ("tanks/tank1_O_S.txt");
char tank1EN[5][28] = charger_carrosserie ("tanks/tank1_E_N.txt");
char tank1EO[5][28] = charger_carrosserie ("tanks/tank1_E_O.txt");
char tank1EE[5][28] = charger_carrosserie ("tanks/tank1_E_E.txt");
char tank1ES[5][28] = charger_carrosserie ("tanks/tank1_E_S.txt");
char tank1SN[5][28] = charger_carrosserie ("tanks/tank1_S_N.txt");
char tank1SO[5][28] = charger_carrosserie ("tanks/tank1_S_O.txt");
char tank1SE[5][28] = charger_carrosserie ("tanks/tank1_S_E.txt");
char tank1SS[5][28] = charger_carrosserie ("tanks/tank1_S_S.txt");
char tank2NN[5][28] = charger_carrosserie ("tanks/tank2_N_N.txt");
char tank2NO[5][28] = charger_carrosserie ("tanks/tank2_N_O.txt");
char tank2NE[5][28] = charger_carrosserie ("tanks/tank2_N_E.txt");
char tank2NS[5][28] = charger_carrosserie ("tanks/tank2_N_S.txt");
char tank2ON[5][28] = charger_carrosserie ("tanks/tank2_O_N.txt");
char tank2OO[5][28] = charger_carrosserie ("tanks/tank2_O_O.txt");
char tank2OE[5][28] = charger_carrosserie ("tanks/tank2_O_E.txt");
char tank2OS[5][28] = charger_carrosserie ("tanks/tank2_O_S.txt");
char tank2EN[5][28] = charger_carrosserie ("tanks/tank2_E_N.txt");
char tank2EO[5][28] = charger_carrosserie ("tanks/tank2_E_O.txt");
char tank2EE[5][28] = charger_carrosserie ("tanks/tank2_E_E.txt");
char tank2ES[5][28] = charger_carrosserie ("tanks/tank2_E_S.txt");
char tank2SN[5][28] = charger_carrosserie ("tanks/tank2_S_N.txt");
char tank2SO[5][28] = charger_carrosserie ("tanks/tank2_S_O.txt");
char tank2SE[5][28] = charger_carrosserie ("tanks/tank2_S_E.txt");
char tank2SS[5][28] = charger_carrosserie ("tanks/tank2_S_S.txt");
char tank3NN[5][28] = charger_carrosserie ("tanks/tank3_N_N.txt");
char tank3NO[5][28] = charger_carrosserie ("tanks/tank3_N_O.txt");
char tank3NE[5][28] = charger_carrosserie ("tanks/tank3_N_E.txt");
char tank3NS[5][28] = charger_carrosserie ("tanks/tank3_N_S.txt");
char tank3ON[5][28] = charger_carrosserie ("tanks/tank3_O_N.txt");
char tank3OO[5][28] = charger_carrosserie ("tanks/tank3_O_O.txt");
char tank3OE[5][28] = charger_carrosserie ("tanks/tank3_O_E.txt");
char tank3OS[5][28] = charger_carrosserie ("tanks/tank3_O_S.txt");
char tank3EN[5][28] = charger_carrosserie ("tanks/tank3_E_N.txt");
char tank3EO[5][28] = charger_carrosserie ("tanks/tank3_E_O.txt");
char tank3EE[5][28] = charger_carrosserie ("tanks/tank3_E_E.txt");
char tank3ES[5][28] = charger_carrosserie ("tanks/tank3_E_S.txt");
char tank3SN[5][28] = charger_carrosserie ("tanks/tank3_S_N.txt");
char tank3SO[5][28] = charger_carrosserie ("tanks/tank3_S_O.txt");
char tank3SE[5][28] = charger_carrosserie ("tanks/tank3_S_E.txt");
char tank3SS[5][28] = charger_carrosserie ("tanks/tank3_S_S.txt");

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
	
}


/* MAIN *

int main (int argc, char * argv[]) {


}

/**/
