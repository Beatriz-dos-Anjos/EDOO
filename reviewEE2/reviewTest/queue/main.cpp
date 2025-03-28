#include <iostream>
#include <queue>
class Node
{
public:
    int value;
    Node *next;
    Node()
    {
        value = 0;
        next = nullptr;
    }
};

class Queue
{
private:
    Node *head;
    Node *tail;

public:
    void enqueue(int val);
    int dequeue();
    int search(int val);
    int length();
    Queue();
    ~Queue();
    int somarFila(Queue fila);
    int maiorElemento(Queue fila);
};

Queue::Queue()
{
    head = nullptr;
    tail = nullptr;
}

void Queue::enqueue(int val)
{
    Node *novoNo = new Node();
    novoNo->value = val;
    if (head == nullptr)
    {
        head = novoNo;
        tail = novoNo;
    }
    else
    {
        tail->next = novoNo;
        tail = novoNo;
    }
}

int Queue::dequeue()
{
    if (head == nullptr)
    {
        return -1;
    }
    else
    {
        Node *currentNode = head;
        int item = head->value;
        head = head->next;
        delete currentNode;
        return item;
        if (head == nullptr)
        {
            tail = nullptr;
        }
    }
}

int Queue::length()
{
    Node *currentNode = head;
    int num = 0;
    while (currentNode != nullptr)
    {
        num++;
        currentNode = currentNode->next;
    };
    return num;
}
// / q exercicios
// 1- somar elementos
int somarFila(Queue fila)
{
    Queue filaTemporaria;
    int soma = 0;

    while (fila.length() > 0)
    {
        int val = fila.dequeue();
        soma += val;
        filaTemporaria.enqueue(val);
    }

    // restaurar fila original (opcional)
    while (filaTemporaria.length() > 0)
    {
        fila.enqueue(filaTemporaria.dequeue());
    }

    return soma;
}

int Queue::maiorElemento(Queue fila)
{
    int maior = -99999;
    int i = 0;
    Queue filaAux;
    while (fila.length() > 0)
    {
        int value = fila.dequeue(); // acessa valor ao ser retirado
        if (value > maior)
        {
            maior = value;
        }
        filaAux.enqueue(value);
    }
    while (filaAux.length() > 0)
    {
        fila.enqueue(filaAux.dequeue());
    }

    return maior;
}
int contarMultiplosDeTres(Queue fila)
{
    int m3 = 0;
    Queue filaAx;
    while (fila.length() > 0)
    {
        int val = fila.dequeue();
        if (val % 3 == 0)
        {
            m3++;
        }
        filaAx.enqueue(val);
    }
    while (filaAx.length() > 0)
    {
        fila.enqueue(filaAx.dequeue());
    }

    return m3;
}
Queue processarChamados(Queue fila)
{
    Queue novafila;
    while (fila.length() > 0)
    {
        int val = fila.dequeue();

        if (val == -1)
        {
            // se tiver algo após o -1, remove (descarta)
            if (fila.length() > 0)
            {
                fila.dequeue(); // descarta o próximo
            }
        }
        else
        {
            novafila.enqueue(val); // valor válido
        }
    }
}