#include <string>
#include "Lab8.h"
using namespace std;

ostream & operator<< (ostream & os, const Person & p)
{
	os << p.name << " " << p.age << endl;
	return os;
}

Student::Student() : univ("MSU"), marks(3) {}

Student::Student(const string& name, int age, const string& u, int m) :
	Person(name, age), univ(u), marks(m) {}

Student::Student(const Student& s) : Person(s), univ(s.univ), marks(s.marks) { }

Student& Student::operator=(const Student& s)
{
	if (&s != this)
	{
		Person::operator=(s); //note: for the private fields of the ancestor we call the ancestor's method!
		this->univ = s.univ;
		this->marks = s.marks;
	}
	return *this;
};

void Student::setMark(int i, int mark)
{
	if (i < 0 || i >= this->marks.length())
		throw ErrMark(i);
	marks[i] = mark;
}
 
ostream & operator<< (ostream & os, const Student & s)
{
	os << static_cast<Person>(s);
	os << s.univ << endl;
	for (int i = 0; i < s.marks.length(); ++i)
		os << s.marks[i] << " ";
	os << endl;
	return os;
}
