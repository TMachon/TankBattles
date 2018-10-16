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
			lecture_fichier(fichier, texte, taille);
			affichage(texte , taille);
		}
		
	}

}

/**/
