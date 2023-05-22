#include "../include/Site.hpp"

Site::Site(const bool& c) : classe(c) {

}

void Site::AjouterBatiment(Batiment* Batiment) {
    listeBatiment.push_back(Batiment);
}

bool Site::retirerBatiment(int num) {
    bool test(true);
    list<Batiment*>::iterator i=listeBatiment.begin();
    while((i != listeBatiment.end()) && (test)){
        //std::cout << "test : " << (*i)->getNumero() << std::endl;
        if ( (*i)->getNumero() == num ){
            listeBatiment.erase(i);
            test = false;
            
        } 
        i++;
    }
    return !test;
}

Batiment* Site::operator[](int i){
    Batiment* ptr = nullptr;
    int count(0);
    list<Batiment*>::iterator it= listeBatiment.begin();
    while(it != listeBatiment.end()){
        if (count==i){
            ptr = *it;
        }
        it++;
        count++;
    }
    return ptr;
}


ostream& operator<<(ostream &os, Site& s) {
    list<Batiment*>::iterator i= s.listeBatiment.begin();
    while(i != s.listeBatiment.end()){
        os << **i;
        i++;
    }

    return os;
}


