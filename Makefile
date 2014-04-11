othello: othello.o couleursTerminal.o joueur.o mouvement.o sauvegarde.o menu.o partie.o ia.o 
	gcc -o othello othello.o couleursTerminal.o joueur.o mouvement.o sauvegarde.o menu.o partie.o ia.o
mouvement.o: mouvement.c othello.h mouvement.h
	gcc -c mouvement.c -o mouvement.o -W -Wall -Wextra 
couleursTerminal.o: couleursTerminal.c couleursTerminal.h
	gcc -c couleursTerminal.c -o couleursTerminal.o -W -Wall -Wextra
joueur.o: joueur.c othello.h joueur.h mouvement.h
	gcc -c joueur.c	-o joueur.o -W -Wall -Wextra
sauvegarde.o: sauvegarde.c sauvegarde.h
	gcc  -c sauvegarde.c -o sauvegarde.o -W -Wall -Wextra
othello.o: othello.c othello.h
	gcc -c othello.c -o othello.o -W -Wall -Wextra
menu.o: menu.c menu.h
	gcc -c menu.c -o menu.o -W -Wall -Wextra
partie.o: partie.c partie.h
	gcc -c partie.c -o partie.o -W -Wall -Wextra
ia.o: ia.c ia.h
	gcc -c ia.c -o ia.o -W -Wall -Wextra
	
