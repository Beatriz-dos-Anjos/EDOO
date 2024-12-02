#include <iostream>
#include "file.h"

void test(Article article);

int main()
{
    Article globalArticle("Laptop", 500.0, 10);
    Article localArticle("Phone", 300.0, 15);

    test(globalArticle);

    std::cout << "Number of articles: " << Article::getCount() << std::endl;

    // Criando uma cópia do objeto globalArticle
    Article copiedArticle = globalArticle;
    std::cout << "Number of articles after copy: " << Article::getCount() << std::endl;

    return 0;
}

// Função de teste
void test(Article article)
{
    article.print(); // Exibe o artigo
    std::cout << "Test function completed." << std::endl;
}
