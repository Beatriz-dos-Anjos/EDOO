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
    virtual float calcularValorEstoque(float price, int quantity) = 0;

    // getters and setters
    string getName();
    float getPrice();
    int getQuantity();

    void setName(string newName);
    void setPrice(float newPrice);
    void setQuantity(int newQuantity);
};
#endif