#pragma once

class Circle
{
protected:
    char type[10]; //name of the type in the inheritance hierarchy  
    double radius;

    const double PI = 3.141592653589793238463;
public:
    // constructors
    Circle();
    Circle(double _radius);
    Circle(const Circle& obj);
    
    // getters and setters
    void setR(double r);
    double getR() const;
    //add the rest yourself

    // methods
    double measure();
    void print();
};

