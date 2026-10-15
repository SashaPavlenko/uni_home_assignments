#pragma once
#include "Circle.h"
#include <tuple>

class Cylinder :
    public Circle
{
private:
    double height;
public:
    // constructors
    Cylinder();
    Cylinder(double _radius, double _height);
    Cylinder(const Cylinder& obj);

    // getters and setters
    void setRH(double r, double h);
    std::tuple<double, double> getRH() const;
    //add the rest yourself

    // methods
    double measure();
    void print();
};

