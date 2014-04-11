#include "partie.h"
#include <stdlib.h>

partie* creerPartie ()
{
    partie * ptr = NULL;
    ptr = malloc(sizeof( partie));
    if(ptr != NULL)
    {
        printf("Nom du Joueur 1: ");
        scanf("%s",ptr->nomJ1);
        ptr->premierJoueurJoue=1;
        int i;
        for ( i=0; i<NB_CASES; i++)
            ptr->damier[i] = VIDE;
        setCase(ptr,3,3,NOIR);
        setCase(ptr,4,4,NOIR);
        setCase(ptr,3,4,BLANC);
        setCase(ptr,4,3,BLANC);
        return ptr;
    }
    printf("L'allocation dynamique du plateau a échoué.");
    exit(2);
}
