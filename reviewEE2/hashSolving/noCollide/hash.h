#include "aluno.h"
#include <string>

using namespace std;

class Hash
{
private:
    int HashFunction(Student student); // função que retorna o valor da chave em que o objeto aluno ficará.
    int max_itens;                     // tamanho máximo da tabela hash
    int max_positions;                 // quantidade máxima de posições que podem ser inseridas na tabela hash
    int quantity;                      // quantidade de elementos inseridos na tabela hash
    Student *structure;                // estrutura que armazenará os elementos da tabela hash
public:
    Hash();
    ~Hash(); //destrutor e construtor
    bool isFull(); //verifica se a tabela hash está cheia
    int getSize(); //retorna a quantidade de elementos inseridos na tabela hash
    void insert(Student student); //insere um elemento na tabela hash
    void remove(Student student); //remove um elemento da tabela hash
    void search(Student& student, bool& found); //procura um elemento na tabela hash  O parâmetro student é passado por referência para evitar a cópia de todo o objeto Student
    void print(); //imprime a tabela hash
}