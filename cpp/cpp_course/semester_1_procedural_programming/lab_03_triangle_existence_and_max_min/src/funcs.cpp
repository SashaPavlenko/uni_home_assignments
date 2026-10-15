#include "funcs.h"
#include <iostream>

double P(double a, double b, double c) {
    return a + b + c;
}

bool exist(double a, double b, double c) {
    return (a < b + c) && (b < a + c) && (c < a + b);
}

extern int z;
static int count = 1;

void f() {
    std::cout << count++;
}

double S(point x1, point x2, point x3) {
    
    return 0;
}