#pragma once
class Shape
{
public:
	virtual ~Shape() {};

	virtual void print() = 0; //print information about the type of the shape
	virtual double getarea() const = 0; //find the area of the shape
	virtual double getperimetr() const = 0; // find the perimeter

	double Pi = 3.141592653589793238463;
};

