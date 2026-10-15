#include "pch.h"
#include "CppUnitTest.h"
#include "..\Pavlenko_lab_6\funcs.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Count_numbers)
		{
			Assert::AreEqual(count_num(12345), 5);
			Assert::AreEqual(count_num(1234), 4);
			Assert::AreEqual(count_num(0), 1);
			Assert::AreEqual(count_num(1), 1);
			Assert::AreEqual(count_num(-1), 1);
			Assert::AreEqual(count_num(-0), 1);
		}

		/*
		TEST_METHOD(Sum_num)
		{
			//Assert::AreEqual(sum_num(111), 3);
			Assert::AreEqual(3, sum_num(111));
			Assert::AreEqual(sum_num(11), 2);
			Assert::AreEqual(sum_num(1), 1);
			Assert::AreEqual(sum_num(0), 0);
			Assert::AreEqual(sum_num(-1), 1);
			Assert::AreEqual(sum_num(-12), 3);
		}
		*/

		TEST_METHOD(Rec_gcd_find)
		{
			Assert::IsTrue(rec_gcd_find(30, 18) == 6);
			Assert::AreEqual(rec_gcd_find(40, 4), 4);
			Assert::AreEqual(rec_gcd_find(37, 13), 1);
		}

		TEST_METHOD(Iter_gcd_find)
		{
			Assert::IsTrue(iter_gcd_find(30, 18) == 6);
			Assert::AreEqual(iter_gcd_find(40, 4), 4);
			Assert::AreEqual(iter_gcd_find(37, 13), 1);
		}

		TEST_METHOD(Prime_sum)
		{
			Assert::AreEqual(3, prime_sum(27));
			Assert::AreEqual(0, prime_sum(1));
			Assert::AreEqual(5, prime_sum(5));
			Assert::AreEqual(10, prime_sum(120));
		}

		TEST_METHOD(To_pow)
		{
			Assert::AreEqual(0.25, to_pow(2, -2));
			Assert::AreEqual(0.5, to_pow(2, -1));
			Assert::AreEqual(1., to_pow(2, 0));
			Assert::AreEqual(2., to_pow(2, 1));
			Assert::AreEqual(4., to_pow(2, 2));

			Assert::AreEqual(1., to_pow(1, -1));
			Assert::AreEqual(1., to_pow(1, 0));
			Assert::AreEqual(1., to_pow(1, 1));
			Assert::AreEqual(1., to_pow(1, 5));
			Assert::AreEqual(1., to_pow(1, -5));

			Assert::IsTrue(abs(8. - to_pow(0.5, -3)) < 1e-8);
			Assert::IsTrue(abs(4. - to_pow(0.5, -2)) < 1e-8);
			Assert::IsTrue(abs(2. - to_pow(0.5, -1)) < 1e-8);
			Assert::IsTrue(abs(1 - to_pow(0.5, 0)) < 1e-8);
			Assert::IsTrue(abs(0.5 - to_pow(0.5, 1)) < 1e-8);
			Assert::IsTrue(abs(0.25 - to_pow(0.5, 2)) < 1e-8);
		}
	};
}
