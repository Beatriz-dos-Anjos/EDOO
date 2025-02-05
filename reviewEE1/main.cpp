#include <iostream>
#include "/home/beatrizanjos/EDOO/reviewEE1/baseClass.h"
#include "/home/beatrizanjos/EDOO/reviewEE1/fruitClass.h"
#include "/home/beatrizanjos/EDOO/reviewEE1/legumes.h"
#include "/home/beatrizanjos/EDOO/reviewEE1/verdura.h"
#include <string>
using namespace std;

int main()

{
    std::string type;
    int newQuantity;
    float newPrice;
    std::string newName;
    baseClass *produto;

    cout << "Quantidade de produtos a serem cadastrados:" << endl;
    cin >> newQuantity;

    cout
        << "Qual o tipo do produto?" << endl;
    cin >> type;

    cout
        << "Qual o nome do produto?" << endl;
    cin >> newName;

    cout << "Qual o preço?" << endl;
    cin >> newPrice;

    if (type == "Fruit")
    {
        produto = new Fruit(newName, newPrice, newQuantity);
        cout << produto->calcularValorEstoque() << endl;
        // implementação dos métodos
    }
    else if (type == "Legumes")
    {
        produto = new Legume(newName, newPrice, newQuantity);
        cout << produto->calcularValorEstoque() << endl;
    }
    else if (type == "Verdura")
    {
        produto = new Verdura(newName, newPrice, newQuantity);
        cout << produto->calcularValorEstoque() << endl;
    }

    return 0;
}