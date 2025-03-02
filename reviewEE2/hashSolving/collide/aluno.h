#include <string>
using namespace std;
class Student {
    private : 
    int ra;
    string name;

    public:
    Student(); // construtor a ser inicializado com valores padrão na tabela HASH
    Student(int r, string n); //construtor geral
    int getRa();
    string getName();
}