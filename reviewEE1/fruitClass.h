#ifndef _FRUIT_
#define _FRUIT_

#include "baseClass.h"

class Fruit : public baseClass
{
public:
    float calcularValorEstoque() const override; // método polimórfico virtual
    Fruit(string newName, float newPrice, int newQuantity); //construtor
};

#endif
