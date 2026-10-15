#include "pch.h"
#include "CppUnitTest.h"
#include "..\individual\The_first.h"
#include "..\individual\The_second.h"
#include "..\individual\The_fird.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Nodd_numer_begins_num)
		{
			Assert::AreEqual(false, nodd_numer_begins_num(1, 1));
			Assert::AreEqual(true, nodd_numer_begins_num(2, 2));
			Assert::AreEqual(false, nodd_numer_begins_num(11, 2));
			Assert::AreEqual(true, nodd_numer_begins_num(22, 2));
			Assert::AreEqual(false, nodd_numer_begins_num(123, 4));
			Assert::AreEqual(false, nodd_numer_begins_num(123, 0));
			Assert::AreEqual(true, nodd_numer_begins_num(-122, 1));
		}

		TEST_METHOD(Count_of_num)
		{
			Assert::AreEqual(1, count_of_num(1));
			Assert::AreEqual(2, count_of_num(12));
			Assert::AreEqual(3, count_of_num(123));
			Assert::AreEqual(4, count_of_num(1234));

			Assert::AreEqual(1, count_of_num(-1));
			Assert::AreEqual(2, count_of_num(-12));
			Assert::AreEqual(3, count_of_num(-123));
			Assert::AreEqual(4, count_of_num(-1234));
		}

		TEST_METHOD(Int_frencl)
		{
			Assert::IsTrue(abs(int_frencl(0.2) - 0.00418761) < 1e-6);
			Assert::IsTrue(abs(int_frencl(2) - 0.34341567836369) < 1e-6);
			Assert::IsTrue(abs(int_frencl(4) - 0.42051575424692) < 1e-6);
		}

		TEST_METHOD(Find_min_num)
		{
			Assert::AreEqual(1, find_min_num(123));
			Assert::AreEqual(1, find_min_num(321));
			Assert::AreEqual(1, find_min_num(312));

			Assert::AreEqual(1, find_min_num(-123));
			Assert::AreEqual(1, find_min_num(-321));
			Assert::AreEqual(1, find_min_num(-312));
			
			Assert::AreEqual(0, find_min_num(301));
			Assert::AreEqual(0, find_min_num(0));
		}
	};
}
