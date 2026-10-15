#include <iostream>
#include "funcs.h"

int main() {

	/*
	double a[] = { 1, 1, 1, -1 };
	double b[] = { 0.5, 0.5, 0.5, -0.5 };
	double c[4];
	int n{ 2 };

	prod_matrix(a, b, c, n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			std::cout << c[i * n + j] << " ";
		std::cout << std::endl;
	}
	*/

	double a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
	int n{ 4 };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			std::cout << a[i * n + j] << " ";
		std::cout << std::endl;
	}

	std::cout << std::endl;

	// tran_matrix(a, n);
	flip_matrix_90(a, n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			std::cout << a[i * n + j] << " ";
		std::cout << std::endl;
	}

	return 0;
}