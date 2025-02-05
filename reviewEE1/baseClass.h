#ifndef _BaseClass_
#define _BaseClass_

#include <string>
using namespace std;
class baseClass
{

private:
    string name;
    float price;
    int quantity;

public:
    virtual float calcularValorEstoque() const = 0;             // método polimórfico
    baseClass(string newName, float newPrice, int newQuantity); // construtor

    // getters and setters
    string getName();
    float getPrice();
    int getQuantity();

    void setName(string newName);
    void setPrice(float newPrice);
    void setQuantity(int newQuantity);
};
#endif