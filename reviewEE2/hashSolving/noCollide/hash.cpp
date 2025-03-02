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

void Hash::insert(Student student)
{
    int localPosition = HashFunction(student); // calcula a posição do objeto na tabela hash de inserção
    structure[localPosition] = student;        // insere o objeto na posição calculada
    quantity++;                                // incrementa a quantidade de elementos inseridos
}

void Hash::remove(Student student)
{
    int localPosition = HashFunction(student); // calcula a posição do objeto na tabela hash de remoção
    if (structure[localPosition].getRa() != -1)
    {
        structure[localPosition] = Student(-1, "");
        quantity--; // decrementa a quantidade de elementos inseridos
    }
}

void Hash::search(Student &student, bool &found)
{
    int localPosition = HashFunction(Student);
    Student aux = structure[localPosition]; // cria um objeto auxiliar para armazenar o objeto encontrado na tabela hash]
    if (student.getRa() != aux.getRa())
    {
        found = false;
    }
    else
    {
        found = true;
        student = aux;
    }
}

void Hash::print()
{
    for (int i = 0; i < max_positions; i++)
    {
        for (structure[i].getRa() != -1)
        {
            cout << "RA: " << structure[i].getRa() << " Nome: " << structure[i].getName() << endl;
        }
    }
}