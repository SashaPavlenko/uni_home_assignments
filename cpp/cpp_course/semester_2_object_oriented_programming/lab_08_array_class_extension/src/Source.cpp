#include <iostream>
#include "Lab8.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	/*Student s("Student", 18, "SFedU", 3);
	s.setMark(0, 5);
	s.setMark(1, 4);
	cout << s;
	Student s1(s);
	cout << s1;
	Student s2;
	cout << s2;
	s2 = s1;
	cout << s2;
	*/
	//for checking type compatibility
	Person p("Ivanov", 20);
	Student sp("Petrov", 19, "SFedU", 3);
	p = sp;
	cout << p;
	// sp = p; will cause a compilation error
	Person* pp = &p;
	Student* ss = &sp;
	pp = ss;
	cout << *pp;
	cout << *(Student*)pp; //downcast
	//ss = pp; // compilation error
	Person& rp = sp;
	//Student& rs = p; // compilation error
	

	return 0;
}