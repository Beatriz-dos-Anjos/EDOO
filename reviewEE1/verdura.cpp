#include <iostream>
#include "/home/beatrizanjos/EDOO/reviewEE1/verdura.h"
#include "/home/beatrizanjos/EDOO/reviewEE1/baseClass.h"

#include <string>
float Verdura::calcularValorEstoque()
{
    float value = getPrice() * getQuantity();
    return value * 0.95;
}

Verdura::Verdura(string newName, float newPrice, int newQuantity) : baseClass(newName, newPrice, newQuantity) {} // constructor