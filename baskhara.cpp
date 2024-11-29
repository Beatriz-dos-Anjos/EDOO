#include <iostream>
#include <math.h>
using namespace std;

bool quadEquation(double a, double b, double c, double *x1, double *x2)
{
    double delta = b * b - 4 * a * c;

    if (delta < 0)
    {
        return false;
    }
    else
    {
        *x1 = (-b + sqrt(delta)) / (2 * a);
        *x2 = (-b - sqrt(delta)) / (2 * a);
        return true;
    }
}

int main()
{
    int n;
    double a, b, c;
    double x1, x2;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;

        if (quadEquation(a, b, c, &x1, &x2))
        {
            cout << x1 << " " << x2 << "\n";
        }
        else
        {
            cout << "none" << "\n";
        }
    }

    return 0;
}