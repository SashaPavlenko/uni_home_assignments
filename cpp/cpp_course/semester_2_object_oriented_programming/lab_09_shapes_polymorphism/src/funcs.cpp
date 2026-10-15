#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <tuple>
#include "funcs.h"
#include "Poligon.h"
#include "Shape.h"
#include "Circled.h"
#include "Square.h"
#include "Triangle.h"

std::string readFile(const std::string& fileName) {
	std::ifstream f(fileName);
	std::stringstream ss;
	ss << f.rdbuf();

	std::string sss = ss.str();
	if (sss[sss.length() - 1] == *"\n") {
		sss.erase(sss.length() - 2);
	}

	return sss;
}

bool lessArea(const Shape* f1, const Shape* f2)
{
	return f1->getarea() < f2->getarea();
}

bool lessPerimetre(const Shape* f1, const Shape* f2)
{
	return f1->getperimetr() < f2->getperimetr();
}

bool lessOuterR(const Shape* f1, const Shape* f2)
{
	Circled* ff1 = dynamic_cast<Circled*>(const_cast<Shape*>(f1));
	Circled* ff2 = dynamic_cast<Circled*>(const_cast<Shape*>(f2));
	return ff1->getOuterR() < ff2->getOuterR();
}

bool lessInnerR(const Shape* f1, const Shape* f2)
{
	Circled* ff1 = dynamic_cast<Circled*>(const_cast<Shape*>(f1));
	Circled* ff2 = dynamic_cast<Circled*>(const_cast<Shape*>(f2));
	return ff1->getInnerR() < ff2->getInnerR();
}

std::tuple<Shape**, int> get_shapes(std::string filename)
{
	std::string str = readFile(filename);
	Shape** shapes;
	int size{ std::count(str.begin(), str.end(), '\n') / 2 }, k{ 0 };
	shapes = new Shape * [size];

	std::string s;
	std::stringstream stream(str);

	while (!stream.eof()) {
		stream >> s;
		if (s == "Triangle") {
			int a, b, c;
			stream >> a >> b >> c;
			Triangle* t = new Triangle(a, b, c);
			shapes[k++] = t;
		}
		else if (s == "Square") {
			int side;
			stream >> side;
			shapes[k++] = new Square(side);
		}
		else if (s == "Poligon") {
			int n, side;
			stream >> n >> side;
			shapes[k++] = new Poligon(n, side); 
			//std::cout << n << " " << side << std::endl;
		}

		//std::cout << s << std::endl;
	}
	stream.beg;
	stream.clear();

	return std::make_tuple(shapes, size);
}

Shape* find_max(Shape** shapes, int size)
{
	int k{ 0 };
	for (int i = 1; i < size; ++i) {
		if (shapes[i]->getarea() > shapes[k]->getarea()) {
			k = i;
		}
	}

	return shapes[k];
}

void sort_shapes(Shape** shapes, int size, my_compare cond)
{
	for (int i = 0; i < size; ++i) {
		for (int j = 1; j < size - i; ++j) {
			if (cond(shapes[j-1], shapes[j])) {
				std::swap(shapes[j], shapes[j - 1]);
			}
		}
	}
}
