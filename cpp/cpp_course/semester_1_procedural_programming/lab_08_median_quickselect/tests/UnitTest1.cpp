#include "pch.h"
#include "CppUnitTest.h"
#include "..\Pavlenko_lab_8\funcs.h"
#include "..\Pavlenko_lab_8\median.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Sum_of_el)
		{
			double a_1[] = { 0 };
			Assert::AreEqual(0., sum_of_el(a_1, 1));
			
			double a_2[] = { 1, 2, 3 };
			Assert::AreEqual(6., sum_of_el(a_2, 3));

			double a_3[] = { -1, 0, 1 };
			Assert::AreEqual(0., sum_of_el(a_3, 3));

			double a_4[] = { -1 };
			Assert::AreEqual(-1., sum_of_el(a_4, 1));

			double a_5[] = { 1000, 100, 10, 1 };
			Assert::AreEqual(1111., sum_of_el(a_5, 4));
		}

		TEST_METHOD(Quickselect_median)
		{
			double a1[] = { 9, 1, 0, 2, 3, 4, 6, 8, 7, 10, 5 };
			const int n1 = 11;
			double b1[n1];

			Assert::AreEqual(5., quickselect_median(a1, n1, b1));

			double a2[] = { 1, 2, 3, 3, 3, 4, 5, 6, 7 };
			const int n2 = 9;
			double b2[n2];

			Assert::AreEqual(3., quickselect_median(a2, n2, b2));

			double a3[] = { 1, 2, 2, 2, 3, 4, 5, 6, 7 };
			const int n3 = 9;
			double b3[n3];

			Assert::AreEqual(3., quickselect_median(a3, n3, b3));

			double a4[] = { 1 };
			const int n4 = 1;
			double b4[n4];

			Assert::AreEqual(1., quickselect_median(a4, n4, b4));

			double a5[] = { 1, 3 };
			const int n5 = 2;
			double b5[n5];

			Assert::AreEqual(2., quickselect_median(a5, n5, b5));
		}

		TEST_METHOD(Max_arr)
		{
			double a1[] = { 1, 2, 3, 4 };
			const int n1{ 4 };

			Assert::AreEqual(4., max_arr(a1, n1));

			double a2[] = { -1, -2, -3, -4 };
			const int n2{ 4 };

			Assert::AreEqual(-1., max_arr(a2, n2));

			double a3[] = { -1, 2, -3, 4 };
			const int n3{ 4 };

			Assert::AreEqual(4., max_arr(a3, n3));

			double a4[] = { 1 };
			const int n4{ 1 };

			Assert::AreEqual(1., max_arr(a4, n4));
		}

		TEST_METHOD(Without_zeros)
		{
			double a1[] = { 1, 2, 3, 4 };
			const int n1{ 4 };

			Assert::AreEqual(true, without_zeros(a1, n1));

			double a2[] = { -1, -2, -3, 0 };
			const int n2{ 4 };

			Assert::AreEqual(false, without_zeros(a2, n2));

			double a3[] = { 0, 2, -3, 4 };
			const int n3{ 4 };

			Assert::AreEqual(false, without_zeros(a3, n3));

			double a4[] = { 1, 1, 0, 1, 1 };
			const int n4{ 5 };

			Assert::AreEqual(false, without_zeros(a4, n4));

			double a5[] = { 0, 0, 0, 0 };
			const int n5{ 4 };

			Assert::AreEqual(false, without_zeros(a5, n5));
		}
	};
}
