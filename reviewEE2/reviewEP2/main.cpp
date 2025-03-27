#include <iostream> // Biblioteca padrão para entrada e saída

// Estrutura que representa um nó da tabela hash
struct HashNode
{
    int key;   // Chave do elemento armazenado
    int value; // Valor associado à chave

    // Construtor padrão: inicializa o nó com valores -1
    // -1 indica que a posição está vazia
    HashNode() : key(-1), value(-1) {}

    // Construtor que permite criar um nó com chave e valor específicos
    HashNode(int k, int v) : key(k), value(v) {}
};

// Classe que implementa a tabela hash
class HashTable
{
private:
    HashNode *arr; // Estrutura de array que armazena os elementos da tabela hash
    int capacity;  // Capacidade máxima da tabela (quantidade total de posições)
    int size;      // Quantidade de elementos atualmente armazenados

public:
    HashTable();                     // Construtor da classe
    ~HashTable();                    // Destrutor da classe (libera a memória)
    void insert(int key, int value); // Método para inserir um elemento na tabela
    int find(int key);               // Método para buscar um elemento na tabela
    void remove(int key);            // Método para remover um elemento da tabela
    int hashFunction(int key);       // Função hash que define a posição de armazenamento
};

// Construtor da HashTable
HashTable::HashTable()
{
    capacity = 20; // Define a capacidade máxima da tabela como 20 posições
    size = 0;      // Inicialmente, a tabela está vazia

    arr = new HashNode[capacity]; // Aloca dinamicamente o vetor de nós

    // Inicializa todas as posições do vetor com valores -1 (indicando posições vazias)
    for (int i = 0; i < capacity; i++)
    {
        arr[i] = HashNode(); //olhar construtor do struct Node
    }
}

// Função hash: calcula a posição da chave na tabela
int HashTable::hashFunction(int key)
{
    return key % capacity; // Usa o operador de módulo para definir a posição
}

// Método para inserir um elemento na tabela hash
void HashTable::insert(int key, int value)
{
    // Verifica se a tabela está cheia
    if (size >= capacity)
    {
        std::cout << "Tabela cheia\n";
        return;
    }

    int hashIndex = hashFunction(key); // Calcula a posição inicial na tabela

    // Utiliza sondagem linear para encontrar uma posição vazia
    while (arr[hashIndex].key != -1) // por não estar vazia
    {
        hashIndex = (hashIndex + 1) % capacity; // Move para a próxima posição circularmente
    }

    // Insere o novo nó na posição encontrada
    arr[hashIndex] = HashNode(key, value);
    size++; // Aumenta o contador de elementos na tabela
}

// Método para buscar um elemento na tabela hash
int HashTable::find(int key)
{
    int hashIndex = hashFunction(key); // Calcula a posição inicial da busca

    // Percorre a tabela procurando a chave, se nao achar valor vazio.
    while (arr[hashIndex].key != -1)
    {
        if (arr[hashIndex].key == key)
        {
            return arr[hashIndex].value; // Retorna o valor associado à chave
        }
        hashIndex = (hashIndex + 1) % capacity; // Continua a busca linearmente
    }

    return -1; // Retorna -1 se a chave não for encontrada
}

void HashTable::remove(int key)
{
    int hashIndex = hashFunction(key);

    while (arr[hashIndex].key != -1) // Enquanto não encontrar um espaço vazio
    {
        if (arr[hashIndex].key == key)
        {
            arr[hashIndex].key = -2;   // Marca como "removido" em vez de vazio
            arr[hashIndex].value = -1; // O valor pode ser descartado
            size--;
            return;
        }
        hashIndex = (hashIndex + 1) % capacity;
    }
}

// Destrutor da tabela hash (libera a memória alocada)
HashTable::~HashTable()
{
    delete[] arr;
}

// Função principal para testar a tabela hash
int main()
{
    HashTable ht; // Cria uma tabela hash

    // Insere alguns elementos
    ht.insert(10, 100);
    ht.insert(20, 200);
    ht.insert(30, 300);

    // Busca um elemento e exibe o valor encontrado
    std::cout << "Valor com chave 20: " << ht.find(20) << std::endl;

    // Remove um elemento
    ht.remove(20);

    // Tenta buscar o elemento removido
    std::cout << "Valor com chave 20 após remoção: " << ht.find(20) << std::endl;

    return 0;
}
