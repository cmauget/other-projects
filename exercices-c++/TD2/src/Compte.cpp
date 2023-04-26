#include "Compte.hpp"

int Compte::nbC(0);

Compte::Compte(float solde1){
    solde = solde1;
    nbC++;
    numCompte = nbC;
    //nomTit = {};
}

float Compte::getSolde(){
    const float out(solde);
    return out;
}

void Compte::setSolde(float solde){
    this -> solde = solde;
}

void Compte::deposer(float ajout){
    setSolde(solde + ajout);
}


void Compte::retirer(float retrait){
    if (solde <= retrait){
        std::cout << "Impossible de retirer \n";
    }
    else{
        setSolde(solde - retrait);
        std::cout << "Retrait effectué \n"; 
    }
}

int Compte::nbComptes(){
    int const out(nbC);
    return out;
}

int Compte::getNumero(){
    int const out(numCompte);
    return out;
}

void Compte::ajouterTitulaire(std::string add){
    nomTit.push_back(add);
}

bool Compte::retirerTitulaire(std::string rmv){

    int i(0);
    bool test(false);

    for (std::string n : nomTit){
        if (n==rmv){
            std::cout << "Bien supprimé \n";
            nomTit.erase(nomTit.begin() + i);
            test = true;
            i=-1;
        }
        i+=1;

        if (not test){
            std::cout << "Il existe pas ton frerot \n";
        }
    }

    return test;
}