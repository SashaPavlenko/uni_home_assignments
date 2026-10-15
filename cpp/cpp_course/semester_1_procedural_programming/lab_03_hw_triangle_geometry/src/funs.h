#pragma once

struct point {
	double x, y;
};

double distance(point, point);

inline double sqr(double a) {
	return a * a;
}

double P(point, point, point);
double square(point, point, point);
double distance_to_line(point, point, point);

enum triangle_type {
    tRight = 0,     // right
    tAcute,         // acute
    tObtuse,         // obtuse
};

void get_sides_tri(point, point, point, double&, double&, double&);
triangle_type check_triangle_type(point, point, point);