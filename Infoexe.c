#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "infoExe.h"
#define MAX_SIZE 10000



void fillInfoConsole(int type,char* special)//Fonction qui écrit dans le log les différentes informations sur l'exéuction de la mise en veille
{	

	FILE* frame = NULL;
	frame = fopen("texte.txt","a");
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	int i =0;


	infoConsole infos;
	//Infos sur la date
	infos.dateJour=(tm.tm_mday);
	infos.dateMois=(tm.tm_mon +1);
	infos.dateAnnee=(tm.tm_year + 1900 );
	infos.dateHeure=(tm.tm_hour);
	infos.dateMin=(tm.tm_min);
	infos.dateSec=(tm.tm_sec);
	
	//Infos sur le type 
	infos.type = type;
	infos.specific = special;
	//printf("%d",type);
//	printf("%s\n",special );
	//Ecriture dans le fichier
	fprintf(frame,"%d/%d/%d %d:%d:%d-%d-%s\n",infos.dateJour,infos.dateMois,infos.dateAnnee,infos.dateHeure,infos.dateMin,infos.dateSec,infos.type,infos.specific);
}

void showInfoConsole()//Fonction qui affiche dans le contenu du fichier log
{

	FILE* frame2 = NULL;
	frame2 = fopen("texte.txt","r");
	char chaine[MAX_SIZE] = "";

	while (fgets(chaine, MAX_SIZE, frame2)!=NULL)
	{
		printf("%s\n",chaine );
	}


}
