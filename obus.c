
#include "obus.h"
#include "variables_globales.h"

#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

void initier_obus(obus* obus_var, tank* tank_var) {
	obus_var->Origine = tank_var;
	obus_var->Timing = 0;
	definir_emplacement_obus(obus_var);
}

void definir_emplacement_obus(obus* obus_var) {
	struct tank* tank_var = obus_var->Origine;
	obus_var->Direction = tank_var->Direction;
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

void tirer_obus(obus* obus_var) {
	struct tank* tank_var = obus_var->Origine;
	switch (tank_var->Direction) {
	case ('N') :
		if (map[tank_var->posy-1][tank_var->posx+4] != ' ') return;
		if (map[tank_var->posy-2][tank_var->posx+4] != ' ') {
			curseur(1+obus_var->posy, 1+obus_var->posx);
			printf(" ");
			obus_var->posx = tank_var->posx+4;
			obus_var->posy = tank_var->posy-1;
			curseur(1+obus_var->posy, 1+obus_var->posx);
			printf("+");
			return;
		}
		break;

	case ('S') :
		if (map[tank_var->posy+5][tank_var->posx+4] != ' ') return;
		if (map[tank_var->posy+6][tank_var->posx+4] != ' ') {
			curseur(1+obus_var->posy, 1+obus_var->posx);
			printf(" ");
			obus_var->posx = tank_var->posx+4;
			obus_var->posy = tank_var->posy+5;
			curseur(1+obus_var->posy, 1+obus_var->posx);
			printf("+");
			return;
		}
		break;

	case ('E') :
		if (map[tank_var->posy+2][tank_var->posx+9] != ' ') return;
		if (map[tank_var->posy+2][tank_var->posx+10] != ' ') {
			curseur(1+obus_var->posy, 1+obus_var->posx);
			printf(" ");
			obus_var->posx = tank_var->posx+9;
			obus_var->posy = tank_var->posy+2;
			curseur(1+obus_var->posy, 1+obus_var->posx);
			printf("+");
			return;
		}
		break;

	case ('O') :
		if (map[tank_var->posy+2][tank_var->posx-1] != ' ') return;
		if (map[tank_var->posy+2][tank_var->posx-2] != ' ') {
			curseur(1+obus_var->posy, 1+obus_var->posx);
			printf(" ");
			obus_var->posx = tank_var->posx-1;
			obus_var->posy = tank_var->posy+2;
			curseur(1+obus_var->posy, 1+obus_var->posx);
			printf("+");
			return;
		}
		break;
	}
	curseur(1+obus_var->posy, 1+obus_var->posx);
	printf(" ");
	definir_emplacement_obus(obus_var);
	
	int stop = 0; //faux
	do {
		curseur(1+obus_var->posy, 1+obus_var->posx);
		printf(" ");
		switch (obus_var->Direction) {

		case ('N') :
			if (map[obus_var->posy-2][obus_var->posx] != ' ') stop++;
		if (map[tank_var->posy-1][tank_var->posx+4] != ' ') return;
			obus_var->posy--;
			break;

		case ('S') :
			if (map[obus_var->posy+2][obus_var->posx] != ' ') stop++;
		if (map[tank_var->posy+5][tank_var->posx+4] != ' ') return;
			obus_var->posy++;
			break;

		case ('E') :
			if (map[obus_var->posy][obus_var->posx+2] != ' ') stop++;
		if (map[tank_var->posy+2][tank_var->posx+9] != ' ') return;
			obus_var->posx++;
			break;

		case ('O') :
			if (map[obus_var->posy][obus_var->posx-2] != ' ') stop++;
		if (map[tank_var->posy+2][tank_var->posx-1] != ' ') return;
			obus_var->posx--;
			break;
		}
		curseur(1+obus_var->posy, 1+obus_var->posx);
		printf("+");
	} while (stop == 0);
}