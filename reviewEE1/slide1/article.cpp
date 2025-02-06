#include "/home/beatrizanjos/EDOO/reviewEE1/slide1/article.h"
#include <iostream>
// Variável global para contar o número de objetos
int quantityObjects = 0;

// Métodos setters
void article::setArtName(std::string newName)
{
    articleName = newName;
}

void article::setArtNumber(long newNumber)
{
    articleNumber = newNumber;
}

void article::setSalesPrice(double newPrice)
{
    if (newPrice < 0.0)
    {
        newPrice = 0.0;
    }
    salesPrice = newPrice;
}

// Métodos getters
std::string article::getArtName() const
{
    return articleName;
}

long article::getArtNumber() const
{
    return articleNumber;
}

double article::getPrice() const
{
    return salesPrice;
}

// Construtor
article::article(long newNumber, const std::string &newName, double newPrice)
{
    setArtName(newName);
    setArtNumber(newNumber);
    setSalesPrice(newPrice);

    ++quantityObjects;

    std::cout << "An object of type Article \"" << articleName << "\" created.\n"
              << "This is the " << quantityObjects << "th Article.\n";
}

// Destrutor
article::~article()
{
    std::cout << "Cleaned up object for the article \"" << articleName << "\".\n"
              << "There are still " << --quantityObjects << " articles!\n";
}

// Método para imprimir os detalhes do artigo
void article::print() const
{
    std::cout << "-----------------------------------------\n"
              << "Article data:\n"
              << " Number ....: " << articleNumber << '\n'
              << " Name ......: " << articleName << '\n'
              << " Sales price: $" << salesPrice << '\n'
              << "-----------------------------------------\n"
              << std::endl;
}
