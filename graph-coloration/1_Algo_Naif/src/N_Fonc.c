#include <stdio.h>
#include "N_Fonc.h"
#include "uses_fonc.h"
#include "Types.h"



int checkcolo(GRAPH graph){ //retourne 1 si la colo est bonne, 0 sinon
  int i,j,taille,test;

  taille = graph.taille;

  i=0;
  test=1;

    while((i<taille)&&(test!=0)){
      j=i+1;
      while((j<taille)&&(test!=0)){
      /*  printf("La matrice d'adj : %d\n",graph.adj[i][j]);
        printf("La couleur i: %d\n",graph.color[i]);
        printf("La couleur j: %d\n",graph.color[j]); */
        if ((graph.adj[i][j]==1)&&(graph.color[i]==graph.color[j])){

          test=0;
          return(0);
        }
        j++;
      }
      i++;
    }
    return(test);
}


int graphcolor(GRAPH graph, int k, int p){ //p doit être initialisé a 0
//retourne 1 si vrai, 0 si faux

int test,res,n,i;

  n=graph.taille;
  res=0;

  if (p==n){ // si on atteint le dernier sommet
    test = checkcolo(graph);
    //printf("%d\n",test);
    if (test==1){
      affichecolor(graph);
      res=1;
      return(res);
    }
    return(res);
  }

  for(i=0;i<k;i++){
    graph.color[p]=i;
    test=graphcolor(graph,k,p+1); // on devellope pour le reste des sommets
    if (test==1){
      res=1;
      return(res);
    }
    graph.color[p]=0;
  }
  return(res);
}
