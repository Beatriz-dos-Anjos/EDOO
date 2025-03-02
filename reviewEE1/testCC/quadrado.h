#ifndef _QUADRADO
#define _QUADRADO_

#include "figuraGeometrica.h"

class Quadrado : public FiguraGeometrica
{
private:
    int lado;

public:
    // constructor, destructor, getter and setter
    Quadrado(int valueX, int valueY, int vLado);  //observar que tem os valores da classe mãe;

    int getLado() const;
    void setLado(int vLado);

    int area() const override;
};
#endif