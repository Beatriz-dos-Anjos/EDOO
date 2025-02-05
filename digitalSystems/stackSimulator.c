#include <stdio.h>

int multiply(int a, int b, int c)
{
    int result = a * b * c;
    return result;
} // function to administrate the stack

int main()
{
    int x = 2;
    int y = 3;
    int z = 4;
    int a;

    a = multiply(x, y, z);
    printf("The result is  %d\n", a);

    return 0;
}