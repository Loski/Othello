#include <stdlib.h>
#include  <string.h>
#include "sauvegarde.h"
#include "menu.h"
#include "partie.h"
#include "joueur.h"

int menu(partie *p)
{
	int choixJ;

		do
		{
			printf("-------------Menu------------\n");
			printf("Voulez vous :\n");
			printf("	-Quitter le jeu (0) \n");
			printf("	-Commencer une nouvelle partie (1) \n");
			printf("	-Charger une sauvegarde (2) \n");
			if (p!=NULL)
			{
				printf("	-Sauvegarder la partie (3) \n");
				printf("	-Reprendre la partie et quittez le menu (4) \n");
			}
			printf("\n:");
			scanf("%d",&choixJ);
		}while( (choixJ<0) || (choixJ>4) || (choixJ>2 && p==NULL) );

	return choixJ;
}

void menu_select(partie *p)
{
	switch(menu(p))
	{
		case 0:
			exit(1);
			break;
		case 1:
		{
			if (p!=NULL)
				free(p);
			
		    char ia;
		    printf("\nVoulez vous jouer contre l'ordinateur?\n(y)\(n)\n");
		    do
		    {
                scanf("%c",&ia);
		    }while(ia!='n' && ia !='y');
		    
		    partie* nvPartie = creerPartie();
		    
		    if(ia == 'y')
            {
                nvPartie->boolIa = 1;
                char nom[] = "Intelligence_Artificielle";
                strcpy(nvPartie->nomJ2,nom);
            }
            else
            {
                printf("Nom du Joueur 2: ");
                scanf("%s",nvPartie->nomJ2);
                nvPartie->boolIa = 0;
            }
            
            printf("Pour jouer : [ligne][colonne] Exemple:a1\n");
            printf("Pour abandonner la partie : 'A'\n");
            printf("Pour retourner au menu : 'M'\n\n");
            
			if(jouerPartie(nvPartie)==0)
				menu_select(nvPartie);
				
			break;
		}
		case 2:
		if (p!=NULL)
		{
			if(chargementPartie(&p))
			{
					if(jouerPartie(p)==0) //Le joueur accède au menu
						menu_select(p);
					else
						menu_select(NULL); //Abandon ou fin de partie
			}
			
			else
				menu_select(p); //Retour au menu
		}

		else
		{
			partie * nvPartie = malloc(sizeof( partie));
			if(chargementPartie(&nvPartie))
			{
				if(jouerPartie(nvPartie)==0)
					menu_select(nvPartie);
				else
					menu_select(NULL);
			}
			
			else
				menu_select(p); //Retour au menu

		}
			break;
		case 3:
		if(sauvegardePartie(p))
		{
			if(jouerPartie(p)==0)
				menu_select(p);
			else
				menu_select(NULL);
		}
		
		else
				menu_select(p); //Retour au menu
				
			break;
		case 4:
			if(jouerPartie(p)==0)
				menu_select(p);
			break;
		default:
			break;
	}
}
