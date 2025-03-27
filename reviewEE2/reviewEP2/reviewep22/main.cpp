#include <iostream>
using namespace std;

// Estrutura de um nó da BST (Árvore de Busca Binária)
struct Node {
    int key;       // Valor armazenado no nó
    Node *left;    // Ponteiro para o filho esquerdo
    Node *right;   // Ponteiro para o filho direito

    // Construtor do nó
    Node(int item) {
        key = item;
        left = right = NULL;
    }
};

// Função para inserir um novo nó na BST
Node* insert(Node* root, int key) {
    // Se a árvore estiver vazia, cria um novo nó
    if (root == NULL) {
        return new Node(key);
    }

    // Se a chave for menor, insere na subárvore esquerda
    if (key < root->key) {
        root->left = insert(root->left, key);
    }
    // Se a chave for maior, insere na subárvore direita
    else if (key > root->key) {
        root->right = insert(root->right, key);
    }

    return root; // Retorna a raiz atualizada
}

// Função para buscar um nó na BST
Node* search(Node* root, int key) {
    // Caso base: se a árvore estiver vazia ou a chave for encontrada
    if (root == NULL || root->key == key)
        return root;

    // Se a chave for menor, busca na subárvore esquerda
    if (key < root->key)
        return search(root->left, key);
    
    // Se a chave for maior, busca na subárvore direita
    return search(root->right, key);
}

// Função para remover um nó da BST
Node* remove(Node* root, int key) {
    if (root == NULL) return root; // Caso base: árvore vazia

    // Se a chave for menor, busca e remove na subárvore esquerda
    if (key < root->key) {
        root->left = remove(root->left, key);
    }
    // Se a chave for maior, busca e remove na subárvore direita
    else if (key > root->key) {
        root->right = remove(root->right, key);
    }
    else {
        // Caso 1: Nó sem filhos (simplesmente remove)
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        // Caso 2: Nó com um único filho (substitui pelo filho existente)
        else if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Caso 3: Nó com dois filhos (substitui pelo sucessor in-order)
        Node* temp = root->right;
        while (temp->left != NULL) { // Encontra o menor valor na subárvore direita
            temp = temp->left;
        }
        root->key = temp->key; // Substitui o valor do nó a ser removido
        root->right = remove(root->right, temp->key); // Remove o sucessor
    }
    return root;
}

// Percorrendo a BST - Em Ordem (Esquerda, Raiz, Direita)
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

// Percorrendo a BST - Pré-Ordem (Raiz, Esquerda, Direita)
void preorder(Node* root) {
    if (root != NULL) {
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Percorrendo a BST - Pós-Ordem (Esquerda, Direita, Raiz)
void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->key << " ";
    }
}

int main() {
    Node* root = NULL; // Inicializa a árvore vazia

    // Inserindo valores na BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    // Exibe os elementos em ordem
    cout << "Caminhamento Em-Ordem: ";
    inorder(root);
    cout << endl;

    // Exibe os elementos em pós-ordem
    cout << "Caminhamento Pós-Ordem: ";
    postorder(root);
    cout << endl;

    // Remove um nó da árvore
    root = remove(root, 50);
    
    // Exibe os elementos em ordem após a remoção
    cout << "Caminhamento Em-Ordem após remoção: ";
    inorder(root);
    cout << endl;

    // Exibe os elementos em pós-ordem após a remoção
    cout << "Caminhamento Pós-Ordem após remoção: ";
    postorder(root);
    cout << endl;

    return 0;
}
