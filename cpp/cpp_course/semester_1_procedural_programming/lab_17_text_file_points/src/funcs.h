#pragma once
#include <string>

using namespace std;

// Task 1
struct point {
	double x, y;
};
point coords(string str);
double max_distance(point* arr, size_t dim, int& index1, int& index2);
double points_distance(point p1, point p2);
double points_longest_distance(string filename, int& index1, int& index2);
