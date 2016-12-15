#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include "lanceurDynamique.h"
#include "infoExe.h"

char **readOpti(char nomImage[], int *linesTab, int *columnsTab);//here we initialize the prototypes
void **loop(char **tab, int *linesTab, int *x);
char *timeReader();

int lancementDynamique()
{
	char nomImage0[50], nomImage1[50], nomImage2[50], nomImage3[50], nomImage4[50], nomImage5[50], nomImage6[50], nomImage7[50];
	int  linesTab = 0, columnsTab = 0;
	int x = 0;
	char commande[200];
	system("clear");
	while (1)
	{
		char *heure = timeReader();//here we put the time in the array heure
		//printf("salut");
		//printf("%s\n", heure);
	
	
		sprintf(nomImage0, "/home/xavier/Images/EXIASAVER2_PBM/%i.pbm", heure[x]);//collect the patch of the pictures
		x++;																		//increment x to pass to the next character of the string heure
		sprintf(nomImage1, "/home/xavier/Images/EXIASAVER2_PBM/%i.pbm", heure[x]);
		x++;
		sprintf(nomImage2, "/home/xavier/Images/EXIASAVER2_PBM/%i.pbm", heure[x]);
		x++;
		sprintf(nomImage3, "/home/xavier/Images/EXIASAVER2_PBM/%i.pbm", heure[x]);
		x++;
		sprintf(nomImage4, "/home/xavier/Images/EXIASAVER2_PBM/%i.pbm", heure[x]);
		x++;
		sprintf(nomImage5,"/home/xavier/Images/EXIASAVER2_PBM/%i.pbm", heure[x]);
		x++;
		sprintf(nomImage6, "/home/xavier/Images/EXIASAVER2_PBM/%i.pbm", heure[x]);
		x++;
		sprintf(nomImage7, "/home/xavier/Images/EXIASAVER2_PBM/%i.pbm", heure[x]);
	
		char **tab0 = readOpti(nomImage0, &linesTab, &columnsTab);//call the function readOpi for each character of the string heure
		char **tab1 = readOpti(nomImage1, &linesTab, &columnsTab);
		char **tab2 = readOpti(nomImage2, &linesTab, &columnsTab);
		char **tab3 = readOpti(nomImage3, &linesTab, &columnsTab);
		char **tab4 = readOpti(nomImage4, &linesTab, &columnsTab);
		char **tab5 = readOpti(nomImage5, &linesTab, &columnsTab);
		char **tab6 = readOpti(nomImage6, &linesTab, &columnsTab);
		char **tab7 = readOpti(nomImage7, &linesTab, &columnsTab);
		//char **tab1 = readOpti("/home/maximel/Documents/Maxime/0.pbm", &linesTab, &columnsTab);
		//printf("yo\n");
	
		//puts(nomImage0);
		//x++;
	
	
		for(x = 0; x < columnsTab; x++)//call loop to print each pictures
		{
			loop(tab0, &linesTab, &x);
		
			loop(tab1, &linesTab, &x);
		
			loop(tab2, &linesTab, &x);
		
			loop(tab3, &linesTab, &x);
		
			loop(tab4, &linesTab, &x);
		
			loop(tab5, &linesTab, &x);
		
			loop(tab6, &linesTab, &x);
		
			loop(tab7, &linesTab, &x);
		
			//printf("coucou");
			printf("\n");
		}
		
		int n = 5;
		
		printf("Cet écran sera actualisé dans %d secondes", n);        //Mettre ce message dans la mémoire tampon
		fflush(stdout);         //Forcer l'affichage du message qui était dans la mémoire tampon puis supprimmer cette mémoire

		int sec = 0;
		

		while (sec < n)        //Tant que le temps n'a pas atteint 10 secondes (Timer)
		{
		    sec++;      //Augmente le temps de 1 seconde
		    sleep(1);       // Attendre 1 seconde
		    printf(".");
		    fflush(stdout);
		}
		printf("\n");       //Retour à la ligne
		system("clear");
		x =0;//set x to 0 to be able to run the function an other time
	}	
	//char sizeImage[25]="5x3";
	strcpy(commande,"/home/xavier/Documents/codeProjet/testFinal ");
	//printf("%s\n",commande );
	system(commande);
	//fillInfoConsole(2,sizeImage);
	return 0;
}


char **readOpti(char nomImage[], int *linesTab, int *columnsTab)//function to read a picture and put it into a array
{
	FILE* image = NULL;
	char tableauImage[5000];// = "0"; 
	int i =0, j = 0, linesTab2 = *linesTab, columnsTab2 = *columnsTab;
	char tank[10], columns[5], lines[5];
	const char s[2] = " ";
	char *token;
	int x = 0 , y = 0, saut = 0;
	int columnsWhile = 0, linesWhile = 0;
	char carac , carac0;
	char **tab; //pointeur qui va nous servir de tableau
	int countLine = 0;
	char ecran[24][80];
	int length = 0, width = 0;
	int a = 0, b = 0;
	int countline;
	int countcarac;
	int compteur = 0;
	
	image = fopen(nomImage, "r"); //ouvrir un fichier
	
	if (image != NULL) 
	{	
	
		while (fgets(tableauImage, 5000, image) != NULL)
		{
			if(i==1)
			{
				fgets (tank, 10, image);
				token = strtok(tank, s);
				while(token != NULL)
				{
					if(j == 0)
					{
						strcpy(columns, token);
						token = strtok(NULL, s);
						j++;
					}
					else if(j == 1)
					{
						strcpy(lines, token);
						token = strtok(NULL, s);
					}
				}
			}
			i++;
		}	
		rewind(image);//allows to return to the beginning of the picture
		
		
		columnsTab2 = atoi(columns);
		linesTab2 = atoi(lines);
		
		
		
		tab = malloc(columnsTab2 * sizeof(*tab)); //create an array of the size of the number of character from the picture
		
		
		for(x = 0; x<columnsTab2; x++){
			tab[x] = malloc(linesTab2 * sizeof(**tab));
		}
		
		do //puts the picture in the array tab
		{		
			carac = fgetc(image);
					
			if ( countLine < 3 &&  carac == 10){//ignore the 3 first lines
				countLine++;
				
			}
			else if (countLine >= 3 && (carac == 48 || carac == 49)){//put the character in the aray
				tab[linesWhile][columnsWhile] = carac;
				columnsWhile++;
				
			}

			else if (countLine >= 3 && carac == 10){//allows to corectly browse in the array
				linesWhile++;
				columnsWhile=0;
			}		
		}while(carac != EOF);
		
		
		
		int l = 0;
		int c = 0;
		int oldl = 0;
		
	

	}
	
	else
	{
		printf("Fail ouverture image :/\n");//if the picture isn't open
	}
	
	*linesTab = linesTab2;//allows the main to use the size of the picture
	*columnsTab = columnsTab2;
	return tab;
}

void **loop(char **tab, int *linesTab, int *x)//print the pictures
{
	int y = 0, x2=*x;
	int linesTab3 = *linesTab;//collect one size of the picture
	for(y = 0; y < linesTab3; y++)//browse in the array and then print it
		{
				
			if(tab[x2][y] == 48)
			{
				printf(" ");
			}
			else if (tab[x2][y] == 49)
			{
				printf("\u2588");
			}
		}
}

char *timeReader() //collect the time
{
	int i = 0;
	char *heure;
	
	heure = malloc(8*sizeof(char)); //allocate memory to the array heure
	
	/* Récupérer l'heure courante */
	time_t now = time (NULL);    // La variable "now" contient la date et l'heure courante
	
	struct tm tm_now = *localtime (&now); // Conversion en heure locale
	
	char s_now[sizeof "HH:MM:SS"]; // Creer une chaine JJ/MM/AAAA HH:MM:SS
	
	/* Formater la date et l'heure (Il enregistre la date et l'heure dans la chaine de caractère s_now  */
	strftime (s_now, sizeof s_now, "%H:%M:%S", &tm_now);
	strcpy(heure, s_now);
	//printf("%s", heure);
	
	return heure;
}




