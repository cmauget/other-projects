#include <iostream>
void echange(int* unA, int* unB)
{
int leTemp ;
leTemp = *unA;
*unA = *unB ;
*unB = leTemp ;
std::cout<< unA << " : " << *unA << std::endl;
}

int main ( )
{
int leA , leB ;
leA = 3;
leB = 5;
std::cout << leA << ":" << leB << std::endl;
echange(&leB, &leA );
std::cout << leA << ":" << leB << std::endl;
}