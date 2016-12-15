#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include "random.h"
#include "infoExe.h"
#include "modeStatique.h"
#include "lanceurStatique.h"

int lancementStatique()
{

	system("clear");
	int numberExiaSaver = generateRandom(1,1);
	char tailleImage[25];
	char testImage[2];
	char cheminImage[100];
	char nomImage[25] = "Image";
	char commande[200]; 
	char chemin[100];
	int numberImagePBM ;


DIR *EXIASAVER1_PBM; //EXIASAVER1_PBM : répertoire
		  struct dirent *lecture;

		  FILE* image = NULL;

		  
		  EXIASAVER1_PBM = opendir("/home/xavier/Images/EXIASAVER1_PBM");//On ouvre le répertoire 





		  if (EXIASAVER1_PBM == NULL)//Si le répertoire est vide alors le programme renvoie un message d'erreur
		  {
		    perror ("Problème ouverture EXIASAVER1_PBM\n");
		    exit(1);
		  }
		  
		  else if (EXIASAVER1_PBM != NULL)//Si le répertoire n'est pas vide 
		  {
		   
		  
		  numberImagePBM = generateRandom(1,8);//Le programme le parcourt et génère un nombre aléatoire


		    sprintf(cheminImage,"/home/xavier/Images/EXIASAVER1_PBM/Image%d.pbm",numberImagePBM);//On remplit la variable avec le chemin vers une image
		    
		    closedir(EXIASAVER1_PBM);


		fillInfoConsole(1,cheminImage);//On envoie les informations du mode de veille(type de mise en veille,chemin) dans le fichier log
		
		strcpy(commande,"/home/xavier/Documents/codeProjet/CodeProjet/modeStatique ");//On envoie à commande le chemin vers le programme qu'on veut exécuter
		
		strcat(commande, cheminImage);
		
		//printf("%s\n",commande );
		
		system(commande);//On fait un appel system de commande

		return 0;

		}
}