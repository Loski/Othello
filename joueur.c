#include "joueur.h"
#include "mouvement.h"
#include "ia.h"
#include <stdlib.h>

void changementJoueur( partie *p)
{
    if (p->premierJoueurJoue)
        p->premierJoueurJoue=0;
    else
        p->premierJoueurJoue=1;
}

int tourJoueur(partie *p)
{
    int ligne,colonne,choixJ;
    if (!joueurPeutJouer(p))
    {
		if(p->premierJoueurJoue)
			printf("%s ",p->nomJ1);
		else
			printf("%s ",p->nomJ2);
		printf("ne peut pas jouer\n");
		changementJoueur(p);
		return 0;
	}

    choixJ = saisieJoueur(p,&ligne,&colonne);
    if(choixJ == 1)
    {
        mouvement(p,ligne,colonne);
    }

    return choixJ;
}
int gagnant(partie *p)
{
    int i,j,compNoir = 0,compBlanc =0;
    for(i = 0; i<NB_CASES_PAR_LIGNE; i++)
        for(j = 0; j< NB_CASES_PAR_LIGNE; j++)
            if(getCase(p,i,j) == NOIR)
                compNoir++;
            else if(getCase(p,i,j) == BLANC)
                compBlanc++;
    if(compBlanc>compNoir)
        return -1;
    else if(compNoir>compBlanc)
        return 1;
    else
        return 0;
}

int finPartie (partie *p)
{
    if(!joueurPeutJouer(p))
    {
        changementJoueur(p);
        if(!joueurPeutJouer(p))
            return 1;
        else
            changementJoueur(p);
    }
    return 0;
}
int jouerPartie (partie *p)
{
    int joueurGagnant;
    int fin;
    do
    {   if(p->boolIa)
            fin=tourJoueurIA(p);
        else
            fin=tourJoueur(p);
        if(fin==-1)	//acces au menu
			return 0;
    }
    while(!finPartie(p) && fin!=-2); // -2 correspond à un abandon

    /**************AFFICHAGE********/
    affichage_difficile(p);
    //affichageWin(p);

    if(fin!=-2)
    {
		joueurGagnant = gagnant(p);
		switch(joueurGagnant)
		{
		case -1:
			printf("Le joueur %s a gagné\n",p->nomJ2);
			break;
		case 0:
			printf("Egalité !\n");
			break;
		case 1:
			printf("Le joueur %s a gagné\n",p->nomJ1);
		default:
			break;
		}
	}

	else
		printf("Abandon\n");

	free(p);
	return 1;

}
int saisieJoueur (partie *p,int *ligne, int *colonne)
{
    char choixRep[3];
    do
    {
        affichage_difficile(p);
        /****************AFFICHAGE***************/
        //affichageWin(p);
        if(p->premierJoueurJoue)
            printf("%s",p->nomJ1);
        else
            printf("%s",p->nomJ2);
        printf(" à toi de jouer !\n");
        printf("Jouer la case: ");
        scanf("%s",choixRep);
    }
    while(!choix(p,ligne,colonne,choixRep));
    return choix(p,ligne,colonne,choixRep);
}

int choix(partie *p,int *ligne,int *colonne,char choixJ[])
{
    int tmpLigne,tmpColonne;
    switch(choixJ[0])
    {
    case 'M':
        return -1;
        break;
    case 'A':
        return -2;
        break;
    default:
        if(choixJ[0] >= 'a' && choixJ[0] <= 'h' && choixJ[1] >= '1' && choixJ[1] < '9')
        {
            tmpLigne = (int)choixJ[0] - 'a';
            tmpColonne = (int)choixJ[1] - '1';
            if(coupValide(p,tmpLigne,tmpColonne))
            {
                *ligne = tmpLigne;
                *colonne = tmpColonne;
                return 1;
            }
            else
            {
				printf("Vous ne pouvez pas jouer cette case : %c%c\n",choixJ[0],choixJ[1]);
                return 0;
            }
        }
        else
        {
			printf("Vous ne pouvez pas jouer cette case : %c%c\n",choixJ[0],choixJ[1]);
            return 0;
        }
        break;
    }
}

