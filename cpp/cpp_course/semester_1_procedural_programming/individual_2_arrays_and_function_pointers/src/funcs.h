#pragma once

enum sign_arr
{
	pos,
	neg,
	zero,
};

// Deletes the matrix.
void delete_matrix(int**& m, const size_t rows, const size_t cols);

// Deletes the array.
void delete_matrix(int*& m, const size_t size);

// Prints the array.
void printArr(int* a, const size_t size);

// Task 1. 
// Check whether the array contains alternating-sign elements.
bool check_sign_alternation(int* a, size_t size);

// Task 2. 
// Remove from the array all elements located before the first zero element.
void del_elements_before_zero(int*& a, size_t& size);

// Task 3.
// Write a recursive function that replaces the negative elements of an array with their absolute values.
void replace_neg_to_zero(int* a, size_t size);

// Task 4.
// Find the sum of the positive elements among the matrix elements marked in black (Figure 4).
int sum_by_cond(int** matr, size_t rows, size_t cols);

typedef bool(*cond_type)(int);

// Checks the condition: is the number positive.
bool num_is_pos(int num);

// Sums the array elements (a part of them) that satisfy the condition of the parameter function.
int sum_part_arr_by_cond(int* begin, int* end, cond_type func);

// Task 5.
// Build a vector in which each element equals the maximum element of the corresponding matrix row that is less than a given value.
int* create_vec(int** matr, size_t rows, size_t cols, int val);

// Finds the maximum element in the array that is less than val.
int find_num(int* arr, size_t size, int val);