#ifndef _FRUIT_
#define _FRUIT_

#include "baseClass.h"

class Fruit : public baseClass
{
public:
    float calcularValorEstoque() const override;
    Fruit(string newName, float newPrice, int newQuantity);
};

#endif
