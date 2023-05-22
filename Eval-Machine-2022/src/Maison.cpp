#include "../include/Maison.hpp"

#include <iostream>

Maison::Maison(const string& nom2) : Batiment(nom2), nbEtage() {}

int Maison::nbEtages() const{
    return nbEtage.size();
}

void Maison::ajouteEtage(int surfaceEtage) {
    if ((nbEtage.size()<1) && (surfaceEtage >0)) {
        nbEtage.push_back(surfaceEtage);
        surface += surfaceEtage;
    } else {
        std::cout << "Une maison ne peut avoir qu'un seul étage" << std::endl;
    }
}

int Maison::prevoirGrue() {
    return 0;
}

std::string Maison::getTypeBatiment() const  {
    return "MAISON";
}