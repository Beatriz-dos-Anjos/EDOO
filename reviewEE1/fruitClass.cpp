#include "fruitClass.h"

float Fruit::calcularValorEstoque() const //método virtual
{
    return getPrice() * getQuantity();
}

Fruit::Fruit(string newName, float newPrice, int newQuantity)
    : baseClass(newName, newPrice, newQuantity) {}
