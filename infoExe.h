#ifndef _INFOEXE_H_INCLUDED
#define _INFOEXE_H_INCLUDED
typedef struct InfoConsole infoConsole;
//typedef struct planeEmplacement planeEmplacement;

//Structure qui va récupérer les informations pour remplir le fichier log
struct InfoConsole 
{
	int dateJour;
	int dateMois;
	int dateAnnee;
	int dateHeure;
	int dateMin;
	int dateSec;
	int type;//Type de mise en veille exécuté
	char* specific;//
	char name[50];
	//*planeEmplacement emplacement;**/

};

void fillInfoConsole(int , char* );
void showInfoConsole ();


/*struct planeEmplacement
{
	int columns;
	int lines;
};*/
#endif