#include "legumes.h"

float Legume::calcularValorEstoque() const
{
    return getPrice() * getQuantity();
}

Legume::Legume(string newName, float newPrice, int newQuantity)
    : baseClass(newName, newPrice, newQuantity) {}
