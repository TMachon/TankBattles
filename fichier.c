
#include "fichier.h"
#include "variables_globales.h"

#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

char** ALLOCATION_MAT_DYN(int NB_L, int NB_C) //Allocation dynamique de mémoire à la matrice
{
	int i;
	char** mat=NULL;

	mat = malloc(NB_L*sizeof(char*));
	for (i=0; i<NB_L; i++)
	{
		mat[i] = malloc(NB_C*sizeof(char));
	}
	return mat;

}

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



void remplir_matrice(int NB_L, int NB_C, char** mat, FILE* file){
	int i, j;

	for(i=0; i<NB_L; i++){
		for(j=0; j<NB_C; j++){
			fscanf(file, "%c", &mat[i][j]);
		}
	}
}