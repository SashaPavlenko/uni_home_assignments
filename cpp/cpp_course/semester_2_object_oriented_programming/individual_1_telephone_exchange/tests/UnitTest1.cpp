#include "pch.h"
#include "CppUnitTest.h"
#include "..\Pavlenko_term_2_indiv_1\ATS.h"
#include "..\Pavlenko_term_2_indiv_1\func.h"
#include <string>
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Summarize_minutes)
		{
			{
				string str{"ACademy\n\
2803139\n\
703 127 388\n\
80108204656\n\
61 258 251\n\
"};
				ATS check;
				std::stringstream stream(str);
				stream >> check;

				Assert::AreEqual(1788, check.summarize_minutes());

			}

			{
				string str{"TWining\n\
2251565\n\
104 179 28\n\
85138752527\n\
300 32 76\n\
"};
				ATS check;
				std::stringstream stream(str);
				stream >> check;

				Assert::AreEqual(719, check.summarize_minutes());

			}

			{
				string str{"BAldwin\n\
2511252\n\
660 400 703\n\
8808901107\n\
20 744 477\n\
"};
				ATS check;
				std::stringstream stream(str);
				stream >> check;

				Assert::AreEqual(3004, check.summarize_minutes());

			}
		} // end testing summarize_minutes.
		
		TEST_METHOD(Check_limit_city)
		{
			{
				string str{"CAnal\n\
2777871\n\
267 309 463\n\
85377557410\n\
68 169 78\n\
"};
				ATS check;
				std::stringstream stream(str);
				stream >> check;

				Assert::AreEqual(false, check.check_limit_city());

			}

			{
				string str{"TWinbrook\n\
2980329\n\
2 171 286\n\
81642778585\n\
380 162 183\n\
" };
				ATS check;
				std::stringstream stream(str);
				stream >> check;

				Assert::AreEqual(true, check.check_limit_city());

			}

		} // end testing check_limit_city.

	};
}
