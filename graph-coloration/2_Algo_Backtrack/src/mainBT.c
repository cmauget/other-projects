#include <stdio.h>
#include <stdlib.h>
#include "backtrack.h"
#include <time.h>
#include <sys/time.h>

//Fonction permettant de calculer le temps d'éxécution:
float time_diff2(struct timespec *start, struct timespec *end)
{
  return (end->tv_sec - start->tv_sec) + 1e-9*(end->tv_nsec - start->tv_nsec); //On ajoute la différence des secondes avec la différence de n-ieme de secondes
}

/* NOTE : Etant débutants avec les fonction de <time.h>, nous avons préféré les utiliser directement dans le main comme vu en cours de calcul
scientifique plutôt que dans un fichier séparé. */



int main() {

  struct timespec start; //Heure de début de l'execution
  struct timespec end; //Heure de fin de l'éxécution

  int k,n;
  GRAPH g;


  printf("Entrez la taille de votre graphe : \n");
  scanf("%d",&n); //On récupère la taille du graphe.


  printf("Entrez la coloration de votre graphe : ");
  scanf("%d",&k); //On récupère le k.

  g=initgraph(n);

  printf("Le graph est : \n");
  affichegraph(g);


  clock_gettime(CLOCK_REALTIME, &start); //On récupère l'heure de début
  backtrack_color(g,k); //Application de l'algorithme Backtracking


  clock_gettime(CLOCK_REALTIME, &end); //On récupère l'heure de fin

  printf("Temps d'éxécution: %0.8f sec\n",time_diff2(&start,&end)); //Affichage du temps d'éxécution
}
