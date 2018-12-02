
typedef struct tank tank;
struct tank
{
	char Direction ; /*N => Nord, S => Sud, E => EST, O => OUEST*/
	int posx; /*Position courante coin gauche X du tank*/
	int posy; /*Position courante coin gauche Y du tank*/
	int Blindage; /*niveau de blindage en cours du tank 0 => rien, 1 => blindé, 2 => ultra-blindé)*/
	int Blindage_orig; /*Blindage d’origine*/
	int Touches; /*Nombre de fois que le tank est touché*/
	char Type; /*’j’ => joueur, ’E’ => tank ennemi*/
	int Etat; /*État du tank 1 => actif, 2 => en destruction, 3 => inactif*/
	
	/*Carrosseries du tank, servira pour l’affichage du tank à tout moment*/
	char carrosserie_h [NB_L_TANK][NB_C_TANK];
	char carrosserie_b [NB_L_TANK][NB_C_TANK];
	char carrosserie_d [NB_L_TANK][NB_C_TANK];
	char carrosserie_g [NB_L_TANK][NB_C_TANK]; 
	
	//int Mise_a_jour; /*utile pour la suppression du tank en tenant compte d’un delay*/
	//struct tank* NXT; /*Pointeur vers un prochain tank*/
};

void charger_carrosserie(tank* tank_var);
void initier_tank_joueur(tank* tank_var);
void initier_tank_ennemi(tank* tank_var, char direction, int pos_x, int pos_y, int blindage);
void afficher_tank(tank* tank_var);
void effacer_tank(tank* tank_var);
void tourner_tank(tank* tank_var, char dir);
void deplacer_tank(tank* tank_var, char dir);