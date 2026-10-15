#include <iostream>
#include "MyTree.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	MyTree<double> t;

	cout << endl << "Before deleting all leaves\n_______________________________________________________" << endl;
	double a[] = { 1.53,-7.47,-3.67,-0.80,-6.40,-5.94,-6.69,3.78,-6.27,-6.24, -6.28, -0.75, -0.72, -0.73, -0.71 };
	int size = sizeof(a) / sizeof(double);
	for (int i = 0; i < size; ++i) {
		t.addNode(a[i]);
	}

	cout << t;


	cout << endl << "After deleting all leaves\n_______________________________________________________" << endl;
	t.del_leafs();
	cout << t;
	return 0;
}