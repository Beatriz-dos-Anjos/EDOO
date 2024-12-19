#include <stdio.h>

int main() {
    int a = 10;          
    int b = 20;          
    int c = a + b;       
    int d = a * b;       

    int and = (a > 5) && (b < 25);  
    int or = (a < 5) || (b > 15);   

    printf("AND- %d\n", and);  
    printf("OR- %d\n", or);   
    if (c > d && and) {  
        printf("C é maior que D ");
    } else {
        printf("D é maior ou igual a C ou AND errado");
    }

    return 0;
}
