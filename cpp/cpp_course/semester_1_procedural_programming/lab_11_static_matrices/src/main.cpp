#include <iostream>
#include "funcs.h"

using namespace std;

int main() {

	/*
	double a[] = { 0, 0, 0 };
	matrix_type b = {
		{1, 1, 1},
		{2, 2, 2},
		{3, 3, 3},
	};
	int s_row{ 3 }, s_col{ 3 };

	insert_row(b, s_row, s_col, a, 2);

	printM(b, s_row, s_col);
	*/


	/*
	matrix_type b = {
		{1, 1, 1},
		{2, 2, 2},
		{3, 3, 3},
	};

	transposeM(b, 3);

	printM(b, 3, 3);
	*/
	
	
	/*
	matrix_type b = {
		{1, 1, 1},
		{2, 2, 2},
		{3, 3, 3},
	};
	int s_row{ 3 }, s_col{ 3 };

	del_row_col(b, s_row, s_col, 1, 1);
	//del_row_col(b, s_row, s_col, 2, 2);
	//del_row_col(b, s_row, s_col, 3, 3);

	printM(b, s_row, s_col);
	*/

	matrix_type b = {
		{1, 3, 1, 1},
		{3, 1, 7, 2},
		{3, 1, 0, 3},
		{0, 1, 3, 0},
	};

	int s_row{ 4 }, s_col{ 4 };
	cout << deter(b, 4);


	printM(b, s_row, s_col);

	return 0;
}