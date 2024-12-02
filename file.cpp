#include "file.h"

// Inicialização do contador estático
int Article::counter = 0;

// Construtor
Article::Article(std::string n, double p, int q) : name(n), price(p >= 0 ? p : 0.0), quantity(q)
{
    counter++;
    std::cout << "Article created: " << name << std::endl;
}

// Construtor de cópia
Article::Article(const Article &other) : name(other.name), price(other.price), quantity(other.quantity)
{
    counter++;
    std::cout << "Article copied: " << other.name << std::endl;
}

// Destruidor
Article::~Article()
{
    counter--;
    std::cout << "Article destroyed: " << name << std::endl;
}

// Método para definir o preço (com validação)
void Article::setPrice(double p)
{
    price = (p >= 0) ? p : 0.0;
}

// Método para imprimir o artigo
void Article::print() const
{
    std::cout << "Article Name: " << name << ", Price: " << price << ", Quantity: " << quantity << std::endl;
    std::cout << "Press enter to continue..." << std::endl;
    std::cin.get(); // Espera a tecla Enter
}
