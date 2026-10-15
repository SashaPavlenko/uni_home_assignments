#pragma once
#include <iostream>
#include <string>
#include <exception>
#include "Array.h"

using namespace std;
class Person {
private: // note!!! the fields are closed to descendants!
	string name;
	int age;
public:
	Person(const string& name = "noname", int age = 18) :
		name(name), age(age) {}
	friend ostream & operator<< (ostream & os, const Person & p);
};


class Student : public Person
{
private:
	string univ; // University
	Array marks;
public:
	Student();
	Student(const string& name, int age, const string& u, int m);
	Student(const Student& s);

	Student& operator=(const Student& s);
	
	void setMark(int i, int mark);
	
	friend ostream & operator<< (ostream & os, const Student & s);
};

class ErrMark : public exception { //inherit from the base exception type
private:
	int mark;
public:
	ErrMark(int n) :mark(n) {};
	const char* what() const { return "Error in mark"; }
	int getmark() const{return mark;}
 };
