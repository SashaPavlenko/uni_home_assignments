#include <iostream>
#include <cmath>
#include "funcs.h"

using namespace std;

int main() {

	setlocale(LC_ALL, "rus");

	// 1 task
	// cout << static_cast<int>("5");
	//print_exc(sin);
	//print_exc(one_div_sin);
	//print_exc(one_div_sin, 1., 5.);
	//print_exc(one_div_sin, 0, 1., 30);

	// 3 task
	/*cout << str_eval("6+2") << endl;
	cout << str_eval("6-2") << endl;
	cout << str_eval("6*2") << endl;
	cout << str_eval("6/2") << endl;

	while (1) {
		char* b = new char[4];
		cin >> b;

		try {
			cout << str_eval(b) << endl;
		}
		catch (int a) {
			switch (a)
			{
			case 2:
				cout << "Exception: division by zero.";
				break;
			case 3:
				cout << "Exception: the command was entered incorrectly.";
				break;
			}
		}

		delete[] b;
	}*/

	// 4 task
	try {
		size_t n{ 5 };
		int* a = new int[5];
		//int* a = nullptr;
		read(a, n);
	}
	catch (const char* a) {
		/*switch (a) {
		case 1: 
			cout << "Exception: an array with allocated memory is passed to the function.";
		}*/

		cout << a;
	}

	return 0;
}