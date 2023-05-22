#ifndef HOTELPARTICULIER_H
#define HOTELPARTICULIER_H

#include"Immeuble.hpp"
#include "Maison.hpp"


using namespace std;

class HotelParticulier : public Maison, public Immeuble {

    protected :
        int standing;

    public :

        string getTypeBatiment() const override;

        void setStanding(const int& s);
};

#endif