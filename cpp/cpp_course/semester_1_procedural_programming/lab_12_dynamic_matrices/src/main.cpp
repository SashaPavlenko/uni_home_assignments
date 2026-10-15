#include <iostream>
#include "funcs.h"
#include <crtdbg.h>

#ifdef _DEBUG
#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC
#endif

#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)

using namespace std;

int main()
{
	_CrtMemState _ms;
	_CrtMemCheckpoint(&_ms);

	setlocale(LC_ALL, "rus");
	double** a = nullptr;
	size_t rows, cols;

	read_new(a, rows, cols);

	cout << "Entered matrix: " << endl;
	printM(a, rows, cols);

	cout << "Ratio of the diagonals: " << prop_diagonals(a, rows) << endl;

	insert_col_with_min_in_row(a, rows, cols);
	cout << endl << "Matrix after inserting the column with the minimum elements of the rows: " << endl;
	printM(a, rows, cols);

	del_row_col_with_max_el(a, rows, cols);
	cout << "Matrix after deleting the row and the column with the maximum element: " << endl;
	printM(a, rows, cols);
	
	del_row_by_cond(a, rows, cols, cond_only_zeros);
	cout << "Matrix after deleting the rows satisfying the condition \"the row consists of zeros\": " << endl;
	printM(a, rows, cols);

	delete_matrix(a, rows, cols);

	_CrtMemDumpAllObjectsSince(&_ms);

	return 0;
}