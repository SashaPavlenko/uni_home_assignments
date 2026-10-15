#include "pch.h"
#include "CppUnitTest.h"
#include "..\Pavlenko_lab_11\funcs.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Arr_has_zero)
		{
			{
				const int n{ 3 };
				double a[n] = { 1, 1, 0 };

				Assert::AreEqual(true, arr_has_zero(a, n));
			}

			{
				const int n{ 3 };
				double a[n] = { 1, 0, 1 };

				Assert::AreEqual(true, arr_has_zero(a, n));
			}

			{
				const int n{ 3 };
				double a[n] = { 0, 1, 1 };

				Assert::AreEqual(true, arr_has_zero(a, n));
			}

			{
				const int n{ 3 };
				double a[n] = { 1, 1, 1 };

				Assert::AreEqual(false, arr_has_zero(a, n));
			}

			{
				const int n{ 1 };
				double a[n] = { 0 };

				Assert::AreEqual(true, arr_has_zero(a, n));
			}

			{
				const int n{ 1 };
				double a[n] = { 1 };

				Assert::AreEqual(false, arr_has_zero(a, n));
			}
		}

		/*
		TEST_METHOD(Count_rows_with_zero)
		{
			{
				const int rows{ 3 };
				const int cols{ 3 };

				matrix_type matr;
					
				double clone[rows][cols] = {
					{1, 2, 3},
					{4, 5, 6},
					{7, 8, 9},
				};

				for (int i = 0; i < rows; ++i)
					for (int j = 0; j < cols; ++j)
						matr[i][j] = clone[i][j];

				Assert::AreEqual(0, count_rows_with_zero(matr, rows, cols));
			}
		
			{
				const int rows{ 2 };
				const int cols{ 2 };

				matrix_type matr; 
				
				double clone[rows][cols] = {
					{0, 2},
					{4, 5},
				};

				for (int i = 0; i < rows; ++i)
					for (int j = 0; j < cols; ++j)
						matr[i][j] = clone[i][j];

				Assert::AreEqual(1, count_rows_with_zero(matr, rows, cols));
			}

			{
				const int rows{ 2 };
				const int cols{ 2 };

				matrix_type matr; 
				
				double clone[rows][cols] = {
					{1, 0},
					{4, 5},
				};

				for (int i = 0; i < rows; ++i)
					for (int j = 0; j < cols; ++j)
						matr[i][j] = clone[i][j];

				Assert::AreEqual(1, count_rows_with_zero(matr, rows, cols));
			}

			{
				const int rows{ 2 };
				const int cols{ 2 };

				matrix_type matr; 
				
				double clone[rows][cols] = {
					{1, 2},
					{0, 5},
				};

				for (int i = 0; i < rows; ++i)
					for (int j = 0; j < cols; ++j)
						matr[i][j] = clone[i][j];

				Assert::AreEqual(1, count_rows_with_zero(matr, rows, cols));
			}

			{
				const int rows{ 2 };
				const int cols{ 2 };

				matrix_type matr; 
				
				double clone[rows][cols] = {
					{1, 2},
					{5, 0},
				};

				for (int i = 0; i < rows; ++i)
					for (int j = 0; j < cols; ++j)
						matr[i][j] = clone[i][j];

				Assert::AreEqual(1, count_rows_with_zero(matr, rows, cols));
			}

			{
				const int rows{ 2 };
				const int cols{ 2 };

				matrix_type matr; 
				
				double clone[rows][cols] = {
					{1, 2},
					{0, 5},
				};

				for (int i = 0; i < rows; ++i)
					for (int j = 0; j < cols; ++j)
						matr[i][j] = clone[i][j];

				Assert::AreEqual(1, count_rows_with_zero(matr, rows, cols));
			}

			{
				const int rows{ 2 };
				const int cols{ 2 };

				matrix_type matr; 
				
				double clone[rows][cols] = {
					{0, 2},
					{0, 5},
				};

				for (int i = 0; i < rows; ++i)
					for (int j = 0; j < cols; ++j)
						matr[i][j] = clone[i][j];

				Assert::AreEqual(2, count_rows_with_zero(matr, rows, cols));
			}

			{
				const int rows{ 2 };
				const int cols{ 2 };

				matrix_type matr; 
				
				double clone[rows][cols] = {
					{1, 2},
					{0, 5},
				};

				for (int i = 0; i < rows; ++i)
					for (int j = 0; j < cols; ++j)
						matr[i][j] = clone[i][j];

				Assert::AreEqual(1, count_rows_with_zero(matr, rows, cols));
			}

			{
				const int rows{ 2 };
				const int cols{ 2 };

				matrix_type matr; 
				
				double clone[rows][cols] = {
					{1, 2},
					{0, 0},
				};

				for (int i = 0; i < rows; ++i)
					for (int j = 0; j < cols; ++j)
						matr[i][j] = clone[i][j];

				Assert::AreEqual(1, count_rows_with_zero(matr, rows, cols));
			}

			{
				const int rows{ 2 };
				const int cols{ 2 };

				matrix_type matr; 
				
				double clone[rows][cols] = {
					{1, 0},
					{0, 1},
				};

				for (int i = 0; i < rows; ++i)
					for (int j = 0; j < cols; ++j)
						matr[i][j] = clone[i][j];

				Assert::AreEqual(2, count_rows_with_zero(matr, rows, cols));
			}

			{
				const int rows{ 3 };
				const int cols{ 3 };

				matrix_type matr; 
				
				double clone[rows][cols] = {
					{0, 0, 0},
					{0, 0, 0},
					{0, 0, 0},
				};

				for (int i = 0; i < rows; ++i)
					for (int j = 0; j < cols; ++j)
						matr[i][j] = clone[i][j];

				Assert::AreEqual(3, count_rows_with_zero(matr, rows, cols));
			}

			{
				const int rows{ 1 };
				const int cols{ 1 };

				matrix_type matr; 
				
				double clone[rows][cols] = {
					{1},
				};

				for (int i = 0; i < rows; ++i)
					for (int j = 0; j < cols; ++j)
						matr[i][j] = clone[i][j];

				Assert::AreEqual(0, count_rows_with_zero(matr, rows, cols));
			}

			{
				const int rows{ 1 };
				const int cols{ 1 };

				matrix_type matr; 
				
				double clone[rows][cols] = {
					{0},
				};

				for (int i = 0; i < rows; ++i)
					for (int j = 0; j < cols; ++j)
						matr[i][j] = clone[i][j];

				Assert::AreEqual(1, count_rows_with_zero(matr, rows, cols));
			}
		}
		*/

		TEST_METHOD(DeleteFirstRow)
		{
			{
				const int rows{ 2 };
				const int cols{ 2 };

				matrix_type matr;

				double clone[rows][cols] = {
					{1, 2},
					{3, 4},
				};

				for (int i = 0; i < rows; ++i)
					for (int j = 0; j < cols; ++j)
						matr[i][j] = clone[i][j];

				int rowsM{ rows }, colsM{ cols };

				deleteFirstRow(matr, rowsM, colsM);

				const int rows_check{ rows - 1 }, cols_check{ cols };

				matrix_type check_M = {
					{3, 4},
				};

				for (int i = 0; i < rowsM; ++i)
					for (int j = 0; i < colsM; ++j)
						Assert::AreEqual(check_M[i][j], matr[i][j]);

			}
		}
	};
}
