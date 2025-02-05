#ifndef _FRUIT_
#define _FRUIT_

#include "/home/beatrizanjos/EDOO/reviewEE1/baseClass.h"

class Fruit : public baseClass
{
public:
    float calcularValorEstoque() override;

    //construtor
    Fruit(string newName, float newPrice, int newQuantity);
}
