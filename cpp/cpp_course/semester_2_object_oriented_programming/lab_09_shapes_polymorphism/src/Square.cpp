#include "Square.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;

Square::Square(): Poligon(4, 1) {}

Square::Square(int _side): Poligon(4, _side) {}

Square::~Square() {}

void Square::print()
{
	cout << "Side of the square: " << side << endl;

	cout << "Area: " << this->getarea() << endl;
	cout << "Perimeter: " << this->getperimetr() << endl;
	cout << "Inscribed circle radius: " << this->getInnerR() << endl;
	cout << "Circumscribed circle radius: " << this->getOuterR() << endl;
}

std::istream& operator>>(std::istream& in, Square& t)
{
	std::string s;
	in >> s;
	in >> t.side;
	t.number = 4;

	return in;
}

std::ostream& operator<<(std::ostream& out, const Square& t)
{
	out << "Side of the square: " << t.side << endl;

	out << "Area: " << t.getarea() << endl;
	out << "Perimeter: " << t.getperimetr() << endl;
	out << "Inscribed circle radius: " << t.getInnerR() << endl;
	out << "Circumscribed circle radius: " << t.getOuterR() << endl;

	return out;
}
