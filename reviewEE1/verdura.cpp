#include "verdura.h"

float Verdura::calcularValorEstoque() const
{
    return getPrice() * getQuantity();
}

Verdura::Verdura(string newName, float newPrice, int newQuantity)
    : baseClass(newName, newPrice, newQuantity) {}
