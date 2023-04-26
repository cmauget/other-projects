#include <iostream>
int main ( )
{
int leB = 0;
int leA ;
leA = 3;

if( leA != 3) 
{
    leA = leA + 1;
}
else
{
    leA = leA - 1;
}

std::cout << leA << std::endl ;

for( leA = 0;  leA < 5; leA = leA + 1) ;
{
    std::cout << leA << ":" << leB << std::endl ;
}

std::cout << leA << std::endl ;

do
{
    leA = leA - 1;
} while (leA > 3);

std::cout << leA << std::endl ;
std::cout<<" Saisir une valeur pour leA : ";

std::cin >> leA; std::cin.ignore();

if (leA%2 == 0)
{
    std::cout << leA << std::endl ;
    std::cout << "C'est la fin" << std::endl;
}
}