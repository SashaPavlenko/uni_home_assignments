#include "Postgraduate.h"
#include "student.h"

Postgraduate::Postgraduate(): student("Ivanov", 1, 1)
{
	this->year_adm = 2021;
	this->sci_director = "Gerasimenko";
}

Postgraduate::Postgraduate(string _name, int year, string sci_name): student(_name, 2021-year + 1, 1)
{
	if (year < 1900 || year > 2021) {
		throw "IncorrectYear";
	}
	
	this->year_adm = year;
	this->sci_director = sci_name;
}

void Postgraduate::print(std::ostream& os)
{
	os << this->get_name() << " " << this->get_course() << "." << this->get_group() << "\n";
	os << "Year of going to the university: " << this->year_adm << "\nName of science director: " \
		<< this->sci_director << "\n";
}