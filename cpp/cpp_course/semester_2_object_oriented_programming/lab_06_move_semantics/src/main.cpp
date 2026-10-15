#include <iostream>
#include "Lab6.h"
#include "Array_ext.h"

using namespace std;

int main() {
	/*cout << "test constructors" << endl;
	Empty a;
	Empty b("1");
	Empty c(a);
	cout << "test move-constructor" << endl;
	Empty s(-b);
	cout << "end test constructors" << endl;
	
	
	cout << "test operator= and functions" << endl;
	cout << "test =" << endl;
	c = -b;
	cout << "test f1" << endl;
	f1(b);
	cout << "test f2" << endl;
	a = f2();
	cout << "test f3" << endl;
	a = f3(c);*/

	Array a(2);
	Array b(a);
	Array c(a + b);
	a = c + b;
	
	system("pause");
	return 0;
}