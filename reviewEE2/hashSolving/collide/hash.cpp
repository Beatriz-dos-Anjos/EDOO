#include "hash.h"
#include <iostream>
#include <string>
using namespace std;

int Hash::HashFunction(Student student)
{
    return (student.getRa() % max_positions);
} // funcao que retorna a posicao da chave na tabela hash, pois o maximo de posicoes é tudo e student é o objeto que será inserido

Hash::Hash(int size_vector, int max)
{
    quantity = 0;                         // quantidade inicial de elementos inseridos será 0;
    max_itens = max;                      // tamanho máximo da tabela hash será setado pelo usuario
    max_positions = size_vector;          // quantidade máxima de posições que podem ser inseridas na tabela hash será setado pelo usuario
    structure = new Student[size_vector]; // aloca um vetor de objetos do tipo Student para armazenar os elementos da tabela hash na estrutura
}

Hash::~Hash()
{
    delete[] structure; // desaloca o vetor de objetos do tipo Student
}

bool Hash::isFull()
{
    return (quantity == max_itens); // retorna verdadeiro se a quantidade de elementos inseridos for igual ao tamanho máximo da tabela hash
}

int Hash::getSize()
{
    return quantity; // retorna a quantidade de elementos inseridos na tabela hash
}
// mudanças nas funções quando há colisão
void Hash::insert(Student student) // em espaço vazio -1 ou disponível -2
{
    int localPosition = HashFunction(student); // calcula a posição do objeto na tabela hash de inserção
    while (structure[localPosition].getRa()>0){
        localPosition = (localPosition + 1 ) % max_positions
    }
    structure[localPosition] = student;        // insere o objeto na posição calculada
    quantity++;                                // incrementa a quantidade de elementos inseridos
}

void Hash::remove(Student student)
{
    int localPosition = HashFunction(student); // calcula a posição do objeto na tabela hash de remoção
    while (structure[localPosition.getRa()] != -1){
        if (structure[localPosition].getRa() == student.getRa()){
            structure[localPosition] = Student(-2, "");
            quantity--; // decrementa a quantidade de elementos inseridos
        }
        localPosition = (localPosition + 1 ) % max_positions
    }
 
}

void Hash::search(Student &student, bool &found)
{
    int localPosition = HashFunction(Student);

    if ( structure[localPosition.getRa()] != -1){
        if (student.getRa()==structure[localPosition].getRa()){
            found = true;
            student = structure[localPosition];
            break
        }
        localPosition = (localPosition + 1 ) % max_positions
    }
   
}

void Hash::print()
{
    for (int i = 0; i < max_positions; i++)
    {
        if (structure[i].getRa()>0)
        {
            cout << "RA: " << structure[i].getRa() << " Nome: " << structure[i].getName() << endl;
        }
    }
}