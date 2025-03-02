#include <iostream>
#include "stack.h"

using namespace std;

Stack::Stack() {
    size = 0;
    stack = new int[MAX_SIZE]; // Agora MAX_SIZE está definido corretamente
}

Stack::~Stack() {
    delete[] stack;
}

bool Stack::isEmpty() {
    return size == 0;
}

bool Stack::isFull() {
    return size == MAX_SIZE;
}

void Stack::push(int newElement) {
    if (isFull()) {
        cout << "Erro: Pilha cheia!" << endl;
        return;
    }
    stack[size] = newElement;
    size++;
}

int Stack::pop() {
    if (isEmpty()) {
        cout << "Erro: Pilha vazia!" << endl;
        return -1;  // Retorna um valor padrão indicando erro
    }
    size--;
    return stack[size];
}

void Stack::print() {
    if (isEmpty()) {
        cout << "A pilha está vazia!" << endl;
        return;
    }
    cout << "Elementos da pilha: ";
    for (int i = 0; i < size; i++) {
        cout << stack[i] << " ";
    }
    cout << endl;
}

// Corrigido: Nome da função agora é igual ao do .h
int Stack::lengthStack() {
    return size;
}
