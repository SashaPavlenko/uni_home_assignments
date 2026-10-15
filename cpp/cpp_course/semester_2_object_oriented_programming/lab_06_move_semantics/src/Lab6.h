#pragma once
#include <string>

class Empty {
	//a class demonstrating when constructors, destructors and operator= are called
private:
	std::string name;
// constructors
public:
	Empty();
	Empty(std::string s);
	Empty(const Empty& other);
	Empty(const Empty&& other)noexcept;
// destructor
	~Empty();
//operator =
	Empty operator-();
	Empty& operator=(const Empty& other);
	Empty& operator=(const Empty&& other)noexcept;
};

void f1(Empty a);
Empty f3(Empty& a);
Empty f2();