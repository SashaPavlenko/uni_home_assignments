#include <iostream>
#include <iomanip>
#include <cmath>
#include "funcs.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    
    int num;

    cout << "Enter a number: ";
    cin >> num;

    cout << endl;
    print_bin(num);
    cout << endl;
    print_mem_bin(num);
    cout << endl << endl;

    double a, b, step;

    cout << "Enter the bounds: ";
    cin >> a >> b;
    cout << "Enter the step: ";
    cin >> step;
    cout << "Exponent function on the given interval: " << endl;

    for (double i = a; i < b; i += step) {
        cout << setw(6) << i;
        cout << setw(10) << my_exp(i) << setprecision(3);
        cout << setw(10) << exp(i) << setprecision(4) << endl;
    }
    
    cout << "Cosine function on the given interval: " << endl;

    for (double i = a; i < b+step; i += step) {
        cout << setw(6) << i;
        cout << setw(10) << my_cos(i) << setprecision(3);
        cout << setw(10) << cos(i) << setprecision(3) << endl;
    }

    cout << endl << "Function that builds, on an interval, a table of values of another function given as a parameter: " << endl;

    good_print(sin);



    return 0;
}