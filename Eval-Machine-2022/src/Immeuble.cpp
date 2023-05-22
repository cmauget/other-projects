#include "../include/Immeuble.hpp"

#include <iostream>

Immeuble::Immeuble(const string& nom2) : Batiment(nom2), nbEtage() {
    nbEtage.push_back(0);
    nbEtage.push_back(0);
}

int Immeuble::nbEtages() const{
    return nbEtage.size();
}

void Immeuble::ajouteEtage(int surfaceEtage) {
    if ((surfaceEtage >0)) {
        nbEtage.push_back(surfaceEtage);
        surface += surfaceEtage;
    } else {
        std::cout << "La surface doit être > 0" << std::endl;
    }
}

std::string Immeuble::getTypeBatiment() const  {
    return "Immeuble";

}


