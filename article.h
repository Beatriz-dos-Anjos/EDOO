#ifndef ARTICLE_H
#define ARTICLE_H

#include <iostream>
#include <string>

class Article
{
private:
    std::string name;
    double price;
    int quantity;

public:
    static int counter;

    Article(std::string n = "Unknown", double p = 0.0, int q = 0);

    ~Article();

    void setName(const std::string &n) { name = n; }
    std::string getName() const { return name; }

    void setPrice(double p);
    double getPrice() const { return price; }

    void setQuantity(int q) { quantity = q; }
    int getQuantity() const { return quantity; }

    void print() const;
};

#endif
