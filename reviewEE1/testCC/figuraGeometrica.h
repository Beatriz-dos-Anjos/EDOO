#ifndef FIGURA_GEOMETRICA_H
#define FIGURA_GEOMETRICA_H

class FiguraGeometrica
{
private:
    int x, y;

public:
    // getters, setters, destructors and constructors

    FiguraGeometrica(int valueX, int valueY); ///constructor com parâmetros
    virtual ~FiguraGeometrica(); //já que temos um método virtual, o destrutor tem que ser virtual por contaa da alocação dinâmica na memória

    int getX() const;
    int getY() const;

    void setX(int valueX);
    void setY(int valueY);

    // método puro virtual

    virtual int area() const = 0;
};
#endif