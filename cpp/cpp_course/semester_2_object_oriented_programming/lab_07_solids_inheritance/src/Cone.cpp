#include "Cone.h"
#include <cstring>
#include <iostream>

#define _CRT_SECURE_NO_WARNINGS

Cone::Cone(): Circle(1.), height(1.)
{
	strcpy_s(this->type, "Cone");
}

Cone::Cone(double _radius, double _height): Circle(_radius)
{
	if (_height < 0) {
		throw "IncorrectHeight";
	}

	this->height = _height;
	strcpy_s(this->type, "Cone");
}

Cone::Cone(const Cone& obj)
{
	this->radius = obj.radius;
	this->height = obj.height;
	strcpy_s(this->type, obj.type);
}

void Cone::setRH(double r, double h)
{
	if (r < 0) {
		throw "IncorrectRadius";
	}

	if (h < 0) {
		throw "IncorrectHeight";
	}

	this->radius = r;
	this->height = h;
}

std::tuple<double, double> Cone::getRH() const
{
	return std::tuple<double, double>(this->radius, this->height);
}

double Cone::measure()
{
	return 1./3*PI*radius*radius*height;
}

void Cone::print()
{
	std::cout << "Radius = " << this->radius << std::endl << "Height = " << this->height << "\nType = " << this->type \
		<< "\nVolume = " << this->measure() << std::endl;
}
