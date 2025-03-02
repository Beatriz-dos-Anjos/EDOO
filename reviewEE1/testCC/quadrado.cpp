#include "quadrado.h"

Quadrado::Quadrado(int valueX, int valueY, int vLado) : FiguraGeometrica(valueX, valueY), lado(vLado) {} //construtor

void Quadrado::setLado(int vLado)
{
    lado = vLado;
}

int Quadrado::getLado() const
{
    return lado;
}

int Quadrado::area() const
{
    return lado * lado;
}