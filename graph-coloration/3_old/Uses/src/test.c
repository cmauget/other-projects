#include "uses_fonc.h"
#include <stdio.h>

void main()
{

int n;
printf("Veuillez entrer le nombre de points du graphe");
scanf("%d",&n);
GRAPH g;
g=initgraph(n);
affichegraph(g);
}
