#include "pch.h"
#include "CppUnitTest.h"
#include "..\Pavlenko_lab_12\funcs.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Prop_diagonals)
		{
			// 
			{
				double** a = new double*[3] {
					new double[3] {1, 1, 1},
					new double[3] {1, 1, 1},
					new double[3] {1, 1, 1},
				};

				Assert::AreEqual(1., prop_diagonals(a, 3));

				delete_matrix(a, 3, 3);
			}

			{
				double** a = new double* [3]{
					new double[3] {2, 1, 1},
					new double[3] {1, 1, 1},
					new double[3] {1, 1, 3},
				};

				Assert::AreEqual(2., prop_diagonals(a, 3));

				delete_matrix(a, 3, 3);
			}

			{
				double** a = new double* [3]{
					new double[3] {1, 1, 2},
					new double[3] {1, 1, 1},
					new double[3] {3, 1, 1},
				};

				Assert::AreEqual(0.5, prop_diagonals(a, 3));

				delete_matrix(a, 3, 3);
			}

			{
				double** a = new double* [1]{
					new double[1] {1},
				};

				Assert::AreEqual(1., prop_diagonals(a, 1));

				delete_matrix(a, 1, 1);
			}

			// Exception check: an uninitialized matrix is passed to the function.
			// Exception code: 2.
			{
				try {
					auto func = [] {
						size_t sizeM{ 1 };
						double** a = nullptr;

						prop_diagonals(a, sizeM);
					};
				}
				catch (int ex) {
					Assert::AreEqual(2, ex);
				}
			}

			// Exception check: division by zero.
			// Exception code: 3.
			{
				try {
					auto func = [] {
						size_t sizeM{ 3 };
						double** a = new double* [sizeM] {
							new double[sizeM] {1, 2, 3},
							new double[sizeM] {1, 2, 3},
							new double[sizeM] {1, 2, -3},
						};

						prop_diagonals(a, sizeM);
					};
				}
				catch (int ex) {
					Assert::AreEqual(3, ex);
				}
			}
		}

		TEST_METHOD(Insert_col_with_min_in_row) 
		{
			// Check: a column of zeros is added at the end, because no row has a positive element.
			{
				size_t rows{ 3 }, cols{ 3 };

				double** a = new double* [rows]{
					new double[cols] {-1, -1, -1},
					new double[cols] {-1, -1, -1},
					new double[cols] {-1, -1, -1},
				};

				double** b = new double* [rows]{
					new double[cols + 1] {-1, -1, -1, 0},
					new double[cols + 1] {-1, -1, -1, 0},
					new double[cols + 1] {-1, -1, -1, 0},
				};

				insert_col_with_min_in_row(a, rows, cols);

				Assert::AreEqual(static_cast<size_t>(3), rows);
				Assert::AreEqual(static_cast<size_t>(4), cols);

				for (int i = 0; i < rows; ++i)
					for (int j = 0; j < cols; ++j)
						Assert::AreEqual(b[i][j], a[i][j]);

				delete_matrix(a, rows, cols);
				delete_matrix(b, rows, cols);
			}

			// Check: a column with the minimum elements of the rows is added. The cases where 0 is both the maximum and the minimum element of a row are also checked.
			{
				size_t rows{ 4 }, cols{ 3 };

				double** a = new double* [rows] {
					new double[cols] {-1, -1, 0},
					new double[cols] {1, 1, 1},
					new double[cols] {1, 2, 3},
					new double[cols] {1, 2, 0},
				};

				double** b = new double* [rows] {
					new double[cols + 1] { -1, -1, 0, 0 },
					new double[cols + 1] { 1, 1, 1, 1 },
					new double[cols + 1] {  1, 2, 3, 1 },
					new double[cols + 1] {  1, 2, 0, 1 },
				};

				insert_col_with_min_in_row(a, rows, cols);

				Assert::AreEqual(static_cast<size_t>(4), rows);
				Assert::AreEqual(static_cast<size_t>(4), cols);

				for (int i = 0; i < rows; ++i)
					for (int j = 0; j < cols; ++j)
						Assert::AreEqual(b[i][j], a[i][j]);

				delete_matrix(a, rows, cols);
				delete_matrix(b, rows, cols);
			}

			// Check: the case where a row contains both the minimum positive number and 0.
			{
				size_t rows{ 3 }, cols{ 3 };

				double** a = new double* [rows] {
					new double[cols] {-1, 1, 0},
					new double[cols] {0, 0, 0},
					new double[cols] {5, 5, 5},
				};

				double** b = new double* [rows] {
					new double[cols + 1]{ -1, 1, 0, 1 },
					new double[cols + 1]{ 0, 0, 0, 0 },
					new double[cols + 1]{ 5, 5, 5, 5 },
				};

				insert_col_with_min_in_row(a, rows, cols);

				Assert::AreEqual(static_cast<size_t>(3), rows);
				Assert::AreEqual(static_cast<size_t>(4), cols);

				for (int i = 0; i < rows; ++i)
					for (int j = 0; j < cols; ++j)
						Assert::AreEqual(b[i][j], a[i][j]);

				delete_matrix(a, rows, cols);
				delete_matrix(b, rows, cols);
			}

			// Checks the function on a (1)x(1) matrix whose only element is non-positive.
			{
				size_t rows{ 1 }, cols{ 1 };

				double** a = new double* [rows] {
					new double[cols] {-1},
				};

				double** b = new double* [rows] {
					new double[cols + 1]{ -1, 0 },
				};

				insert_col_with_min_in_row(a, rows, cols);

				Assert::AreEqual(static_cast<size_t>(1), rows);
				Assert::AreEqual(static_cast<size_t>(2), cols);

				for (int i = 0; i < rows; ++i)
					for (int j = 0; j < cols; ++j)
						Assert::AreEqual(b[i][j], a[i][j]);

				delete_matrix(a, rows, cols);
				delete_matrix(b, rows, cols);
			}

			// Checks the function on a (1)x(1) matrix whose only element is zero.
			{
				size_t rows{ 1 }, cols{ 1 };

				double** a = new double* [rows] {
					new double[cols] {0},
				};

				double** b = new double* [rows] {
					new double[cols + 1]{ 0, 0 },
				};

				insert_col_with_min_in_row(a, rows, cols);

				Assert::AreEqual(static_cast<size_t>(1), rows);
				Assert::AreEqual(static_cast<size_t>(2), cols);

				for (int i = 0; i < rows; ++i)
					for (int j = 0; j < cols; ++j)
						Assert::AreEqual(b[i][j], a[i][j]);

				delete_matrix(a, rows, cols);
				delete_matrix(b, rows, cols);
			}

			// Checks the function on a (1)x(1) matrix whose only element is positive.			
			{
				size_t rows{ 1 }, cols{ 1 };

				double** a = new double* [rows] {
					new double[cols] {1},
				};

				double** b = new double* [rows] {
					new double[cols + 1]{ 1, 1 },
				};

				insert_col_with_min_in_row(a, rows, cols);

				Assert::AreEqual(static_cast<size_t>(1), rows);
				Assert::AreEqual(static_cast<size_t>(2), cols);

				for (int i = 0; i < rows; ++i)
					for (int j = 0; j < cols; ++j)
						Assert::AreEqual(b[i][j], a[i][j]);

				delete_matrix(a, rows, cols);
				delete_matrix(b, rows, cols);
			}

			// Exception check: an uninitialized matrix is passed to the function.
			// Exception code: 2.
			{
				try {
					auto func = [] {
						size_t rows{ 1 }, cols{ 1 };
						double** a = nullptr;

						insert_col_with_min_in_row(a, rows, cols);
					};
				}
				catch (int ex) {
					Assert::AreEqual(2, ex);
				}
			}
		}

		TEST_METHOD(Del_row_col_with_max_el)
		{
			// Check: row 2 (counting from zero) and column 0 (counting from zero) must be deleted, 
			// because the first maximum element is located at their intersection.
			{
				size_t rows{ 3 }, cols{ 3 };

				double** a = new double* [rows] {
					new double[cols] {-1, 1, 0},
					new double[cols] {0, 0, 0},
					new double[cols] {5, 5, 5},
				};

				double** b = new double* [rows - 1]{
					new double[cols - 1]{ 1, 0 },
					new double[cols - 1]{ 0, 0 },
				};

				del_row_col_with_max_el(a, rows, cols);

				Assert::AreEqual(static_cast<size_t>(2), rows);
				Assert::AreEqual(static_cast<size_t>(2), cols);

				for (int i = 0; i < rows; ++i)
					for (int j = 0; j < cols; ++j)
						Assert::AreEqual(b[i][j], a[i][j]);

				delete_matrix(a, rows, cols);
				delete_matrix(b, rows, cols);
			}

			// Check: row 1 (counting from zero) and column 1 (counting from zero) must be deleted, 
			// because the first maximum element is located at their intersection.
			{
				size_t rows{ 3 }, cols{ 3 };

				double** a = new double* [rows] {
					new double[cols] {-1, 1, 0},
						new double[cols] {0, 10, 0},
						new double[cols] {5, 5, 6},
				};

				double** b = new double* [rows - 1]{
					new double[cols - 1]{ -1, 0 },
					new double[cols - 1]{ 5, 6 },
				};

				del_row_col_with_max_el(a, rows, cols);

				Assert::AreEqual(static_cast<size_t>(2), rows);
				Assert::AreEqual(static_cast<size_t>(2), cols);

				for (int i = 0; i < rows; ++i)
					for (int j = 0; j < cols; ++j)
						Assert::AreEqual(b[i][j], a[i][j]);

				delete_matrix(a, rows, cols);
				delete_matrix(b, rows, cols);
			}

			// Check: row 0 (counting from zero) and column 2 (counting from zero) must be deleted, 
			// because the first maximum element is located at their intersection.
			{
				size_t rows{ 3 }, cols{ 3 };

				double** a = new double* [rows] {
					new double[cols] {-1, 1, 10},
						new double[cols] {0, 0, 0},
						new double[cols] {5, 5, 5},
				};

				double** b = new double* [rows] {
					new double[cols - 1]{ 0, 0 },
						new double[cols - 1]{ 5, 5 },
				};

				del_row_col_with_max_el(a, rows, cols);

				Assert::AreEqual(static_cast<size_t>(2), rows);
				Assert::AreEqual(static_cast<size_t>(2), cols);

				for (int i = 0; i < rows; ++i)
					for (int j = 0; j < cols; ++j)
						Assert::AreEqual(b[i][j], a[i][j]);

				delete_matrix(a, rows, cols);
				delete_matrix(b, rows, cols);
			}

			// Exception check: an uninitialized matrix is passed to the function.
			// Exception code: 2.
			{
				try {
					auto func = [] {
						size_t rows{ 1 }, cols{ 1 };
						double** a = nullptr;

						del_row_col_with_max_el(a, rows, cols);
					};
				}
				catch (int ex) {
					Assert::AreEqual(2, ex);
				}
			}

			// Exception check: after deleting a row or a column the matrix became singular.
			// Exception code: 4.
			{
				try {
					auto func = [] {
						size_t rows{ 1 }, cols{ 2 };
						double** a = new double* [rows] {
							new double[cols] {0, 0},
						};

						del_row_col_with_max_el(a, rows, cols);
					};
				}
				catch (int ex) {
					Assert::AreEqual(4, ex);
				}
			}

		}

		TEST_METHOD(Del_row_by_cond)
		{
			// Check: if there are rows satisfying the condition "the row consists of zeros only", they are deleted.
			{
				size_t rows{ 3 }, cols{ 3 };

				double** a = new double* [rows] {
					new double[cols] {-1, 1, 10},
					new double[cols] {0, 0, 0},
					new double[cols] {5, 5, 5},
				};

				double** b = new double* [rows-1] {
					new double[cols]{ -1, 1, 10 },
					new double[cols]{ 5, 5, 5},
				};

				del_row_by_cond(a, rows, cols, cond_only_zeros);

				Assert::AreEqual(static_cast<size_t>(2), rows);
				Assert::AreEqual(static_cast<size_t>(3), cols);

				for (int i = 0; i < rows; ++i)
					for (int j = 0; j < cols; ++j)
						Assert::AreEqual(b[i][j], a[i][j]);

				delete_matrix(a, rows, cols);
				delete_matrix(b, rows, cols);
			}

			// Check: if there is no row satisfying the condition "the row consists of zeros only", but there are rows containing zeros, 
			// then we delete nothing.
			{
				size_t rows{ 3 }, cols{ 3 };

				double** a = new double* [rows] {
					new double[cols] {0, 1, 10},
					new double[cols] {1, 0, 1},
					new double[cols] {5, 5, 0},
				};

				double** b = new double* [rows] {
					new double[cols] {0, 1, 10},
					new double[cols] {1, 0, 1},
					new double[cols] {5, 5, 0},
				};


				del_row_by_cond(a, rows, cols, cond_only_zeros);

				Assert::AreEqual(static_cast<size_t>(3), rows);
				Assert::AreEqual(static_cast<size_t>(3), cols);

				for (int i = 0; i < rows; ++i)
					for (int j = 0; j < cols; ++j)
						Assert::AreEqual(b[i][j], a[i][j]);

				delete_matrix(a, rows, cols);
				delete_matrix(b, rows, cols);
			}

			// Check: if there is no row satisfying the condition "the row consists of zeros only", nothing is deleted.
			{
				size_t rows{ 3 }, cols{ 3 };

				double** a = new double* [rows] {
					new double[cols] {-1, 1, 10},
						new double[cols] {1, 1, 1},
						new double[cols] {5, 5, 5},
				};

				double** b = new double* [rows] {
					new double[cols] { -1, 1, 10 },
						new double[cols] { 1, 1, 1 },
						new double[cols] { 5, 5, 5 },
				};

				del_row_by_cond(a, rows, cols, cond_only_zeros);

				Assert::AreEqual(static_cast<size_t>(3), rows);
				Assert::AreEqual(static_cast<size_t>(3), cols);

				for (int i = 0; i < rows; ++i)
					for (int j = 0; j < cols; ++j)
						Assert::AreEqual(b[i][j], a[i][j]);

				delete_matrix(a, rows, cols);
				delete_matrix(b, rows, cols);
			}

			// Check: if there is no row satisfying the condition "the row has no positive elements", nothing is deleted.
			{
				size_t rows{ 3 }, cols{ 3 };

				double** a = new double* [rows] {
					new double[cols] {1, 1, 1},
					new double[cols] {1, 1, 1},
					new double[cols] {1, 1, 1},
				};

				double** b = new double* [rows] {
					new double[cols] {1, 1, 1},
					new double[cols] {1, 1, 1},
					new double[cols] {1, 1, 1},
				};

				del_row_by_cond(a, rows, cols, cond_withot_pos_num);

				Assert::AreEqual(static_cast<size_t>(3), rows);
				Assert::AreEqual(static_cast<size_t>(3), cols);

				for (int i = 0; i < rows; ++i)
					for (int j = 0; j < cols; ++j)
						Assert::AreEqual(b[i][j], a[i][j]);

				delete_matrix(a, rows, cols);
				delete_matrix(b, rows, cols);
			}
		
			// Check: if there are rows satisfying the condition "the row has no positive elements", they are deleted.
			{
				size_t rows{ 3 }, cols{ 3 };

				double** a = new double* [rows] {
					new double[cols] {-1, -1, -1},
					new double[cols] {0, 0, 0},
					new double[cols] {1, 1, 1},
				};

				double** b = new double* [rows] {
					new double[cols] {1, 1, 1},
				};

				del_row_by_cond(a, rows, cols, cond_withot_pos_num);

				Assert::AreEqual(static_cast<size_t>(1), rows);
				Assert::AreEqual(static_cast<size_t>(3), cols);

				for (int i = 0; i < rows; ++i)
					for (int j = 0; j < cols; ++j)
						Assert::AreEqual(b[i][j], a[i][j]);

				delete_matrix(a, rows, cols);
				delete_matrix(b, rows, cols);
			}

			// Exception check: an uninitialized matrix is passed to the function.
			// Exception code: 2.
			{
				try {
					auto func = [] {
						double** a = nullptr;
						size_t rows{ 1 }, cols{ 1 };

						del_row_by_cond(a, rows, cols, cond_only_zeros);
					};
				}
				catch (int ex) {
					Assert::AreEqual(2, ex);
				}
			}

			// Exception check: after deleting a row or a column the matrix became singular.
			// Exception code: 4.
			{
				try {
					auto func = [] {
						size_t rows{ 1 }, cols{ 2 };
						double** a = new double* [rows] {
							new double[cols] {0, 0},
						};

						del_row_by_cond(a, rows, cols, cond_only_zeros);
					};
				}
				catch (int ex) {
					Assert::AreEqual(4, ex);
				}
			}
		}
	};
}
