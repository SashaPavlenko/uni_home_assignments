#include <iostream>
#include <string>
#include "funcs.h"

using namespace std;

int main() {

	int first_point, second_point;
	double dis;
	dis = points_longest_distance("text.txt", first_point, second_point);

	cout << dis << " " << first_point << " " << second_point;
	return 0;
}