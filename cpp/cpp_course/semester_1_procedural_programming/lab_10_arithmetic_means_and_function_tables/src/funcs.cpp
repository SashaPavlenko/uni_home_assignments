#include <iostream>
#include "funcs.h"
#include <iomanip>
#include <cmath>
#include <stdlib.h>
#include <cassert> 

using namespace std;

double arith_mean(double* a, int size) {
	double sum_before{ 0. }, sum_after{ 0. };
	int i{ 0 }, count_before{ 0 }, count_after{ 0 };

	while (i < size && a[i] != 0) {
		sum_before += a[i];
		count_before++;
		
		i++;
	}

	// Exception: no zero element was found.
	// Error code: 1.
	if (i == size)
		throw 1;

	// Exception: there are no elements before the first zero.
	// Error code: 2.
	if (count_before == 0)
		throw 2;

	for (i = i + 1; i < size; i++) {
		sum_after += a[i];
		count_after++;
	}

	// Exception: there are no elements after the first zero.
	// Error code: 3.
	if (count_after == 0)
		throw 3;

	// Exception: the arithmetic mean after the first zero is zero (DivisionByZero).
	// Error code: 4.
	if (sum_after == 0)
		throw 4;

	double arith_before{ sum_before / count_before }, arith_after{ sum_after / count_after };

	return arith_before / arith_after;
}

double one_div_sin(double x) {
	double res{ sin(x) };
	if (res)
		return 1 / res;
	else
		// Exception: division by 0.
		// Error code: 1 of type int.
		throw 1;
}

void print_exc(type_f func, double a, double b, int n) {
	double h{ (b - a) / static_cast<double>(n) };

	cout << "–––––––––––––––––––––––––––";
	for (double i = a; i < b + h; i += h) {
		cout << endl;
		try {
			cout << "|" << setw(8) << i << setw(3) << "|" << setw(14) << func(i) << '|';
		}
		catch (int) {
			cout << "For i = " << i << " the value of the function is not defined";
		}
		
		cout << endl << "–––––––––––––––––––––––––––";
	}
	cout << endl;
}

double get_num(char a) {
	switch (a)
	{
	case '0': return 0; break;
	case '1': return 1; break;
	case '2': return 2; break;
	case '3': return 3; break;
	case '4': return 4; break;
	case '5': return 5; break;
	case '6': return 6; break;
	case '7': return 7; break;
	case '8': return 8; break;
	case '9': return 9; break;
	}
}

double str_eval(const char* expr) {
	// double a{ atof(expr[0]) };
	// double b{ atof(expr[2]) };
	
	double a{ get_num(expr[0]) };
	double b{ get_num(expr[2]) };

	switch (expr[1])
	{
	case '+': 
		return a + b; 
		break;
	
	case '-': 
		return a - b;
		break;

	case '*': 
		return a * b;
		break;
	case '/': 
		if (b)
			return a / b;
		else
			// Exception: division by zero.
			// Error code: 2 of type int.
			throw 2;
		break;
	
	default:
		// Exception: the command was entered incorrectly.
		// Error code: 3 of type int.
		throw 3;
		break;
	}
}

void read(int*& a, std::size_t& n) {

	//assert(a == nullptr);
	
	if (a != nullptr)
		// Exception: the array is located in dynamic memory.
		// Error code: 1.
		throw "ExistedArray";

	cout << "Enter the size of the arrays: ";
	cin >> n;
	a = new int[n];

	for (size_t i = 0; i < n; i++)
		cin >> a[i];
}