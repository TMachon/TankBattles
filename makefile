lancement: TankBattles EXEC clean
	
TankBattles :
	gcc -Werror -Wall jeu.c -o run
	
EXEC :
	./run
	
clean :
	rm -rf run
