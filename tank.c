
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include "fichier.c"

typedef struct tank tank;
struct tank
{
	char Direction ; /*N => Nord, S => Sud, E => EST, O => OUEST*/
	int posx; /*Position courante coin gauche X du tank*/
	int posy; /*Position courante coin gauche Y du tank*/
	int Blindage; /*niveau de blindage en cours du tank
	(0 => rien, 1 => blindé, 2 => ultra-blindé)*/
	int Blindage_orig; /*Blindage d’origine*/
	int Touches; /*Nombre de fois que le tank est touché*/
	char carrosserie_h [5][10];
	char carrosserie_b [5][11];
	char carrosserie_d [4][12];
	char carrosserie_g [5][12];/*Carrosserie du tank, servira pour
	l’affichage du tank à tout moment*/
	char Type; /*’M’ => mon tank, ’E’ => tank ennemi*/
	int Etat; /*État du tank 1 => actif, 2 => en destruction,
	3 => inactif*/
	int Mise_a_jour; /*utile pour la suppression du tank en tenant
	compte d’un delay*/
	struct tank * NXT; /*Pointeur vers un prochain tank*/
	/*Vous pouvez rajouter d’autres variables si nécessaire */
};

void **CHARGEMENT_MAT (tank* tank) //Chargement matrice
{
	int i, j, fd1, 	k, fd2, fd3, fd4;
	char c;
	fd1 = open("tank_haut.txt", O_RDONLY);
	if(fd1==-1) {
		perror("open");
		exit(-1);
	}
	i=0;
	j=0;
	while(1) {
		k = read(fd1, &c, 1);
		if(k<1) break;
		if(k==EOF) break;
		tank->carrosserie_h[i][j] = c;
		j++;
		if(c=='\n'){
			i++;
			j=0;
		}
	}
	close(fd1);
	fd2 = open("tank_bas.txt", O_RDONLY);
	if(fd2==-1) {
		perror("open");
		exit(-1);
	}
	i=0;
	j=0;
	while(1) {
		k = read(fd2, &c, 1);
		if(k<1) break;
		if(k==EOF) break;
		tank->carrosserie_b[i][j] = c;
		j++;
		//printf("%c", c);
		if(c=='\n'){
			i++;
			j=0;
		}
	}
	close(fd2);
	fd3 = open("tank_gauche.txt", O_RDONLY);
	if(fd3==-1) {
		perror("open");
		exit(-1);
	}
	i=0;
	j=0;
	while(1) {
		k = read(fd3, &c, 1);
		if(k<1) break;
		if(k==EOF) break;
		tank->carrosserie_g[i][j] = c;
		j++;
		//printf("%c", c);
		if(c=='\n'){
			i++;
			j=0;
		}
	}
	close(fd3);
	fd4 = open("tank_droit.txt", O_RDONLY);
	if(fd4==-1) {
		perror("open");
		exit(-1);
	}
	i=0;
	j=0;
	while(1) {
		k = read(fd4, &c, 1);
		if(k<1) break;
		if(k==EOF) break;
		tank->carrosserie_d[i][j] = c;
		j++;
		//printf("%c", c);
		if(c=='\n'){
			i++;
			j=0;
		}
	}
	close(fd4);   
	return 0;
}

void AFFICHAGE_MAT(int NB_L, int NB_C, tank* tank, int posx, int posy)
{//Affichage matrice
	int i, j;

	//system("clear");
	for (i=0; i<NB_L; i++)
	{
		for(j=0;j<NB_C;j++) {
			curseur(1+posx+i, 1+posy+j);
			if(tank->Direction == 'N')
				fill_car(tank->carrosserie_h[i][j]);
			if(tank->Direction == 'S')
				fill_car(tank->carrosserie_b[i][j]);
			if(tank->Direction == 'E')
				fill_car(tank->carrosserie_d[i][j]);
			if(tank->Direction == 'O')
				fill_car(tank->carrosserie_g[i][j]);       
		}
		
	}
}

void effacer_tank(int NB_L, int NB_C, tank* tank, int posx, int posy)
{//Affichage matrice
	int i, j;

	//system("clear");
	for (i=0; i<NB_L; i++)
	{
		for(j=0;j<NB_C;j++) {
			curseur(1+posx+i, 1+posy+j);
			if(tank->Direction == 'N')
				fill_car('0');
			if(tank->Direction == 'S')
				fill_car('0');
			if(tank->Direction == 'E')
				fill_car('0');
			if(tank->Direction == 'O')
				fill_car('0');   
		}
		
	}
}

void deplacer_tank(tank* tank, char dir) {
	int i, j, NB_L, NB_C;

	switch(dir) {
		case 'N':
			NB_L=5;
			NB_C=10;
			effacer_tank(NB_L, NB_C, tank, tank->posx, tank->posy);
			tank->Direction = dir;
			tank->posx--;
			AFFICHAGE_MAT(NB_L, NB_C, tank, tank->posx, tank->posy);
			break;
		case 'S':
			NB_L=5;
			NB_C=11;
			effacer_tank(NB_L, NB_C, tank, tank->posx, tank->posy);
			tank->Direction = dir;
			tank->posx++;
			AFFICHAGE_MAT(NB_L, NB_C, tank,tank->posx, tank->posy);
			break;
		case 'E':
			NB_L=4;
			NB_C=12;
			effacer_tank(NB_L, NB_C, tank, tank->posx, tank->posy);
			tank->Direction = dir;
			tank->posy++;
			AFFICHAGE_MAT(NB_L, NB_C, tank,tank->posx, tank->posy);
			break;
		case 'O':
			NB_L=4;
			NB_C=12;
			effacer_tank(NB_L, NB_C, tank, tank->posx, tank->posy);
			tank->Direction = dir;
			tank->posy--;
			AFFICHAGE_MAT(NB_L, NB_C, tank,tank->posx, tank->posy);
			break;
	}

}