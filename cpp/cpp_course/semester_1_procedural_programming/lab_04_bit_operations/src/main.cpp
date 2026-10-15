// lab_4.cpp : This file contains the "main" function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>

using namespace std;

void rev_bin(unsigned char x) {

    while (x) {
        cout << (x & 1);
        x >>= 1;
    }
    cout << endl;
}

void print_bin(unsigned char x) {
    unsigned char i{ 128 };

    while (i) {
        cout << (x & i) / i;
        // cout << (x & i);
        i >>= 1;
    }
    cout << endl;
}

unsigned int print_x2(unsigned int x) {
    /*
    Pow to 2.
    */

    return x << 1;
}

unsigned int print_div2(unsigned int x) {
    return x >> 1;
}

bool odd(unsigned int x) {
    return (x & 1);
}

int value_bit(unsigned int x, unsigned int num) {
    return (1 & (x >> (num - 1)));
}

unsigned int set_bit(unsigned int x, unsigned int num) { 
    return ((1 << (num - 1)) | x);
}

unsigned int set_bit_syp(unsigned int x, unsigned int num) {
    return (~(1 << (num - 1)) & x);
}

double my_exp(double x) {
    double sum_exp{ 0 }, a{ 1 }; 

    for (int i = 1; abs(a) > 1e-7; i++) {
        sum_exp += a;
        a *=  x / i;
    }
    return sum_exp;
}

int main()
{
    /*
    unsigned char x{ 23 };
    unsigned char y{ 102 };

    print_bin(x);

    print_bin(value_bit(x, 3));
    print_bin(set_bit(x, 4));
    print_bin(set_bit_syp(x, 2));
    */

    setlocale(LC_ALL, "rus");

    double a, b, step;

    cout << "Enter the sides: ";
    cin >> a >> b;
    cout << "Enter the step: ";
    cin >> step;
    cout << endl;

    for (double i = a; i < b; i += step) {
        cout << setw(6) << i;
        cout << setw(10) << my_exp(i) << setprecision(3);
        cout << setw(10) << exp(i) << setprecision(4) << endl;
    }

    return 0;
}