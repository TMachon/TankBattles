
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

void affiche_map(int NB_L, int NB_C, char **mat){
	int i, j;
	
	for(i=0; i<NB_L; i++){
		for(j=0; j<NB_C; j++){
			switch(mat[i][j]){
				case '1':
				printf("T");
				break;
				default: 
				printf("%c", *(*(mat + i)+j));
			}
			
		}
	}
}