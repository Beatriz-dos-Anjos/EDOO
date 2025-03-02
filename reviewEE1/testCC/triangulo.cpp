#include "triangulo.h"

Triangulo::Triangulo(int valueX, int valueY, int vBase, int vAltura) : FiguraGeometrica(valueX, valueY), base(vBase), altura(vAltura) {}
Triangulo::~Triangulo() {}

void Triangulo::setBase(int vBase)
{
    base = vBase;
}

void Triangulo::setAltura(int vAltura)
{
    altura = vAltura;
}

int Triangulo::getBase() const
{
    return base;
}

int Triangulo::getAltura() const
{
    return altura;
}

int Triangulo::area() const
{
    return ((base * altura) / 2);
}