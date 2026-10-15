#include <iostream>
#include "funcs.h"
#include <iomanip>

using namespace std;

void sign_enter(sign_arr& sign_num, double num) {
	if (num > 0)
		sign_num = pos;
	else
		if (num < 0)
			sign_num = neg;
		else
			sign_num = zero;
}

void delete_matrix(int**& m, const size_t rows, const size_t cols) {
	// Exception: an uninitialized array is passed to the function.
	// Error code: 1.
	if (m == nullptr)
		throw 2;

	for (size_t i = 0; i < rows; ++i)
		delete[] m[i];
	delete[] m;
}

void delete_matrix(int*& m, const size_t size) {
	// Exception: an uninitialized array is passed to the function.
	// Error code: 1.
	if (m == nullptr)
		throw 2;

	delete[] m;
}

void printArr(int* a, const size_t size) {
	for (size_t i = 0; i < size; ++i)
		cout << setw(5) << a[i];
	cout << endl;
}

void printM(double** m, const size_t rows, const size_t cols) {
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < cols; ++j)
			cout << setw(5) << m[i][j];
		cout << endl;
	}
	cout << endl;
}

// Task 1. 
// Check whether the array contains alternating-sign elements.
bool check_sign_alternation(int* a, size_t size) {
	
	// Exception: an array consisting of 1 element cannot have alternating elements.
	// Error code: 2.
	if (size < 2)
		throw 2;

	sign_arr sign_prev, sign_now;
	
	sign_enter(sign_prev, a[0]);
	sign_enter(sign_now, a[1]);

	size_t index{ 2 };

	while (index < size && sign_prev == sign_now){
		sign_prev = sign_now;
		sign_enter(sign_now, a[index]);
		index++;
	}

	if (size == 2)
		return sign_prev != sign_now;
	else
		return index != size;
}

// Task 2. 
// Remove from the array all elements located before the first zero element.
void del_elements_before_zero(int*& a, size_t& size) {
	// Exception: an uninitialized array is passed to the function.
	// Error code: 1.
	if (a == nullptr)
		throw 1;
	
	size_t index{ 0 };
	
	while (index < size && a[index] != 0)
		index++;

	// Exception: if the array has no zeros, an exception is thrown saying that the condition cannot be fulfilled.
	// Error code: 3.
	if (index == size)
		throw 3;

	int* b = new int[size - index];
	for (size_t i = index; i < size; ++i)
		b[i - index] = a[i];
	
	size = size - index;
	delete[] a;
	a = b;
}

// Task 3.
// Write a recursive function that replaces the negative elements of an array with their absolute values.
void replace_neg_to_zero(int* a, size_t size) {
	if (size == 1)
		a[0] = a[0]>0 ? a[0] : -a[0];
	else {
		a[size - 1] = a[size - 1] > 0 ? a[size - 1] : -a[size - 1];
		// printArr(a, size);
		replace_neg_to_zero(a, size - 1);
	}
}

bool num_is_pos(int num) {
	return num > 0;
}

int sum_part_arr_by_cond(int* begin, int* end, cond_type func) {
	int sum{ 0 };

	for (int* i = begin; i < end; ++i) {
		if (func(*(i)))
			sum += *i;
	}

	return sum;
}

// Task 4.
// Find the sum of the positive elements among the matrix elements marked in black (Figure 4).
int sum_by_cond(int** matr, size_t rows, size_t cols) {
	int sum{ 0 };
	size_t cur_row, cur_col_left, cur_col_right;

	cur_row = rows / 2;
	cur_col_left = cols / 2;
	cur_col_right = cur_col_left;

	if (cols % 2 == 0)
		cur_col_left--;

	for (size_t i = cur_row; i < rows; ++i, cur_col_left--, cur_col_right++)
		sum += sum_part_arr_by_cond(matr[i] + cur_col_left, matr[i] + cur_col_right + 1, num_is_pos);

	return sum;
}

int find_num(int* arr, size_t size, int val) {
	int cur{ arr[0] };
	bool flag{ arr[0] < val };

	for (size_t i = 0; i < size; ++i)
		if (flag) 
			if (arr[i] < val)
				cur = max(arr[i], cur);
		else 
			if (arr[i] < val) {
				cur = arr[i];
				flag = true;
			}

	// Exception: there is no element less than val in the array.
	// Error code: 4.
	if (!flag)
		throw 4;

	return cur;
}

// Task 5.
// Build a vector in which each element equals the maximum element of the corresponding matrix row that is less than a given value.
int* create_vec(int** matr, size_t rows, size_t cols, int val) {
	int* vec = new int[rows];

	for (size_t i = 0; i < rows; ++i) 
		vec[i] = find_num(matr[i], cols, val);

	return vec;
}