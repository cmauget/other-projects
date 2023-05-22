#include "../include/HotelParticulier.hpp"

using namespace std;

string HotelParticulier::getTypeBatiment() const {
    return "HOTEL PARTICULIER";
}
void HotelParticulier::setStanding(const int& s) {
    this->standing = s;
}


