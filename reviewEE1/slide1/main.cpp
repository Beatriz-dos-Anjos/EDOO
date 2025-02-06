#include "article.h"
#include <iostream>
// Definição de um objeto global
article globalArticle(1001, "Laptop", 2500.0);

// Função de teste
void test()
{
    static article staticArticle(1002, "Smartphone", 1500.0);
    article localArticle(1003, "Tablet", 800.0);

    std::cout << "\nInside test() function:\n";
    staticArticle.print();
    localArticle.print();
    std::cout << "Exiting test() function.\n";
}

int main()
{
    std::cout << "Program started.\n\n";

    // Objeto local dentro do main
    article mainArticle(1004, "Monitor", 1200.0);

    // Chamando a função de teste duas vezes
    test();
    test();

    std::cout << "\nModifying the global article:\n";
    globalArticle.setArtName("Gaming Laptop");
    globalArticle.setSalesPrice(3000.0);
    globalArticle.print();

    std::cout << "\nEnd of program.\n";
    return 0;
}
