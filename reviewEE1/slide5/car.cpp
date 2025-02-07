#include "car.h"
#include <string>

using namespace std;
// constructor!! tem que inicializar os membros dele certinho

Car::Car(int n, string p) : nr(n), producer(p) {}

void Car::setProd(string p)
{
    producer = p;
}

void Car::setNr(int n)
{
    nr = n;
}

string Car::getProd() const
{
    return producer;
}

int Car::getNr() const 
{
    return nr;
}