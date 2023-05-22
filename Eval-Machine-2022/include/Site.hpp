#ifndef SITE_HPP
#define SITE_HPP

class Batiment;

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

        bool getClasse() const;

        Batiment* operator[](int i);

        friend std::ostream& operator<<(std::ostream &os, Site& s);

};

#endif