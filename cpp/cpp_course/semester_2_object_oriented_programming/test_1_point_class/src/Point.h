#include <iostream>
#pragma once

class Point
{
private:
	double x;
	double y;
	double z;
public:
	Point(): x(0), y(0), z(0) {};
	Point(double _x, double _y, double _z) {
		this->x = _x;
		this->y = _y;
		this->z = _z;
	};

	double length();

	friend std::istream& operator >> (std::istream& in, Point& A);
	friend std::ostream& operator << (std::ostream& out, const Point& A);

	bool operator == (const Point& B) const;
	double operator - (const Point& B) const;
	Point operator + (double x);

};

