#include "figuraGeometrica.h"

class Quadrado : public FiguraGeometrica
{
private:
    int lado;

public:
    // constructor, destructor, getter and setter
    Quadrado(int vLado);

    int getLado() const;
    void setLado(int vLado);

    int area() const override;
}