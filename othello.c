#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

#include "othello.h"
#include "couleursTerminal.h"
#include "joueur.h"
#include "mouvement.h"
#include "menu.h"

void score(partie *p)
{
    int i;
    p->scoreJ1 = p->scoreJ2 = 0;
    for (i = 0; i < NB_CASES ; i++)
    {
        if (p->damier[i] == NOIR)
            p->scoreJ1++;
        else if (p->damier[i] == BLANC)
            p->scoreJ2++;
    }
}
void affichageWin(partie * p)
{
    int i,j;
    score(p);
    printf("Score de %s : %d\tScore de %s : %d\n",p->nomJ1,p->scoreJ1,p->nomJ2,p->scoreJ2);
    printf("\t");
    for(i=0; i <NB_CASES_PAR_LIGNE; i++)
        printf("%d\t",1+i);
    printf("\n\n");
    for(i = 0; i<NB_CASES_PAR_LIGNE; i++)
    {
        printf("%c\t"  ,'a'+i);
        for(j = 0; j< NB_CASES_PAR_LIGNE; j++)
        {
            if(p->damier[i*NB_CASES_PAR_LIGNE+j]==-1)
                printf("B\t");
            else if(p->damier[i*NB_CASES_PAR_LIGNE+j]==1)
                printf("N\t");
            else
                printf("-\t");
        }
        printf("\n\n\n");
    }
}
void affichage_difficile(partie * p)
{
    int i,j, couleur=5;
    char lettre='a';
    score(p);
    printf("Score de %s : %d\tScore de %s : %d\n",p->nomJ1,p->scoreJ1,p->nomJ2,p->scoreJ2);
    printf("\n");

    for (i=1; i<=NB_CASES_PAR_LIGNE; i++)
        printf("   %d  ",i);
    printf("\n");
    for (i=0; i<NB_CASES_PAR_LIGNE*2; i++)
    {
        if (!(i%2))
        {
            printf("%c",lettre);
            lettre++;
        }
        else
            printf(" ");
        for (j=0; j<NB_CASES_PAR_LIGNE; j++)
        {
            changerCouleurFondTerminal(couleur);
            if (p->damier[(i/2)*NB_CASES_PAR_LIGNE+j]== BLANC)
            {
                changerCouleurEcritureTerminal(7);
                printf("  BBB ");

            }
            else if (p->damier[(i/2)*NB_CASES_PAR_LIGNE+j]== NOIR)
            {
                changerCouleurEcritureTerminal(0);
                printf("  NNN ");
            }
            else
                printf("      ");
            if (couleur==5)
                couleur=6;
            else
                couleur=5;
        }
        changerCouleursTerminal(9,9);
        printf("\n");
        if (i%2)
        {
            if (couleur==5)
                couleur=6;
            else
                couleur=5;
        }
    }
}

int main()
{
	mkdir("sauvegardes",0777);

	menu_select(NULL);

    return 0;
}
