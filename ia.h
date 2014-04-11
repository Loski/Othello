#ifndef IA
#define IA

int priseDansDirectionPossibleIA(partie *p, int ligne, int colonne, int horizontal,int vertical);
void coupValideIA(partie *p, int ligne, int colonne);
int meilleurCoup(partie *p);
int tourJoueurIA(partie *p);

#endif // IA
