#include <iostream>
#include "Circled.h"
#include "Poligon.h"
#include "Shape.h"
#include "Square.h"
#include "Triangle.h"
#include <string>
#include "funcs.h"
#include <fstream>
#include <sstream>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	string filename{"Shapes.txt"};

	int size;
	Shape** shapes = nullptr;
	
	tie(shapes, size) = get_shapes(filename);

	for (int i = 0; i < size; ++i) {
		shapes[i]->print();
		cout << endl;
	}

	//find_max(shapes, size)->print();
	//cout << readFile(filename);

	sort_shapes(shapes, size, lessArea);
	
	cout << "\n\n----------------------------------\nArray sorted by area:\n----------------------------------\n\n";
	
	for (int i = 0; i < size; ++i) {
		shapes[i]->print();
		cout << endl;
	}
	
	sort_shapes(shapes, size, lessPerimetre);
	
	cout << "\n\n----------------------------------\nArray sorted by perimeter:\n----------------------------------\n\n";
	
	for (int i = 0; i < size; ++i) {
		shapes[i]->print();
		cout << endl;
	}
	
	sort_shapes(shapes, size, lessInnerR);
	
	cout << "\n\n----------------------------------\nArray sorted by inner radius:\n----------------------------------\n\n";
	
	for (int i = 0; i < size; ++i) {
		shapes[i]->print();
		cout << endl;
	}

	for (int i = 0; i < size; i++) {
		delete shapes[i];
	}
	//delete shapes;

	return 0;
}