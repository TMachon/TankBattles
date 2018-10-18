#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

#include "tab_mat_char.c"
#include "tank.c"

/* FONCTIONS ET PROCEDURES */

char key_pressed() {

	struct termios oldterm, newterm;
	int oldfd;
	char c, result = 0;
	tcgetattr (STDIN_FILENO, &oldterm);
	newterm = oldterm;
	newterm.c_lflag &= ~(ICANON | ECHO);
	tcsetattr (STDIN_FILENO, TCSANOW, &newterm);
	oldfd = fcntl (STDIN_FILENO, F_GETFL, 0);
	fcntl (STDIN_FILENO, F_SETFL, oldfd | O_NONBLOCK);
	c = getchar();
	tcsetattr (STDIN_FILENO, TCSANOW, &oldterm);
	fcntl (STDIN_FILENO, F_SETFL, oldfd);
	if (c != EOF) {
		ungetc(c, stdin);
		result = getchar();
	}
	return result;
}


/* MAIN */

int main (int argc, char * argv[]) {
	char ** tank1NN = allocation_mat_dyn(NB_L_TANK, NB_C_TANK);
	char ** tank1NO = allocation_mat_dyn(NB_L_TANK, NB_C_TANK);
	char ** tank1NE = allocation_mat_dyn(NB_L_TANK, NB_C_TANK);
	char ** tank1NS = allocation_mat_dyn(NB_L_TANK, NB_C_TANK);
	char ** tank1ON = allocation_mat_dyn(NB_L_TANK, NB_C_TANK);
	char ** tank1OO = allocation_mat_dyn(NB_L_TANK, NB_C_TANK);
	char ** tank1OE = allocation_mat_dyn(NB_L_TANK, NB_C_TANK);
	char ** tank1OS = allocation_mat_dyn(NB_L_TANK, NB_C_TANK);
	char ** tank1EN = allocation_mat_dyn(NB_L_TANK, NB_C_TANK);
	char ** tank1EO = allocation_mat_dyn(NB_L_TANK, NB_C_TANK);
	char ** tank1EE = allocation_mat_dyn(NB_L_TANK, NB_C_TANK);
	char ** tank1ES = allocation_mat_dyn(NB_L_TANK, NB_C_TANK);
	char ** tank1SN = allocation_mat_dyn(NB_L_TANK, NB_C_TANK);
	char ** tank1SO = allocation_mat_dyn(NB_L_TANK, NB_C_TANK);
	char ** tank1SE = allocation_mat_dyn(NB_L_TANK, NB_C_TANK);
	char ** tank1SS = allocation_mat_dyn(NB_L_TANK, NB_C_TANK);
	char ** tank2NN = allocation_mat_dyn(NB_L_TANK, NB_C_TANK);
	char ** tank2NO = allocation_mat_dyn(NB_L_TANK, NB_C_TANK);
	char ** tank2NE = allocation_mat_dyn(NB_L_TANK, NB_C_TANK);
	char ** tank2NS = allocation_mat_dyn(NB_L_TANK, NB_C_TANK);
	char ** tank2ON = allocation_mat_dyn(NB_L_TANK, NB_C_TANK);
	char ** tank2OO = allocation_mat_dyn(NB_L_TANK, NB_C_TANK);
	char ** tank2OE = allocation_mat_dyn(NB_L_TANK, NB_C_TANK);
	char ** tank2OS = allocation_mat_dyn(NB_L_TANK, NB_C_TANK);
	char ** tank2EN = allocation_mat_dyn(NB_L_TANK, NB_C_TANK);
	char ** tank2EO = allocation_mat_dyn(NB_L_TANK, NB_C_TANK);
	char ** tank2EE = allocation_mat_dyn(NB_L_TANK, NB_C_TANK);
	char ** tank2ES = allocation_mat_dyn(NB_L_TANK, NB_C_TANK);
	char ** tank2SN = allocation_mat_dyn(NB_L_TANK, NB_C_TANK);
	char ** tank2SO = allocation_mat_dyn(NB_L_TANK, NB_C_TANK);
	char ** tank2SE = allocation_mat_dyn(NB_L_TANK, NB_C_TANK);
	char ** tank2SS = allocation_mat_dyn(NB_L_TANK, NB_C_TANK);
	char ** tank3NN = allocation_mat_dyn(NB_L_TANK, NB_C_TANK);
	char ** tank3NO = allocation_mat_dyn(NB_L_TANK, NB_C_TANK);
	char ** tank3NE = allocation_mat_dyn(NB_L_TANK, NB_C_TANK);
	char ** tank3NS = allocation_mat_dyn(NB_L_TANK, NB_C_TANK);
	char ** tank3ON = allocation_mat_dyn(NB_L_TANK, NB_C_TANK);
	char ** tank3OO = allocation_mat_dyn(NB_L_TANK, NB_C_TANK);
	char ** tank3OE = allocation_mat_dyn(NB_L_TANK, NB_C_TANK);
	char ** tank3OS = allocation_mat_dyn(NB_L_TANK, NB_C_TANK);
	char ** tank3EN = allocation_mat_dyn(NB_L_TANK, NB_C_TANK);
	char ** tank3EO = allocation_mat_dyn(NB_L_TANK, NB_C_TANK);
	char ** tank3EE = allocation_mat_dyn(NB_L_TANK, NB_C_TANK);
	char ** tank3ES = allocation_mat_dyn(NB_L_TANK, NB_C_TANK);
	char ** tank3SN = allocation_mat_dyn(NB_L_TANK, NB_C_TANK);
	char ** tank3SO = allocation_mat_dyn(NB_L_TANK, NB_C_TANK);
	char ** tank3SE = allocation_mat_dyn(NB_L_TANK, NB_C_TANK);
	char ** tank3SS = allocation_mat_dyn(NB_L_TANK, NB_C_TANK);
	
	
	
	tank1NN = charger_carrosserie ("tanks/tank1_N_N.txt");
	tank1NO = charger_carrosserie ("tanks/tank1_N_O.txt");
	tank1NE = charger_carrosserie ("tanks/tank1_N_E.txt");
	tank1NS = charger_carrosserie ("tanks/tank1_N_S.txt");
	tank1ON = charger_carrosserie ("tanks/tank1_O_N.txt");
	tank1OO = charger_carrosserie ("tanks/tank1_O_O.txt");
	tank1OE = charger_carrosserie ("tanks/tank1_O_E.txt");
	tank1OS = charger_carrosserie ("tanks/tank1_O_S.txt");
	tank1EN = charger_carrosserie ("tanks/tank1_E_N.txt");
	tank1EO = charger_carrosserie ("tanks/tank1_E_O.txt");
	tank1EE = charger_carrosserie ("tanks/tank1_E_E.txt");
	tank1ES = charger_carrosserie ("tanks/tank1_E_S.txt");
	tank1SN = charger_carrosserie ("tanks/tank1_S_N.txt");
	tank1SO = charger_carrosserie ("tanks/tank1_S_O.txt");
	tank1SE = charger_carrosserie ("tanks/tank1_S_E.txt");
	tank1SS = charger_carrosserie ("tanks/tank1_S_S.txt");
	tank2NN = charger_carrosserie ("tanks/tank2_N_N.txt");
	tank2NO = charger_carrosserie ("tanks/tank2_N_O.txt");
	tank2NE = charger_carrosserie ("tanks/tank2_N_E.txt");
	tank2NS = charger_carrosserie ("tanks/tank2_N_S.txt");
	tank2ON = charger_carrosserie ("tanks/tank2_O_N.txt");
	tank2OO = charger_carrosserie ("tanks/tank2_O_O.txt");
	tank2OE = charger_carrosserie ("tanks/tank2_O_E.txt");
	tank2OS = charger_carrosserie ("tanks/tank2_O_S.txt");
	tank2EN = charger_carrosserie ("tanks/tank2_E_N.txt");
	tank2EO = charger_carrosserie ("tanks/tank2_E_O.txt");
	tank2EE = charger_carrosserie ("tanks/tank2_E_E.txt");
	tank2ES = charger_carrosserie ("tanks/tank2_E_S.txt");
	tank2SN = charger_carrosserie ("tanks/tank2_S_N.txt");
	tank2SO = charger_carrosserie ("tanks/tank2_S_O.txt");
	tank2SE = charger_carrosserie ("tanks/tank2_S_E.txt");
	tank2SS = charger_carrosserie ("tanks/tank2_S_S.txt");
	tank3NN = charger_carrosserie ("tanks/tank3_N_N.txt");
	tank3NO = charger_carrosserie ("tanks/tank3_N_O.txt");
	tank3NE = charger_carrosserie ("tanks/tank3_N_E.txt");
	tank3NS = charger_carrosserie ("tanks/tank3_N_S.txt");
	tank3ON = charger_carrosserie ("tanks/tank3_O_N.txt");
	tank3OO = charger_carrosserie ("tanks/tank3_O_O.txt");
	tank3OE = charger_carrosserie ("tanks/tank3_O_E.txt");
	tank3OS = charger_carrosserie ("tanks/tank3_O_S.txt");
	tank3EN = charger_carrosserie ("tanks/tank3_E_N.txt");
	tank3EO = charger_carrosserie ("tanks/tank3_E_O.txt");
	tank3EE = charger_carrosserie ("tanks/tank3_E_E.txt");
	tank3ES = charger_carrosserie ("tanks/tank3_E_S.txt");
	tank3SN = charger_carrosserie ("tanks/tank3_S_N.txt");
	tank3SO = charger_carrosserie ("tanks/tank3_S_O.txt");
	tank3SE = charger_carrosserie ("tanks/tank3_S_E.txt");
	tank3SS = charger_carrosserie ("tanks/tank3_S_S.txt");
	
	/*
	char c, direction="N", canon;
	int changement = 0;
	char fichier[] = "tanks/tank3_N_N.txt";
	while (( c = key_pressed()) != 'e') {
		if (c == 'd') {
			fichier[12] = 'E';
			changement = 1;
		}
		if (c == 'q') {
			fichier[12] = 'O';
			changement = 1;
		}
		if (c == 's') {
			fichier[12] = 'S';
			changement = 1;
		}
		if (c == 'z') {
			fichier[12] = 'N';
			changement = 1;
		}
		if (c == 'm') {
			fichier[14] = 'E';
			changement = 1;
		}
		if (c == 'k') {
			fichier[14] = 'O';
			changement = 1;
		}
		if (c == 'l') {
			fichier[14] = 'S';
			changement = 1;
		}
		if (c == 'o') {
			fichier[14] = 'N';
			changement = 1;
		}
		if (changement) {
			changement = 0;
			int taille = taille_fichier(fichier);
			char texte[taille];
			lecture_fichier_mat(fichier, texte, taille);
			affichage(texte , taille);
		}
		
	}
	*/
}

/**/
