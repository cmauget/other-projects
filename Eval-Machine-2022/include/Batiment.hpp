#ifndef Batiment_H
#define Batiment_H

#include <string>
#include <iostream>

using namespace std;

class Batiment {

    private : 
        static int compteur;
        static int id;

    protected : 
        string nom;
        int surface;
        int numero;

    public :
        Batiment(const string& nom2);
        ~Batiment();

        void modifNom(const string& nom2);
        void modifSurface(const int& surface2);
        int nbBatiment() const;



};

#endif