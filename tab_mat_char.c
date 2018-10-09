#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/* FONCTIONS ET PROCEDURES */

char * allocation_tab_dyn (int n) {
	char * tab = malloc(n * sizeof(char));
	return tab;
}

void affichage (char * tab, int size) {
	for (int i=0; i<size; i++) {
		printf("%c", *(tab+i));
	}
	printf("\n");
}

int nombre_caracteres_fichier (char * chemin) {
	
	FILE * fichier = NULL; //creation d'un pointeur vers un fichier
	fichier = fopen(chemin, "r"); //attribution du fichier que l'on veut ouvrir au pointeur que l'on vient de creer
	
	if (fichier == NULL) //creation erreur si l'ouverture du fichier a echoue
	{
		printf("erreur : l'ouverture du fichier \"%s\" a echoue", chemin);
		exit(1);
	}
	
	int caractere_lu = NULL; //creation du caractere de lecture
	int compteur = 0; //creation du compteur de caracteres
	do // boucler ...
	{
		caractere_lu = fgetc(fichier); //lecture du caractere et passage au suivant
		compteur++; //incrementation du compteur
	}
	while (caractere_lu != EOF); // ... tant que le caractere lu n'est pas nul
	
	fclose(fichier); //fermeture du fichier
	return compteur; //retour sans erreur
	
}

void lecture_fichier (char * chemin, char * tab, int taille) {
	
	FILE * fichier = NULL; //creation d'un pointeur vers un fichier
	fichier = fopen(chemin, "r"); //attribution du fichier que l'on veut ouvrir au pointeur que l'on vient de creer
	
	if (fichier == NULL) //creation erreur si l'ouverture du fichier a echoue
	{
		printf("erreur : l'ouverture du fichier \"%s\" a echoue", chemin);
		exit(1);
	}
	
	char caractere_lu = NULL; //creation du caractere de lecture
	int i = 0; //creation du compteur pour incrementer 'tab'
	do {
		caractere_lu = fgetc(fichier); //lecture du caractere et passage au suivant
		*(tab+i) = caractere_lu; //attribution de la valeur du caractere a 'tab'
		i++;
	}
	while (caractere_lu != EOF); // ... tant que le caractere lu n'est pas nul
	fclose(fichier); //fermeture du fichier
	return 0; //retour sans erreur
}



/* MAIN */

int main (int argc, char * argv[]) {

	char * fichier = argv[1];
	int taille = nombre_caracteres_fichier(fichier);
	printf("%d\n", taille);
	
	char texte[taille];
	lecture_fichier(fichier, texte, taille);
	printf("%c\n", texte[0]);
	printf("%c\n", texte[1]);
	affichage( texte , taille);
	
	return 0;
}

/**/