#include "queue.h"
#include <iostream>

using namespace std;

Queue::Queue() {
    first = 0;
    last = 0;
    estrutura = new int[MAX_ITEMS]; // Alocando memória corretamente
}

Queue::~Queue() {
    delete[] estrutura; // Liberando memória alocada
}

bool Queue::isEmpty() {
    return (first == last);
}

bool Queue::isFull() {
    return (last - first == MAX_ITEMS); // Uso correto de MAX_ITEMS
}

void Queue::enqueue(int newElement) {
    if (isFull()) {
        cout << "Fila cheia!" << endl;
        return;
    }
    estrutura[last % MAX_ITEMS] = newElement;
    last++;
}

int Queue::dequeue() {
    if (isEmpty()) {
        cout << "Fila vazia!" << endl;
        return -1; // Retorno de erro
    }
    int aux = estrutura[first % MAX_ITEMS];
    first++;
    return aux;
}

void Queue::print() {
    for (int i = first; i < last; i++) {
        cout << estrutura[i % MAX_ITEMS] << " ";
    }
    cout << endl;
}
