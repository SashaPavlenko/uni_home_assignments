#pragma once

// Function that reads the matrix size, allocates the matrix in dynamic memory and reads its elements.
void read_new(double**& m, size_t& rows, size_t& cols);

// Function that deletes a matrix located in dynamic memory.
void delete_matrix(double**& m, const size_t rows, const size_t cols);

// Function that prints a matrix to the screen.
void printM(double** m, const size_t rows, const size_t cols);

// Function that computes the ratio of the sums of the elements on the main and secondary diagonals of a square matrix.
double prop_diagonals(double**& m, const size_t size);

// Adds to the matrix a column containing the minimum positive element of each row. 
void insert_col_with_min_in_row(double**& m, size_t& rows, size_t& cols);

// Deletes from the matrix the row and the column at whose intersection the maximum element of the matrix is located.
void del_row_col_with_max_el(double**& m, size_t& rows, size_t& cols);

// User-defined type that points to a function of boolean type that takes an array with its size.
typedef bool(func_param_type)(double*, size_t);

// Deletes from the matrix the rows that satisfy the condition given by the parameter function.
void del_row_by_cond(double**& m, size_t& rows, const size_t cols, func_param_type func_param);

// Function that checks the condition: the array consists of zeros only.
bool cond_only_zeros(double* a, size_t size);

// Function that checks the condition: the array has no positive numbers.
bool cond_withot_pos_num(double* a, size_t size);

