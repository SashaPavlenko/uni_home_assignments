#include <iostream>
#include "point.h"
#include <cmath>

const double PI = 3.141592653589793238463;

std::tuple<double, double> Point::convert_to_polar() const
{
    double phi;
    if (x == 0) {
        phi = (y > 0) ? (PI/2) : (-PI / 2);
    } 
    else {
        phi = atan(y / x);
    }
    
    //return std::tuple<double, double>(std::sqrt(x*x + y*y), phi);
    double R{ std::sqrt(x * x + y * y) };

    return std::make_tuple(R, phi);
}

Point::Point() {
    this->x = 0;
    this->y = 0;
	std::cout<<"Point created - ("<<this->x<<","<<this->y <<")"<<std::endl;
}

Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;
    std::cout << "Instance created. " << std::endl;
}

Point::Point(const Point& other)
{
    x = other.x;
    y = other.y;
    std::cout << "Object copied. " << std::endl;
}

void Point::set_point(double x, double y)
{
    this->x = x;
    this->y = y;

    std::cout << "Values saved. " << std::endl;
}

std::tuple<double, double> Point::get_point(CoordinatesType type) const
{
    if (type == EUCLIDIAN) {
        return std::tuple<double, double>(x, y);
    }
    else {
        return convert_to_polar();
    }
}

void Point::shift_X(double dx)
{
    this->x = this->x + dx;
}

void Point::shift_Y(double dy)
{
    this->y = this->y + dy;
}

void Point::print()
{
    std::cout << "(" << x << ", " << y << ")" << std::endl;
}

bool Point::isEqual(const Point& p, double EPS)
{   
    return (this->x - p.x) < EPS && (this->y - p.y) < EPS;
}

void Point::add(const Point& p)
{
    this->x += p.x;
    this->y += p.y;
}

int Point::distance_to(const Point& p)
{   
    return std::sqrt((p.x - this->x)* (p.x - this->x) + (p.y - this->y)* (p.y - this->y));
}

Point add1(Point a, Point b)
{
    space_point p1{ a.get_point() }, p2{ b.get_point() };
    double x_new{ std::get<0>(p1) + std::get<0>(p2) }, y_new{ std::get<1>(p1) + std::get<1>(p2) };
    return Point(x_new, y_new);
}

Point add2(const Point& a, const Point& b)
{
    double xa, ya, xb, yb;
    std::tie(xa, ya) = a.get_point();
    std::tie(xb, yb) = b.get_point();

    //space_point p1{ a.get_point() }, p2{ b.get_point() };
    //double x_new{ std::get<0>(p1) + std::get<0>(p2) }, y_new{ std::get<1>(p1) + std::get<1>(p2) };
    //return Point(x_new, y_new);

    return Point(xa+xb, ya+yb);
}
