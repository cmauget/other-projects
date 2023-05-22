#ifndef SITE_HPP
#define SITE_HPP

#include"Batiment.hpp"

#include<iostream>
#include<list>

class Site {

    protected :

        const bool classe;
        std::list<Batiment*> listeBatiment;

    public :

        Site(const bool& c);

        void AjouterBatiment(Batiment* Batiment);
        bool retirerBatiment(int num);

        Batiment* operator[](int i);

        friend ostream& operator<<(ostream &os, Site& s);

};

#endif