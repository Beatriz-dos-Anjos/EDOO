#include <iostream>

using namespace std;

#include "quadrado.h"
#include "triangulo.h"

int main()
{

    FiguraGeometrica *f1 = new Quadrado(0, 0, 3);
    FiguraGeometrica *f2 = new Triangulo(0, 0, 4, 4);
    cout << "Area 1" << f1->area() << endl;
    cout << "Area 2" << f2->area() << endl;

    delete f1;
    delete f2;

    return 0;
}