
#include "fichier.h"
#include "variables_globales.h"

#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

// Allocation dynamique de memoire à la matrice
char** allocation_mat_dyn(int nb_l, int nb_c) {
	
	int i;
	char** mat=NULL;

	mat = malloc(nb_l*sizeof(char*));
	for (i=0; i<nb_l; i++) mat[i] = malloc(nb_c*sizeof(char));
	return mat;

}

// Permet de changer un caractere en un autre selon les parametres pre-defenis
void fill_car(char c) {
	
	switch(c) {
		
	case '0':
		printf(" ");
		break;
		
	case '1':
		printf("|");
		break;
		
	case '2':
		printf("-");
		break;
		
	case '3':
		printf("_");
	}
}

// Remplit un matrice a partir d'un fichier
void remplir_matrice(int nb_l, int nb_c, char** mat, FILE* file) {
	
	int i, j;

	for(i=0; i<nb_l; i++){
		for(j=0; j<nb_c; j++){
			fscanf(file, "%c", &mat[i][j]);
		}
	}
}