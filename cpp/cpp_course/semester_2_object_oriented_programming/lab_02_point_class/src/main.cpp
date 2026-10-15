#include <iostream>
#include "point.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	//Point p1(3, 0), p2(0, 4);
	////Point p3{ add2(p1, p2) };

	////p3.print();
	//cout << p1.distance_to(p2) << endl;

	Point* p2 = new Point();//or with parameters Point *p2=new Point(3,7.5);
	double x, y;
	tie(x, y) = p2->get_point();
	cout << x << " " << y << endl;
	delete p2; //must be freed!

	return 0;
}