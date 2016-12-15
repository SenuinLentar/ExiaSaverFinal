#ifndef _LANCEURDYNAMIQUE_H_INCLUDED
#define _LANCEURDYNAMIQUE_H_INCLUDED
char **readOpti(char nomImage[], int *linesTab, int *columnsTab);
void **loop(char **tab, int *linesTab, int *x);
char *timeReader();
int lancementDynamique();
#endif
