#ifndef _FIGURA_
#define _FIGURA_

class FiguraGeometrica
{
private:
    int x, y;

public:
    // getters, setters, destructors and constructors

    
    FiguraGeometrica(int valueX, int valueY);
    ~FiguraGeometrica();

    int getX() const;
    int getY() const;

    void setX(int valueX);
    void setY(int valueY);

    // método puro virtual

    virtual int area() = 0;
}