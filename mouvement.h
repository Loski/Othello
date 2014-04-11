#ifndef MOUVEMENT_H
#define MOUVEMENT_H
#include "othello.h"
#include "joueur.h"

int appartient(int ligne , int colonne);
int getCase(partie *p, int ligne, int colonne);
void setCase( partie *p, int ligne, int colonne, int val);
int priseDansDirectionPossible(partie *p, int ligne, int colonne, int horizontal,int vertical);
int coupValide(partie *p, int ligne, int colonne);
void mouvementDansDirection(partie *p, int ligne, int colonne, int horizontal,int vertical);
void mouvement(partie *p, int ligne, int colonne);
int joueurPeutJouer(partie *p);

#endif
