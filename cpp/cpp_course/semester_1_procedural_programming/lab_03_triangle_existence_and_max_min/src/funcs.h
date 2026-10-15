#ifndef FUNCS_H
#define FUNCS_H

#include "head2.h"

double P(double, double, double);
bool exist(double, double, double);

inline int max(int a, int b) {
	return (a > b ? a : b);
}

struct point {
	double x, y;
};

#endif