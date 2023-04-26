#include <iostream>

void fonction(std::string p, std::string& q, int* r, double* s)
{
    char c = (*r) + '0'; 
    p = p + '_' + c ;
    q = p + " et " + q ; 
    *r = (*r) * 2 ;
    double h = 0.3 ; 
    *s = (*s) / 2 + h ;
}

void exo5()
{
    std::string d("PROGRAMMATION"), e("LANGAGE_C++"); int f(2);
    double g(7.1);
    std::cout << "d = " << d << ", e = " << e;
    std::cout << ", f = " << f << ", g = " << g << '\n';
    fonction(d, e, &f, &g);
    std::cout << "d = " << d << ", e = " << e;
    std::cout << ", f = " << f << ", g = " << g << '\n';
}

int main()
{
    exo5();
    return 0;
}