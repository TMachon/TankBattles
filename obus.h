
typedef struct obus obus;
struct obus
{
	char Direction ; /*N => Nord, S => Sud, E => EST, O => OUEST*/
	int posx; /*Position courante X de l'obus*/
	int posy; /*Position courante Y de l'obus*/
	struct tank* Origine; /*Pointeur vers le tank qui a tiré l'obus*/
	int Timing; /*Permet d'afficher l'obus pas a pas*/
};

void initier_obus(obus* obus_var, tank* tank_var);
void definir_emplacement_obus(obus* obus_var);
void tirer_obus(obus* obus_var);