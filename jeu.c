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

	char c;
	while (( c = key_pressed()) != 'e') {
		if (c == 'd') {
			char * fichier = "tanks/tank1_E_E.txt";
			int taille = taille_fichier(fichier);
			char texte[taille];
			lecture_fichier(fichier, texte, taille);
			affichage( texte , taille);
		}
		if (c == 'q') {
			char * fichier = "tanks/tank1_O_O.txt";
			int taille = taille_fichier(fichier);
			char texte[taille];
			lecture_fichier(fichier, texte, taille);
			affichage( texte , taille);
		}
		if (c == 's') {
			char * fichier = "tanks/tank1_S_S.txt";
			int taille = taille_fichier(fichier);
			char texte[taille];
			lecture_fichier(fichier, texte, taille);
			affichage( texte , taille);
		}
		if (c == 'z') {
			char * fichier = "tanks/tank1_N_N.txt";
			int taille = taille_fichier(fichier);
			char texte[taille];
			lecture_fichier(fichier, texte, taille);
			affichage( texte , taille);
		}
	}

}

/**/
