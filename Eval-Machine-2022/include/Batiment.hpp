#ifndef Batiment_H
#define Batiment_H

#include <string>
#include <iostream>

using namespace std;

class Site;  // Déclaration anticipée de la classe Site

class Batiment {

    private : 
        static int compteur;
        static int id;

    protected : 
        string nom;
        int surface;
        int numero;
        Site* site;

    public :
        Batiment(const string& nom2);
        ~Batiment();


        void modifNom(const string& nom2);
        void modifSurface(const int& surface2);

        int nbBatiment() const;
        int getNumero() const;
        string getNom() const;


        virtual string getTypeBatiment() const = 0;

        friend std::ostream& operator<<(std::ostream& os, const Batiment& batiment);



};

#endif