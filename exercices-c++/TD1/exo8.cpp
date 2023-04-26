#include <iostream>

int main()
{
int val;
std::cout << "Entrez la valeur : ";
std::cin >> val;
std::cin.ignore();

if (val%2 == 0){
    val = val/2;
}
else {
    val = val*4;
}

std::cout << "La nouvelle valeur est "<<val<< "\n";
}