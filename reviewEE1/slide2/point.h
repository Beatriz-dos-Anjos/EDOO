#ifndef _POINT_H
#define _POINT_H

#include <iostream>
using namespace std;
class Point
{
private:
    float x, y;

public:
    Point(float valueX = 0, float valueY = 0);

    // getters and setters
    float getX() const;
    float getY() const;

    void setX(float valueX);
    void setY(float valueY);

    // operator overloading

    Point &operator+=(const Point &otherObject);

    // friend function para acessar os atributos privados
    // classe, operador e objetos qque atinge
    friend Point operator+(const Point &p1, const Point &p2);

    // friend function para <<

    friend ostream &operator<<(ostream &os, const Point &p);
};
#endif