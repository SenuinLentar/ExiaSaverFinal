#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "random.h"

int generateRandom(int min, int max)//Fonction qui génère un nombre aléatoire qui est appelé plusieurs fois dans le programme
{
	int i=0;
	int n=1;
	time_t t;

	int nbgenere=0;

	srand((unsigned) time (&t));//Permet d'éviter une génération de nombre aléatoire qui se répète 

	for(i=0; i<n; i++)
	{
		nbgenere = 1+rand()% max ;
		//printf("%d\n", nbgenere);
	}
	return nbgenere;
}



