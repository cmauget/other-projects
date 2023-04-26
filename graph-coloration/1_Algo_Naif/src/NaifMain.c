#include <stdio.h>
#include "uses_fonc.h"
#include "N_Fonc.h"
#include "Types.h"
#include <time.h>
#include <sys/time.h>
//#define premade
#define user_input


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

  int test,k,p,n;
  GRAPH graph;

  p=0;
    test=0;

  #ifdef user_input
  printf("Entrez la taille de votre graphe : ");
  scanf("%d",&n);
  //printf("%d\n",n);

  printf("Entrez la coloration de votre graphe : ");
  scanf("%d",&k);
//  printf("%d\n",k);

  graph=initgraph(n);
  #endif

  #ifdef premade
  int i,j;

  int adj[TAILLE][TAILLE] = {
        { -1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0 },
        { 1, -1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 1, -1, 1, 0, 0, 0, 0, 1, 1, 1 },
        { 0, 0, 1, -1, 1, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 1, -1, 1, 0, 0, 1, 0, 0 },
        { 0, 0, 0, 0, 1, -1, 1, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 1, -1, 1, 1, 0, 0 },
        { 1, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0 },
        { 1, 0, 1, 0, 1, 0, 1, 0, -1, 0, 0 },
        { 0, 0, 1, 0, 0, 0, 0, 0, 0, -1, 1 },
        { 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, -1 },
  };

  for (i=0;i<11;i++){
    for (j=0;j<11;j++){
      graph.adj[i][j]=adj[i][j];
    }
  }

  graph.taille = 11;

  k=3;

  for (i=0;i<11;i++){
    graph.color[i]=-1;
  }
  #endif

  printf("Le graph est : \n");
  affichegraph(graph);

  clock_gettime(CLOCK_REALTIME, &start); //On récupère l'heure de début

  test=graphcolor(graph,k,p);

  if (test==1) {
    printf("La coloration marche ! \n");

  } else {
    printf("La coloration ne marche pas ! \n");
  }

  clock_gettime(CLOCK_REALTIME, &end); //On récupère l'heure de fin

  printf("Temps d'éxécution: %0.8f sec\n",time_diff2(&start,&end)); //Affichage du temps d'éxécution


}
