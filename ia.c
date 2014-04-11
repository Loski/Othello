#include "othello.h"
#include "mouvement.h"
#include "joueur.h"
#include "ia.h"

int priseDansDirectionPossibleIA(partie *p, int ligne, int colonne, int horizontal,int vertical)
{
    int pionAdv,pion,i;
    pion = BLANC;
    pionAdv = NOIR;
    for(i = 1; getCase(p,ligne +  horizontal * i ,colonne + vertical * i) == pionAdv && ligne +  horizontal * i >= 0 && colonne + vertical * i >= 0; i++);
    if(getCase(p,ligne +  horizontal * i,colonne + vertical * i) == pion && i!=1)
        return i-1;
    return 0;
}

void coupValideIA(partie *p, int ligne, int colonne)
{
    int i,j,compteur = 0;
    if(!getCase(p,ligne,colonne))
    {
        for(i = -1; i <2; i++)
            for(j = -1 ; j <2; j++)
                compteur+=priseDansDirectionPossibleIA(p,ligne,colonne,i,j);
    }
    if(compteur > p->ia[0])
    {
        p->ia[0] = compteur;
        p->ia[1] = ligne;
        p->ia[2] = colonne;
    }
}

int meilleurCoup(partie *p)
{
    int i,j;
    p->ia[0] = 0;
    for(i = 0; i < NB_CASES_PAR_LIGNE;i++)
        for(j = 0;j < NB_CASES_PAR_LIGNE;j++)
        {
            coupValideIA(p,i,j);
        }
    return p->ia[0];
}
int tourJoueurIA(partie *p)
{
    int ligne,colonne,choixJ = 1;
    if (!joueurPeutJouer(p))
    {
		printf("Le joueur ne peut pas jouer");
		changementJoueur(p);
		return 0;
	}
    if(p->premierJoueurJoue)
    {
        choixJ = saisieJoueur(p,&ligne,&colonne);
            if(choixJ == 1)
                mouvement(p,ligne,colonne);
    }
    else
    {
        if(meilleurCoup(p))
         {
            affichage_difficile(p);
            printf("%s joue en [%c][%d]\n",p->nomJ2,(char)(p->ia[1]+1+'a'),p->ia[2]+1);
            mouvement(p,p->ia[1],p->ia[2]);
         }
    }
    return choixJ;
}
