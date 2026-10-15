#pragma once
#include "Circled.h"
#include <string>

enum class type_triangle {
    Acute,
    Right,
    Obtuse
};

class Triangle :
    public Circled
{
private:
    int a;
    int b;
    int c;

    void sort_sides(bool reverse=false);
    std::string type_str() const;

public:
    Triangle();
    Triangle(int _a, int _b, int _c);
    virtual ~Triangle();

    type_triangle check_type() const;
    virtual double getarea() const; //find the area of the shape
    virtual double getperimetr() const; // find the perimeter
    virtual double getInnerR() const; //radius of the inscribed circle
    virtual double getOuterR() const; //radius of the circumscribed circle

    virtual void print() override; //print information about the type of the shape

    friend std::istream& operator >> (std::istream& in, Triangle& t);
    friend std::ostream& operator << (std::ostream& out, const Triangle& t);
};

