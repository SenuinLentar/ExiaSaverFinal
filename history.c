#include <stdio.h> // Cette bibliothèque renferme les routines de traitement d'entrée/sortie fichier.
#include <stdlib.h> // Cette bibliothèque renferme les routines Standard.
#include <sys/types.h> // Cette bibliothèque renferme les définitions de temps pour Unix.
#include <unistd.h> // Cette bibliothèque renferme les types et les constantes symbole standard.
#include <string.h> // Cette bibliothèque renferme les routines de traitement de chaine de caractères.

/* Déclaration des variables de type define */
#define TAILLE_MAX 1000 // Tableau de taille 1000
#define TRUE 1; // Attribut la valeur 1 à la variable "TRUE"  
#define FALSE 0; // Attribut la valeur 0 à la variable "FALSE"  

/* Algorithme de tri simple à bulle  */
void tri_a_bulle(int *tableau, int const n)
{
 	int j   = 0; /* Variable de boucle */
 	int tmp = 0; /* Variable de stockage temporaire */

	/* Booléen marquant l'arrêt du tri si le tableau est ordonné */
	int en_desordre = TRUE;
	/* Boucle de répétition du tri et le test qui
	 arrête le tri dès que le tableau est ordonné(en_desordre=FALSE) */
	while (en_desordre)
	{
		/* Supposons le tableau ordonné */
		en_desordre = FALSE;
		/* Vérification des éléments des places j et j+1 */
		for (j = 0; j < n-1; j++)
		{
			/* Si les 2 éléments sont mal triés */
			if(tableau[j] > tableau[j+1])
			{
				/* Inversion des 2 éléments */
 				tmp = tableau[j+1];
 				tableau[j+1] = tableau[j];
 				tableau[j] = tmp;
				
				en_desordre = TRUE; //Le tableau n'est toujours pas trié
 			}
		}
	}
}

void history() 
{
	/* Déclaration de la variable */
    char str[50];
    do
    {
		
		/* Affichage visuel de la commande -stats */
        system("clear");								// Efface le contenu de la console
        printf("\t\t ----------------------------\n");
        printf("\t\t- Affichage des statistiques -\n");
        printf("\t\t ----------------------------\n\n");
        printf("1 - Statistiques sur le nombre de types d'ecrans lances\n");
        printf("2 - Affichage du contenu du fichier 'texte.txt'\n");
        printf("3 - Retour\n\n");
        printf("-----------------\n");
        printf("Votre choix : ");
        gets(str);									//lit une ligne depuis stdin et la stocke dans "str"
        printf("-----------------\n");
    } while(strcmp (str,"1") != 0 && strcmp (str,"2") != 0 && strcmp (str,"3") != 0);   // La boucle attend que l'utilisateur entre "1", "2", "3" dans le terminal
																						//cf. Porte logique NON-ET
		/* Compare avec l'entrée saisie */
        if (strcmp(str, "1") == 0)
        {
			/* Déclaration des variables */
            int nbStatique = 0;
            int nbDynamique = 0;
            int nbInteractif = 0;
            int c;
			
			system("clear");					// Efface le contenu de la console
			
            FILE * pFile;
            pFile=fopen ("texte.txt","r");
            if (pFile==NULL) perror ("Error opening file");
            else
            do {
              c = fgetc (pFile);
                if (c == '-')
                {
                 c = fgetc (pFile);
                    if (c == '1')
                    {
                        nbStatique++;
                    }
                    else if (c == '2')
                    {
                        nbDynamique++; //
                    }
                    if (c == '3')
                    {
                        nbInteractif++;
                    }

                }
            } while (c != EOF);
            fclose (pFile);
			
			/* Déclaration des variables */
			int tableau[3]={nbStatique, nbDynamique, nbInteractif};
			char* premierType;
            char* deuxiemeType;
            char* troisiemeType;
			
            tri_a_bulle(tableau, 3);
			
			// Correspond à la première case du tableau
            if (tableau[0] == nbStatique)
            {
                premierType="statique";
            }
            else if (tableau[0] == nbDynamique)
            {
                premierType="dynamique";
            }
            else
            {
                premierType="interactif";
            }

            // Correspond à la deuxième case du tableau
            if (tableau[1] == nbStatique)
            {
                deuxiemeType="statique";
            }
            else if (tableau[1] == nbDynamique)
            {
                deuxiemeType="dynamique";
            }
            else
            {
                deuxiemeType="interactif";
            }
            
			// Correspond à la troisième case du tableau
            if (tableau[2] == nbStatique)
            {
                troisiemeType="statique";
            }
            else if (tableau[2] == nbDynamique)
            {
                troisiemeType="dynamique";
            }
            else
            {
                troisiemeType="interactif";
            }
            
            printf("\t -----------------------------------------------------\n");
            printf("\t- Statistiques sur le nombre de types d'ecrans lances -\n");
            printf("\t -----------------------------------------------------\n\n\n");
			
            float ntotal = 0.0;
            float pourcentagePremierType = 0.0;
            float pourcentageDeuxiemeType = 0.0;
            float pourcentageTroisiemeType = 0.0;

            ntotal = nbStatique + nbDynamique + nbInteractif;

            pourcentageTroisiemeType = (tableau[2] / ntotal) *100.0;
            pourcentageDeuxiemeType = (tableau[1] / ntotal) *100.0;
            pourcentagePremierType = (tableau[0] / ntotal) *100.0;
            printf("> - Le mode le plus lance est %s avec %.0f %% ", troisiemeType, pourcentageTroisiemeType); 
            printf("\n-------------------------------------------------\n");
            printf("- %s avec %.0f %% .\n", deuxiemeType, pourcentageDeuxiemeType);
            /*printf("- %s avec %.0f %% .\n", premierType, pourcentagePremierType);*/
		
            do
            {
                printf("\nAppuyer sur (1) pour retourner en arrière : ");
                gets(str);

                if ((strcmp(str, "1") == 0))
                {
                    history();
                }

            } while(strcmp (str,"1") != 0);
        }
        else if (strcmp(str, "2") == 0)
        {
            system("clear");															// Efface le contenu de la console
			
            printf("\t\t--------------------------------------------------\n");
            printf("\t\t- Affichage du contenu du fichier 'historique.txt'-\n");
            printf("\t\t---------------------------------------------------\n\n");

            FILE* fichier = NULL;
            char chaine[TAILLE_MAX] = ""; // Chaîne vide de taille TAILLE_MAX
            fichier = fopen("texte.txt", "r");

                if (fichier != NULL)
                {
                    while (fgets(chaine, TAILLE_MAX, fichier) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
                    {
                        printf("%s", chaine); // On affiche la chaîne qu'on vient de lire
                    }
                    fclose(fichier);
                }
            //
                do
                {
                    printf("\nAppuyer sur (1) pour retourner en arrière : ");

                    gets(str);
                    if ((strcmp(str, "1") == 0))
                    {
                        history();
                    }

                } while(strcmp (str,"1") != 0);
        }
        else if (strcmp(str, "3") == 0)
        {
			system("clear");
        }
}
