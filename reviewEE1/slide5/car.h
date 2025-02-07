#ifndef _CAR_
#define _CAR_
#include <string>

using namespace std;
class Car
{
private:
    int nr;
    string producer;

public:
    Car(int n, string p); // constructor
    ~Car() {};            // destrutor

    // getters and setters
    void setNr(int n);
    void setProd(string p);

    int getNr() const;
    string getProd() const;

    virtual string display() const = 0; // display será uma função sobrescrita pelas classes filhas
};
#endif