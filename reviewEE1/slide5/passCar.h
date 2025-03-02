#include "car.h"
#include <string>

using namespace std;

class PassCar : public Car
{
private:
    string passCarType;
    bool sunRoof;

public:
    // construtor, tem que colocar as variáveis até da classe mãe tbm
    PassCar(const string &tp, bool sr, int n, const string &p);

    // getters and setters
    void setType(const string &tp);
    void setSr(bool sr);

    string getType() const;
    bool getSr() const;

    string display() const override; // sobrescrevendo, método virtual
};
