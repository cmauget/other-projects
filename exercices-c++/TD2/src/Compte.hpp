#ifndef TAMERELOL
#define TAMERLOL

#include <iostream>
#include <string>
#include <vector>

class Compte {

    private:
        static int nbC;
        int numCompte;
        std::vector<std::string> nomTit;

    public:
        float solde;
        Compte(float solde);
        float getSolde();
        void setSolde(float solde);
        void deposer(float ajout);
        void retirer(float retrait);
        int nbComptes();
        int getNumero();
        void ajouterTitulaire(std::string add);
        bool retirerTitulaire(std::string rmv);

};

#endif