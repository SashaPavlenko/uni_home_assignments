#include <iostream>
#include "Postgraduate.h"
#include "student.h"
#include "Conscript.h"
#include "funcs.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	//int* a = new int[100];
	
	//Postgraduate f;
	//f.print();

	//cout << endl;

	//Conscript ff;
	//ff.print();

	int size{ 8 };

	student** studs = new student*[size]{
		new Postgraduate("Irina", 2020, "Kryakvin"),
		new Postgraduate(),
		new Postgraduate("Ilya", 2019, "Biden"),
		new Conscript("Alexander", 2019, 178, 43),
		new Postgraduate(),
		new Conscript(),
		new Postgraduate("Maxim", 2018, "Putin"),
		new Conscript("Vadim", 2020, 186, 42),
	};

	for (int i = 0; i < size; ++i) {
		studs[i]->print();
		cout << endl;
	}

	int index{ 0 };
	for (int i = 1; i < size; ++i) {
		if (course_less(studs[i - 1], studs[i])) {
			index = i;
		}
	}

	cout << "The first student is from the most senior year" << endl;
	studs[index]->print();

	return 0;
}