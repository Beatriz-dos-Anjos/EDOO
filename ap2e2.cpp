#include <iostream>
#include <fstream>
#include <cmath> 

double raizQuadrada(double num)
{
    if (num == 0)
        return 0; 
    double guess = num / 2.0;
    double prevGuess;

    do
    {
        prevGuess = guess;
        guess = (guess + num / guess) / 2.0;
    } while (std::fabs(guess - prevGuess) > 1e-6); 

    return guess;
}

bool quadEquation(double a, double b, double c, double *x1, double *x2)
{
    double discriminante = b * b - 4 * a * c;

    if (discriminante < 0)
    {
        return false; 
    }

    *x1 = (-b + raizQuadrada(discriminante)) / (2 * a);
    *x2 = (-b - raizQuadrada(discriminante)) / (2 * a);
    return true; 
}

int main()
{
    std::ifstream inputFile("ap2e2txt.txt");
    std::ofstream outputFile("ap2e2cout.txt");

    int t;         
    inputFile >> t; 

    for (int i = 0; i < t; ++i)
    {
        double a, b, c;
        inputFile >> a >> b >> c; 
        double x1, x2;
        if (quadEquation(a, b, c, &x1, &x2))
        {
            outputFile << x1 << " " << x2 << std::endl;
        }
        else
        {
            outputFile << "none" << std::endl;
        }
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
