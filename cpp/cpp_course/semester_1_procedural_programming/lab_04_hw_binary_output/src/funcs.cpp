#include <iostream>
#include <iomanip>

using namespace std;

void print_bin(int number)
{
    do {
        cout << (number & 1);
        number = number >> 1;
    } while (number);
}

void print_bin(short number)
{
    do {
        cout << (number & 1);
        number = number >> 1;
    } while (number);
}

void print_mem_bin(int number) {
    for (int i = 0; i < sizeof(int) * 8; ++i) {
        cout << (number & 1);
        number = number >> 1;
    }
}

void print_mem_bin(char number) {
    for (int i = 0; i < sizeof(char) * 8; ++i) {
        cout << (number & 1);
        number = number >> 1;
    }
}

void print_bin_by_order(unsigned char x) {
    unsigned char i{ 128 };

    while (i) {
        cout << (x & i) / i;
        i >>= 1;
    }
    cout << endl;
}

int value_bit(unsigned int x, unsigned int num) {
    return (1 & (x >> (num - 1)));
}

unsigned int set_bit(unsigned int x, unsigned int num, unsigned int val) {
    return ((val << (num - 1)) | x);
}

unsigned int set_bit_syp(unsigned int x, unsigned int num) {
    return (~(1 << (num - 1)) & x);
}

double my_exp(double x) {
    double sum_exp{ 0 }, a{ 1 };

    for (int i = 1; abs(a) > 1e-7; i++) {
        sum_exp += a;
        a *= x / i;
    }
    return sum_exp;
}

double my_cos(double x) {
    double sum_cos{ 0 }, a{ 1 }, z{ 1 };

    for (int i = 1; abs(a) > 1e-7; i++) {
        sum_cos += a;
        z = -z;
        a *= z * x*x / (2*i - 1) / (2*i);
    }
    return sum_cos;
}

void good_print(double (*func)(double)) {
    double a, b, step;
    
    cout << "Enter the bounds: ";
    cin >> a >> b;
    cout << "Enter the step: ";
    cin >> step;
    cout << "Function on the given interval: " << endl;

    for (double i = a; i < b + step; i += step) {
        cout << setw(6) << i;
        cout << setw(10) << func(i) << setprecision(3) << endl;
    }
}
