#ifndef _LEGUME_
#define _LEGUME_

#include "/home/beatrizanjos/EDOO/reviewEE1/baseClass.h"

class Legume : public baseClass
{
public:
    float calcularValorEstoque() override;

    Legume(string newName, float newPrice, int newQuantity);
}
