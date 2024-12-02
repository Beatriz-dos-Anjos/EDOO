#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <string>

class Article
{
private:
    std::string name;
    double price;
    int quantity;

public:
    static int counter; // Contador estático

    // Construtor padrão com valores padrão
    Article(std::string n = "Unknown", double p = 0.0, int q = 0);

    // Construtor de cópia
    Article(const Article &other);

    // Destruidor
    ~Article();

    // Métodos de acesso (inline)
    void setName(const std::string &n) { name = n; }
    std::string getName() const { return name; }

    void setPrice(double p);
    double getPrice() const { return price; }

    void setQuantity(int q) { quantity = q; }
    int getQuantity() const { return quantity; }

    // Método para obter o número atual de objetos
    static int getCount() { return counter; }

    // Método para imprimir o artigo
    void print() const;
};

#endif
