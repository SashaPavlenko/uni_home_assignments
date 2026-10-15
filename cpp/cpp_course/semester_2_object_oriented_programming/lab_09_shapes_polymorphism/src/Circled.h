#pragma once
#include "Shape.h"
class Circled :
    public Shape
{
public:
    virtual ~Circled() {};

    virtual double getInnerR() const  = 0; //radius of the inscribed circle
    virtual double getOuterR() const = 0; //radius of the circumscribed circle
};

