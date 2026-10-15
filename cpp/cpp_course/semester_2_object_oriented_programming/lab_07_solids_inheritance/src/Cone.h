#pragma once
#include "Circle.h"
#include <tuple>
class Cone :
    public Circle
{
private:
    double height;
public:
    // constructors
    Cone();
    Cone(double _radius, double _height);
    Cone(const Cone& obj);

    // getters and setters
    void setRH(double r, double h);
    std::tuple<double, double> getRH() const;
    //add the rest yourself

    // methods
    double measure();
    void print();
};

