#pragma once
#include "student.h"
#include <string>

using std::string;

class Conscript: 
	public student
{
private:
	int year_of_con;
	int height;
	int size_of_shoes;

public:
	// constructors
	Conscript();
	Conscript(string name, int year, int _height, int size);

	virtual ~Conscript() {};

	// getters and setters
	int get_year_of_con() const { return this->year_of_con; };
	int get_height() const { return this->height; };
	int get_size_of_shoes() const { return this->size_of_shoes; };

	virtual void print(std::ostream& os = std::cout);
};

