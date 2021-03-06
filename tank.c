
#include "tank.h"
#include "variables_globales.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include "fichier.c"

// Fonction pour charger les matrices de carrosserie
void charger_carrosserie(tank* tank_var)
{
	int i, j, fd1, 	k, fd2, fd3, fd4;
	char c;
	
	char file1[30];
	snprintf(file1, sizeof(file1), "txt/tank_haut_%d.txt", tank_var->Blindage);
	fd1 = open("txt/tank_haut_0.txt", O_RDONLY);
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
		tank_var->carrosserie_h[i][j] = c;
		j++;
		if(c=='\n'){
			i++;
			j=0;
		}
	}
	close(fd1);
	
	char file2[30];
	snprintf(file2, sizeof(file2), "txt/tank_bas_%d.txt", tank_var->Blindage);
	fd2 = open("txt/tank_bas_0.txt", O_RDONLY);
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
		tank_var->carrosserie_b[i][j] = c;
		j++;
		if(c=='\n'){
			i++;
			j=0;
		}
	}
	close(fd2);
	
	char file3[30];
	snprintf(file3, sizeof(file3), "txt/tank_gauche_%d.txt", tank_var->Blindage);
	fd3 = open("txt/tank_gauche_0.txt", O_RDONLY);
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
		tank_var->carrosserie_g[i][j] = c;
		j++;
		if(c=='\n'){
			i++;
			j=0;
		}
	}
	close(fd3);
	
	char file4[30];
	snprintf(file4, sizeof(file4), "txt/tank_droit_%d.txt", tank_var->Blindage);
	fd4 = open("txt/tank_droit_0.txt", O_RDONLY);
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
		tank_var->carrosserie_d[i][j] = c;
		j++;
		if(c=='\n'){
			i++;
			j=0;
		}
	}
	close(fd4);
}

// Constructeur pour le tank joueur
void initier_tank_joueur(tank* tank_var) {
	
	tank_var->Direction = 'E';
	tank_var->posx = 5;
	tank_var->posy = 5;
	tank_var->Blindage = 0;
	tank_var->Blindage_orig = 0;
	tank_var->Touches = 0;
	tank_var->Type = 'J';
	tank_var->Etat = 1;
	charger_carrosserie(tank_var);
}

// Constructeur pour les tanks ennemis
void initier_tank_ennemi(tank* tank_var, char direction, int pos_x, int pos_y, int blindage) {
	
	tank_var->Direction = direction;
	tank_var->posx = pos_x;
	tank_var->posy = pos_y;
	tank_var->Blindage = blindage;
	tank_var->Blindage_orig = blindage;
	tank_var->Touches = 0;
	tank_var->Type = 'E';
	tank_var->Etat = 1;
	charger_carrosserie(tank_var);
}

// Fonction qui s'occupe d'afficher le tank
void afficher_tank(tank* tank_var) {
	
	for (int i=0; i<NB_L_TANK; i++)
	{
		for(int j=0;j<NB_C_TANK;j++) {
			curseur(1+tank_var->posy+i, 1+tank_var->posx+j);
			if(tank_var->Direction == 'N')
				fill_car(tank_var->carrosserie_h[i][j]);
			if(tank_var->Direction == 'S')
				fill_car(tank_var->carrosserie_b[i][j]);
			if(tank_var->Direction == 'E')
				fill_car(tank_var->carrosserie_d[i][j]);
			if(tank_var->Direction == 'O')
				fill_car(tank_var->carrosserie_g[i][j]);       
		}
	}
}

// Fonction qui s'occupe d'effacer le tank
void effacer_tank(tank* tank_var) {
	
	for (int i=0; i<NB_L_TANK; i++)
	{
		for(int j=0;j<NB_C_TANK;j++) {
			curseur(1+tank_var->posy+i, 1+tank_var->posx+j);
			if(tank_var->Direction == 'N')
				fill_car('0');
			if(tank_var->Direction == 'S')
				fill_car('0');
			if(tank_var->Direction == 'E')
				fill_car('0');
			if(tank_var->Direction == 'O')
				fill_car('0');   
		}
		
	}
}

// Fonction qui gere la rotation du tank
void tourner_tank(tank* tank_var, char dir) {
	
	effacer_tank(tank_var);
	tank_var->Direction = dir;
	afficher_tank(tank_var);
}

// Fonction qui gere les deplacements d'un tank au sens large
void deplacer_tank(tank* tank_var, char dir) {
	
	switch(dir) {
		
	case 'N':
		effacer_tank(tank_var);
		tank_var->posy--;
		afficher_tank(tank_var);
		break;
		
	case 'S':
		effacer_tank(tank_var);
		tank_var->posy++;
		afficher_tank(tank_var);
		break;
		
	case 'E':
		effacer_tank(tank_var);
		tank_var->posx++;
		afficher_tank(tank_var);
		break;
		
	case 'O':
		effacer_tank(tank_var);
		tank_var->posx--;
		afficher_tank(tank_var);
		break;
	}
}
