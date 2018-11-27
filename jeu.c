
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

int main(int argc, char ** argv)
{
	system("clear");
	system("setterm -cursor off");
	system("stty -echo");

	char c;
	char i ;
	FILE * file = NULL;

	char ** map = ALLOCATION_MAT_DYN(NB_L_MAP, NB_C_MAP);
	struct tank * tank = malloc(sizeof(tank));
	tank->posx = 10;
	tank->posy = 3;


	file = fopen("map.txt", "r+");

	if(file != NULL){
		remplir_matrice(NB_L_MAP, NB_C_MAP, map, file);
		affiche_map(NB_L_MAP, NB_C_MAP, map);

		fclose(file);
	}
	
	CHARGEMENT_MAT(tank);
	
	
	while(1){

		i = key_pressed();
		int passage = 0;

		//affichage infos
		curseur(50, 0);
		printf("%d %d %c", tank->posx, tank->posy, map[tank->posy][tank->posx]);
		
		switch(i) {
			case 'z': ;
				for (int j=0; j<NB_C_TANK; j++) {
					if (map[tank->posy-1][tank->posx+j] != ' ') passage++;
				}
				if (passage == 0) deplacer_tank(tank, 'N');
				break;
			case 's':
				for (int j=0; j<NB_C_TANK; j++) {
					if (map[tank->posy+NB_L_TANK][tank->posx+j] != ' ') passage++;
				}
				if (passage == 0)deplacer_tank(tank, 'S');
				break;
			case 'd':
				for (int j=0; j<NB_L_TANK; j++) {
					if (map[tank->posy+j][tank->posx+NB_C_TANK] != ' ') passage++;
				}
				if (passage == 0)deplacer_tank(tank, 'E');
				break;
			case 'q':
				for (int j=0; j<NB_L_TANK; j++) {
					if (map[tank->posy+j][tank->posx-1] != ' ') passage++;
				}
				if (passage == 0)deplacer_tank(tank, 'O');
				break;
			case ' ':
			//tirer_obus();
			break;
		}
	}
	//printf("%c", tab[0][0]);
	//AFFICHAGE_MAT(4, 10, tab);
	
	return 0;
}