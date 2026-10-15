#pragma once
#include "Circle.h"
class Sphere :
    public Circle
{
public:
    // constructors
    Sphere();
    Sphere(double _radius);
    Sphere(const Sphere& obj);

    // getters and setters
    void setR(double r);
    double getR() const;

    // methods
    double measure();
    void print();
};

