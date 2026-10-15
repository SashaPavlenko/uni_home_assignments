#include <iostream>
#include "funcs.h"
#include <iomanip>

#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)

using namespace std;

void read_new(double**& m, size_t& rows, size_t& cols) {
	// Exception: an already initialized matrix is passed to the function.
	// Error code: 1.
	if (m != nullptr)
		throw 1;
	
	cout << "enter number of rows: ";
	cin >> rows;
	cout << "enter number of cols: ";
	cin	>> cols;
	cout << endl;

	m = new double*[rows];
	for (size_t i = 0; i < rows; ++i)
		m[i] = new double[cols];

	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < cols; ++j)
			cin >> m[i][j];
		cout << endl;
	}
}

void delete_matrix(double**& m, const size_t rows, const size_t cols) {
	// Exception: an uninitialized matrix is passed to the function.
	// Error code: 2.
	if (m == nullptr)
		throw 2;
	
	for (size_t i = 0; i < rows; ++i)
		delete[] m[i];
	delete[] m;
}

void printM(double** m, const size_t rows, const size_t cols) {
	// Exception: an uninitialized matrix is passed to the function.
	// Error code: 2.
	if (m == nullptr)
		throw 2;

	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < cols; ++j)
			cout << setw(5) << m[i][j];
		cout << endl;
	}
	cout << endl;
}

double prop_diagonals(double**& m, const size_t size) {
	// Exception: an uninitialized matrix is passed to the function.
	// Error code: 2.
	if (m == nullptr)
		throw 2;

	double sum_main{ 0. }, sum_side{ 0. };

	for (size_t i = 0; i < size; ++i) {
		sum_main += m[i][i];
		sum_side += m[i][size - i - 1];
	}

	// Exception: division by zero.
	// Error code: 3
	if (sum_side == 0)
		throw 3;

	return sum_main / sum_side;
}

void insert_col_with_min_in_row(double**& m, size_t& rows, size_t& cols) {
	// Exception: an uninitialized matrix is passed to the function.
	// Error code: 2.
	if (m == nullptr)
		throw 2;

	double** new_m = new double* [rows];
	for (size_t i = 0; i < rows; ++i)
		new_m[i] = new double[cols + 1];

	for (size_t i = 0; i < rows; ++i) {
		double min_num{ m[i][0] };
		new_m[i][0] = m[i][0];

		for (size_t j = 1; j < cols; ++j) {
			new_m[i][j] = m[i][j];
			if (m[i][j] > 0) 
				if (min_num < 0 || m[i][j] < min_num)
				min_num = m[i][j];
		}
		
		if (min_num < 0)
			new_m[i][cols] = 0;
		else
			new_m[i][cols] = min_num;
	}
	
	delete_matrix(m, rows, cols);
	m = new_m;
	cols++;
}

void del_row_col_with_max_el(double**& m, size_t& rows, size_t& cols) {
	// Exception: an uninitialized matrix is passed to the function.
	// Error code: 2.
	if (m == nullptr)
		throw 2;

	// Find the maximum element and its indices.
	size_t index_row{ 0 }, index_col{ 0 }; 
	double max_el{ m[0][0] };

	for (size_t i = 0; i < rows; ++i)
		for (size_t j = 0; j < cols; ++j)
			if (m[i][j] > max_el) {
				max_el = m[i][j];
				index_row = i;
				index_col = j;
			}
	
	// Create a new matrix of size (rows-1)x(cols-1).
	double** new_m = new double* [rows - 1];
	for (size_t i = 0; i < rows - 1; ++i)
		new_m[i] = new double[cols - 1];

	// Delete the column with the maximum element up to the row with the maximum element.
	for (size_t i = 0; i < index_row; ++i) {
		for (size_t j = 0; j < index_col; ++j)
			new_m[i][j] = m[i][j];
		for (size_t j = index_col; j < cols - 1; ++j)
			new_m[i][j] = m[i][j + 1];
	}

	// Delete the column with the maximum element from the deletion row to the end.
	for (size_t i = index_row; i < rows - 1; ++i) {
		for (size_t j = 0; j < index_col; ++j)
			new_m[i][j] = m[i+1][j];
		for (size_t j = index_col; j < cols - 1; ++j)
			new_m[i][j] = m[i+1][j+1];
	}

	delete_matrix(m, rows, cols);
	m = new_m;
	rows--;
	cols--;

	// Exception: after deleting a row or a column the matrix became singular.
	// Error code: 4.
	if (rows == 0 || cols == 0)
		throw 4;
}

void del_row_by_cond(double**& m, size_t& rows, const size_t cols, func_param_type func_param) {
	// Exception: an uninitialized matrix is passed to the function.
	// Error code: 2.
	if (m == nullptr)
		throw 2;

	
	size_t size_index_arr{ 0 };
	size_t* index_arr = new size_t[rows];

	// Remember the indices of the rows that satisfy func_param.
	for (size_t i = 0; i < rows; ++i)
		if (func_param(m[i], cols)) {
			index_arr[size_index_arr] = i;
			size_index_arr++;
		}

	// Create an array that will store the following information: 
	// If the i-th row does not need to be deleted, deleting_arr[i] does not equal -1.
	// If the i-th row is going to be deleted, deleting_arr[i] equals -1.
	size_t* deleting_arr = new size_t[rows];
	for (size_t i = 0; i < rows; ++i)
		deleting_arr[i] = i;
	// For every row index we are going to delete, we set the element to -1 so that the row can be deleted from the array m later.
	for (size_t i = 0; i < size_index_arr; ++i)
		deleting_arr[index_arr[i]] = -1;

	// Delete from the array m all rows that satisfy the function condition.
	// Copy the pointers to the rows that should not be deleted into the matrix new_m.
	double** new_m = new double* [rows - size_index_arr];
	size_t index{ 0 };
	for (size_t i = 0; i < rows; ++i)
		if (deleting_arr[i] == -1)
			delete[] m[i];
		else {
			new_m[index++] = m[deleting_arr[i]];
		}

	delete[] index_arr;
	delete[] deleting_arr;
	
	// Since the rows that had to be deleted are already deleted, and the ones that had to be kept, 
	// we saved in new_m (by copying the pointers), then the matrix m does not need to be cleaned completely.
	delete[] m;

	m = new_m;
	rows = rows - size_index_arr;

	// Exception: after deleting a row or a column the matrix became singular.
	// Error code: 4.
	if (rows == 0)
		throw 4;
}

bool cond_only_zeros(double* a, size_t size) {
	// Exception: an uninitialized matrix is passed to the function.
	// Error code: 2.
	if (a == nullptr)
		throw 2;

	size_t i{ 0 };

	while (i < size && a[i] == 0)
		++i;

	return i == size;
}

bool cond_withot_pos_num(double* a, size_t size) {
	// Exception: an uninitialized matrix is passed to the function.
	// Error code: 2.
	if (a == nullptr)
		throw 2;

	size_t i{ 0 };

	while (i < size && (a[i] < 0 || abs(a[i]) < 1e-7))
		++i;

	return i == size;
}