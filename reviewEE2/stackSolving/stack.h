#ifndef _STACK_
#define _STACK_

const int MAX_SIZE = 100; // Definição da constante

class Stack {
private:
    int size;
    int* stack;
public:
    Stack();
    ~Stack();
    
    bool isEmpty();
    bool isFull();
    
    void push(int newElement);
    int pop();
    
    void print();
    int lengthStack(); // Corrigido: antes estava "lenghtStack"
};

#endif
