#pragma once

// Prints a number to the console in binary form. 
// Output format - from the least significant digits to the most significant.
void print_bin(int);
void print_bin(short);

// Prints the binary digits of a number to the console. 
// Output format - from the least significant digits to the most significant.
void print_mem_bin(int);
void print_mem_bin(char);


// Prints a number to the console in binary form.
// From the most significant to the least significant.
void print_bin_by_order(unsigned char);

// Function that checks the value of the i-th bit of an integer. 
int value_bit(unsigned int, unsigned int);

// Function that sets the value of the i-th bit of an integer.
unsigned int set_bit(unsigned int, unsigned int, unsigned int);


// Function that clears the value of the i-th bit of an integer.
unsigned int set_bit_syp(unsigned int, unsigned int);

// Function that computes the exponent with a given precision, using the Taylor series expansion.
double my_exp(double);

// Function that computes the cosine with a given precision, for an angle in radians, using the Taylor series expansion.
double my_cos(double);

// Function that builds, on an interval, a table of values of another function given as a parameter.
void good_print(double (*)(double));