lancement: TankBattles EXEC clean
	
map.o : map.c
	gcc -c -Werror -Wall map.c

fichier.o : fichier.c map.o
	gcc -c -Werror -Wall fichier.c
	
tank.o : tank.c fichier.o
	gcc -c -Werror -Wall tank.c

jeu.o : jeu.c tank.o
	gcc -c -Werror -Wall main.c
	
TankBattles : jeu.o
	gcc -Werror -Wall jeu.o -o run
	
EXEC :
	./run
	
clean : TankBattles
	rm -rf *.o
