#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "lectureOpti.h"
#include "modeStatique.h"
#include "lectureOptiStatique.h"


int main(int argc, char *argv[])

{	
	char cheminImage[1000];
	strcpy(cheminImage, argv[1]);//Copie le deuxième argument dans le 1er
	
	readOptiStatique(cheminImage);//On appelle la fonction de lecture d'image

	pid_t pid;
	
	pid = fork();//Crée un processus fils
	if(pid == 0)
	{
		execl("/home/xavier/Documents/codeProjet/CodeProjet/testFinal", "xavier", NULL);//Exécution d'un programme qui permet de quitter un processus avec une touche
	}
	else
	{
		wait(NULL);

		return 0;
	}
}