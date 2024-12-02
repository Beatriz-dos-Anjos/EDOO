#include <iostream>
#include "Article.h"

void test();

int main()
{
    Article globalArticle("Laptop", 500.0, 10);

    Article localArticle("Phone", 300.0, 15);

    test();

    return 0;
}

void test()
{
    static Article staticArticle("Tablet", 200.0, 5);
    Article dynamicArticle("Headphones", 150.0, 8);

    staticArticle.print();
    dynamicArticle.print();
}
