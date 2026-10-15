#include "Cylinder.h"
#include <cstring>
#include <iostream>
#include <tuple>

Cylinder::Cylinder(): Circle(1.), height(1.)
{
	strcpy_s(this->type, "Cylinder");
}

Cylinder::Cylinder(double _radius, double _height): Circle(_radius)
{
	if (_height < 0) {
		throw "IncorrectHeight";
	}

	this->height = _height;
	strcpy_s(this->type, "Cylinder");
}

Cylinder::Cylinder(const Cylinder& obj)
{
	this->radius = obj.radius;
	this->height = obj.height;
	strcpy_s(this->type, "Cylinder");
}

void Cylinder::setRH(double r, double h)
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

std::tuple<double, double> Cylinder::getRH() const
{
	return std::tuple<double, double>(this->radius, this->height);
}

double Cylinder::measure()
{
	return PI*radius*radius*height;
}

void Cylinder::print()
{
	std::cout << "Radius = " << this->radius << std::endl << "Height = " << this->height << "\nType = " << this->type \
		<< "\nVolume = " <<  this->measure() << std::endl;
}
