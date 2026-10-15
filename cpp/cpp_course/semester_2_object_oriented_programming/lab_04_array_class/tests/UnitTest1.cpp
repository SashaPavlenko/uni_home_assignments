#include "pch.h"
#include "CppUnitTest.h"
#include "..\Pavlenko_term_2_lab_4\Array.h"
#include <cstring>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(oper_plus)
		{
			int size{ 5 };
			int a1_new[] = { 1, 2, 3, 4, 5 };
			Array a1(a1_new, size);
			int a2_new[] = { 1, 1, 1, 1, 1 };
			Array a2(a2_new, size);
			int arr[] = { 1, 2, 3, 4, 5, 1, 1, 1, 1, 1 };
			Array arr_check(arr, size*2);

			Assert::IsTrue(arr_check == (a1 + a2));
		} // end testing oper_plus.

		TEST_METHOD(oper_plus_eq)
		{
			int size{ 5 };
			int a1_new[] = { 1, 2, 3, 4, 5 };
			Array a1(a1_new, size);
			int a2_new[] = { 1, 1, 1, 1, 1 };
			Array a2(a2_new, size);
			a1 += a2;
			int arr[] = { 1, 2, 3, 4, 5, 1, 1, 1, 1, 1 };
			Array arr_check(arr, size * 2);

			Assert::IsTrue(arr_check == a1);
		} // end testing oper_plus_eq.
	
		TEST_METHOD(oper_plus_int)
		{
			int size{ 5 };
			int a1_new[] = { 1, 2, 3, 4, 5 };
			Array a1(a1_new, size);
			int arr[] = { 2, 3, 4, 5, 6 };
			Array arr_check(arr, size);

			Assert::IsTrue(arr_check == (a1 + 1));
		} // end testing oper_plus_int.
	
		TEST_METHOD(oper_assign)
		{
			int size{ 5 };
			int a1_new[] = { 1, 2, 3, 4, 5 };
			Array a1(a1_new, size);
			int a2_new[] = { 1, 1, 1, 1, 1 };
			Array a2(a2_new, size);
			a1 = a2;
			int arr[] = { 1, 1, 1, 1, 1 };
			Array arr_check(arr, size);

			Assert::IsTrue(arr_check == a1);
		} // end testing oper_assign.
	
		TEST_METHOD(Find)
		{
			int size{ 5 };
			int a1_new[] = { 1, 2, 3, 4, 3 };
			Array a1(a1_new, size);
			int a2_new[] = { 1, 1, 1, 1, 1 };
			Array a2(a2_new, size);

			Assert::AreEqual(2, a1.find(3));
			Assert::AreEqual(-1, a2.find(3));
		} // end testing find.
	
		TEST_METHOD(Upsize)
		{
			int size{ 5 };
			int a1_new[] = { 1, 2, 3, 4, 5 };
			Array a1(a1_new, size);
			a1.upsize();
			int arr1[] = { 1, 2, 3, 4, 5, 0, 0, 0, 0, 0 };
			Array arr_check1(arr1, size * 2);

			int a2_new[] = { 1, 1, 1, 1, 1 };
			Array a2(a2_new, size);
			a2.upsize(1);
			int arr2[] = { 1, 1, 1, 1, 1, 0 };
			Array arr_check2(arr2, size + 1);

			Assert::IsTrue(arr_check1 == a1);
			Assert::IsTrue(arr_check2 == a2);

			try {
				a1.upsize(-5);
			}
			catch (const char* str) {
				Assert::IsTrue(strcmp(str, "IncorrectSize") == 0);
			}
		} // end testing upsize.
	
		TEST_METHOD(Downsize)
		{
			int size{ 5 };
			int a1_new[] = { 1, 2, 3, 4, 5 };
			Array a1(a1_new, size);
			a1.downsize();
			int arr1[] = { 1, 2, 3 };
			Array arr_check1(arr1, size - 2);

			int a2_new[] = { 1, 1, 1, 1, 1 };
			Array a2(a2_new, size);
			a2.downsize(1);
			int arr2[] = { 1, 1, 1, 1 };
			Array arr_check2(arr2, size - 1);

			Assert::IsTrue(arr_check1 == a1);
			Assert::IsTrue(arr_check2 == a2);

			try {
				a1.downsize(-5);
			}
			catch (const char* str) {
				Assert::IsTrue(strcmp(str, "IncorrectSize") == 0);
			}
		} // end testing downsize.
	
		TEST_METHOD(Insert)
		{
			int size{ 5 };
			int a1_new[] = { 1, 2, 3, 4, 5 };
			Array a1(a1_new, size);
			a1.insert(2, 6);
			int arr2[] = { 1, 2, 6, 3, 4, 5 };
			Array arr_check2(arr2, size + 1);

			Assert::IsTrue(arr_check2 == a1);
		} // end testing insert.
	
		TEST_METHOD(Rinsert)
		{
			int size{ 5 };
			int a1_new[] = { 1, 2, 3, 4, 5 };
			Array a1(a1_new, size);
			a1.rinsert(6);
			int arr2[] = { 1, 2, 3, 4, 5, 6 };
			Array arr_check2(arr2, size + 1);

			Assert::IsTrue(arr_check2 == a1);
		} // end testing rinsert.

		TEST_METHOD(Pop)
		{
			int size{ 5 };
			int a1_new[] = { 1, 2, 3, 4, 5 };
			Array a1(a1_new, size);
			a1.pop(2);
			int arr2[] = { 1, 2, 4, 5 };
			Array arr_check2(arr2, size - 1);

			try
			{
				Assert::IsTrue(arr_check2 == a1);
			}
			catch (const char* str)
			{
				Assert::IsTrue(strcmp(str, "NothingToDelete") == 0);
			}
		} // end testing pop.

	};
}
