#include <iostream>
#include "/home/beatrizanjos/EDOO/reviewEE1/legumes.h"
#include "/home/beatrizanjos/EDOO/reviewEE1/baseClass.h"

#include <string>
float Legume::calcularValorEstoque()
{
    float value = getPrice() * getQuantity();
    return value;
}

Legume::Legume(string newName, float newPrice, int newQuantity) :baseClass(newName, newPrice, newQuantity){} //constructor