#include "pch.h"
#include "CppUnitTest.h"
#include "..\Pavlenko_lab_13\funcs.h"

#define MSG(msg) [&]{ std::wstringstream _s; _s << msg; return _s.str(); }().c_str()

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Str_cmp)
		{
			// Check: s1 > s2, where the length of s1 equals that of s2. 
			{
				char s1[Max_Length] = "124";
				char s2[Max_Length] = "123";

				Assert::AreEqual(1, str_cmp(s1, s2));
			}

			// Check: s1 < s2, where the length of s1 equals that of s2. 
			{
				char s1[Max_Length] = "123";
				char s2[Max_Length] = "124";

				Assert::AreEqual(-1, str_cmp(s1, s2));
			}
			
			// Check: s1 = s2, where the length of s1 equals that of s2. 
			{
				char s1[Max_Length] = "123";
				char s2[Max_Length] = "123";

				Assert::AreEqual(0, str_cmp(s1, s2));
			}

			// Check: s1 > s2, where the length of s1 is greater than that of s2 and the first differing character is the last one. 
			{
				char s1[Max_Length] = "1234";
				char s2[Max_Length] = "123";

				Assert::AreEqual(1, str_cmp(s1, s2));
			}

			// Check: s1 < s2, where the length of s1 is less than that of s2 and the first differing character is the last one. 
			{
				char s1[Max_Length] = "123";
				char s2[Max_Length] = "1234";

				Assert::AreEqual(-1, str_cmp(s1, s2));
			}

			// Check: s1 < s2, where the length of s1 is greater than that of s2 and the first differing character is not the last one. 
			{
				char s1[Max_Length] = "12333";
				char s2[Max_Length] = "1234";

				Assert::AreEqual(-1, str_cmp(s1, s2));
			}
			
			// Check: s1 > s2, where the length of s1 is greater than that of s2 and the first differing character is not the last one. 
			{
				char s1[Max_Length] = "12353";
				char s2[Max_Length] = "1234";

				Assert::AreEqual(1, str_cmp(s1, s2));
			}

			// Check: s1 < s2, where the length of s1 is less than that of s2 and the first differing character is not the last one. 
			{
				char s1[Max_Length] = "123";
				char s2[Max_Length] = "1244";

				Assert::AreEqual(-1, str_cmp(s1, s2));
			}
			
			// Check: s1 > s2, where the length of s1 is less than that of s2 and the first differing character is not the last one. 
			{
				char s1[Max_Length] = "125";
				char s2[Max_Length] = "1234";

				Assert::AreEqual(1, str_cmp(s1, s2));
			}
		} // End of testing the function.
		TEST_METHOD(Word_count)
		{
			// Check: the number of words in the string "" is 0.
			{
				char str1[Max_Length] = "";
				Assert::AreEqual(0, word_count(str1));
			}

			// Check: the number of words in the string " " is 0.
			{
				char str1[Max_Length] = " ";
				Assert::AreEqual(0, word_count(str1));
			}

			// Check: the number of words in the string "   " is 0.
			{
				char str1[Max_Length] = "   ";
				Assert::AreEqual(0, word_count(str1));
			}

			// Check: the number of words in the string "f" is 1.
			{
				char str1[Max_Length] = "f";
				Assert::AreEqual(1, word_count(str1));
			}

			// Check: the number of words in the string " f" is 1.
			{
				char str1[Max_Length] = " f";
				Assert::AreEqual(1, word_count(str1));
			}

			// Check: the number of words in the string " f " is 1.
			{
				char str1[Max_Length] = " f ";
				Assert::AreEqual(1, word_count(str1));
			}

			// Check: the number of words in the string "  f" is 1.
			{
				char str1[Max_Length] = "  f";
				Assert::AreEqual(1, word_count(str1));
			}

			// Check: the number of words in the string "ff" is 1.
			{
				char str1[Max_Length] = "ff";
				Assert::AreEqual(1, word_count(str1));
			}

			// Check: the number of words in the string "f f" is 2.
			{
				char str1[Max_Length] = "f f";
				Assert::AreEqual(2, word_count(str1));
			}

			// Check: the number of words in the string "f ff" is 2.
			{
				char str1[Max_Length] = "f ff";
				Assert::AreEqual(2, word_count(str1));
			}

			// Check: the number of words in the string "f ff " is 2.
			{
				char str1[Max_Length] = "f ff ";
				Assert::AreEqual(2, word_count(str1));
			}

			// Check: the number of words in the string " f ff" is 2.
			{
				char str1[Max_Length] = " f ff";
				Assert::AreEqual(2, word_count(str1));
			}

			// Check: the number of words in the string " f f " is 2.
			{
				char str1[Max_Length] = " f f ";
				Assert::AreEqual(2, word_count(str1));
			}

			// Check: the number of words in the string "hello world!" is 2.
			{
				char str1[Max_Length] = "hello world!";
				Assert::AreEqual(2, word_count(str1));
			}

			// Check: the number of words in the string "one two three" is 3.
			{
				char str1[Max_Length] = "one two three";
				Assert::AreEqual(3, word_count(str1));
			}

		} // End of testing the function.

		TEST_METHOD(Remove_chr)
		{
			// Check: removing the Cyrillic character 'с' from the string "сabde". Result: "abde".
			{
				char str[Max_Length] = "сabde";

				char check_str[Max_Length] = "abde";
				
				remove_chr(str, 'с');

				Assert::AreEqual(0, str_cmp(str, check_str), MSG(str));

			}

			// Check: removing the characters 'c' from the string "abcde". Result: "abde".
			{
				char str[Max_Length] = "abcde";

				char check_str[Max_Length] = "abde";

				remove_chr(str, 'c');
				Assert::AreEqual(0, str_cmp(str, check_str));

			}

			// Check: removing the Cyrillic character 'с' from the string "abdeс". Result: "abde".
			{
				char str[Max_Length] = "abdec";

				char check_str[Max_Length] = "abde";

				remove_chr(str, 'c');
				Assert::AreEqual(0, str_cmp(str, check_str));

			}

			// Check: removing the characters 'c' from the string "abccde". Result: "abde".
			{
				char str[Max_Length] = "abccde";

				char check_str[Max_Length] = "abde";

				remove_chr(str, 'c');
				Assert::AreEqual(0, str_cmp(str, check_str));

			}

			// Check: removing the Cyrillic character 'с' from the string "сabсcdeс". Result: "abde".
			{
				char str[Max_Length] = "cabccdec";

				char check_str[Max_Length] = "abde";

				remove_chr(str, 'c');
				Assert::AreEqual(0, str_cmp(str, check_str), MSG(str));

			}

			// Check: removing the characters 'c' from the string "abde". Result: "abde".
			{
				char str[Max_Length] = "abde";

				char check_str[Max_Length] = "abde";

				remove_chr(str, 'c');
				Assert::AreEqual(0, str_cmp(str, check_str));

			}
		} // End of testing the function.
	
		TEST_METHOD(Insert_str)
		{
			// Check: inserting the substring "123" into the string "caaa" after the character 'c'. Result: "c123aaa".
			{
				char str[Max_Length] = "caaa";
				char substr[Max_Length] = "123";

				char check_str[Max_Length] = "c123aaa";

				insert_str(str, substr, 'c');
				Assert::AreEqual(0, str_cmp(str, check_str));

			}

			// Check: inserting the substring "123" into the string "acaa" after the character 'c'. Result: "ac123aa".
			{
				char str[Max_Length] = "acaa";
				char substr[Max_Length] = "123";

				char check_str[Max_Length] = "ac123aa";

				insert_str(str, substr, 'c');
				Assert::AreEqual(0, str_cmp(str, check_str));

			}

			// Check: inserting the substring "123" into the string "aaac" after the character 'c'. Result: "aaac123".
			{
				char str[Max_Length] = "aaac";
				char substr[Max_Length] = "123";

				char check_str[Max_Length] = "aaac123";

				insert_str(str, substr, 'c');
				Assert::AreEqual(0, str_cmp(str, check_str));
			
			}

			// Check: inserting the substring "" into the string "aaac" after the character 'c'. Result: "aaac".
			{
				char str[Max_Length] = "caaa";
				char substr[Max_Length] = "";

				char check_str[Max_Length] = "caaa";

				insert_str(str, substr, 'c');
				Assert::AreEqual(0, str_cmp(str, check_str));

			}
			
			// Exception check: the insertion is impossible because the character after which the substring has to be inserted is not in the string.
			{
				try {
					auto func = [] {
						
						char str[Max_Length] = "aaa";
						char substr[Max_Length] = "1";
						
						insert_str(str, substr, 'c');
					};
				}
				catch (char* s) {
					Assert::AreEqual(0, str_cmp("Incorrect data", s));
				}
			}

		} // End of testing the function.
	};

}