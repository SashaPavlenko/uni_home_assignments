#include <iostream>

using namespace std;

// A matrix of real numbers in dynamic memory is given.
// Write a function that computes the sum of the minimum values of the matrix rows.
double sum_mins_in_rows(double** matr, int rows, int cols) {
	double sum{ 0. };

	for (int i = 0; i < rows; ++i) {
		double minn{ matr[i][0] };

		for (int j = 1; j < cols; ++j)
			if (minn > matr[i][j])
				minn = matr[i][j];
		
		sum += minn;
	}

	return sum;
}

int main() {

	int rows{ 3 };
	int cols{ 3 };
	double** a = new double* [rows] {
		new double[cols] {1, 0, 3},
		new double[cols] {-3, 2, -100},
		new double[cols] {4, 4, 3},
	};
	

	//int rows{ 1 };
	//int cols{ 1 };
	//double** a = new double* [rows] {
	//	new double[cols] {1},
	//};
	
	cout << sum_mins_in_rows(a, rows, cols);

	return 0;
}
