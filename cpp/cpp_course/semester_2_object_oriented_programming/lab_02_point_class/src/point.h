#pragma once
#include <iostream>
#include <tuple>

enum CoordinatesType {
    EUCLIDIAN,
    POLAR
};

class Point {
private:
    double x, y;

    std::tuple<double, double> convert_to_polar() const;

public:
    Point();
    Point(double x, double y);
    Point(const Point& other);

    void set_point(double x, double y);
    std::tuple<double, double> get_point(CoordinatesType type = CoordinatesType::EUCLIDIAN) const;
    void shift_X(double dx);
    void shift_Y(double dy);
    void print();

    bool isEqual(const Point& p, double EPS = 1e-6);

    void add(const Point& p);
    int distance_to(const Point& p);


	~Point(){
		std::cout<<"Destruct point \n";
	}

};

Point add1(Point a,  Point b);
Point add2(const Point& a, const Point& b);

typedef std::tuple<double, double> space_point;