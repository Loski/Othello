#ifndef JOUEUR
#define JOUEUR
#include "othello.h"

void changementJoueur( partie *p);
int tourJoueur(partie *p);
int gagnant(partie *p);
int finPartie (partie *p);
int jouerPartie (partie *p);
int saisieJoueur (partie *p,int *ligne, int *colonne);
int choix(partie *p,int *ligne,int *colonne,char choixJ[]);

#endif
