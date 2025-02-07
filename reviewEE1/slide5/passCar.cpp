#include "passCar.h"
#include <string>

using namespace std;

void PassCar::setType(const string &tp)
{
    passCarType = tp;
}

void PassCar::setSr(bool sr)
{
    sunRoof = sr;
}

string PassCar::getType() const
{
    return passCarType;
}

bool PassCar::getSr() const
{
    return sunRoof;
}

// construtor com lista de inicialização de membros
PassCar::PassCar(const string &tp, bool sr, int n, const string &p) : Car(n, p), passCarType(tp), sunRoof(sr) {}

/// método virtual polimórfico sendo sobrecrito
string PassCar::display() const
{
    return "Car number: " + to_string(getNr()) +
           "\nProducer: " + getProd() +
           "\nType: " + passCarType +
           "\nSunroof: " + (sunRoof ? "yes" : "no");
}