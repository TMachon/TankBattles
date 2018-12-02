
#include "jeu.h"
#include "variables_globales.h"

#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

// Permet d'afficher la map
void affiche_map(int nb_l, int nb_c, char** mat){
	
	int i, j;
	
	for(i=0; i<nb_l; i++){
		for(j=0; j<nb_c; j++){
			printf("%c", *(*(mat + i)+j));
		}
	}
}
