// q01 -> fazer função que conta o número de itens numa lista encadeada
class Node
{
public:
    int value;
    Node *next;
    Node();
};

Node::Node()
{
    value = 0;
    next = nullptr;
}

int search(Node *head)
{
    Node *currentNode = head; // um nó atual criado agora que aponta para o primeiro nó de lista, head
    int num = 0;
    while (currentNode ! = nullptr)
    {
        num++;
        currentNode = currentNode->next;
    }
    return num;
}
class LinkedList //// implementacao de lista encadeada

{
private:
    Node *head;

public:
    LinkedList();            // construtor
    void push_back(int val); // adiciona ao final
    void remove(int val);
    void changePositions(Node *first, Node *second);
    void print(); // imprime os valores
};
//// altura de um nó numa lista encadeada
int height(Node *currentNode)
{
    int heightNode = 0;
    while (currentNode != nullptr)
    {
        currentNode = currentNode->next;
        heightNode++;
    }
    return heightNode;
}
// profundidade de um nó numa lista encadeada

int depth(Node *head, Node *c)
{
    int depth = 0;
    Node *currentNode = head;
    while (currentNode != c)
    {
        currentNode = currentNode->next;
        depth++;
    }
    return depth;
}

// funcao que faz cópia de uma lista encadeada
// valores iguais, mas os nós são diferentes.
Node *copyLinkedList(Node *headerOriginal)
{
    if (headerOriginal == nullptr)
    {
        return nullptr;
    } // a cópia é uma lista vazia
    Node *headerCopy = new Node();              // primeiro nó da lista copiada
    Node *currentNodeCopy = headerCopy;         // nó atual da lista copiada
    Node *currentNodeOriginal = headerOriginal; // nó atual da lista original
    while (currentNodeOriginal != nullptr)
    {
        currentNodeCopy->value = currentNodeOriginal->value;
        if (currentNodeOriginal->next != nullptr)
        {
            currentNodeCopy->next = new Node();      // conecta o próximo nó
            currentNodeCopy = currentNodeCopy->next; // avança para ele
        }
        currentNodeOriginal = currentNodeOriginal->next;
    }
    return headerCopy;
}

// inserir no final da lista encadeada
void LinkedList::push_back(int val)
{
    Node *newNode = new Node(); // criacao de um novo nó
    newNode->value = val;       // esse novo nó recebe o valor passando como parametro
    if (head == nullptr)
    {
        head = newNode; // se a lista estiver vazia, o novo nó é o primeiro
    }
    else
    {
        Node *currentNode = head; // faz um nó temporario que vai percorrer toda a lista
        while (currentNode->next != nullptr)
        {
            currentNode = currentNode->next; // segue o percurso para o próximo node
        }
        currentNode->next = newNode; // conecta o novo nó ao último nó da lista
    }
}
#include <stdexcept> // necessário para std::runtime_error

void LinkedList::remove(int val)
{
    // Caso especial: o valor está no primeiro nó (head)
    if (head->value == val)
    {
        Node *temp = head; // nó temporario que guarda o valor de head, para que head passe para o próximo e o valor inicial seja deletado
        head = head->next;
        delete temp;
        return;
    }

    Node *currentNode = head->next;
    Node *previousNode = head;

    // Percorre até encontrar o valor ou chegar ao fim
    while (currentNode != nullptr && currentNode->value != val)
    {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }

    if (currentNode == nullptr)
    {
        throw std::runtime_error("Valor não encontrado na lista.");
    }

    // Remove o nó e realoca os ponteiros
    previousNode->next = currentNode->next;
    delete currentNode;
}
// funcao para trocar de posicao dois elementos de uma mesma lista encadeada (nós)

void LinkedList::changePositions(Node *first, Node *second)
{
    if (first == second)
    {
        // Se os dois nós forem o mesmo, não há nada a fazer
        return;
    }

    // Ponteiros para armazenar os nós anteriores a 'first' e 'second'
    Node *prevFirst = nullptr;
    Node *prevSecond = nullptr;
    Node *current = head;

    // Percorre a lista para encontrar os nós anteriores a 'first' e 'second'
    while (current != nullptr)
    {
        if (current->next == first)
        {
            prevFirst = current;
        }
        if (current->next == second)
        {
            prevSecond = current;
        }
        current = current->next;
    }

    // Se algum dos dois que estamos trocando for o head, precisamos atualizar o head pra continuar apontando pro primeiro nó da lista.
    if (first == head)
    {
        head = second;
    }
    else if (second == head)
    {
        head = first;
    }

    // Atualiza os ponteiros dos nós anteriores
    if (prevFirst != nullptr)
    {
        prevFirst->next = second;
    }
    if (prevSecond != nullptr)
    {
        prevSecond->next = first;
    }

    // Troca os ponteiros 'next' de 'first' e 'second'
    Node *temp = first->next;
    first->next = second->next;
    second->next = temp;
}
