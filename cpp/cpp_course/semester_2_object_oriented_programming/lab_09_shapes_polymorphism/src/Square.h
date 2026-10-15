#pragma once
#include "Poligon.h"
class Square :
    public Poligon
{
public:
    Square();
    Square(int _side);
    virtual ~Square();

    virtual void print() override; //print information about the type of the shape

    friend std::istream& operator >> (std::istream& in, Square& t);
    friend std::ostream& operator << (std::ostream& out, const Square& t);
};