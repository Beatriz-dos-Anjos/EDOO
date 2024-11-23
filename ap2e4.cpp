#include <time.h>
#include <stdlib.h>
#include <iostream>

int main() {


    while (true){
        long sec;
        time ( &sec );
        srand ( (unsigned)sec);

        int randomNumber = (rand()%15)+1;
        bool guessed = false;

        for (int i=0; i<3; i++){
            
            int guessedNumber;

            std::cout <<"\nDiga um número\n";
            std::cin>>guessedNumber;


            if (guessedNumber==randomNumber) {
                std::cout << "Parabéns, você acertou.\n";
                guessed = true;
                break; }
            else if (guessedNumber>randomNumber) {
                std::cout <<"O número é menor que o que você digitou\n";
            }
            else{
                std::cout<<"O número é maior que o que você digitou\n";
            }


            }

            if (guessed == false) {
                std::cout <<"\t\nO número correto era:" <<randomNumber ;
                
            }
            char answer;
            std::cout <<"\t\nVocê quer continuar jogando(T/F)?\n";
                std::cin>>answer;

                if (answer=='F') {
                    break;
                }
        


        }
    }


