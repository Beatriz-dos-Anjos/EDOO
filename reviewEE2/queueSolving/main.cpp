#include "queue.h"
#include <iostream>

using namespace std;

int main() {
    Queue fila1; // Criando um objeto do tipo Queue

    int opcao, item;
    do {
        cout << "1 - Inserir\n2 - Remover\n3 - Imprimir\n0 - Sair\n";
        cin >> opcao;

        switch (opcao) {
        case 1:
            cout << "Digite um número: ";
            cin >> item;
            fila1.enqueue(item);
            break;
        case 2:
            cout << "Elemento removido: " << fila1.dequeue() << endl;
            break;
        case 3:
            fila1.print();
            break;
        case 0:
            cout << "Saindo...\n";
            break;
        default:
            cout << "Opção inválida!\n";
        }
    } while (opcao != 0);

    return 0;
}
