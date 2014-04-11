#ifndef OTHELLO
#define OTHELLO

#define TAILLE_CH 256
#define NB_CASES 64
#define NB_CASES_PAR_LIGNE  8
#define NOIR 1
#define BLANC -1
#define VIDE 0

#include "couleursTerminal.h"


typedef struct
{
    int damier[NB_CASES];
    char nomJ1[TAILLE_CH];
    char nomJ2[TAILLE_CH];
    int premierJoueurJoue;
    int scoreJ1;
    int scoreJ2;
    int ia[3];
    int boolIa;
    /*
    [0] : compteur
    [1] : ordonnée
    [2] : abscisse */
} partie;
void affichageWin(partie * p);
void score(partie *p);
void affichage_difficile(partie * p);




#endif
