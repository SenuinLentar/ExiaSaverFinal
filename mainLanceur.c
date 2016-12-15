#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include "lanceurStatique.h"
#include "lanceurSauvegarde.h"
#include "modeStatique.h"
#include "infoExe.h"
#include "lanceurDynamique.h"

void main(int argc,char *argv[])
{


	system("clear");
	char sizeImage[25]="5x3";
	if(argc >1)//On détecte si l'utilisateur a entré un paramètre
	{
		if (strcmp(argv[1],"-1")==0)//Si le paramètre rentré est -1 alors le mode de veille statique se lance
		{
			lancementStatique();
		
		}

		if (strcmp(argv[1],"-2")==0)//Si le paramètre rentré est -2 alors le mode de veille dynamique se lance
		{

			fillInfoConsole(2,sizeImage);
			lancementDynamique();
			//fillInfoConsole(2,sizeImage);
		
		}
		if(strcmp(argv[1],"-random")==0)//Si le paramètre rentré est -random alors le mode de veille est choisi aléatoirement
		{
			lanceurRandom();
		}
	}
	if (argc>1)
	{
		if (strcmp(argv[1],"-stats")==0)//Si le paramètre rentré est -stats alors l'utilsateur peut accéder aux stats/historique des lancements
		{
			
			printf("STATS");
		  // Partie relative au Stat*/
			/*showInfoConsole();*/
			history();
			

		}
	}
}
