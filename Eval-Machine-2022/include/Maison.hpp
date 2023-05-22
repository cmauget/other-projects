#ifndef MAISON_H
#define MAISON_H

#include "Batiment.hpp"
#include <string>

#include <vector>

using namespace std;

class Maison : public Batiment{

    private :

        vector<int> nbEtage;

    public :

        Maison(const string& nom2);

        int nbEtages() const;
        void ajouteEtage(int surfaceEtage);
        string getTypeBatiment() const override;
        int prevoirGrue() override;
};

#endif