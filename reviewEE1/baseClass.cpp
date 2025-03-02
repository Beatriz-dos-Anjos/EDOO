#include "baseClass.h"

string baseClass::getName()
{
    return name;
}

float baseClass::getPrice() const
{
    return price;
}

int baseClass::getQuantity() const
{
    return quantity;
}

void baseClass::setName(string newName)
{
    name = newName;
}

void baseClass::setPrice(float newPrice)
{
    price = newPrice;
}

void baseClass::setQuantity(int newQuantity)
{
    quantity = newQuantity;
}

baseClass::baseClass(string newName, float newPrice, int newQuantity)
    : name(newName), price(newPrice), quantity(newQuantity) {} // até a classe base tem que ter lista de inicialização
