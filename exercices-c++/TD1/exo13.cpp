#include <iostream>

int main(){

    const char* mois[4] = { "Janvier", "Fevrier", "Mars", "Avril" };
    int j;
    int m;
    std::string a;

    std::cin>>j; std::cin.ignore();
    std::cin>>m; std::cin.ignore();
    std::cin>>a; std::cin.ignore();

    std::cout<<j<<" "<<mois[m-1]<<" 20"<<a<<"\n";
    return 0;
}