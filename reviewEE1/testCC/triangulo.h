#ifndef _TRIANGULO_
#define _TRIANGULO_

#include "figuraGeometrica.h"

class Triangulo : public FiguraGeometrica
{
private:
    int base, altura;

public:
    Triangulo(int valueX, int valueY, int vBase, int vAltura);
    ~Triangulo();

    // getters and setters

    void setBase(int vBase);
    void setAltura(int vAltura);

    int getBase() const;
    int getAltura() const;

    // chamando o método virtual polimórfico
    int area() const override;
};
#endif