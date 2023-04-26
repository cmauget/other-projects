#include "backtrack.h"


/* Fonction qui vérifie que la couleur c peut être attribuée au sommet   s*/
int checkColor(int s, GRAPH g, int c)
{
  int i;
  for (i=0;i<g.taille;i++) /*On boucle sur tous les sommets du graphe*/
  {
    if ( (g.adj[s][i] == 1) &&  (c == g.color[i]) ) /*Si il y'a connection entre le sommet s et i et que le sommet i est déjà de la couleur souhaitée, on renvoie faux*/
      return 0;
  }
  return 1; /* Sinon on renvoie vrai, la couleur est valide*/

}


/* Fonction récursive utilisée dans la résolution du problème par Backtracking*/
int backtrack_recursive(GRAPH g , int k, int s)
{
  int c; /*Entier qui va servir a représenter les différentes couleurs testées*/

  if (s==g.taille){
    affichecolor(g);//Cas terminal si le sommet s est égal à la taille effective du tableau d'adjacence, on a fini d'attribuer une couleur à tous les sommets, on renvoie vrai
    return 1;
}
  for (c=1; c<=k ; c++)
  {
    if ( checkColor(s,g,c) == 1) /* On regarde si la couleur c est possible pour le sommet s*/
    {

      g.color[s] = c;
       /* Si la couleur est valide, on l'attribue au sommet s*/

      if ( backtrack_recursive(g,k,s+1) == 1 ) /*On passe au sommet suivant dans un appel récursif*/
        return 1;


      g.color[s]= 0; /*Si à un moment dans l'arbre la couleur choisie n'est plus valide, on remet la couleur à 0 et on essaye une autre branche de l'arbre*/
    }
  }

  return 0; /*Dans le cas où c est égal à k et que la fonction n'a pas déjà retourné Vrai, on a épuisé toutes les possibilités, donc on retourne faux*/
}


/*Fonction principale pour la résolution qui sert surtout à initialiser correctement notre fonction récursive*/
int backtrack_color(GRAPH g, int k)
{
  int i;
  for (i=0;i<g.taille;i++)

    g.color[i]=0; /* On commence par initialiser toutes les couleurs de sommet à 0 (pas de couleur) */


  if ( backtrack_recursive(g,k,0) == 0 ) /* On applique la fonction récursive en commençant par le sommet 0*/
  {
    printf("Pas de solution!\n");
     /* Cas ou aucune solution n'a été trouvée par notre fonction*/
    return 0;
  }


  printf("Solution trouvée!\n");
   /* Si la fonction n'a pas retourné faux, on affiche la solution trouvée (qui n'est pas forcément unique!) et on retourne vrai*/
  return 1;
}

void affichecolor(GRAPH graph){ /*Meme fonction que dans l'algorithme naïf servant à afficher la solution si elle existe*/
  int j,n;
  n=graph.taille;
  printf("La coloration est : \n");
  for (j=0;j<n;j++){
    printf("| %d | \n", graph.color[j]);
  }
}
