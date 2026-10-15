#include "pch.h"
#include "CppUnitTest.h"
#include "..\Pavlenko_term_2_lab_5\funcs.h"
#include "..\Pavlenko_term_2_lab_5\bignum.h"
#include <string>
#include <cstring>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Is_numeric)
		{
			{
				std::string s = "1234";
				Assert::AreEqual(true, is_numeric(s));
			}
		

			{
				std::string s = "+1234";
				Assert::AreEqual(true, is_numeric(s));
			}
		
			{
				std::string s = "-1234";
				Assert::AreEqual(true, is_numeric(s));
			}
		
			{
				std::string s = "12-34";
				Assert::AreEqual(false, is_numeric(s));
			}
		
			
			{
				std::string s = "f1234";
				Assert::AreEqual(false, is_numeric(s));
			}
		
			
			{
				std::string s = "1234-";
				Assert::AreEqual(false, is_numeric(s));
			}
		
			{
				std::string s = "0";
				Assert::AreEqual(true, is_numeric(s));
			}
		
			{
				std::string s = "+0";
				Assert::AreEqual(true, is_numeric(s));
			}
		
			{
				std::string s = "-0";
				Assert::AreEqual(true, is_numeric(s));
			}
		} // end testing is_numeric.

		TEST_METHOD(Oper_eq) {
			{
				bignum n1(123);
				bignum n2(123);

				Assert::AreEqual(true, (n1 == n2));
			}
		
			{
				bignum n1(-123);
				bignum n2(-123);

				Assert::AreEqual(true, (n1 == n2));
			}
		
			{
				bignum n1(123);
				bignum n2(-123);

				Assert::AreEqual(false, (n1 == n2));
			}
		
			{
				bignum n1(-123);
				bignum n2(123);

				Assert::AreEqual(false, (n1 == n2));
			}
		
			{
				bignum n1(123);
				bignum n2(133);

				Assert::AreEqual(false, (n1 == n2));
			}
		
			{
				bignum n1(123);
				bignum n2(-133);

				Assert::AreEqual(false, (n1 == n2));
			}
		
			{
				bignum n1(-123);
				bignum n2(133);

				Assert::AreEqual(false, (n1 == n2));
			}
		
			{
				bignum n1(0);
				bignum n2(123);

				Assert::AreEqual(false, (n1 == n2));
			}
		
			{
				bignum n1(123);
				bignum n2(0);

				Assert::AreEqual(false, (n1 == n2));
			}
		
			{
				bignum n1(0);
				bignum n2(0);

				Assert::AreEqual(true, (n1 == n2));
			}
		} // end testing oper_eq.
	
		TEST_METHOD(Oper_more) {
			{
				bignum n1(123);
				bignum n2(123);

				Assert::AreEqual(false, (n1 > n2));
			}
		
			{
				bignum n1(-123);
				bignum n2(-123);

				Assert::AreEqual(false, (n1 > n2));
			}
		
			{
				bignum n1(123);
				bignum n2(-123);

				Assert::AreEqual(true, (n1 > n2));
			}
		
			{
				bignum n1(-123);
				bignum n2(123);

				Assert::AreEqual(false, (n1 > n2));
			}
		
			{
				bignum n1(123);
				bignum n2(133);

				Assert::AreEqual(false, (n1 > n2));
			}
		
			{
				bignum n1(133);
				bignum n2(123);

				Assert::AreEqual(true, (n1 > n2));
			}
		
			{
				bignum n1(123);
				bignum n2(-133);

				Assert::AreEqual(true, (n1 > n2));
			}
		
			{
				bignum n1(-123);
				bignum n2(133);

				Assert::AreEqual(false, (n1 > n2));
			}
		
			{
				bignum n1(0);
				bignum n2(123);

				Assert::AreEqual(false, (n1 > n2));
			}
		
			{
				bignum n1(123);
				bignum n2(0);

				Assert::AreEqual(true, (n1 > n2));
			}
		
			{
				bignum n1(0);
				bignum n2(0);

				Assert::AreEqual(false, (n1 > n2));
			}
		
			{
				bignum n1(12);
				bignum n2(1234);

				Assert::AreEqual(false, (n1 > n2));
			}
		
			{
				bignum n1(-12);
				bignum n2(-1234);

				Assert::AreEqual(true, (n1 > n2));
			}
		} // end testing oper_more.

		TEST_METHOD(Int) 
		{
			{
				bignum n_to(123);
				int n_check(123);

				Assert::AreEqual(n_check, static_cast<int>(n_to));
			}
		
			{
				bignum n_to(0);
				int n_check(0);

				Assert::AreEqual(n_check, static_cast<int>(n_to));
			}
		
			{
				bignum n_to(-123);
				int n_check(-123);

				Assert::AreEqual(n_check, static_cast<int>(n_to));
			}
		} // end testing int.

		TEST_METHOD(String) 
		{
			{
				bignum n_to(123);
				std::string n_check = "123";

				Assert::IsTrue(n_check == static_cast<std::string>(n_to));
			}
		
			{
				bignum n_to(0);
				std::string n_check = "0";

				Assert::IsTrue(n_check == static_cast<std::string>(n_to));
			}
		
			{
				bignum n_to(-123);
				std::string n_check = "-123";

				Assert::IsTrue(n_check == static_cast<std::string>(n_to));
			}
		} // end testing string.

		TEST_METHOD(Oper_plus)
		{
			{
				bignum n1(500);
				bignum n2(-499);
				bignum n_check(1);

				Assert::IsTrue(n_check == (n1 + n2));
			}

			{
				bignum n1(-500);
				bignum n2(499);
				bignum n_check(-1);

				Assert::IsTrue(n_check == (n1 + n2));
			}
			
			{
				bignum n1(123);
				bignum n2(123);
				bignum n_check(246);

				Assert::IsTrue(n_check == (n1 + n2));
			}
	
			{
				bignum n1(123);
				bignum n2(1000);
				bignum n_check(1123);

				Assert::IsTrue(n_check == (n1 + n2));
			}

			{
				bignum n1(0);
				bignum n2(123);
				bignum n_check(123);

				Assert::IsTrue(n_check == (n1 + n2));
			}

			{
				bignum n1(123);
				bignum n2(0);
				bignum n_check(123);

				Assert::IsTrue(n_check == (n1 + n2));
			}
			
			{
				bignum n1(123);
				bignum n2(-23);
				bignum n_check(100);

				Assert::IsTrue(n_check == (n1 + n2));
			}
	
			{
				bignum n1(23);
				bignum n2(-123);
				bignum n_check(-100);

				Assert::IsTrue(n_check == (n1 + n2));
			}
	
			{
				bignum n1(-123);
				bignum n2(123);
				bignum n_check(0);

				Assert::IsTrue(n_check == (n1 + n2));
			}
		
			{
				bignum n1(-1000);
				bignum n2(-123);
				bignum n_check(-1123);

				Assert::IsTrue(n_check == (n1 + n2));
			}
		
			{
				bignum n1(0);
				bignum n2(0);
				bignum n_check(0);

				Assert::IsTrue(n_check == (n1 + n2));
			}
		} // end testing oper_plus.
	
		/*
		TEST_METHOD(Oper_dot)
		{
			{
				bignum n1(10);
				bignum n2(1);
				bignum n_check(10);

				Assert::IsTrue(n_check == (n1 * n2));
			}
	
			{
				bignum n1(10);
				bignum n2(-1);
				bignum n_check(-10);

				Assert::IsTrue(n_check == (n1 * n2));
			}

			{
				bignum n1(1);
				bignum n2(10);
				bignum n_check(-10);

				Assert::IsTrue(n_check == (n1 * n2));
			}

			{
				bignum n1(-1);
				bignum n2(10);
				bignum n_check(-10);

				Assert::IsTrue(n_check == (n1 * n2));
			}
			
			{
				bignum n1(10);
				bignum n2(20);
				bignum n_check(200);

				Assert::IsTrue(n_check == (n1 * n2));
			}
	
			{
				bignum n1(11);
				bignum n2(-11);
				bignum n_check(-121);

				Assert::IsTrue(n_check == (n1 * n2));
			}
	
			{
				bignum n1(11);
				bignum n2(0);
				bignum n_check(0);

				Assert::IsTrue(n_check == (n1 * n2));
			}
		
			{
				bignum n1(0);
				bignum n2(11);
				bignum n_check(0);

				Assert::IsTrue(n_check == (n1 * n2));
			}
		
			{
				bignum n1(-153);
				bignum n2(123);
				bignum n_check(18819);

				Assert::IsTrue(n_check == (n1 * n2));
			}
		} // end testing dot.
		*/

		TEST_METHOD(Oper_multiply)
		{
			{
				bignum n1(1);
				bignum n2(1);
				bignum n_check(1);

				Assert::IsTrue(n_check == (n1 * n2));
			}
		
			{
				bignum n1(2);
				bignum n2(1);
				bignum n_check(2);

				Assert::IsTrue(n_check == (n1 * n2));
			}
		
			{
				bignum n1(1);
				bignum n2(2);
				bignum n_check(2);

				Assert::IsTrue(n_check == (n1 * n2));
			}
		
			{
				bignum n1(2);
				bignum n2(3);
				bignum n_check(6);

				Assert::IsTrue(n_check == (n1 * n2));
			}
		
			{
				bignum n1(3);
				bignum n2(2);
				bignum n_check(6);

				Assert::IsTrue(n_check == (n1 * n2));
			}
		
			{
				bignum n1(3);
				bignum n2(-2);
				bignum n_check(-6);

				Assert::IsTrue(n_check == (n1 * n2));
			}
		
			{
				bignum n1(-2);
				bignum n2(3);
				bignum n_check(-6);

				Assert::IsTrue(n_check == (n1 * n2));
			}
		
			{
				bignum n1(-10);
				bignum n2(-10);
				bignum n_check(100);

				Assert::IsTrue(n_check == (n1 * n2));
			}
		
			{
				bignum n1(0);
				bignum n2(10);
				bignum n_check(0);

				Assert::IsTrue(n_check == (n1 * n2));
			}
		
			{
				bignum n1(1);
				bignum n2(0);
				bignum n_check(0);

				Assert::IsTrue(n_check == (n1 * n2));
			}
		} // end testing oper_multiply.

		TEST_METHOD(Oper_division)
		{
			{
				bignum n1(2);
				bignum n2(1);
				bignum n_check(2);

				Assert::IsTrue(n_check == (n1 / n2));
			}
		
			{
				bignum n1(2);
				bignum n2(-1);
				bignum n_check(-2);

				Assert::IsTrue(n_check == (n1 / n2));
			}
		
			{
				bignum n1(-2);
				bignum n2(1);
				bignum n_check(-2);

				Assert::IsTrue(n_check == (n1 / n2));
			}
		
			{
				bignum n1(1);
				bignum n2(2);
				bignum n_check(0);

				Assert::IsTrue(n_check == (n1 / n2));
			}
		
			{
				bignum n1(14);
				bignum n2(7);
				bignum n_check(2);

				Assert::IsTrue(n_check == (n1 / n2));
			}
		
			{
				bignum n1(14);
				bignum n2(-3);
				bignum n_check(-4);

				Assert::IsTrue(n_check == (n1 / n2));
			}
		
			{
				bignum n1(-6);
				bignum n2(-2);
				bignum n_check(3);

				Assert::IsTrue(n_check == (n1 / n2));
			}
		
			{
				try
				{
					bignum n1(2);
					bignum n2(0);
					
					n1 / n2;
				}
				catch (const char* a)
				{
					Assert::AreEqual(0, strcmp(a, "DivisionByZero"));
				}
			}
		} // end testing oper_division.

		TEST_METHOD(GSM_bignum)
		{
			{
				bignum n1(2);
				bignum n2(2);
				bignum n_check(2);

				Assert::IsTrue(n_check == n1.GCM(n2));
			}
		
			{
				bignum n1(7);
				bignum n2(3);
				bignum n_check(1);

				Assert::IsTrue(n_check == n1.GCM(n2));			}
		
			{
				bignum n1(10);
				bignum n2(5);
				bignum n_check(5);

				Assert::IsTrue(n_check == n1.GCM(n2));
			}
		} // end testing GSM_bignum.

		TEST_METHOD(is_primary_bignum)
		{
			{
				bignum n1(1);

				Assert::AreEqual(false, n1.is_primary());
			}
		
			{
				bignum n1(7);

				Assert::AreEqual(true, n1.is_primary());
			}
		
			{
				bignum n1(2);

				Assert::AreEqual(true, n1.is_primary());
			}
		
			{
				bignum n1(4);

				Assert::AreEqual(false, n1.is_primary());
			}
		} // end testing is_primary_bignum.
	};
}
