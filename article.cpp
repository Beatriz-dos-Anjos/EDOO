#include "article.h"
int Article::counter = 0;

Article::Article(std::string n, double p, int q) : name(n), price(p >= 0 ? p : 0.0), quantity(q)
{
    counter++;
    std::cout << "Article created: " << name << std::endl;
}

Article::~Article()
{
    counter--;
    std::cout << "Article destroyed: " << name << std::endl;
}
void Article::print() const
{
    std::cout << "Article Name: " << name << ", Price: " << price << ", Quantity: " << quantity << std::endl;
    std::cout << "Press enter to continue..." << std::endl;
    std::cin.get();
}
