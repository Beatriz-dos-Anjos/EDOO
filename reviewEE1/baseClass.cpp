#include <iostream>
#include "/home/beatrizanjos/EDOO/reviewEE1/baseClass.h"

// implementação de getters and setters

string baseClass::getName()
{
    return name;
}

float baseClass::getPrice()
{
    return price;
}

int baseClass::getQuantity()
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

baseClass::baseClass(string newName, float newPrice, int newQuantity) : price(newPrice), name(newName), quantity(newQuantity) {} //constructor