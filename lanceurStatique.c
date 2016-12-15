#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lectureOptiStatique.h"


int readOptiStatique(char cheminImage[])//function to read a picture, put it in an array, center it and print it
{
	FILE* image = NULL;
	char *tableauImage; 
	int i =0, j = 0, linesTab = 0, columnsTab = 0;
	char tank[10], columns[5], lines[5];
	const char s[2] = " ";
	char *token;
	int x = 0 , y = 0, saut = 0;
	int columnsWhile = 0, linesWhile = 0;
	char carac;
	char **tab; //pointeur qui va nous servir de tableau
	int countLine = 0;
	char ecran[24][80];
	int length = 0, width = 0;
	int a = 0, b = 0;
	int countline;
	int countcarac;
	int nbcarac = 0;
	
	image = fopen(cheminImage, "r"); //ouvrir un fichier
	
	if (image != NULL) 
	{	
		
		//recupérer la taille de l'image
		while(fgetc(image) != EOF){
			nbcarac++;
		}
		
		//printf("%d",nbcarac);
		
		tableauImage = malloc(nbcarac * sizeof(char));//create an array of the size of the number of character from the picture
		
		rewind(image);//allows to return to the beginning of the picture
		
		while (fgets(tableauImage, nbcarac, image) != NULL)//collect the size of the picture in two char
		{
			if(i==1)
			{
				fgets (tank, 10, image);//get the line in a char
				token = strtok(tank, s);//cut the char
				while(token != NULL)
				{
					if(j == 0)
					{
						strcpy(lines, token);//puts the first parameter of the size in a char
						token = strtok(NULL, s);
						j++;
					}
					else if(j == 1)
					{
						strcpy(columns, token);//puts the second parameter of the size in a char
						token = strtok(NULL, s);

					}
				}
			}
			i++;
		}
		
		rewind(image);
		
		linesTab = atoi(lines);//put the char line into the int linesTab
		columnsTab = atoi(columns);//put the char columns into the int columnsTab
		
		
		//printf("%d %d \n",  linesTab, columnsTab);
		
		tab = malloc(columnsTab * sizeof(*tab)); //allocation d'un tableau de pointeur de 'taille1'
		
		
		for(x = 0; x<columnsTab; x++){
			tab[x] = malloc(linesTab * sizeof(**tab));
		}
		
		for(x=0 ; x<columnsTab ; x++)
		{
			for(y=0 ; y<linesTab ; y++)
			{
				tab[x][y] = '1';
				//printf("%c " , tab[x][y]);
			}
			printf("\n");
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
		
		
		countline = 0;
		countcarac =0;
		
		length = (80 - linesTab)/2 ;//calculate the space between the two array
		width = (24 - columnsTab)/2;
		
		int lengthmax = length + linesTab;//calculate the max size
		int widthmax = width + columnsTab;
		
		
		int l = 0;
		int c = 0;
		int oldl = 0;

		for(l = 0; l < 24; l++){//browse in the array
			for(c = 0; c < 80; c++){
			
				if(c > length && l > width && l <= widthmax && c <= lengthmax)//if we are in the zone were the array picture must be writhen
				{
					if(oldl == 0)
					{
						oldl = l;
					}
					if(oldl != l)
					{
						oldl = l;
						a++;
					}
					ecran[l][c] = tab[a][b];//print the array tab (the picture) in the array ecran
					b++;
					
					
				}
				else
				{
					b=0;
					ecran[l][c] = 48;//fill the array ecran with 0
				}
				
			}
			
			
	
		}
		
		
		for(l = 0; l < 24; l++){ //print the array ecran
			for(c = 0; c < 80; c++){
				
				if(ecran[l][c] == 48){
					printf(" ");
				}
				else if (ecran[l][c] == 49){
					printf("\u2588");
				}
			}
		}

	
	}
	
	else
	{
		printf("Fail ouverture image :/\n");//if the picture isn't open
	}
	return 0;
}

