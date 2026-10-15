#include "pch.h"
#include "CppUnitTest.h"
#include "..\Pavlenko_lab_7\funcs.h"
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace my_arrays {
	double a_1[] = { 1, 1, -1, 0 };
	double a_2[] = { 1, -1, -1, 2 };
	double a_3[] = { 1, -1, 1, 0 };

	double len_1[] = { 1, 1 };
	double len_2[] = { 3, 4 };
	double len_3[] = { 3, 4, 5, 3, 2, 1};

	double cos_1[] = {0, 1};
	double cos_2[] = {1, 0};

	double arr_1[] = { 1, 1 };
	double arr_2[] = { 3, 4 };
}

namespace UnitTest1
{

	TEST_CLASS(UnitTest1)
	{
	public:
		

		TEST_METHOD(Sum_el)
		{
			double a1[] = { 1, 2, 3, 4, 5 };
			Assert::AreEqual(15., sum_el(a1, sizeof(a1)/sizeof(double)));

			double a2[] = {0};
			Assert::AreEqual(0., sum_el(a2, sizeof(a2) / sizeof(double)));

			double a3[] = { 0, 0 };
			Assert::AreEqual(0., sum_el(a3, sizeof(a3) / sizeof(double)));
			
			double a4[] = { -1, 1 };
			Assert::AreEqual(0., sum_el(a4, sizeof(a4) / sizeof(double)));

			double a5[] = { 0.1, 0.1, 0.1 };
			Assert::AreEqual(0.3, sum_el(a5, sizeof(a5) / sizeof(double)), 1e-7);

			double a6[] = { -1, -1, -1, 0 };
			Assert::AreEqual(-3., sum_el(a6, sizeof(a6) / sizeof(double)));
			
		}
		
		TEST_METHOD(Prod_el)
		{
			double c[4];
			prod_el(my_arrays::a_1, my_arrays::a_2, c, 4);

			for (int i = 0; i < 4; i++)
				Assert::AreEqual(c[i], my_arrays::a_3[i]);
		}

		TEST_METHOD(Len_vec)
		{
			Assert::AreEqual(sqrt(2), len_vec(my_arrays::len_1, 2));
			Assert::AreEqual(5., len_vec(my_arrays::len_2, 2));
			Assert::AreEqual(8., len_vec(my_arrays::len_3, 6));
		}

		TEST_METHOD(Cos_similarity)
		{
			using my_arrays::arr_1;
			Assert::IsTrue(abs(1. - cos_similarity(arr_1, arr_1, my_arrays::arr_2, 2)) < 1e-9);
		
			using my_arrays::cos_1;
			using my_arrays::cos_2;
			Assert::AreEqual(0., cos_similarity(cos_1, cos_2, arr_1, 2));

			double a_1[] = { 0, 1 };
			double a_2[] = { 0, -1 };
			double a_null[2];

			Assert::AreEqual(-1., cos_similarity(a_1, a_2, a_null, 2));

		}

		TEST_METHOD(Prod_matrix) {
			double a_1[] = { 1, 2, 3, 4 };
			double a_2[] = { 1, 2, 3, 4 };
			double a_null[4];
			double a_check[] = { 7, 10, 15, 22 };
			int n1{ 2 };

			prod_matrix(a_1, a_2, a_null, n1);

			for (int i = 0; i < n1; i++)
				for (int j = 0; j < n1; j++)
					Assert::AreEqual(a_check[i * n1 + j], a_null[i * n1 + j]);


			double b_1[] = { 1 };
			double b_2[] = { 1 };
			double b_null[1];
			double b_check[] = { 1 };
			int n2{ 1 };

			prod_matrix(b_1, b_2, b_null, n2);

			for (int i = 0; i < n2; i++)
				for (int j = 0; j < n2; j++)
					Assert::AreEqual(b_check[i * n2 + j], b_null[i * n2 + j]);

			double c_1[] = { 1, 1, 1, -1 };
			double c_2[] = { 0.5, 0.5, 0.5, -0.5 };
			double c_null[4];
			double c_check[] = { 1, 0, 0, 1 };
			int n3{ 2 };

			prod_matrix(c_1, c_2, c_null, n3);

			for (int i = 0; i < n3; i++)
				for (int j = 0; j < n3; j++)
					Assert::IsTrue(abs(c_check[i * n3 + j] - c_null[i * n3 + j]) < 1e-9);

		}

		TEST_METHOD(Tran_matrix)
		{
			double a1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			double a1_check[] = { 1, 4, 7, 2, 5, 8, 3, 6, 9 };
			tran_matrix(a1, 3);

			for (int i = 0; i < 9; i++)
				Assert::AreEqual(a1_check[i], a1[i]);

			double a2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
			double a2_check[] = { 1, 5, 9, 13, 2, 6, 10, 14, 3, 7, 11, 15, 4, 8, 12, 16};
			tran_matrix(a2, 4);

			for (int i = 0; i < 16; i++)
				Assert::AreEqual(a2_check[i], a2[i]);
			
			double a3[] = { 1 };
			double a3_check[] = { 1 };
			tran_matrix(a3, 1);

			for (int i = 0; i < 1; i++)
				Assert::AreEqual(a3_check[i], a3[i]);
		
		}

		TEST_METHOD(Flip_matrix_90)
		{
			double a1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			double a1_check[] = { 3, 6, 9, 2, 5, 8, 1, 4, 7 };
			flip_matrix_90(a1, 3);

			for (int i = 0; i < 9; i++)
				Assert::AreEqual(a1_check[i], a1[i]);

			double a2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
			double a2_check[] = { 4, 8, 12, 16, 3, 7, 11, 15, 2, 6, 10, 14, 1, 5, 9, 13 };
			flip_matrix_90(a2, 4);

			for (int i = 0; i < 16; i++)
				Assert::AreEqual(a2_check[i], a2[i]);

			double a3[] = { 1 };
			double a3_check[] = { 1 };
			flip_matrix_90(a3, 1);

			for (int i = 0; i < 1; i++)
				Assert::AreEqual(a3_check[i], a3[i]);

		}
	};
}
