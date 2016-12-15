#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include "random.h"
#include "infoExe.h"
#include "lanceurSauvegarde.h"
#include "modeStatique.h"
#include "lanceurDynamique.h"


int lanceurRandom ()
{
	system("clear");
	int numberExiaSaver = generateRandom(1,2);
	char tailleImage[25];
	char testImage[2];
	char cheminImage[100];
	char nomImage[25] = "Image";
	char commande[200]; 
	char chemin[100];
	int numberImagePBM ;
	
	if(numberExiaSaver == 1)//Si le nombre aléatoire est 1 on lance le mode de veille statique
	{

		//nouveau RANDOM qui ouvre un des 7 fichier PBM proposés

		DIR *EXIASAVER1_PBM; //EXIASAVER1_PBM : répertoire
		struct dirent *lecture;
		FILE* image = NULL;		  
		EXIASAVER1_PBM = opendir("/home/xavier/Images/EXIASAVER1_PBM");

		if (EXIASAVER1_PBM == NULL)
		{
		   perror ("Problème ouverture EXIASAVER1_PBM\n");
		   exit(1);
		 }
		  
		else if (EXIASAVER1_PBM != NULL)
		{
		  	numberImagePBM = generateRandom(1,8);

		  	sprintf(cheminImage,"/home/xavier/Images/EXIASAVER1_PBM/Image%d.pbm",numberImagePBM);
		    
		  	closedir(EXIASAVER1_PBM);
		 
			fillInfoConsole(1,cheminImage);
			strcpy(commande,"/home/xavier/Documents/codeProjet/CodeProjet/modeStatique ");// "/home/xavier/Documents/codeProjet/modeStatique");
			strcat(commande, cheminImage);// + " " + "test";		
			system(commande);//On lance le mode Statique

			return 0;
		}
	}

	else if(numberExiaSaver == 2)//Si le nombre aléatoire est 2 on lance le mode de veille dynamique
	{
		lancementDynamique();//On lance le mode dynamique
		fillInfoConsole(2,tailleImage);
		printf("Ouvre exiasaver2\n");
	}

	else
	{
		printf("Probleme");
	}

	return(0);
}

