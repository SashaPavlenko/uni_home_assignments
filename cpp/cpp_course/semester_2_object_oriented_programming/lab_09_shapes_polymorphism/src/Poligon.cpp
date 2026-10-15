#include "Poligon.h"
#include <cmath>
#include <iostream>
#include <string>

using std::cout;
using std::endl;

Poligon::Poligon() : number{ 3 }, side{ 1 } {};
Poligon::Poligon(int _n, int _side) : number{ _n }, side{ _side } {};

Poligon::~Poligon() {}

double Poligon::getperimetr() const
{
	return side * number;
}

double Poligon::getarea() const
{
	double R{ this->getOuterR() };
	return number*R*R/2.*sin(2*Pi/number);
}

double Poligon::getOuterR() const
{
	return static_cast<double>(side) / (2*sin(Pi/number));
}

double Poligon::getInnerR() const
{
	return static_cast<double>(side) / (2 * tan(Pi / number));
}

double Poligon::angle_between_sides()
{
	return static_cast<double>(number-2)/number*Pi/2.;
}

void Poligon::print()
{
	cout << "Side of the polygon: " << side << endl;
	cout << "Number of sides: " << number << endl;

	cout << "Area: " << this->getarea() << endl;
	cout << "Perimeter: " << this->getperimetr() << endl;
	cout << "Inscribed circle radius: " << this->getInnerR() << endl;
	cout << "Circumscribed circle radius: " << this->getOuterR() << endl;
}

std::istream& operator>>(std::istream& in, Poligon& t)
{
	std::string s;
	in >> s;
	in >> t.number >> t.side;
	return in;
}

std::ostream& operator<<(std::ostream& out, const Poligon& t)
{
	out << "Side of the polygon: " << t.side << endl;
	out << "Number of sides: " << t.number << endl;

	out << "Area: " << t.getarea() << endl;
	out << "Perimeter: " << t.getperimetr() << endl;
	out << "Inscribed circle radius: " << t.getInnerR() << endl;
	out << "Circumscribed circle radius: " << t.getOuterR() << endl;

	return out;
}
