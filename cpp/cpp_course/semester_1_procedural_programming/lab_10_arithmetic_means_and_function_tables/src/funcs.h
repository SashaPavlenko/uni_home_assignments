#pragma once

// The function determines the ratio of the arithmetic mean of the array elements before the first zero 
// to the arithmetic mean of the elements after the first zero.
double arith_mean(double* a, int size);

// Function that returns the value 1 / sin(x).
double one_div_sin(double x);

typedef double(*type_f)(double);

// Function that prints a function in tabular form.
void print_exc(type_f func, double a = -5., double b = 5., int n = 10);

// Function that returns the number contained in the character a.
double get_num(char a);

// Function that evaluates an expression in a string of the form "digit operation-sign digit".
double str_eval(const char* expr);

// Function that reads elements into the array a.
void read(int*& a, std::size_t& n);
