#include "figuraGeometrica.h"

// no construtor já tem que fazer a lista de inicialização
FiguraGeometrica::FiguraGeometrica(int valueX, int valueY) : x(valueX), y(valueY) {}
FiguraGeometrica::~FiguraGeometrica() {}

void FiguraGeometrica::setX(int valueX)
{
    x = valueX;
}

void FiguraGeometrica::setY(int valueY)
{
    y = valueY;
}

int FiguraGeometrica::getX() const
{
    return x;
}

int FiguraGeometrica::getY() const
{
    return y;
}