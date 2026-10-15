#include "pch.h"
#include "CppUnitTest.h"
#include "..\Pavlenko_term_2_lab_2\point.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Add2)
		{
			Point p1(1, 0), p2(0, 1);
			Point p_test(1, 1);

			Assert::IsTrue(p_test.isEqual(add2(p1, p2)));
		} // end testing add2.

		TEST_METHOD(Add)
		{
			Point p1(1, 0), p2(0, 1);
			Point p_test(1, 1);
			p1.add(p2);

			Assert::IsTrue(p_test.isEqual(p1));
		} // end testing add2.

		TEST_METHOD(Distance_to)
		{
			Point p1(3, 0), p2(0, 4);
			Assert::AreEqual(5, p1.distance_to(p2));
		} // end testing distance_to.

		TEST_METHOD(Shift_X)
		{
			Point p1(3, 0), p2(3, 0);
			Point p_test1(5, 0), p_test2(1, 0);
			
			p1.shift_X(2);
			p2.shift_X(-2);

			Assert::IsTrue(p1.isEqual(p_test1));
			Assert::IsTrue(p2.isEqual(p_test2));
		} // end testing shift_X.

		TEST_METHOD(Shift_Y)
		{
			Point p1(0, 3), p2(0, 3);
			Point p_test1(0, 5), p_test2(0, 1);

			p1.shift_Y(2);
			p2.shift_Y(-2);

			Assert::IsTrue(p1.isEqual(p_test1));
			Assert::IsTrue(p2.isEqual(p_test2));
		} // end testing shift_Y.

		TEST_METHOD(Get_point)
		{
			Point p1(1, 1);
			space_point p = p1.get_point(POLAR);

			Assert::IsTrue((std::get<0>(p) - 1.41421356237) < 1e-6);
			Assert::IsTrue((std::get<1>(p) - 0.78539816339) < 1e-6);
		} // end testing get_point.
		
		//TEST_METHOD()
		//{

		//} // end testing .
	};
}
