#ifndef IMMEUBLE_H
#define IMMEUBLE_H

#include "Batiment.hpp"
#include <string>

#include <vector>

using namespace std;

class Immeuble : public Batiment{

    private :

        vector<int> nbEtage;

    public :

        Immeuble(const string& nom2);

        void setSite(Site* s);
        int nbEtages() const;
        void ajouteEtage(int surfaceEtage);
        string getTypeBatiment() const override;
        int prevoirGrue() override;
};

#endif