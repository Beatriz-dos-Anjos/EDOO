#ifndef _LEGUME_
#define _LEGUME_

#include "baseClass.h"

class Legume : public baseClass
{
public:
    float calcularValorEstoque() const override;
    Legume(string newName, float newPrice, int newQuantity);
};

#endif
