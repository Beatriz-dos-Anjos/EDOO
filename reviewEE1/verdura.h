#ifndef _VERDURA_
#define _VERDURA_

#include "/home/beatrizanjos/EDOO/reviewEE1/baseClass.h"

class Verdura : public baseClass
{
public:
    float calcularValorEstoque() override;

    Verdura(string newName, float newPrice, int newQuantity);
}
