#pragma once
#include <iostream>
#include <string>

using std::string;

class student {
    string name;
    int course, group;
public:
    student() : name{ "Ivanov" }, course{ 1 }, group{ 1 } {}

    student(string _name, int course, int group) :
        name(_name), course(course), group(group) {}


    student(char* _name, int course, int group) :
        name(_name), course(course), group(group) {}

    virtual ~student() {};

    string get_name() const { return name; }

    int get_course() const { return course; }

    int get_group() const { return group; }
    
    virtual void print(std::ostream& os = std::cout) {
        os << name << " " << course << "." << group << "\n";
    }

};
