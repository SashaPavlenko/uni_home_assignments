#include "Triangle.h"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

using std::cout;
using std::endl;

void Triangle::sort_sides(bool reverse)
{
	int arr[3] = { a, b, c };

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2 - i; j++) {
            if (arr[j] > arr[j + 1] && reverse == false) {
                // swap the elements
                std::swap(arr[j], arr[j + 1]);
            }
            else if (arr[j] < arr[j + 1] && reverse == true) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }

    a = arr[0];
    b = arr[1];
    c = arr[2];
}

std::string Triangle::type_str() const
{
    std::string s;
    type_triangle t = this->check_type();
    if (t == type_triangle::Acute) {
        s = "Acute";
    }
    else if (t == type_triangle::Right) {
        s = "Right";
    }
    else {
        s = "Obtuse";
    }

    return s;
}

Triangle::Triangle() : a(1), b(1), c(1) {}

Triangle::Triangle(int _a, int _b, int _c): a(_a), b(_b), c(_c)
{
    this->sort_sides();
}

Triangle::~Triangle() {}

type_triangle Triangle::check_type() const
{
    type_triangle ret;
    if (c * c < a * a + b * b) {
        ret = type_triangle::Acute;
    }
    else if (c * c == a * a + b * b) {
        ret = type_triangle::Right;
    }
    else {
        ret = type_triangle::Obtuse;
    }

    return ret;
}

double Triangle::getarea() const
{
    double p{ this->getperimetr() / 2. };

    return std::sqrt(p * (p-a)*(p-b)*(p-c));
}

double Triangle::getperimetr() const
{
    return a+b+c;
}

double Triangle::getInnerR() const
{
    return this->getarea()*2./(a+b+c);
}

double Triangle::getOuterR() const
{
    return a*b*c/4./this->getarea();
}

void Triangle::print()
{
    cout << "Sides of the triangle: " << a << ", " << b << ", " << c << ";" << endl;
    cout << "Area: " << this->getarea() << endl;
    cout << "Perimeter: " << this->getperimetr() << endl;
    cout << "Inscribed circle radius: " << this->getInnerR() << endl;
    cout << "Circumscribed circle radius: " << this->getOuterR() << endl;
    cout << "Type of the triangle: " << this->type_str() << endl;
}

std::istream& operator>>(std::istream& in, Triangle& t)
{
    std::string s;
    in >> s;
    in >> t.a >> t.b >> t.c;
    t.sort_sides();
    
    return in;
}

std::ostream& operator<<(std::ostream& out, const Triangle& t)
{
    cout << "Sides of the triangle: " << t.a << ", " << t.b << ", " << t.c << ";" << endl;
    cout << "Area: " << t.getarea() << endl;
    cout << "Perimeter: " << t.getperimetr() << endl;
    cout << "Inscribed circle radius: " << t.getInnerR() << endl;
    cout << "Circumscribed circle radius: " << t.getOuterR() << endl;
    cout << "Type of the triangle: " << t.type_str() << endl;

    return out;
}
