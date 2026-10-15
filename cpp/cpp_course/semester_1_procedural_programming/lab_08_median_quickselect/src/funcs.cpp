#include "funcs.h"
#include <cmath>
#include <iostream>

double sum_of_el(double* a, int size)
{
	double sum{ 0.0 };

	if (!size)
		return 0;
	
	return sum + *a + sum_of_el(a+1, size-1);
}

double max_arr(double* a, int size) {
	if (size == 1)
		return a[0];
	else
	{
		double x{ max_arr(a + 1, size - 1) };
		return std::max(a[0], x);
	}
}

bool without_zeros(double* a, int size) {
	if (size == 1)
		return a[0] != 0;
	else
		return a[0] && without_zeros(a + 1, size - 1);
}