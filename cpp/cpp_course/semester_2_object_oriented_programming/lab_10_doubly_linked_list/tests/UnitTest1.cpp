#include "pch.h"
#include "CppUnitTest.h"
#include "..\Pavlenko_term_2_lab_10\List.h"
#include "..\Pavlenko_term_2_lab_10\funcs.h"
#include <string>
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(method_List_delIt)
		{
			{
				std::string s = "5\n1 2 3 4 5";
				std::stringstream stream(s);
				List a;
				stream >> a;

				auto it = a.begin();
				++it;
				++it;
				a.delIt(it);

				stream.clear();
				stream << a;
				std:string s_out_test1 = stream.str();

				std::string s_check = "first --> 5 --> 4 --> 2 --> 1 --> last\n";

				Assert::AreEqual(s_check, s_out_test1);
			}
			
			{
				std::string s = "5\n1 2 3 4 5";
				std::stringstream stream(s);
				List a;
				stream >> a;

				auto it = a.begin();
				a.delIt(it);

				stream.clear();
				stream << a;
			std:string s_out_test2{ stream.str() };

				std::string s_check = "first --> 4 --> 3 --> 2 --> 1 --> last\n";

				Assert::AreEqual(s_check, s_out_test2);
			}
			
			{
				std::string s = "5\n1 2 3 4 5";
				std::stringstream stream(s);
				List a;
				stream >> a;

				auto it = a.begin();
				++it;
				++it;
				++it;
				++it;
				a.delIt(it);

				stream.clear();
				stream << a;
				std:string s_out_test3 = stream.str();

				std::string s_check = "first --> 5 --> 4 --> 3 --> 2 --> last\n";

				Assert::AreEqual(s_check, s_out_test3);
			}
		} // end testing delIt.

		TEST_METHOD(method_List_setIter) {
			{
				std::string s = "5\n1 2 3 4 5";
				std::stringstream stream(s);
				List a;
				stream >> a;

				auto it = a.begin();
				++it;
				++it;
				a.setIter(it, 1000);

				stream.clear();
				stream << a;
			std:string s_out = stream.str();

				std::string s_check = "first --> 5 --> 4 --> 1000 --> 3 --> 2 --> 1 --> last\n";

				Assert::AreEqual(s_check, s_out);
			}
		} // end testing setIter.

	};
}
