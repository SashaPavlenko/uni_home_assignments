#include "pch.h"
#include "CppUnitTest.h"
#include "..\Pavlenko_term_2_individual_3\mSet.h"
#include "..\Pavlenko_term_2_individual_3\TreeRec.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(mSet_is_there)
		{
			{
				int a[] = { 1, 2 ,3, -2, 5, 3, 0 };
				int size = sizeof(a) / sizeof(int);

				mSet t(a, size);

				Assert::AreEqual(true, t.is_there(1));
				Assert::AreEqual(true, t.is_there(3));
				Assert::AreEqual(true, t.is_there(-2));
				Assert::AreEqual(true, t.is_there(0));
				Assert::AreEqual(true, t.is_there(5));
				Assert::AreEqual(false, t.is_there(100));
			}

			{
				mSet t;

				Assert::AreEqual(false, t.is_there(1));
			}
		} // end testing it_there.

		TEST_METHOD(mSet_capacity) {
			{
				int a[] = { 1, 2 ,3, -2, 5, 3, 0 };
				int size = sizeof(a) / sizeof(int);

				mSet t(a, size);

				Assert::AreEqual(6, t.capacity());
			}
		
			{
				int a[] = { 1 };
				int size = sizeof(a) / sizeof(int);

				mSet t(a, size);

				Assert::AreEqual(1, t.capacity());
			}
		
			{
				mSet t;

				Assert::AreEqual(0, t.capacity());
			}
		} // end testing capacity.

		TEST_METHOD(mSet_equal) {
			
			// Identical sets.
			{
				mSet a;
				mSet b;

				a += 1;
				a += 2;
				a += 3;
				a += 4;
				a += 5;
				a += 6;
				a += 7;
				
				// The same elements, but a different order of insertion.
				b += 6;
				b += 3;
				b += 7;
				b += 4;
				b += 5;
				b += 1;
				b += 2;

				Assert::AreEqual(true, (a == b));
			}
			
			// The first set does not have the element 1, but has the extra element 8
			{
				mSet a;
				mSet b;

				a += 8;
				a += 2;
				a += 3;
				a += 4;
				a += 5;
				a += 6;
				a += 7;
				
				b += 6;
				b += 3;
				b += 7;
				b += 4;
				b += 5;
				b += 1;
				b += 2;

				Assert::AreEqual(false, (a == b));
			}
			
			// The second set does not have the element 1, but has the extra element 8
			{
				mSet a;
				mSet b;

				a += 1;
				a += 2;
				a += 3;
				a += 4;
				a += 5;
				a += 6;
				a += 7;
				
				b += 6;
				b += 3;
				b += 7;
				b += 4;
				b += 5;
				b += 8;
				b += 2;

				Assert::AreEqual(false, (a == b));
			}
			
			// Sets of different cardinality
			{
				mSet a;
				mSet b;

				a += 1;
				a += 2;
				a += 3;
				a += 4;
				a += 5;
				a += 6;
				a += 7;
				
				b += 6;
				b += 3;
				b += 7;
				b += 4;
				b += 5;
				b += 2;

				Assert::AreEqual(false, (a == b));
			}
			
			// Comparison with the empty set.
			{
				mSet a;
				mSet b;
				
				b += 6;
				b += 3;
				b += 7;
				b += 4;
				b += 5;
				b += 1;
				b += 2;

				Assert::AreEqual(false, (a == b));
			}
			
			{
				mSet a;
				mSet b;

				a += 1;
				a += 2;
				a += 3;
				a += 4;
				a += 5;
				a += 6;
				a += 7;

				Assert::AreEqual(false, (a == b));
			}

		} // end testing ==.

		TEST_METHOD(mSet_pop) {
			{
				int a[] = { 1, 2 ,3, -2, 5, 3, 0 };
				int size = sizeof(a) / sizeof(int);

				mSet t(a, size);

				int a_check[] = { 1,3, -2, 5, 3, 0 };
				int size_check = sizeof(a_check) / sizeof(int);

				mSet t_check(a_check, size_check);

				t.pop(2);

				Assert::AreEqual(true, (t == t_check));
			}
			
			{
				int a[] = { 0 };
				int size = sizeof(a) / sizeof(int);

				mSet t(a, size);

				mSet t_check;

				t.pop(0);

				Assert::AreEqual(true, (t == t_check));
			}

			{
				int a[] = { 1, 2 ,3, -2, 5, 3, 0 };
				int size = sizeof(a) / sizeof(int);

				mSet t(a, size);

				int a_check[] = { 1,2, 3, -2, 5, 3, 0 };
				int size_check = sizeof(a_check) / sizeof(int);

				mSet t_check(a_check, size_check);

				t.pop(10);

				Assert::AreEqual(true, (t == t_check));
			}


		} // end testing pop.

		TEST_METHOD(mSet_union) {
			{
				mSet t1(1);
				mSet t2(2);

				int a[] = { 1, 2 };
				int size = sizeof(a) / sizeof(int);
				mSet t_check(a, size);

				Assert::AreEqual(true, (t_check == (t1 + t2)));
			}
		
			{
				mSet t1;
				mSet t2;

				t1 += 0;
				t1 += 1;
				t1 += 2;
				t1 += 3;

				t2 += 3;
				t2 += 4;
				t2 += 5;
				t2 += 6;

				int a[] = { 0, 1, 2, 3, 4, 5, 6 };
				int size = sizeof(a) / sizeof(int);
				mSet t_check(a, size);

				Assert::AreEqual(true, (t_check == (t1 + t2)));
			}
		
			{
				mSet t1;
				mSet t2;

				mSet t_check;

				Assert::AreEqual(true, (t_check == (t1 + t2)));
			}
		} // end testing union.
		
		TEST_METHOD(mSet_intersection) {

			{
				mSet t1(1);
				mSet t2(2);

				mSet t_check;

				Assert::AreEqual(true, (t_check == (t1 * t2)));
			}

			{
				mSet t1;
				mSet t2;

				t1 += 0;
				t1 += 1;
				t1 += 2;
				t1 += 3;

				t2 += 3;
				t2 += 4;
				t2 += 5;
				t2 += 6;

				int a[] = { 3 };
				int size = sizeof(a) / sizeof(int);
				mSet t_check(a, size);

				Assert::AreEqual(true, (t_check == (t1 * t2)));
			}

			{
				mSet t1;
				mSet t2;

				mSet t_check;

				Assert::AreEqual(true, (t_check == (t1 * t2)));
			}

		} // end testing intersection.

		TEST_METHOD(mSet_equal_plus) {

			{
				mSet t1(1);
				mSet t2(2);

				int a[] = { 1, 2 };
				int size = sizeof(a) / sizeof(int);
				mSet t_check(a, size);

				t1 += t2;

				Assert::AreEqual(true, (t_check == t1));
			}

			{
				mSet t1;
				mSet t2;

				t1 += 0;
				t1 += 1;
				t1 += 2;
				t1 += 3;

				t2 += 3;
				t2 += 4;
				t2 += 5;
				t2 += 6;

				int a[] = { 0, 1, 2, 3, 4, 5, 6 };
				int size = sizeof(a) / sizeof(int);
				mSet t_check(a, size);
				
				t1 += t2;

				Assert::AreEqual(true, (t_check == t1));
			}

			{
				mSet t1;
				mSet t2;

				mSet t_check;

				t1 += t2;

				Assert::AreEqual(true, (t_check == t1));
			}

		} // end testing equal_plus.

		TEST_METHOD(mSet_equal_minus) {

			{
				mSet t1(1);
				mSet t2(2);

				int a[] = { 1 };
				int size = sizeof(a) / sizeof(int);
				mSet t_check(a, size);

				t1 -= t2;

				Assert::AreEqual(true, (t_check == t1));
			}
			
			{
				mSet t1(1);
				mSet t2;

				int a[] = { 1 };
				int size = sizeof(a) / sizeof(int);
				mSet t_check(a, size);

				t1 -= t2;

				Assert::AreEqual(true, (t_check == t1));
			}
			
			{
				mSet t1(1);
				mSet t2(1);

				mSet t_check;

				t1 -= t2;

				Assert::AreEqual(true, (t_check == t1));
			}

			{
				mSet t1;
				mSet t2;

				t1 += 0;
				t1 += 1;
				t1 += 2;
				t1 += 3;

				t2 += 2;
				t2 += 3;
				t2 += 4;
				t2 += 5;

				int a[] = { 0, 1 };
				int size = sizeof(a) / sizeof(int);
				mSet t_check(a, size);

				t1 -= t2;

				Assert::AreEqual(true, (t_check == t1));
			}

			{
				mSet t1;
				mSet t2;

				mSet t_check;

				t1 -= t2;

				Assert::AreEqual(true, (t_check == t1));
			}

		} // end testing equal_minus.
		
	};
}
