#include "Compte.hpp"

int main(){

    Compte test(50);
    test.ajouterTitulaire("Francis");
    test.ajouterTitulaire("Francis");
    test.ajouterTitulaire("Macron");
    test.retirerTitulaire("Francis");
    test.retirerTitulaire("Francis");
    test.retirerTitulaire("Francis");


    
    return 0;
}