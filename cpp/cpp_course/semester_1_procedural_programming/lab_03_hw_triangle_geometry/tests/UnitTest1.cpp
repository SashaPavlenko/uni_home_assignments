#include "pch.h"
#include "CppUnitTest.h"
#include "..\lab_2_HW\funs.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TEST_DISTANCE)
		{
			point x{ 0, 0 }, y{ 0, 0 };
			Assert::IsTrue(abs(distance(x, y)) < 1e-7);

			x = { 0, 0 }; 
			y = { 0, 0 };
			Assert::IsTrue(abs(distance(x, y)) < 1e-7);
		}

		TEST_METHOD(TEST_P)
		{
			point x{ 0, 0 }, y{ 1, 0 }, z{ 0, 1 };
			Assert::IsTrue(P(x, y, z) > 0);
		}

		TEST_METHOD(DISTANCE_TO_LINE)
		{
			point x{ 0, 0 }, a1{ 1, 0 }, a2{ 0, 1 };
			Assert::AreNotEqual(distance(a1, a2), 0.);
			Logger::WriteMessage("All test were succsesed");
		}

		TEST_METHOD(CHECK_TRIANGLE_TYPE)
		{
			point a1{0, 0}, a2{1, 0}, a3{0, 1};
			point b1{0, 0}, b2{3, 0}, b3{2, 4};
			point c1{0, 0}, c2{-1, -1}, c3{1, 0};

			Assert::IsTrue(check_triangle_type(a1, a2, a3) == tRight, L"Triangle A1A2A3 isn't right");
			Assert::IsTrue(check_triangle_type(b1, b2, b3) == tAcute, L"Triangle B1B2B3 isn't acute");
			Assert::IsTrue(check_triangle_type(c1, c2, c3) == tObtuse, L"Triangle C1C2C3 isn't obtuse");
			
			Logger::WriteMessage("You are the best, my Lord.");
		}

	};
}
