#include <iostream>
#include "The_second.h"

double int_frencl(double x, double EPS) {
	double sum{ 0.0 }, a;
	double count{ 3. }, fac{ -1. };

	const double HALF_PI = 3.141592653589793 / 2.;

	a = (HALF_PI) * x * x * x / count;

	while (abs(a) > EPS) {
		sum += a;

		fac += 2.;
		count += 4.;

		a = -a * sqr(x * x) * sqr(HALF_PI) * (count - 4.) / count / (fac + 1.) / (fac + 2.);
	}
	return sum;
}