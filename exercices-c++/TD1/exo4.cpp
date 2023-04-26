#include <iostream>
int main()
{
char leA ;
leA = 'B' ;
int leIndex;
std::cout << leA << std::endl ;
for (leIndex = 0; leIndex < 3; leIndex = leIndex + 1)
{
std::cout << leA << ":" << leIndex << std::endl;
}
leIndex = 4;
std::cout << leA << ":" << leIndex << std::endl;
}