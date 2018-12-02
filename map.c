
#include "jeu.h"
#include "variables_globales.h"

#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

void affiche_map(int NB_L, int NB_C, char** mat){
	int i, j;
	
	for(i=0; i<NB_L; i++){
		for(j=0; j<NB_C; j++){
			printf("%c", *(*(mat + i)+j));
		}
	}
}
