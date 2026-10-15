#pragma once
#include "Circled.h"
#include <iostream>

class Poligon :
    public Circled
{
protected:
    int number;
    int side;
public:
    Poligon();
    Poligon(int _n, int _side);
    virtual ~Poligon();

    virtual double getperimetr() const; // find the perimeter
    virtual double getarea() const; //find the area of the shape
    virtual double getOuterR() const; //radius of the circumscribed circle
    virtual double getInnerR() const; //radius of the inscribed circle

    virtual void print() override; //print information about the type of the shape

    double angle_between_sides();

    friend std::istream& operator >> (std::istream& in, Poligon& t);
    friend std::ostream& operator << (std::ostream& out, const Poligon& t);
};

