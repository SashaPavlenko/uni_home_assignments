#include "pch.h"
#include "CppUnitTest.h"
#include "..\Pavlenko_lab_10\funcs.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(Arith_mean)
		{
			{
				auto func = [] {
					double a[] = { 1, 1, 1, 0, 1, 1, 1 };

					double arith{ arith_mean(a, sizeof(a) / sizeof(double)) };

					Assert::AreEqual(1., arith);
				};
			}

			{
				try {
					auto func = [] {
						double a[] = { 1, 1, 1, 1, 1, 1 };
						double arith{ arith_mean(a, sizeof(a) / sizeof(double)) };
					};
				}
				catch (int a) {
					Assert::AreEqual(1, a);
				}
			}

			{
				try {
					auto func = [] {
						double a[] = { 0, 1, 1, 1, 1, 1 };
						double arith{ arith_mean(a, sizeof(a) / sizeof(double)) };
					};
				}
				catch (int a) {
					Assert::AreEqual(2, a);
				}
			}

			{
				try {
					auto func = [] {
						double a[] = { 1, 1, 1, 1, 1, 0 };
						double arith{ arith_mean(a, sizeof(a) / sizeof(double)) };
					};
				}
				catch (int a) {
					Assert::AreEqual(3, a);
				}
			}

			{
				try {
					auto func = [] {
						double a[] = { 1, 1, 1, 0, -1, 1 };
						double arith{ arith_mean(a, sizeof(a) / sizeof(double)) };
					};
				}
				catch (int a) {
					Assert::AreEqual(4, a);
				}
			}
		}

		TEST_METHOD(Str_eval)
		{
			{
				char a[] = "1+1";
				Assert::AreEqual(2., str_eval(a));
			}

			{
				char a[] = "1-1";
				Assert::AreEqual(0., str_eval(a));
			}

			{
				char a[] = "2*4";
				Assert::AreEqual(8., str_eval(a));
			}

			{
				char a[] = "6/3";
				Assert::AreEqual(2., str_eval(a));
			}

			{
				char a[] = "5/2";
				Assert::AreEqual(2.5, str_eval(a));
			}

			{
				try {
					auto func = [] {
						char a[] = "1/0";
						double res = str_eval(a);
					};
				}
				catch (int a) {
					Assert::AreEqual(2, a);
				}
			}

			{
				try {
					auto func = [] {
						char a[] = "1%5";
						double res = str_eval(a);
					};
				}
				catch (int a) {
					Assert::AreEqual(3, a);
				}
			}
		}
	};
}
