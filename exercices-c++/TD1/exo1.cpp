#include <iostream>

void fonct_1()
{ std::cout << "appel de la fonction n°1 " << '\n'; return; }

void fonct_3()
{std::cout << "appel de la fonction n°3 " << '\n'; fonct_1();}

void fonct_2()
{ std::cout << "appel de la fonction n°2 " << '\n'; fonct_3(); }

void exo1()
{
std::cout << '\n' << "Exo 1 : Fil d'execution" << '\n';
int laValeur(0);
std::cout << "Entrez un nombre entre 5 et 100 ? ";
std::cin >> laValeur; std::cin.ignore();
switch(laValeur)
{
case 50 :
{
std::cout << "Cas 50 : valeur " << laValeur << '\n';
fonct_3();
}
case 5 :
case 10 :
{
std::cout << "Cas 5 ou 10 : valeur " << laValeur << '\n';
if (laValeur == 5) fonct_1();
else fonct_3();
break;
}
case 25 :
case 100 :
{
std::cout << "Cas 25 ou 100 : valeur " << laValeur << '\n';
fonct_2();
break;
}
std::cout << "je suis passe par 25" << '\n';

std::cout << "je suis passe par 50 !! \n";
default :
std::cout << "Cette valeur n'est pas prise en compte !! " << '\n';
}
}
int main()
{
exo1();
return 0;
}