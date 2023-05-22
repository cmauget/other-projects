#include "../include/Batiment.hpp"
#include "../include/Immeuble.hpp"
#include "../include/Maison.hpp"
#include "../include/Site.hpp"

int main() {

    Immeuble t = Immeuble("tour1");
    Maison m = Maison("maison1");
    Site s = Site(true);
    s.AjouterBatiment(&t);
    s.AjouterBatiment(&m);

    cout << t.nbBatiment() << endl;
    cout << m.getNumero() << endl;

    cout << s[0] << endl;

    cout << s[2] << endl;


    cout << s << endl;

    return 0;
}