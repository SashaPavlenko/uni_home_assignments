#include <iostream>
#include "funcs.h"
#include <iomanip>

using namespace std;

bool arr_has_zero(double* a, size_t size) {
	size_t i{ 0 };

	while (i < size && a[i])
		++i;

	return i != size;
}

int count_rows_with_zero(matrix_type a, int size_row, int size_col) {
	int sum{ 0 };
	
	for (int i = 0; i < size_row; ++i)
		if (arr_has_zero(a[i], size_col))
			sum++;

	return sum;
}

//void deleteFirstRow(double** matr, int& rows, int& cols) {
//	for (int i = 0; i < rows-1; ++i) 
//		matr[i] = matr[i + 1];
//	
//	rows--; // decrease the row counter
//}

void deleteFirstRow(matrix_type matr, int& rows, int& cols) {
	for (int i = 0; i < rows - 1; ++i)
		for (int j = 0; j < cols; ++j)
			matr[i][j] = matr[i + 1][j];
	rows--;
}

void insert_row(matrix_type matr, int& rows, int cols, double* out_row, int k) {
	for (int i = rows - 1; i >= k; --i)
		for (int j = 0; j < cols; ++j)
			matr[i + 1][j] = matr[i][j];

	for (int j = 0; j < cols; ++j)
		matr[k][j] = out_row[j];

	// if (k+1 != rows)
	rows++;
}

void printM(matrix_type matr, int rows, int cols) {
	
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j)
			cout << setw(5) << matr[i][j];
		cout << endl;
	}
}

void printM(double matr[], int cols) {
	for (int i = 0; i < cols; ++i)
		cout << setw(5) << matr[i];
	cout << endl;
}

void transposeM(matrix_type matr, int sizeM) {
	for (int i = 0; i < sizeM; ++i)
		for (int j = i; j < sizeM; ++j)
			swap(matr[i][j], matr[j][i]);
}

void del_row_col(matrix_type matr, int& rows, int& cols, int M, int N) {
	for (int i = M; i < rows - 1; ++i)
		for (int j = 0; j < cols; ++j)
			matr[i][j] = matr[i + 1][j];
	rows--;

	for (int i = 0; i < rows; ++i)
		for (int j = N; j < cols - 1; ++j)
			matr[i][j] = matr[i][j + 1];
	cols--;
}

void del_row_col(matrix_type matr, int& size, int M, int N) {
	for (int i = M; i < size - 1; ++i)
		for (int j = 0; j < size; ++j)
			matr[i][j] = matr[i + 1][j];

	for (int i = 0; i < size; ++i)
		for (int j = N; j < size - 1; ++j)
			matr[i][j] = matr[i][j + 1];
	size--;
}

bool proportional_arrays(double* a, double* b, int size) {
	double m{ a[0] / b[0] };
	int i{ 1 };

	while (i < size && abs((a[i] / b[i]) - m) < 1e-7)
		i++;

	return i == size;
}

//void del_first_col(matrix_type matr, int rows, int cols) {
//	for (int i = 0; i < rows; ++i)
//		for (int j = 0; j < cols - 1; ++j)
//			matr[i][j] = matr[i][j + 1];
//}

void copy_arr(double** a, matrix_type b, int rows, int cols) {
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j)
			a[i][j] = b[i][j];
}

void copy_arr(matrix_type a, double** b, int rows, int cols) {
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j)
			a[i][j] = b[i][j];
}

double deter(matrix_type matr, int size) {
	if (size <= 2) {
		cout << matr[0][0] << " * " << matr[1][1] << " - " << matr[1][0] << " * " << matr[0][1] << " = " << count_det_size_2(matr) << endl;
		return count_det_size_2(matr);
	}
	else {
		for (int i = 0; i < size; ++i)
			for (int j = i + 1; j < size; ++j)
				if (proportional_arrays(matr[i], matr[j], size))
					return 0;
		
		// Looking for the row with the most zeros.
		int index{ 0 };
		if (count_rows_with_zero(matr, size, size)) {
			int max{ 0 };
			for (int i = 0; i < size; ++i) {
				if (arr_has_zero(matr[i], size)) {
					int count{ 0 };
					for (int j = 0; j < size; ++j)
						if (matr[i][j] == 0)
							count++;
					if (count > max) {
						max = count;
						index = i;
					}
				}
			}
		}

		double sum{ 0. };
		
		// Create a dynamic array in which the elements of the static array will be stored.
		// This is needed so that in the static matrix we first delete rows and columns and can then restore them.
		double ** a = new double* [size];
		for (int i = 0; i < size; ++i)
			a[i] = new double[size];

		for (int i = 0; i < size; ++i) { 
			copy_arr(a, matr, size, size);

			printM(matr, size, size);

			double num{ a[index][i] }, k{ static_cast<double>(koef_det(index, i)) };
			
			cout << num << " " << k << " " << size << endl;

			if (num != 0) {
				del_row_col(matr, size, index, i);

				printM(matr, size, size);
				cout << endl;

				sum += num * k * deter(matr, size);

				size++;
			}

			copy_arr(matr, a, size, size);
		}

		for (int i = 0; i < size; ++i)
			delete[] a[i];

		return sum;
	}
}