#include <iostream>
//#include <vector>
#include <algorithm>
#include <list>
#include <iterator>

using namespace std;
class A { };
class B : public A { };
class C : public B { };

int main() {
	A a1;
	B b1;
	C c1;

	b1 = a1;
	//a1 = c1;
	//c1 = a1;
	//a1 = b1;

	return 0;
}