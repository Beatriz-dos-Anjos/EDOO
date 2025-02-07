#include "point.h"

float Point::getX() const 
{
    return x;
};

float Point::getY() const 
{
    return y;
};

void Point::setX(float valueX)
{
    x = valueX;
};

void Point::setY(float valueY)
{
    y = valueY;
}

Point &Point::operator+=(const Point &otherObject)
{
    x += otherObject.x;
    y += otherObject.y;

    return *this; // retorna o próprio objecto atualizado para ser reutilizado
}

// implementação do construtor:

Point::Point(float valueX, float valueY)
{
    x = valueX;
    y = valueY;
}

// friend function

Point operator+(const Point &p1, const Point &p2)
{
    return Point(p1.x + p2.x, p1.y + p2.y);
}

ostream &operator<<(ostream &os, const Point &p)
{
    os << "(" << p.x << "," << p.y << ")";
    return os;
}