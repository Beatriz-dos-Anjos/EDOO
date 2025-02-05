#include <iostream>
#include "/home/beatrizanjos/EDOO/reviewEE1/fruitClass.h"
#include "/home/beatrizanjos/EDOO/reviewEE1/baseClass.h"
#include <string>
float Fruit::calcularValorEstoque()
{
    float value = getPrice() * getQuantity();
    return value * 0.9;
}
Fruit::Fruit(string newName, float newPrice, int newQuantity) : baseClass(newName, newPrice, newQuantity) {} // constructor