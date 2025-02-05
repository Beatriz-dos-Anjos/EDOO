#include "fruitClass.h"

float Fruit::calcularValorEstoque() const
{
    return getPrice() * getQuantity();
}

Fruit::Fruit(string newName, float newPrice, int newQuantity)
    : baseClass(newName, newPrice, newQuantity) {}
