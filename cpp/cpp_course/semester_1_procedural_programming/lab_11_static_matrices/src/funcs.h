#pragma once

// Maximum number of rows.
const int MAXROWS = 256;

// Maximum number of columns.
const int MAXCOLS = 256;

// User-defined matrix type of size MAXROWS by MAXCOLS.
typedef double matrix_type[MAXROWS][MAXCOLS];

// Checks the condition: does the array contain zero?
bool arr_has_zero(double* a, size_t size);

// Returns the number of rows that contain zeros.
int count_rows_with_zero(matrix_type a, int size_row, int size_col);

// Deletes 1 row.
//void deleteFirstRow(double** matr, int& rows, int& cols);
void deleteFirstRow(matrix_type matr, int& rows, int& cols);

// Adds a row to the matrix at index k.
void insert_row(matrix_type matr, int& rows, int cols, double* out_row, int k);

// Function that prints a matrix to the screen.
void printM(matrix_type matr, int rows, int cols);

// Output function overload for a one-dimensional matrix.
void printM(double matr[], int cols);

// Transposes the matrix.
void transposeM(matrix_type matr, int sizeM);

// Deletes from the matrix the row with number M and the column with number N.
void del_row_col(matrix_type matr, int& rows, int& cols, int M, int N);

// Overload for a square matrix.
void del_row_col(matrix_type matr, int& size, int M, int N);


// Checks whether the arrays are proportional.
bool proportional_arrays(double* a, double* b, int size);

// Copies the elements of the static array b into the dynamic array a.
void copy_arr(double** a, matrix_type b, int rows, int cols);

// Copies the elements of the dynamic array b into the static array a.
void copy_arr(matrix_type a, double** b, int rows, int cols);

/*
Computes the determinant of a matrix.
Structure:
Checks the matrix size. If <= 2, the determinant is computed by the formula.
Otherwise
1. Check each row for proportionality. If at least 1 row is proportional to another one, return 0.
2. Check for zeros and, if there are any, later split the row with the most zeros into a sum of determinants.
3. Expand the determinant as a sum of determinants.
*/ 
double deter(matrix_type matr, int size);

// Computes a determinant of order 2.
inline double count_det_size_2(matrix_type matr) {
	return matr[0][0] * matr[1][1] - matr[1][0] * matr[0][1];
}

// Returns the coefficient 1 or -1 for the determinant when a row and a column are crossed out.
inline int koef_det(int i, int j) {
	return (((i + j) % 2 == 0) ? 1 : (-1));
}