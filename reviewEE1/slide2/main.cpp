#include "point.h"
using namespace std;

int main() {
    Point p1(3.5, 2.0);
    Point p2(1.5, 4.0);

    cout << "Ponto 1: " << p1 << endl;
    cout << "Ponto 2: " << p2 << endl;

    p1 += Point(2, 2);  // Correção: deslocando p1 corretamente

    cout << "Após p1 += Point(2,2): " << p1 << endl;

    Point p3 = p1 + p2;

    cout << "Novo ponto (p1 + p2): " << p3 << endl;

    return 0;
}
