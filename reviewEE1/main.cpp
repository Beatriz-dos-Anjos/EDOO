#include <iostream>
#include <vector>
#include <iomanip>
#include "baseClass.h"
#include "fruitClass.h"
#include "/home/beatrizanjos/EDOO/reviewEE1/legumes.h"
#include "/home/beatrizanjos/EDOO/reviewEE1/verdura.h"

using namespace std;

int main()
{
    int quantidadeProdutos;
    cout << "Quantidade de produtos a serem cadastrados: ";
    cin >> quantidadeProdutos;

    // Vetores para armazenar os produtos de cada tipo
    vector<baseClass *> frutas, verduras, legumes;

    // Loop para cadastrar os produtos
    for (int i = 0; i < quantidadeProdutos; i++)
    {
        string type, newName;
        float newPrice;
        int newQuantity;

        cout << "Qual o tipo do produto? (Fruta, Verdura, Legume): ";
        cin >> type;

        cout << "Qual o nome do produto? ";
        cin >> newName;

        cout << "Qual o preço? ";
        cin >> newPrice;

        cout << "Qual a quantidade? ";
        cin >> newQuantity;

        baseClass *produto = nullptr; // Ponteiro para armazenar o produto criado

        // Verifica qual o tipo do produto e cria a instância correta
        if (type == "Fruta")
        {
            produto = new Fruit(newName, newPrice, newQuantity);
            frutas.push_back(produto);
        }
        else if (type == "Verdura")
        {
            produto = new Verdura(newName, newPrice, newQuantity);
            verduras.push_back(produto);
        }
        else if (type == "Legume")
        {
            produto = new Legume(newName, newPrice, newQuantity);
            legumes.push_back(produto);
        }
        else
        {
            cout << "Tipo inválido! Tente novamente." << endl;
            i--; // Voltar uma iteração para repetir a entrada
            continue;
        }
    }

    // Variáveis para armazenar os totais e descontos de cada categoria
    double totalFruit = 0.0, descontoFruit = 0.0;
    double totalVerdura = 0.0, descontoVerdura = 0.0;
    double totalLegume = 0.0;

    // Formatação dos valores para duas casas decimais
    cout << fixed << setprecision(2);

    // Exibição dos produtos do tipo Fruta
    cout << "\nValor total do estoque de Fruta:\n";
    for (auto &produto : frutas)
    {
        double valor = produto->calcularValorEstoque();
        cout << produto->getName() << ": R$" << valor << endl;
        totalFruit += valor;
    }
    descontoFruit = totalFruit * 0.1; // Aplicação do desconto de 10%
    cout << "Desconto: R$" << descontoFruit << endl;
    cout << "Total: R$" << totalFruit - descontoFruit << endl;

    // Exibição dos produtos do tipo Verdura
    cout << "\nValor total do estoque de Verdura:\n";
    for (auto &produto : verduras)
    {
        double valor = produto->calcularValorEstoque();
        cout << produto->getName() << ": R$" << valor << endl;
        totalVerdura += valor;
    }
    descontoVerdura = totalVerdura * 0.05; // Aplicação do desconto de 5%
    cout << "Desconto: R$" << descontoVerdura << endl;
    cout << "Total: R$" << totalVerdura - descontoVerdura << endl;

    // Exibição dos produtos do tipo Legume
    cout << "\nValor total do estoque de Legume:\n";
    for (auto &produto : legumes)
    {
        double valor = produto->calcularValorEstoque();
        cout << produto->getName() << ": R$" << valor << endl;
        totalLegume += valor;
    }
    cout << "Desconto: R$0.00" << endl; // Nenhum desconto é aplicado para legumes
    cout << "Total: R$" << totalLegume << endl;

    // Liberação da memória alocada para os produtos
    for (auto &produto : frutas)
        delete produto;
    for (auto &produto : verduras)
        delete produto;
    for (auto &produto : legumes)
        delete produto;

    return 0;
}
