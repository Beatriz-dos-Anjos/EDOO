#include <iostream>
#include <fstream>
#include <cmath> // Biblioteca para funções matemáticas

// Função auxiliar para calcular raiz quadrada com precisão
double raizQuadrada(double num)
{
    if (num == 0)
        return 0; // Raiz quadrada de 0 é 0
    double guess = num / 2.0;
    double prevGuess;

    // Continua até que a diferença entre chutes seja pequena o suficiente
    do
    {
        prevGuess = guess;
        guess = (guess + num / guess) / 2.0;
    } while (std::fabs(guess - prevGuess) > 1e-6); // Tolerância de 1e-6 para precisão

    return guess;
}

// Função para calcular as raízes da equação quadrática
bool quadEquation(double a, double b, double c, double *x1, double *x2)
{
    double discriminante = b * b - 4 * a * c;

    if (discriminante < 0)
    {
        return false; // Sem raízes reais
    }

    // Calculando as raízes manualmente
    *x1 = (-b + raizQuadrada(discriminante)) / (2 * a);
    *x2 = (-b - raizQuadrada(discriminante)) / (2 * a);
    return true; // Raízes reais existem
}

int main()
{
    // Abra o arquivo ap2e2txt.txt no modo leitura
    std::ifstream inputFile("ap2e2txt.txt");
    std::ofstream outputFile("ap2e2cout.txt");

    if (!inputFile)
    {
        std::cerr << "Erro ao abrir o arquivo de entrada!" << std::endl;
        return 1;
    }

    if (!outputFile)
    {
        std::cerr << "Erro ao abrir o arquivo de saída!" << std::endl;
        return 1;
    }

    int t;          // Número de casos de teste
    inputFile >> t; // Lê a primeira linha (quantidade de equações)

    for (int i = 0; i < t; ++i)
    {
        double a, b, c;
        inputFile >> a >> b >> c; // Lê os coeficientes de cada equação

        double x1, x2;
        if (quadEquation(a, b, c, &x1, &x2))
        {
            // Imprime no arquivo de saída as raízes calculadas
            outputFile << x1 << " " << x2 << std::endl;
        }
        else
        {
            outputFile << "none" << std::endl; // Sem raízes reais
        }
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
