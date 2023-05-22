#include "../include/Batiment.hpp"

int Batiment::compteur = 0;
int Batiment::id = 0;

Batiment::Batiment(const string& nom2) : nom(nom2), surface(0), numero(id++){
    compteur++;
};

void Batiment::modifNom(const string& nom2) {
    this->nom = nom2;
};

void Batiment::modifSurface(const int& surface2) {
    this->surface = surface2;
}

int Batiment::nbBatiment() const{
    return this->compteur;
};

int Batiment::getNumero() const {
    return this->numero;
}

std::string Batiment::getNom() const {
    return this-> nom;
}



Batiment::~Batiment()  {
    this->compteur--;
};

/**
string Batiment::getTypeBatiment() const {
    return "IMMEUBLE";
};**/

std::ostream& operator << (std::ostream& os, const Batiment& battiment) {
    os << "BATIMENT N° "<< battiment.numero << " Nom " << battiment.nom << std::endl;

    return os;
}




