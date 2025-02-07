#include "figuraGeometrica.h"


// no construtor já tem que fazer a lista de inicialização
FiguraGeometrica::FiguraGeometrica(int valueX, int valueY) : x(valueX), y(valueY) {}

FiguraGeometrica::setX(int valueX)
{
    x = valueX;
}

FiguraGeometrica::setY(int valueY)
{
    y = valueY;
}

FiguraGeometrica::getX() const
{
    return x;
}

FiguraGeometrica::getY() const
{
    return y;
}