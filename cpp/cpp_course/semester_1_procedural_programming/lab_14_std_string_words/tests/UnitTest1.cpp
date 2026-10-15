#include "pch.h"
#include "CppUnitTest.h"
#include "..\Pavlenko_lab_14\funcs.h"

#define MSG(msg) [&]{ std::wstringstream _s; _s << msg; return _s.str(); }().c_str()

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Count_words)
		{
			Assert::AreEqual(0, count_words(""));
			Assert::AreEqual(1, count_words("f"));
			Assert::AreEqual(1, count_words(" f"));
			Assert::AreEqual(1, count_words("f "));
			Assert::AreEqual(1, count_words(" f "));
			Assert::AreEqual(2, count_words("f f"));
			Assert::AreEqual(2, count_words(" f f"));
			Assert::AreEqual(2, count_words("f f "));
			Assert::AreEqual(2, count_words(" f f "));
			Assert::AreEqual(3, count_words("f  f  f"));
			Assert::AreEqual(3, count_words("  f f f"));
			Assert::AreEqual(3, count_words("f f f  "));
			Assert::AreEqual(3, count_words("f f  f "));
			Assert::AreEqual(4, count_words("  f f f  f  "));
			Assert::AreEqual(4, count_words("  f ff ffff  fff  "));

		} // End of testing the function count_words.
		
		TEST_METHOD(Del_symb)
		{
			{
				string s, s_check;
				char symb;

				s = "12345";
				symb = '1';
				s_check = "2345";
				del_symb(s, symb);
				Assert::IsTrue(s == s_check);
			}

			{
				string s, s_check;
				char symb;

				s = "12345";
				symb = '2';
				s_check = "1345";
				del_symb(s, symb);
				Assert::IsTrue(s == s_check);
			}

			{
				string s, s_check;
				char symb;

				s = "12345";
				symb = '5';
				s_check = "1234";
				del_symb(s, symb);
				Assert::IsTrue(s == s_check);
			}

			{
				string s, s_check;
				char symb;

				s = "12311";
				symb = '1';
				s_check = "23";
				del_symb(s, symb);
				Assert::IsTrue(s == s_check);
			}

			{
				string s, s_check;
				char symb;

				s = "12345";
				symb = '6';
				s_check = "12345";
				del_symb(s, symb);
				Assert::IsTrue(s == s_check);
			}

		} // End of testing the function del_symb.
		
		TEST_METHOD(Insert_substr_after_symb)
		{
			{
				string s, s_check, substr;
				char symb;

				s = "12345";
				symb = '6';
				substr = "fff";
				s_check = "12345";
				s = insert_substr_after_symb(s, substr, symb);
				Assert::IsTrue(s == s_check, MSG(s.c_str()));
			}

			{
				string s, s_check, substr;
				char symb;

				s = "12345";
				symb = '1';
				substr = "fff";
				s_check = "1fff2345";
				s = insert_substr_after_symb(s, substr, symb);
				Assert::IsTrue(s == s_check);
			}

			{
				string s, s_check, substr;
				char symb;

				s = "12345";
				symb = '3';
				substr = "fff";
				s_check = "123fff45";
				s = insert_substr_after_symb(s, substr, symb);
				Assert::IsTrue(s == s_check);
			}

			{
				string s, s_check, substr;
				char symb;

				s = "12345";
				symb = '5';
				substr = "fff";
				s_check = "12345fff";
				s = insert_substr_after_symb(s, substr, symb);
				Assert::IsTrue(s == s_check);
			}

			{
				string s, s_check, substr;
				char symb;

				s = "";
				symb = '6';
				substr = "fff";
				s_check = "";
				s = insert_substr_after_symb(s, substr, symb);
				Assert::IsTrue(s == s_check);
			}

		} // End of testing the function insert_substr_after_symb.
		
		TEST_METHOD(Replace_even)
		{
			{
				string s, s_check, substr;

				s = "12 12 12 12 12";
				substr = "ff";
				s_check = "12 ff 12 ff 12";
				replace_even(s, substr);
				Assert::IsTrue(s == s_check, MSG(s.c_str()));
			}

			{
				string s, s_check, substr;

				s = "  12  12   12     12     12  ";
				substr = "ff";
				s_check = "  12  ff   12     ff     12  ";
				replace_even(s, substr);
				Assert::IsTrue(s == s_check, MSG(s.c_str()));
			}

			{
				string s, s_check, substr;

				s = "1212121212   1212121212";
				substr = "ff";
				s_check = "1212121212   ff";
				replace_even(s, substr);
				Assert::IsTrue(s == s_check, MSG(s.c_str()));
			}

			{
				string s, s_check, substr;

				s = "1212121212";
				substr = "ff";
				s_check = "1212121212";
				replace_even(s, substr);
				Assert::IsTrue(s == s_check, MSG(s.c_str()));
			}
		} // End of testing the function replace_even.
	};
}
