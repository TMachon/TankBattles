
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

typedef struct obus obus;
struct obus
{
	char Direction ; /*N => Nord, S => Sud, E => EST, O => OUEST*/
	int posx; /*Position courante X de l'obus*/
	int posy; /*Position courante Y de l'obus*/
	struct tank* origine; /*Pointeur vers le tank qui a tiré l'obus*/
};

void initier_obus(obus* obus_var, tank* tank_var) {
	obus_var->Direction = tank_var->Direction;
	obus_var->origine = tank_var;
	switch (tank_var->Direction) {
		
		case 'N':
		obus_var->posx = tank_var->posx+4;
		obus_var->posy = tank_var->posy-1;
		break;
		
		case 'S':
		obus_var->posx = tank_var->posx+4;
		obus_var->posy = tank_var->posy+5;
		break;
		
		case 'E':
		obus_var->posx = tank_var->posx+9;
		obus_var->posy = tank_var->posy+2;
		break;
		
		case 'O':
		obus_var->posx = tank_var->posx-1;
		obus_var->posy = tank_var->posy+2;
		break;
	}
}

void tirer_obus(obus* obus_var, char ** map) {
	int i=0;
	int j=0;
	int stop=0; //faux
	
	while (stop == 0) {
		switch (obus_var->Direction) {
		
		case ('N') :
			printf(" ");
			i--;
			if (map[obus_var->posy-1][obus_var->posx] != ' ') stop++;
			break;
		
		case ('S') :
			printf(" ");
			i++;
			if (map[obus_var->posy+1][obus_var->posx] != ' ') stop++;
			break;
		
		case ('E') :
			printf(" ");
			j++;
			if (map[obus_var->posy][obus_var->posx+1] != ' ') stop++;
			break;
		
		case ('O') :
			printf(" ");
			j--;
			if (map[obus_var->posy][obus_var->posx-1] != ' ') stop++;
			break;
		}
		curseur(1+obus_var->posy+i, 1+obus_var->posx+j);
		printf("+");
	} 
}