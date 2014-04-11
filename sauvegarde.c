 #include "sauvegarde.h"
#include "othello.h"
#include <stdlib.h>


int compteursauv(void)
{
    FILE * fichier = NULL;
    char lettre='a';
    int compteur = 0;
    fichier = fopen("sauvegardes/sauvegarde.save","rt");
    if(fichier == NULL)
        return 0;
        
        while(!feof(fichier))
        {
            fscanf(fichier,"%c",&lettre);
            if(lettre=='#')
                compteur++;
        }
        fclose(fichier);
        
    return compteur;
}
int sauvegardePartie(partie *p)
{
    FILE * fichier = NULL;
    fichier = fopen("sauvegardes/sauvegarde.save","at");
    if(fichier == NULL)
    {
		printf("\nSauvegarde non effectuee\n");
        return 0;
    }
        int i,numSauv = compteursauv()+1;
        fprintf(fichier,"%c",'\n');
        fprintf(fichier,"%s","#Sauvegarde n");
        fprintf(fichier,"%d",numSauv);
        fprintf(fichier,"%c",'\n');
        fprintf(fichier,"%s\n",p->nomJ1);
        fprintf(fichier,"%s\n",p->nomJ2);

        for(i = 0; i < NB_CASES; i++)
            fprintf(fichier,"%d ",p->damier[i]);

        fprintf(fichier,"%c",'\n');
        fprintf(fichier,"%d",p->premierJoueurJoue);
        fprintf(fichier,"%c",'\n');
        fprintf(fichier,"%d",p->boolIa);
        fprintf(fichier,"%c",'\n');
        fclose(fichier);
        printf("Sauvegarde effectuee !\n ");

    return 1;
}

int chargementPartie(partie **p)
{
    FILE * fichier = NULL;
    int nbSauv = compteursauv();
    int i,choix,compteur = 0;
    char letter='a';
    if(!nbSauv)
        printf("Aucune sauvegarde enregistree");
    else
    {
        nbSauv++;
        for(i = 1; i<nbSauv; i++)
            printf("Sauvegarde n° %d\n",i);
        printf("Quelle sauvegarde?\n:");
        do
        {
            scanf("%d",&choix);
        }
        while(choix < 0 && choix > nbSauv);
    }

    fichier = fopen("sauvegardes/sauvegarde.save","rt");
    if(fichier == NULL)
    {
        printf("\nImpossible d'ouvrir la sauvegarde\n");
        return 0;
    }
        while(compteur != choix)
        {
            fscanf(fichier,"%c",&letter);
            if(letter == '#')
                compteur++;
        }
        while(letter != '\n')
            fscanf(fichier,"%c",&letter);
        fscanf(fichier,"%s",(*p)->nomJ1);
        fscanf(fichier,"%s",(*p)->nomJ2);
        for(i = 0; i < NB_CASES; i++)
            fscanf(fichier,"%d",(*p)->damier+i);
        fscanf(fichier,"%d",(&(*p)->premierJoueurJoue));
        fscanf(fichier,"%d",(&(*p)->boolIa));
        fclose(fichier);
        printf("Chargement terminee !\n\n ");
    

    return 1;

}


