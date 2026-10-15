#include "pch.h"
#include "CppUnitTest.h"
#include "..\Pavlenko_test_3\funcs.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#define MSG(msg) [&]{ std::wstringstream _s; _s << msg; return _s.str(); }().c_str()

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Remove_chr)
		{
			{
				char str[] = "1122334455";
				char str_check[] = "1122334455";
				char symb = '6';

				remove_chr(str, symb);
				Assert::AreEqual(0, strcmp(str, str_check));
			}
		
			{
				char str[] = "1122334455";
				char str_check[] = "112334455";
				char symb = '1';

				remove_chr(str, symb);
				Assert::AreEqual(0, strcmp(str, str_check), MSG(str));
			}
		
			{
				char str[] = "1122334455";
				char str_check[] = "112233455";
				char symb = '3';

				remove_chr(str, symb);
				Assert::AreEqual(0, strcmp(str, str_check));
			}
		
			{
				char str[] = "1122334455";
				char str_check[] = "1122334455";
				char symb = '5';

				remove_chr(str, symb);
				Assert::AreEqual(0, strcmp(str, str_check), MSG(str));
			}
		
			{
				char str[] = "1122334455";
				char str_check[] = "112233445";
				char symb = '4';

				remove_chr(str, symb);
				Assert::AreEqual(0, strcmp(str, str_check));
			}
		
			{
				char str[] = "112233445";
				char str_check[] = "11223344";
				char symb = '4';

				remove_chr(str, symb);
				Assert::AreEqual(0, strcmp(str, str_check));
			}
		} // End of testing the function remove_chr.

		TEST_METHOD(Insert_word)
		{
			{
				string str = "11 22 33 44 5";
				string substr = "hello";
				string str_check = "11 22 33 hello44 5";
				char symb = '4';

				insert_word(str, substr, symb);
				Assert::AreEqual(true, str == str_check, MSG(str.c_str()));
			}
		
			{
				string str = "11 22 33 44 5";
				string substr = "hello";
				string str_check = "hello11 22 33 44 5";
				char symb = '1';

				insert_word(str, substr, symb);
				Assert::AreEqual(true, str == str_check, MSG(str.c_str()));
			}
		
			{
				string str = "11 22 33 44 5";
				string substr = "hello";
				string str_check = "11 22 33 44 5";
				char symb = '5';

				insert_word(str, substr, symb);
				Assert::AreEqual(true, str == str_check, MSG(str.c_str()));
			}
		
			{
				string str = "11 34 33 44 5";
				string substr = "hello";
				string str_check = "11 34 33 hello44 5";
				char symb = '4';

				insert_word(str, substr, symb);
				Assert::AreEqual(true, str == str_check, MSG(str.c_str()));
			}
		
			{
				string str = "11 22 33 44 5";
				string substr = "hello";
				string str_check = "hello41 22 hello43 hello44 hello4";
				char symb = '4';

				insert_word(str, substr, symb);
				Assert::AreEqual(true, str == str_check, MSG(str.c_str()));
			}
		} // End of testing the function insert_word.
	};
}
