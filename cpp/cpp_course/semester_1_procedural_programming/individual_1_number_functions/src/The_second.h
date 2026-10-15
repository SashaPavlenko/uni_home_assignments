#pragma once

// Squares a number.
inline double sqr(double num) {
	return num * num;
}

// Computes the Fresnel integral with a given precision.
double int_frencl(double x, double EPS = 1e-9);

// Finds the minimum digit in the notation of a decimal integer.
int find_min_num(int n);
