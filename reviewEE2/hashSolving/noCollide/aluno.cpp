#include "aluno.h"
#include <string>
using namespace std;
Student::Student() //construtor que ajudará na construção da tabela Hash
{
    ra = -1;
    name = "";
}

Student::Student( int r, string n) { //construtor de aluno geral 
    ra = r;
    name = n;
}

string Student::getName(){
    return name;
}

Student::getRa(){
    return ra;
}