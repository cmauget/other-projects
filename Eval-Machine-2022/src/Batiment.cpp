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

Batiment::~Batiment()  {
    this->compteur--;
};


int main(int argc, char const *argv[])
{
    Batiment* a = new Batiment("test");
    Batiment* b = new Batiment("test2");
    cout << b->nbBatiment() << endl;
    cout << a->nbBatiment() << endl;

    delete a;

    cout << b->nbBatiment() << endl;

    return 0;
}



