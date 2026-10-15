#include "funs.h"
#include <cmath>

double distance(point p1, point p2) {
	return sqrt(sqr(p1.x - p2.x) + sqr(p1.y - p2.y));
}

double P(point x, point y, point z) {
	return distance(x, y) + distance(x, z) + distance(y, z);
}

double square(point x, point y, point z) {
	double p{ P(x, y, z)/2. };
	double a{ distance(x, y) }, b{ distance(x, z) }, c{ distance(y, z) };

	return sqrt(p * (p - a) * (p - b) * (p - c));
}

double distance_to_line(point x, point a1, point a2) {
	double s{ square(x, a1, a2) }, base{ distance(a1, a2) };
	
	return 2 * s / base;
}

void get_sides_tri(point x, point y, point z, double& a, double& b, double& c) {
	a = distance(x, y);
	b = distance(x, z);
	c = distance(y, z);

	double t;

	if (a < b) {
		t = a;
		a = b;
		b = t;
	}

	if (b < c) {
		if (a < c) {
			t = b;
			b = a;
			a = c;
			c = t;
		}
		else {
			t = b;
			b = c;
			c = t;
		}
	}
}

triangle_type check_triangle_type(point x, point y, point z) {
	double a, b, c;
	triangle_type index;

	get_sides_tri(x, y, z, c, a, b);

	if (abs(sqr(c) - (sqr(a) + sqr(b))) < 1e-5)
		index = tRight;
	else
		if (sqr(c) > sqr(a) + sqr(b))
			index = tObtuse;
		else
			index = tAcute;

	return index;
}