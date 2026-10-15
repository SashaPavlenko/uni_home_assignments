#include "Circle.h"
#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS

Circle::Circle() : type{"Circle"}
{
	this->radius = 1;
}

Circle::Circle(double _radius): type("Circle")
{
	if (_radius < 0) {
		throw "IncorrectRadius";
	}

	radius = _radius ;
}

Circle::Circle(const Circle& obj)
{
	strcpy_s(this->type, obj.type);
	this->radius = obj.radius;
}

void Circle::setR(double r)
{
	if (r < 0) {
		throw "IncorrectRadius";
	}

	this->radius = r;
}

double Circle::getR() const
{
	return this->radius;
}

double Circle::measure()
{
	return PI*this->radius * this->radius;
}

void Circle::print()
{
	std::cout << "Radius = " << this->radius << "\nType = " << this->type \
		<< "\nSquare = " << this->measure() << std::endl;
}
