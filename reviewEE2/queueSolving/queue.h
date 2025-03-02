#ifndef __QUEUE__
#define __QUEUE__

const int MAX_ITEMS = 100; // Corrigido

class Queue {
private:
    int first, last;
    int* estrutura; // Ponteiro para a estrutura dinâmica
public:
    Queue();
    ~Queue();
    bool isEmpty();
    bool isFull();
    void enqueue(int);
    int dequeue();
    void print();
};

#endif // __QUEUE__
