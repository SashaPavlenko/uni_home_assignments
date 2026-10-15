#include "pch.h"
#include "CppUnitTest.h"
#include "../Pavlenko_test_4/funcs.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Find_pos)
		{
			{
				char* str = const_cast<char*>("nol\'1234");
				int pos{ find_pos(str) };

				Assert::AreEqual(0, pos);
			}
			
			{
				char* str = const_cast<char*>("01\dva34");
				int pos{ find_pos(str) };

				Assert::AreEqual(2, pos);
			}

			{
				char* str = const_cast<char*>("01234pyat\'");
				int pos{ find_pos(str) };

				Assert::AreEqual(5, pos);
			}
		}
	};
}
