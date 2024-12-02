#include <iostream>
#include "article2.h"

void test(Article article);

int main()
{
    Article globalArticle("Laptop", 500.0, 10);
    Article localArticle("Phone", 300.0, 15);

    test(globalArticle);

    std::cout << "Number of articles: " << Article::getCount() << std::endl;

    Article copiedArticle = globalArticle;
    std::cout << "Number of articles after copy: " << Article::getCount() << std::endl;

    return 0;
}

void test(Article article)
{
    article.print();
    std::cout << "Test function completed." << std::endl;
}
