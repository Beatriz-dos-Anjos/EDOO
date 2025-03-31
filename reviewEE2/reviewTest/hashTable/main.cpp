#include <vector>
#include <iostream>

using namespace std;

void imprimirHashIndices(vector<int> valores)
{
    int i = 0;

    for (i = 0; i < valores.size(); i++)
    {
        int h = valores[i] % 10;
        cout << h;
    }
}

//--------------------
#include <iostream>
#include <vector>
using namespace std;

bool existeParComSoma(vector<int> numeros, int X)
{
    // Tamanho máximo dos números que vamos suportar
    const int MAX = 1000;

    // Vetor que simula uma tabela hash de valores já vistos
    // Inicialmente todos são false (nenhum número foi visto ainda)
    bool jaVisto[MAX] = {false};

    // Percorre todos os números do vetor
    for (int i = 0; i < numeros.size(); i++)
    {
        int n = numeros[i];

        // Calcula o valor que, somado com n, daria X
        int complemento = X - n;

        // Verifica se esse complemento já apareceu antes no vetor
        if (complemento >= 0 && complemento < MAX && jaVisto[complemento])
        {
            // Se sim, encontramos um par que satisfaz a condição
            return true;
        }

        // Marca o número atual como já visto
        // Assim ele pode ser complemento de algum valor futuro
        if (n >= 0 && n < MAX)
        {
            jaVisto[n] = true;
        }
    }

    // Terminamos de percorrer tudo e não achamos nenhum par válido
    return false;
}


