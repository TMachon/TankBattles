#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/* FONCTIONS ET PROCEDURES */

char * allocation_tab_dyn (int n) {
	char * tab = malloc(n * sizeof(char));
	return tab;
}

char ** allocation_mat_dyn (int nb_l, int nb_c) {
	char ** mat = malloc(nb_l * sizeof(char *));
	for (int i=0; i<nb_l; i++) {
		*(mat+i) = malloc(nb_c);
	}
	return mat;
}

void affichage (char * tab, int size) {
	for (int i=0; i<size; i++) {
		printf("%c", *(tab+i));
	}
	printf("\n");
}

int taille_fichier (char * chemin) {
	
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
	return compteur-1; //retour sans erreur
	
}

void lecture_fichier_tab (char * chemin, char * tab, int taille) {
	
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
}

char ** lecture_ficher_mat (char * chemin, int nb_l, int nb_c) {
	
	char ** mat = allocation_mat_dyn(nb_l, nb_c);
	
	FILE * fichier = NULL; //creation d'un pointeur vers un fichier
	fichier = fopen(chemin, "r"); //attribution du fichier que l'on veut ouvrir au pointeur que l'on vient de creer
	
	if (fichier == NULL) //creation erreur si l'ouverture du fichier a echoue
	{
		printf("erreur : l'ouverture du fichier \"%s\" a echoue", chemin);
		exit(1);
	}
	
	int caractere_lu = NULL; //creation du caractere de lecture
	int i=0, j=0; //creation des compteurs
	while ( caractere_lu!=EOF && i<nb_l && j<nb_c) {
		
		caractere_lu = fgetc(fichier); //lecture du caractere et passage au suivant
		if ((char)caractere_lu != '\n') //equivaut a "tant qu'on est pas a un retour a la ligne"
		{
			mat[i][j] = (char) caractere_lu;
			j++;
			if (j == nb_c) //si on est au bout de la ligne
			{
				j=0;
				i++;
			}
		}
	}
	
	fclose(fichier); //fermeture du fichier
	return mat; //retour sans erreur
	
}


/* MAIN *

int main (int argc, char * argv[]) {

	char * fichier = argv[1];
	int taille = taille_fichier(fichier);
	printf("%d\n", taille);
	
	char texte[taille];
	lecture_fichier_tab(fichier, texte, taille);
	affichage( texte , taille);
	
	return 0;
}

/**/
