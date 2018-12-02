
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

typedef struct obus obus;
struct obus
{
	char Direction ; /*N => Nord, S => Sud, E => EST, O => OUEST*/
	int posx; /*Position courante coin gauche X de l'obus*/
	int posy; /*Position courante coin gauche Y de l'obus*/
	struct tank* origine; /*Pointeur vers un le tank qui a tiré l'obus*/
};

