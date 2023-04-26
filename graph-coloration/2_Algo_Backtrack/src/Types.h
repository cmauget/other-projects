//copy de types pour le makefile
#ifndef __TYPES__
#define __TYPES__

#include<stdio.h>

#define TAILLE 50

struct graph{
  int adj[TAILLE][TAILLE]; //Matrice d'adjacence de notre graphe (sommets numérotés de 0 à n-1)
  int color[TAILLE]; //Coloration de chacuns des sommets (0 à n-1)
  int taille; //On représente la couleur par un numéro pour avoir une infinité de couleurs.
};

typedef struct graph GRAPH;


/*---------------COULEURS-------------------*/
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

//Macros servant à l'affichage en couleur dans le terminal

#endif
