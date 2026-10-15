#pragma once
#include "student.h"
#include <string>

using std::string;

class Postgraduate :
    public student
{
private:
    int year_adm;
    string sci_director;

public:
    // constructors
    Postgraduate();
    Postgraduate(string _name, int year, string sci_name);

    virtual ~Postgraduate() {};

    // getters and setters
    int get_year_adm() const { return year_adm; };
    string get_sci_director() const { return sci_director; };

    virtual void print(std::ostream& os = std::cout);
};



