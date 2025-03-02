#ifndef _BASECLASS_
#define _BASECLASS_

#include <string>

using namespace std;

class baseClass  //classe abstrata por ter um  método virtual puro
{
private:
    string name;
    float price;
    int quantity;

public:
    virtual float calcularValorEstoque() const = 0;             // Método polimórfico
    baseClass(string newName, float newPrice, int newQuantity); // Construtor

    // Getters e Setters
    string getName();
    float getPrice() const;
    int getQuantity() const;

    void setName(string newName);
    void setPrice(float newPrice);
    void setQuantity(int newQuantity);
};

#endif
