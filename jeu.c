
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

#define NB_L_MAP 48
#define NB_C_MAP 184

#include "tank.c"
#include "map.c"

char key_pressed()
{
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

int main(int argc, char** argv)
{
	system("clear");
	system("setterm -cursor off");
	system("stty -echo");
	
	FILE * file = NULL;
	file = fopen("map.txt", "r+");
	char ** map = ALLOCATION_MAT_DYN(NB_L_MAP, NB_C_MAP);

	if(file != NULL){
		remplir_matrice(NB_L_MAP, NB_C_MAP, map, file);
		affiche_map(NB_L_MAP, NB_C_MAP, map);

		fclose(file);
	}

	struct tank* tank_joueur = malloc(sizeof(tank));
	tank_init(tank_joueur);
	
	CHARGEMENT_MAT(tank_joueur);
	
	char i ;
	while(1){

		i = key_pressed();
		int passage = 0;

		//affichage infos
		curseur(50, 0);
		printf("%d %d %c", tank_joueur->posx, tank_joueur->posy, map[tank_joueur->posy][tank_joueur->posx]);
		
		switch(i) {
			case 'z':
				tourner_tank(tank_joueur, 'N');
				for (int j=0; j<NB_C_TANK; j++) {
					if (map[tank_joueur->posy-1][tank_joueur->posx+j] != ' ') passage++;
				}
				if (passage == 0) deplacer_tank(tank_joueur, 'N');
				break;
			case 's':
				tourner_tank(tank_joueur, 'S');
				for (int j=0; j<NB_C_TANK; j++) {
					if (map[tank_joueur->posy+NB_L_TANK][tank_joueur->posx+j] != ' ') passage++;
				}
				if (passage == 0)deplacer_tank(tank_joueur, 'S');
				break;
			case 'd':
				tourner_tank(tank_joueur, 'E');
				for (int j=0; j<NB_L_TANK; j++) {
					if (map[tank_joueur->posy+j][tank_joueur->posx+NB_C_TANK] != ' ') passage++;
				}
				if (passage == 0)deplacer_tank(tank_joueur, 'E');
				break;
			case 'q':
				tourner_tank(tank_joueur, 'O');
				for (int j=0; j<NB_L_TANK; j++) {
					if (map[tank_joueur->posy+j][tank_joueur->posx-1] != ' ') passage++;
				}
				if (passage == 0)deplacer_tank(tank_joueur, 'O');
				break;
			case 'f':
				system("setterm -cursor on");
				system("stty echo");
				exit(0);
			case ' ':
			//tirer_obus();
			break;
		}
	}
	//printf("%c", tab[0][0]);
	//AFFICHAGE_MAT(4, 10, tab);
	
	return 0;
}