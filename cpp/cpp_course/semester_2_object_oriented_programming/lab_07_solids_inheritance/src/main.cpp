#include "Circle.h"
#include "Cone.h"
#include "Cylinder.h"
#include "Sphere.h"
#include "funcs.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
	////Sphere a;
	//Cone a;
	////Cylinder a;
	////Sphere a;

	//a.print();
	//cout << a.measure();

	string str, filename{ "test.txt" }, subs;
	str = readFile(filename);

	int index{ 0 }, pos{ 0 }, i{ 0 };

	while (index != -1)
	{
		subs = str.substr(pos, str.find('\n', pos));
		pos = str.find('\n', pos) + 1;

		unsigned int tpos{ subs.find(" ") };
		string type_shape{ subs.substr(0, tpos) };

		if (type_shape == "Cone") {
			int r, h;
			tie(r, h) = getRH(subs, 2);
			Cone A(r, h);
			A.print();
			cout << endl;

			Cone B(A);
			B.print();
			cout << endl;
		}
		else if (type_shape == "Sphere") {
			int r, h;
			tie(r, h) = getRH(subs, 1);
			Sphere A(r);
			A.print();
			cout << endl;
		}
		else if (type_shape == "Cylinder") {
			int r, h;
			tie(r, h) = getRH(subs, 2);
			Cylinder A(r, h);
			A.print();
			cout << endl;
		}
		else if (type_shape == "Circle") {
			int r, h;
			tie(r, h) = getRH(subs, 1);
			Circle A(r);
			A.print();
			cout << endl;

		}

		index = str.find('\n', pos);
	}

	return 0;
}