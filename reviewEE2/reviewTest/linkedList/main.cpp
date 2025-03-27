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
    void print();            // imprime os valores
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
