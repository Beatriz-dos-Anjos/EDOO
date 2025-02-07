#include "passCar.h" // car está incluso
#include <iostream>
#include <string>

int main()
{
    PassCar Beetle("Beetle", false, 3421, " VW");

    cout << Beetle.display() << endl;

    return 0;
}