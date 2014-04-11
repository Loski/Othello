#include "othello.h"
#include "mouvement.h"

int appartient(int ligne , int colonne)
{
    if (ligne >= 0 && ligne < NB_CASES_PAR_LIGNE && colonne >= 0 && colonne < NB_CASES_PAR_LIGNE)
        return 1;
    return 0;
}

int getCase(partie *p, int ligne, int colonne)
{
    if (appartient(ligne,colonne))
        return p->damier[colonne+NB_CASES_PAR_LIGNE*ligne];
    return 2; //Case invalide
}

void setCase( partie *p, int ligne, int colonne, int val)
{
    if(appartient(ligne,colonne))
        p->damier[colonne+NB_CASES_PAR_LIGNE*ligne]=val;
}


int priseDansDirectionPossible(partie *p, int ligne, int colonne, int horizontal,int vertical)
{
    int pionAdv,pion,i;
    if(p->premierJoueurJoue)
        pion = NOIR;
    else
        pion = BLANC;
    pionAdv = pion * -1;
    for(i = 1; getCase(p,ligne +  horizontal * i ,colonne + vertical * i) == pionAdv; i++);
    if(getCase(p,ligne +  horizontal * i,colonne + vertical * i) == pion && i!=1)
        return 1;
    return 0;
}

int coupValide(partie *p, int ligne, int colonne)
{
    int i,j;
    if(!getCase(p,ligne,colonne))
    {
        for(i = -1; i <2; i++)
            for(j = -1 ; j <2; j++)
                if(priseDansDirectionPossible(p,ligne,colonne,i,j))
                    return 1;
    }
    return 0;
}

void mouvementDansDirection(partie *p, int ligne, int colonne, int horizontal,int vertical)
{

    int pionAdv,pion,i,j;
    if(p->premierJoueurJoue)
        pion = NOIR;
    else
        pion = BLANC;
    pionAdv = pion * -1;
    for(i = 1;getCase(p,ligne +  horizontal * i ,colonne + vertical * i) == pionAdv; i++);
    if(getCase(p,ligne +  horizontal * i,colonne + vertical * i) == pion)
    {
        for(j = 0; j <= i && i!=1 ; j++)
            setCase(p,ligne +  horizontal * j,colonne + vertical * j,pion);
    }

}
void mouvement(partie *p, int ligne, int colonne)
{
    int i,j;
    if(coupValide(p,ligne,colonne))
    {
        for(i = -1; i <2; i++)
            for(j = -1 ; j <2; j++)
                mouvementDansDirection(p,ligne,colonne,i,j);
        changementJoueur(p);
    }
}
int joueurPeutJouer(partie *p)
{
    int i,j;

    for(i = 0; i < NB_CASES_PAR_LIGNE; i++)
        for(j = 0; j < NB_CASES_PAR_LIGNE; j++)
        {
            if(getCase(p,i,j) == VIDE)
            {
                if(coupValide(p,i,j))
                    return 1;
            }
        }
    return 0;
}
