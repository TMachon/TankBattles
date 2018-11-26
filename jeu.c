
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

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
	char c;
	char i ;
	FILE*file = NULL;

	char **map = ALLOCATION_MAT_DYN(47, 184);
	struct tank * tank = malloc(sizeof(tank));
	tank->posx = 10;
	tank->posy = 10;


	file = fopen("map.txt", "r+");

	system("clear");
	if(file != NULL){
		remplir_matrice(47, 184, map, file);
		affiche_map(47, 184, map);

		fclose(file);
	}
	
	CHARGEMENT_MAT(tank);
	
	
	while(1){

		i = key_pressed();

		switch(i){

			case 'z':
				deplacer_tank(tank, 'N');
				break;
			case 's':
				deplacer_tank(tank, 'S');
				break;
			case 'd':
				deplacer_tank(tank, 'E');
				break;
			case 'q':
				deplacer_tank(tank, 'O');
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