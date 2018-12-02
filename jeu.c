
#include "jeu.h"
#include "variables_globales.h"

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

#include "tank.c"
#include "obus.c"
#include "map.c"

char** map;

// fonction qui gere la perssions des touches du clavier
char key_pressed() {
	struct termios oldterm, newterm;
	int oldfd; char c, result = 0;
	tcgetattr (STDIN_FILENO, &oldterm);
	newterm = oldterm; newterm.c_lflag &= ~(ICANON | ECHO);
	tcsetattr (STDIN_FILENO, TCSANOW, &newterm);
	oldfd = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl (STDIN_FILENO, F_SETFL, oldfd | O_NONBLOCK);
	c = getchar();
	tcsetattr (STDIN_FILENO, TCSANOW, &oldterm);
	fcntl (STDIN_FILENO, F_SETFL, oldfd);
	if (c != EOF) {ungetc(c, stdin); result = getchar();}
	return result;
}

void quitter() {
	system("setterm -cursor on");
	system("stty echo");
	exit(0);
}

// fonction qui fait tourner le jeu
int main(int argc, char** argv) {
	// gestion du terminal
	system("clear");
	system("setterm -cursor off");
	system("stty -echo");
	
	char i;
	int jeu_lancee = 0; //faux
	
	// gestion menu
	char ** menu = ALLOCATION_MAT_DYN(NB_L_MAP, NB_C_MAP);
	FILE * file1 = NULL;
	file1 = fopen("txt/menu.txt", "r+");
	if(file1 != NULL){
		remplir_matrice(NB_L_MAP, NB_C_MAP, menu, file1);
		fclose(file1);
	} else {
		system("clear");
		printf("Erreur lors du chargement de la carte");
		exit(1);
	}
	affiche_map(NB_L_MAP, NB_C_MAP, menu);
	
	// gestion de la carte
	map = ALLOCATION_MAT_DYN(NB_L_MAP, NB_C_MAP);
	FILE * file2 = NULL;
	file2 = fopen("txt/map.txt", "r+");
	if(file2 != NULL){
		remplir_matrice(NB_L_MAP, NB_C_MAP, map, file2);
		fclose(file2);
	} else {
		system("clear");
		printf("Erreur lors du chargement de la carte");
		exit(1);
	}
	
	// creation du tank du joueur
	struct tank* tank_joueur = malloc(sizeof(tank));
	struct obus* obus1 = malloc(sizeof(obus));
	initier_tank_joueur(tank_joueur);
	initier_obus(obus1, tank_joueur);	
	
	while(1){

		i = key_pressed();
		int passage = 0;
		
		// affichage position
		if (jeu_lancee == 1) {
			curseur(50, 0);
			printf("               ");
			curseur(50, 0);
			printf("%d %d - %d %d", tank_joueur->posx, tank_joueur->posy, obus1->posx, obus1->posy);
		}
		
		switch(i) {
			
		// pour lancer le jeu
		case 'j':
			if (jeu_lancee == 0) {
				
				// afficher de la carte
				system("clear");
				affiche_map(NB_L_MAP, NB_C_MAP, map);
				
				jeu_lancee = 1;
			}
			break;
			
		// pour terminer le jeu
		case 't':
			quitter();
			break;
			
		// pour tirer un obus
		case ' ':
			tirer_obus(obus1);
			break;
			
		// gestion deplacements du tank joueur
			
		case 'z':
			if (jeu_lancee == 1) {
				tourner_tank(tank_joueur, 'N');
				for (int j=0; j<NB_C_TANK; j++) {
					if (map[tank_joueur->posy-1][tank_joueur->posx+j] != ' ') passage++;
				}
				if (passage == 0) deplacer_tank(tank_joueur, 'N');
			}
			break;
			
		case 'q':
			if (jeu_lancee == 1) {
				tourner_tank(tank_joueur, 'O');
				for (int j=0; j<NB_L_TANK; j++) {
					if (map[tank_joueur->posy+j][tank_joueur->posx-1] != ' ') passage++;
				}
				if (passage == 0)deplacer_tank(tank_joueur, 'O');
			}
			break;
			
		case 's':
			if (jeu_lancee == 1) {
				tourner_tank(tank_joueur, 'S');
				for (int j=0; j<NB_C_TANK; j++) {
					if (map[tank_joueur->posy+NB_L_TANK][tank_joueur->posx+j] != ' ') passage++;
				}
				if (passage == 0)deplacer_tank(tank_joueur, 'S');
			}
			break;
			
		case 'd':
			if (jeu_lancee == 1) {
				tourner_tank(tank_joueur, 'E');
				for (int j=0; j<NB_L_TANK; j++) {
					if (map[tank_joueur->posy+j][tank_joueur->posx+NB_C_TANK] != ' ') passage++;
				}
				if (passage == 0)deplacer_tank(tank_joueur, 'E');
			}
			break;
		}
	}
	
	return 0;
}