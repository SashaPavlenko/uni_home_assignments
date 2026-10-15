#include "pch.h"
#include "CppUnitTest.h"
#include "..\Pavlenko_lab_15\funcs.h"
#include <assert.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

bool is_equal_text(const char* filename1, const char* filename2);

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(Biggiest_line) {
            string str = biggiest_line("../Pavlenko_lab_15/test_2.txt");
            string str_max = "1234567";

            Assert::IsTrue(str_max == str);
        }

        TEST_METHOD(Num_of_words) {
            int c1 = num_of_words("../Pavlenko_lab_15/test_3.txt");

            Assert::AreEqual(13, c1);
        }

        TEST_METHOD(Del_words) {
            del_words("../Pavlenko_lab_15/test_4.txt", "123");

            Assert::IsTrue(is_equal_text("../Pavlenko_lab_15/test_4.txt", "../Pavlenko_lab_15/test_4_check.txt"));
        }

        TEST_METHOD(Rep_word_to_num) {
            rep_word_to_num("../Pavlenko_lab_15/test_5.txt", "123");

            Assert::IsTrue(is_equal_text("../Pavlenko_lab_15/test_5.txt", "../Pavlenko_lab_15/test_5_check.txt"));
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
