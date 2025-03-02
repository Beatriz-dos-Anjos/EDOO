#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    Stack s1;
    int item;
    int opcao;

    cout << "Programa gerador de pilha:\n" << endl;

    do {
        cout << "Digite a opcao desejada:\n";
        cout << "1 - Inserir elemento na pilha\n";
        cout << "2 - Remover elemento da pilha\n";
        cout << "3 - Imprimir pilha\n";
        cout << "0 - Sair\n";
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Digite o elemento a ser inserido: ";
                cin >> item;
                s1.push(item);
                break;
            case 2:
                if (!s1.isEmpty()) {
                    cout << "Elemento removido: " << s1.pop() << endl;
                } else {
                    cout << "A pilha já está vazia!" << endl;
                }
                break;
            case 3:
                s1.print();
                break;
            case 0:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opcao inválida!" << endl;
        }
    } while (opcao != 0);

    return 0;
}
