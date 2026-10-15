#include <iostream>
#include "funcs.h"

using namespace std;

int main() {


	int** a = new int*[4] {
		new int[4] {1, 1, 1, 1},
		new int[4] {2, 2, 2, 2},
		new int[4] {3, 3, 3, 3},
		new int[4] {4, 4, 4, 4},
	};

	cout << sum_by_cond(a, 4, 4) << endl;
	delete_matrix(a, static_cast<size_t>(4), static_cast<size_t>(4));
	
	int** b = new int* [3]{
		new int[3] {1, 1, 1},
		new int[3] {2, 2, 2},
		new int[3] {3, 3, 3},
	};
	cout << sum_by_cond(b, 3, 3) << endl;
	delete_matrix(b, static_cast<size_t>(3), static_cast<size_t>(3));

	int** c = new int* [2]{
		new int[2] {1, 1},
		new int[2] {2, 2},
	};
	cout << sum_by_cond(c, 2, 2) << endl;
	delete_matrix(c, static_cast<size_t>(2), static_cast<size_t>(2));

	int** d = new int* [1]{
		new int[1] {1},
	};
	cout << sum_by_cond(d, 1, 1) << endl;

	delete_matrix(d, static_cast<size_t>(1), static_cast<size_t>(1));
	return 0;
}