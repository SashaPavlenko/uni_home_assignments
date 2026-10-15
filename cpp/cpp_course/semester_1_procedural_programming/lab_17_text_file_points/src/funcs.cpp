#include "funcs.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

double points_distance(point p1, point p2) {
	return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

point coords(string str) {
	point p;

	auto pos = str.find(" ");
	if (pos != string::npos)
		return { atof(str.substr(0, pos).c_str()), atof(str.substr(pos + 1).c_str()) };
}

double max_distance(point* arr, size_t dim, int& index1, int& index2) {
	double max_d = 0, d;

	for (int i = 0; i < dim; ++i)
		for (int j = 0; j < dim; ++j) {
			d = points_distance(arr[i], arr[j]);
			if (i != j && d > max_d) {
				max_d = d;
				index1 = i;
				index2 = j;
			}
		}
	index1++;
	index2++;
	return max_d;
}

double points_longest_distance(string filename, int& index1, int& index2) {
	ifstream f(filename);
	string str;
	size_t dim;
	int number = 0;

	getline(f, str);
	dim = stoi(str);
	point* arr_c = new point[dim];

	while (!f.eof()) {
		getline(f, str);
		number++;
		arr_c[number - 1] = coords(str);
	}

	//delete[] arr_c;
	return max_distance(arr_c, dim, index1, index2);
}