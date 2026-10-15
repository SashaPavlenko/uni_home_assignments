#include "pch.h"
#include "CppUnitTest.h"
#include "..\Pavlenko_lab_16\funcs.h"
#include <cassert>
#include <fstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

bool is_equal_text(const char* filename1, const char* filename2);

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Find_min_abs)
		{
			Assert::AreEqual(1., find_min_abs("../Pavlenko_lab_16/tests/test_1.txt"));
		}

		TEST_METHOD(Find_min_max_in_rows)
		{	
			find_min_max_in_rows("../tests/test_2.txt");
            Assert::IsTrue(is_equal_text("../tests/test_2_out.txt", "../tests/test_2_check.txt"));
		}

	};
}

bool is_equal_text(const char* filename1, const char* filename2)
{
    assert(filename1); //an empty string is not allowed
    assert(filename2); //an empty string is not allowed

    std::ifstream f1(filename1);
    if (!f1.is_open()) {
        char error[128] = "Couldn't open file ";
        //strncat(error, filename1, 108);
        throw error;
    }

    std::ifstream f2(filename2);
    if (!f2.is_open()) {
        char error[128] = "Couldn't open file ";
        //strncat(error, filename2, 108);
        throw error;
    }
    bool result = true;
    char c1, c2;
    while (result && !f1.eof() && !f2.eof()) {
        f1.get(c1);
        f2.get(c2);
        if (c1 != c2)   result = false;
    }
    if (!f1.eof() || !f2.eof())
        result = false;

    f1.close(); // close in any case
    f2.close();
    return result;
}