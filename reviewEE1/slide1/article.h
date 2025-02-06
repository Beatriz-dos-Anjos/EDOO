#ifndef _ARTICLE_
#define _ARTICLE_

#include <string>
using namespace std;

class article
{
private:
    long articleNumber;
    string articleName;
    double salesPrice;

public:
    article(long articleNumber, const string &articleName, double salesPrice); // construtor
    ~article();                                                                // destruidor

    // Métodos setters
    void setArtNumber(long newNumber);
    void setArtName(std::string newName);
    void setSalesPrice(double newPrice);

    // Métodos getters
    long getArtNumber() const;
    std::string getArtName() const;
    double getPrice() const;

    // Método print
    void print() const;
};
#endif