#include "pch.h"
#include "CppUnitTest.h"
#include "..\Pavlenko_term_2_lab_7\Circle.h"
#include "..\Pavlenko_term_2_lab_7\Cone.h"
#include "..\Pavlenko_term_2_lab_7\Cylinder.h"
#include "..\Pavlenko_term_2_lab_7\Sphere.h"
#include "..\Pavlenko_term_2_lab_7\funcs.h"
#include "..\Pavlenko_term_2_lab_7\funcs.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Measure)
		{
			{			
				Cone a(2, 3);
				Circle b(2);
				Sphere c(2);
				Cylinder d(3, 2);

				Assert::IsTrue(abs(a.measure() - 12.5664) < 1e-3);
				Assert::IsTrue(abs(b.measure() - 12.5664) < 1e-3);
				Assert::IsTrue(abs(c.measure() - 100.531) < 1e-3);
				Assert::IsTrue(abs(d.measure() - 56.5487) < 1e-3);

			}
		} // end testing measure.
	};
}
