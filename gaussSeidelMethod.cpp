/*Знайти розв'язок системи нелінійних алгебраїчних рівнянь методом Гауса-Зейделя*/
/*To find solution for system of nonlinear equation using Gauss-Seidel method*/

#include <iostream>

using namespace std;

//express from the first equation x
double funcF(double x, double y) {
    return (36 - (sin(8 * x + y - 36)) / 10) / 8;
}

//express from the second equation y
double funcS(double x, double y) {
    return (sin(8 * x + y - 36)) / 100;
}

void gauss_seidel(double eps) {
    int n = 2;
    int iter = 0;
    double x = 0;
    double y = 0;
    double x1 = 4;          //initial x
    double y1 = 1;          //initial у
    do {
        iter++;
        x = x1;
        y = y1;
        x1 = funcF(x, y);   //substitute the value for x
        y1 = funcS(x1, y);  //substitute the value with new 'x' for y

    } while (abs(x1 - x) >= eps || abs(y1 - y) >= eps);

    cout << "x = " << x1 << endl << endl;
    cout << "y = " << y1 << endl << endl;
    cout << "Iter: " << iter << endl;
};

int main()
{
    double eps = 0.01;
    gauss_seidel(eps);
}