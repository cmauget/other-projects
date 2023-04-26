#include <iostream>

void calculMoyenne(double uneDistance, int uneHeure, int uneMinute, double uneSeconde, double& uneMoyenne, double& uneAllure){

    double s = uneHeure*3600 + uneMinute*60 + uneSeconde;

    uneMoyenne = ((uneDistance*1000)/s)*3.6;

    uneAllure = (1/uneMoyenne);
}

void test(){
    double m(0);
    double a(0);
    calculMoyenne(42,1,13,22,m,a);
    std::cout << m << " allure : "<< a << "\n";
    calculMoyenne(0.5,0,41,29,m,a);
    std::cout << m << " allure : "<< a << "\n";
}

int main(){
    test();
    return 0;
}