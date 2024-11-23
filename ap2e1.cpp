#include <iostream>
#include <math.h>


int main ()  {
    std::cout << " 4 possui raiz quadrada :" << sqrt(4) << std::endl;
    std::cout << " 12.25 possui raiz quadrada :" << sqrt(12.25) << std::endl;
    std::cout << " 0.0121 possui raiz quadrada :" << sqrt(0.0121) << std::endl;

    double number;
    std::cout <<"Número";
    std::cin>>number;

    std::cout << number << " possui raiz quadrada " <<sqrt(number)<< std::endl;

    return 0;
}