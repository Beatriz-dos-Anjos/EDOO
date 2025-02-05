#ifndef _VERDURA_
#define _VERDURA_

#include "baseClass.h"

class Verdura : public baseClass
{
public:
    float calcularValorEstoque() const override;
    Verdura(string newName, float newPrice, int newQuantity);
};

#endif
