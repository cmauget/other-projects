//copy de uses_fonc pour le makefile

#include <stdio.h>
#include "Types.h"
#include "uses_fonc.h"

GRAPH initgraph(int n){
  GRAPH graph;
  int i,j,t;

  graph.taille = n;

  for (i=0;i<n;i++){
    for (j=0;j<n;j++){
      graph.adj[i][j]=-1; //permet de s'assurer que tout est bien initialisé
    }
  }


  for (i=0;i<n;i++){
    for (j=0;j<n;j++){
        if ((i!=j)&&(graph.adj[i][j]==-1)){
           do {
          printf("Le sommet %d est relié au sommet %d ? (1 pour oui, 0 pour non) : ", i,j );
          scanf("%d",&t);
          //printf("%d\n",t );
          } while ((t!=0) && (t!=1));
          graph.adj[i][j]=t;
          graph.adj[j][i]=t;
        }
        else

        //if (graph.adj[i][j]!=1){
        //  graph.adj[i][j]=0;
        //}

        graph.color[i] = -1; // -1 couleur graph par défaut
    }
  }
return(graph);
}

void affichegraph(GRAPH graph){
  int i,j, n;

  n=graph.taille;
//
  for (i=0;i<n;i++){
    printf(RED "|" RESET);

    for (j=0;j<n;j++){
      if (graph.adj[i][j]==-1){
        printf("/ x /");
      } else {
        printf("/ %d /", graph.adj[i][j]);
      }
    }
    printf(RED "|\n" RESET);
  }

}

void affichecolor(GRAPH graph){
  int j,n;
  n=graph.taille;
  printf("La coloration est : \n");
  for (j=0;j<n;j++){
    switch(graph.color[j]){
      case 0 :
        printf(RED "| Sommet %d | \n" RESET, j);
      break;
      case 1 :
        printf(BLU "| Sommet %d | \n" RESET, j);
      break;
      case 2 :
        printf(GRN "| Sommet %d | \n" RESET, j);
      break;
      case 3 :
        printf(BLU "| Sommet %d | \n" RESET, j);
      break;
      case 4 :
        printf(MAG "| Sommet %d | \n" RESET, j);
      break;
      case 5 :
        printf(CYN "| Sommet %d | \n" RESET, j);
      break;
      default :
        printf("| sommet %d, couleur %d | \n", j,graph.color[j]);
    }
  }
}
