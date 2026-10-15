#include "pch.h"
#include "CppUnitTest.h"
#include "..\Pavlenko_lab_13\funcs.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Check_sign_alternation)
		{
			// Check: an array of 2 elements with alternating signs.
			{
				int a[] = { 1, -1 };
				Assert::AreEqual(true, check_sign_alternation(a, sizeof(a)/sizeof(int)));
			}

			// Check: an array of 2 elements without alternating signs.
			{
				int a[] = { 1, 1 };
				Assert::AreEqual(false, check_sign_alternation(a, sizeof(a) / sizeof(int)));
			}

			// Check: an array of several elements with alternating signs.
			{
				int a[] = { 1, 1, 1, -1, 1, -1 };
				Assert::AreEqual(true, check_sign_alternation(a, sizeof(a) / sizeof(int)));
			}

			// Check: an array of several elements without alternating signs.
			{
				int a[] = { 1, 1, 1, 1, 1, 1 };
				Assert::AreEqual(false, check_sign_alternation(a, sizeof(a) / sizeof(int)));
			}

			// Exception check: an array consisting of 1 element cannot have alternating elements.
			// Error code: 2.
			{
				try {
					auto func = [] {
						int a[] = { 1 };
						bool check = check_sign_alternation(a, 1);
					};
				}
				catch (int a) {
					Assert::AreEqual(2, a);
				}
			}
		} // End of testing the function.

		TEST_METHOD(Del_elements_before_zero)
		{
			// Check: the elements before the first 0 are deleted, where the first 0 is in the middle of an array of 2 or more elements.
			{
				size_t size{ 5 };
				int* a = new int[size] {1, 2, 3, 0, 1};

				int* check_arr = new int[size - 3]{ 0, 1 };
				del_elements_before_zero(a, size);

				Assert::AreEqual(static_cast<size_t>(2), size);

				for (size_t i = 0; i < size; ++i)
					Assert::AreEqual(check_arr[i], a[i]);

				delete_matrix(a, size);
			}

			// Check: the elements before the first 0 are deleted, where the first 0 is the first one in an array of 2 or more elements.
			{
				size_t size{ 5 };
				int* a = new int[size] {0, 1, 2, 3, 1};

				int* check_arr = new int[size] { 0, 1, 2, 3, 1 };
				del_elements_before_zero(a, size);

				Assert::AreEqual(static_cast<size_t>(5), size);

				for (size_t i = 0; i < size; ++i)
					Assert::AreEqual(check_arr[i], a[i]);

				delete_matrix(a, size);
			}

			// Check: the elements before the first 0 are deleted, where the first 0 is the second one in an array of 2 elements.
			{
				size_t size{ 2 };
				int* a = new int[size] {1, 0};

				int* check_arr = new int[size - 1]{ 0 };
				del_elements_before_zero(a, size);

				Assert::AreEqual(static_cast<size_t>(1), size);

				for (size_t i = 0; i < size; ++i)
					Assert::AreEqual(check_arr[i], a[i]);

				delete_matrix(a, size);
			}

			// Check: the elements before the first 0 are deleted, where the first 0 is the first one in an array of 2 elements.
			{
				size_t size{ 2 };
				int* a = new int[size] {0, 1};

				int* check_arr = new int[size] { 0, 1 };
				del_elements_before_zero(a, size);

				Assert::AreEqual(static_cast<size_t>(2), size);

				for (size_t i = 0; i < size; ++i)
					Assert::AreEqual(check_arr[i], a[i]);

				delete_matrix(a, size);
			}

			// Exception check: an uninitialized array is passed to the function.
			// Error code: 1.
			{
				try {
					auto func = [] {
						int* a = nullptr;
						size_t size{ 0 };
						del_elements_before_zero(a, size);
					};
				}
				catch (int a) {
					Assert::AreEqual(1, a);
				}
			}


			// Exception check: if the array has no zeros, an exception is thrown saying that the condition cannot be fulfilled.
			// Error code: 3.
			{
				try {
					auto func = [] {
						size_t size{ 3 };
						int* a = new int[size] {1, 1, 1};
						del_elements_before_zero(a, size);
					};
				}
				catch (int a) {
					Assert::AreEqual(3, a);
				}
			}
		} // End of testing the function.

		TEST_METHOD(Replace_neg_to_zero)
		{
			// Check of the function on an array where all elements are negative.
			{
				const size_t size{ 5 };
				int a[size] = { -1, -2, -3, -4, -5 };
				replace_neg_to_zero(a, size);

				int check_arr[size] = { 1, 2, 3, 4, 5 };

				for (size_t i = 0; i < size; ++i)
					Assert::AreEqual(check_arr[i], a[i]);
			}

			// Check of the function on an array where only 1 element is negative, not at the beginning.
			{
				const size_t size{ 5 };
				int a[size] = { 1, 2, 3, 4, -5 };
				replace_neg_to_zero(a, size);

				int check_arr[size] = { 1, 2, 3, 4, 5 };

				for (size_t i = 0; i < size; ++i)
					Assert::AreEqual(check_arr[i], a[i]);
			}
			
			// Check of the function on an array where only 1 element is negative, at the beginning.
			{
				const size_t size{ 5 };
				int a[size] = { -1, 2, 3, 4, 5 };
				replace_neg_to_zero(a, size);

				int check_arr[size] = { 1, 2, 3, 4, 5 };

				for (size_t i = 0; i < size; ++i)
					Assert::AreEqual(check_arr[i], a[i]);
			}
			
			// Check of the function on an array where no element is non-negative.
			{
				const size_t size{ 5 };
				int a[size] = { 1, 2, 3, 4, 5 };
				replace_neg_to_zero(a, size);

				int check_arr[size] = { 1, 2, 3, 4, 5 };

				for (size_t i = 0; i < size; ++i)
					Assert::AreEqual(check_arr[i], a[i]);
			}
			
			// Check of the function on an array with only one negative element.
			{
				const size_t size{ 1 };
				int a[size] = { -1 };
				replace_neg_to_zero(a, size);

				int check_arr[size] = { 1 };

				for (size_t i = 0; i < size; ++i)
					Assert::AreEqual(check_arr[i], a[i]);
			}
			
			// Check of the function on an array with only one non-negative element.
			{
				const size_t size{ 1 };
				int a[size] = { 1 };
				replace_neg_to_zero(a, size);

				int check_arr[size] = { 1 };

				for (size_t i = 0; i < size; ++i)
					Assert::AreEqual(check_arr[i], a[i]);
			}
		} // End of testing the function.

		TEST_METHOD(Sum_by_cond)
		{
			// Check: the sum of a 4x4 matrix.
			{
				int** a = new int* [4]{
					new int[4] {1, 1, 1, 1},
					new int[4] {2, 2, 2, 2},
					new int[4] {3, 3, 3, 3},
					new int[4] {4, 4, 4, 4},
				};

				Assert::AreEqual(22, sum_by_cond(a, 4, 4));
				delete_matrix(a, static_cast<size_t>(4), static_cast<size_t>(4));
			}

			// Check: the sum of a 3x3 matrix.
			{
				int** b = new int* [3]{
					new int[3] {1, 1, 1},
					new int[3] {2, 2, 2},
					new int[3] {3, 3, 3},
				};
				Assert::AreEqual(11, sum_by_cond(b, 3, 3));
				delete_matrix(b, static_cast<size_t>(3), static_cast<size_t>(3));
			}

			// Check: the sum of a 2x2 matrix.
			{
				int** c = new int* [2]{
					new int[2] {1, 1},
					new int[2] {2, 2},
				};
				Assert::AreEqual(4, sum_by_cond(c, 2, 2));
				delete_matrix(c, static_cast<size_t>(2), static_cast<size_t>(2));
			}
			
			// Check: the sum of a 1x1 matrix.
			{
				int** d = new int* [1]{
					new int[1] {1},
				};
				Assert::AreEqual(1, sum_by_cond(d, 1, 1));

				delete_matrix(d, static_cast<size_t>(1), static_cast<size_t>(1));
			}

		} // End of testing the function.

		TEST_METHOD(Create_vec)
		{
			// Check: the function with valid data and a 4x4 matrix.
			{
				size_t rows{ 4 }, cols{ 4 };
				int** matr = new int* [rows] {
					new int [cols] {-4, -3, -2, -1},
					new int [cols] {1, 2, 3, 4},
					new int [cols] {1, 1, 1, 1},
					new int [cols] {0, 0, 0, 0},
				};
				int val{ 5 };
				int* check_vec = new int[rows] { -1, 4, 1, 0 };

				int* vec = create_vec(matr, rows, cols, val);
				
				for (size_t i = 0; i < rows; ++i)
					Assert::AreEqual(check_vec[i], vec[i]);

				delete_matrix(matr, rows, cols);
				delete[] vec;
				delete[] check_vec;
			}

			// Check: the function with valid data and a 4x1 matrix.
			{
				size_t rows{ 4 }, cols{ 1 };
				int** matr = new int* [rows] {
					new int [cols] {-4},
						new int [cols] {1},
						new int [cols] {1},
						new int [cols] {0},
				};
				int val{ 5 };
				int* check_vec = new int[rows] { -4, 1, 1, 0};

				int* vec = create_vec(matr, rows, cols, val);

				for (size_t i = 0; i < rows; ++i)
					Assert::AreEqual(check_vec[i], vec[i]);

				delete_matrix(matr, rows, cols);
				delete[] vec;
				delete[] check_vec;
			}
			
			// Check: the function with valid data and a 1x4 matrix.
			{
				size_t rows{ 1 }, cols{ 4 };
				int** matr = new int* [rows] {
					new int [cols] {-4, 1, 1, 0},
				};
				int val{ 5 };
				int* check_vec = new int[rows] { 1 };

				int* vec = create_vec(matr, rows, cols, val);

				for (size_t i = 0; i < rows; ++i)
					Assert::AreEqual(check_vec[i], vec[i]);

				delete_matrix(matr, rows, cols);
				delete[] vec;
				delete[] check_vec;
			}

			// Exception check: the function works when one row has no element less than the given value
			// Error code: 4
			{
				try {
					auto func = [] {
						size_t rows{ 4 }, cols{ 4 };
						int** matr = new int* [rows] {
							new int [cols] {-4, -3, -2, -1},
							new int [cols] {1, 2, 3, 4},
							new int [cols] {5, 5, 5, 5},
							new int [cols] {0, 0, 0, 0},
						};
						int val{ 5 };

						int* vec = create_vec(matr, rows, cols, val);
					};
				}
				catch (int a) {
					Assert::AreEqual(4, a);
				}
			}

		} // End of testing the function.
	};

}
