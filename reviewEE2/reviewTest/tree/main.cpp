#include <iostream>
using namespace std;
struct Node
{
    int val;
    Node *leftchild;
    Node *rightChild;
}

class Bst
{
private:
    Node *root;

public:
    Bst();
    void insert(int value);
    void preOrder(Node *current);
    void inOrder(Node *current);
    void postOrder(Node *current);

}

Bst::Bst()
{
    root = nullptr;
}

void Bst::insert(int value)
{
    Node *novoNo = new Node();
    novoNo->value = value;
    novoNo->leftchild = nullptr;
    novoNo->rightChild = nullptr;
    if (root == nullptr)
    {
        root = novoNo;
    }
    else
    {
        Node *currentNode = root;
        if (value < currentNode->val)
        {
            if (currentNode->leftchild == nullptr)
            {
                currentNode->leftchild = novoNo;
            }
            else
            {
                currentNode = currentNode->leftchild;
            }
        }
        else if (value > currentNode->val)
        {
            if (currentNode->rightChild == nullptr)
            {
                currentNode->rightChild = novoNo;
            }

            else
            {
                currentNode = currentNode->rightChild;
            }
        }
    }
}

void Bst::preOrder(Node *current)
{
    cout << current->val;
    preOrder(current->leftchild);
    preOrder(current->rightChild);
}

void Bst::inOrder(Node *current)
{
    inOrder(current->leftchild);
    cout << current->val;
    inOrder(current->rightChild);
}

void Bst::postOrder(Node *current)
{
    postOrder(current->leftchild);
    postOrder(current->rightChild);
    cout << current->val;
}