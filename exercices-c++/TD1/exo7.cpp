#include <iostream>

int fonction_7(int *unPtM, char const *unPtC)
{
    std::cout << *unPtM << '\t' << *unPtC << '\t' << *(unPtC + 3) << '\n';
    char leC('1');
    return *unPtM + *(unPtC + 1) + leC;
}
int main()
{
    std::cout << "exercice 2 : Pointeurs \n";
    char const* leS = "ALGRITHMES";
    int leI = 4;
    std::cout << "resultat fonction_2 : " << fonction_7(&leI, leS) << '\n';
    std::cout << std::endl;
    return 0;
}