#include "Sphere.h"
#include <cstring>
#include <iostream>
#include <tuple>

Sphere::Sphere(): Circle(1.)
{
	strcpy_s(type, "Sphere");
}

Sphere::Sphere(double _radius): Circle(_radius)
{
	strcpy_s(type, "Sphere");
}

Sphere::Sphere(const Sphere& obj)
{
	this->radius = obj.radius;
	strcpy_s(this->type, obj.type);
}

void Sphere::setR(double r)
{
	this->radius = r;
}

double Sphere::getR() const
{
	return this->radius;
}

double Sphere::measure()
{
	return 4*PI*radius * radius * radius;
}

void Sphere::print()
{
	std::cout << "Radius = " << this->radius << "\nType = " << this->type \
		<< "\nVolume = " << this->measure() << std::endl;
}
