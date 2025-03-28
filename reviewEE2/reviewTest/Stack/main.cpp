
#include <iostream>
using namespace std;
// implementar uma pilha em uma lista encadeada
class Node
{
public:
    int value;
    Node *nextNode;
    Node()
    {
        value = 0;
        nextNode = nullptr;
    }
}

class Stack
{
private:
    Node *NoTopo;

public:
    Stack();
    ~Stack();
    bool isEmpty();
    bool isFull();
    void push(int item);
    int pop();
    int length();
}

Stack::Stack()
{
    NoTopo = nullptr; // não tem nada!!!!
}

Stack::~Stack()
{
    delete Stack;
}

bool Stack::isEmpty()
{
    return (NoTopo == nullptr);
}

bool Stack::isFull()
{
    try
    {
        Node *currentNode;
        currentNode = new Node(); // criação de um novo nó para testar alocacão de memória - se há espaço
        delete currentNode;
        return false;
    }
    catch ()
    {
        return true;
    }
}

void Stack::push(int item)
{
    if (isFull)
    {
        cout << "Full";
    }
    Node *NovoNo = new Node();
    NovoNo->value = item;
    NovoNo->next = NoTopo;
    NoTopo = NovoNo;
}

int Stack::pop()
{
    if (isEmpty)
    {
        return 0;
    }
    else
    {
        Node *temporaryNode;              // criação de um nó temporário
        temporaryNode = NoTopo;           // que aponta para o nó topo
        int value = temporaryNode->value; // uma nova variável chamada valor, que recebe como valor o valor que o nó temporario guarda
        NoTopo = NoTopo->next;            // avança o no topo
        delete temporaryNode;             // deleta o temporário!!!!!!1
        return value;
    }
}

int Stack::length()
{
    int num;
    num = 0;
    Node *temporary;
    temporary = NoTopo;
    while (temporary!= nullptr)
    {
        num++;
        temporary = temporary->nextNode;
    }
    return num;
}