#include <iostream>

#include "quadrado.h"
#include "triangulo.h"
using namespace std;

int main()
{

    // ponteiros para objetos do tipo FiguraGeométrica
    FiguraGeometrica *f1 = new Quadrado(0, 0, 3); // aloca memória para instâncias
    // f1 armazena o endereço do objeto quadrado
    FiguraGeometrica *f2 = new Triangulo(0, 0, 4, 4);
    // f2 armazena o endereço do objeto retângulo


    //ponteiros e polimorfismo
    //se f1 aponta para um quadrado, f1->area() chama Quadrado::area()
    cout << "Area 1" << f1->area() << endl;

    //se f2 aponta para um triângulo, f2-> chama Triangulo::area
    cout << "Area 2" << f2->area() << endl;

    delete f1;
    delete f2;

    return 0;
}