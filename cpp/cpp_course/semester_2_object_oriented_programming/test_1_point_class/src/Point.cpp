#include "Point.h"
#include <cmath>

double EPS = 1e-6;

double Point::length()
{
	return sqrt( this->x * this->x + this->y * this->y + this->z * this->z );
}

bool Point::operator==(const Point& B)  const
{
	return abs(this->x - B.x) < EPS && abs(this->y - B.y) < EPS && abs(this->z - B.z) < EPS;
}

double Point::operator-(const Point& B) const
{
	Point C(this->x - B.x, this->y - B.y, this->z - B.z);
	return C.length();
}

Point Point::operator+(double x)
{
	return Point(this->x + x, this->y, this->z);
}

std::istream& operator>>(std::istream& in, Point& A)
{
	in >> A.x >> A.y >> A.z;
	return in;
}

std::ostream& operator<<(std::ostream& out, const Point& A)
{
	out << "(" << A.x << "; " << A.y << "; " << A.z << ")";
	return out;
}