#include "pch.h"
#include "CppUnitTest.h"
#include "../Pavlenko_lab_9/funcs.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Insert_to_the_center)
		{
			// Start of test 1. -------------------------------------------------
			int k1 = 0;
			int n1 = 3;
			int* a1 = new int[n1] {1, 2, 3};
			int* a1_1 = new int[n1+1] {1, 2, 0, 3};
			
			insert_to_the_center(a1, n1, k1);


			for (int i = 0; i < n1; i++) 
				Assert::AreEqual(a1_1[i], a1[i]);
			
			// Start of test 2. -------------------------------------------------			
			int k2 = 101;
			int n2 = 4;
			int* a2 = new int[n2] {404, 404, 404, 404};
			int* a2_1 = new int[n2+1] {404, 404, 101, 404, 404};

			insert_to_the_center(a2, n2, k2);


			for (int i = 0; i < n2; i++) 
				Assert::AreEqual(a2_1[i], a2[i]);

			// Start of test 3. -------------------------------------------------			
			int k3 = 0;
			int n3 = 1;
			int* a3 = new int[n3] {1};
			int* a3_1 = new int[n3+1] {1, 0};

			insert_to_the_center(a3, n3, k3);


			for (int i = 0; i < n3; i++) 
				Assert::AreEqual(a3_1[i], a3[i]);
		
			delete[] a1;
			delete[] a2;
			delete[] a3;
			delete[] a1_1;
			delete[] a2_1;
			delete[] a3_1;
		}

		TEST_METHOD(Del_index)
		{
		
			int k1 = 1;
			int n1 = 3;
			int* a1 = new int[n1] {1, 2, 3};
			int* a1_1 = new int[n1] {1, 3};

			del_index(a1, n1, k1);

			for (int i = 0; i < n1; i++)
				Assert::AreEqual(a1_1[i], a1[i]);


			int k2 = 0;
			int n2 = 3;
			int* a2 = new int[n2] {1, 2, 3};
			int* a2_1 = new int[n2] {2, 3};

			del_index(a2, n2, k2);

			for (int i = 0; i < n2; i++)
				Assert::AreEqual(a2_1[i], a2[i]);


			int k3 = 2;
			int n3 = 3;
			int* a3 = new int[n3] {1, 2, 3};
			int* a3_1 = new int[n3] {1, 2};

			del_index(a3, n3, k3);

			for (int i = 0; i < n3; i++)
				Assert::AreEqual(a3_1[i], a3[i]);

			delete[] a1;
			delete[] a2;
			delete[] a3;
			delete[] a1_1;
			delete[] a2_1;
			delete[] a3_1;
		}

		TEST_METHOD(Del_duplicates)
		{
			{
				int n1 = 7;
				int* a1 = new int[n1] {1, 2, 3, 3, 3, 4, 5};
				int* a1_1 = new int[n1-2] {1, 2, 3, 4, 5};

				del_duplicates(a1, n1);

				for (int i = 0; i < n1; i++)
					Assert::AreEqual(a1_1[i], a1[i]);

				delete[] a1, a1_1;
			}

			{
				int n1 = 7;
				int* a1 = new int[n1] {1, 2, 3, 4, 5, 5, 5};
				int* a1_1 = new int[n1 - 2]{ 1, 2, 3, 4, 5 };

				del_duplicates(a1, n1);

				for (int i = 0; i < n1; i++)
					Assert::AreEqual(a1_1[i], a1[i]);

				delete[] a1, a1_1;
			}

			{
				int n1 = 7;
				int* a1 = new int[n1] {1, 1, 1, 2, 3, 4, 5};
				int* a1_1 = new int[n1 - 2]{ 1, 2, 3, 4, 5 };

				del_duplicates(a1, n1);

				for (int i = 0; i < n1; i++)
					Assert::AreEqual(a1_1[i], a1[i]);

				delete[] a1, a1_1;
			}
		}

		TEST_METHOD(Is_sorted)
		{
			{
				int n{ 5 };
				int* a = new int[n] {1, 2, 3, 4, 5};

				Assert::AreEqual(true, is_sorted(a, n));

				delete[] a;
			}

			{
				int n{ 5 };
				int* a = new int[n] {1, 3, 2, 4, 5};

				Assert::AreEqual(false, is_sorted(a, n));

				delete[] a;
			}

			{
				int n{ 5 };
				int* a = new int[n] {5, 4, 3, 2, 1};

				Assert::AreEqual(false, is_sorted(a, n));

				delete[] a;
			}

			{
				int n{ 5 };
				int* a = new int[n] {-1, -2, -3, -4, -5};

				Assert::AreEqual(false, is_sorted(a, n));

				delete[] a;
			}

			{
				int n{ 5 };
				int* a = new int[n] {-5, -4, -3, -2, -1};

				Assert::AreEqual(true, is_sorted(a, n));

				delete[] a;
			}

			{
				int n{ 3 };
				int* a = new int[n] {-1, 0, 1};

				Assert::AreEqual(true, is_sorted(a, n));

				delete[] a;
			}

			{
				int n{ 3 };
				int* a = new int[n] {1, 0, -1};

				Assert::AreEqual(false, is_sorted(a, n));

				delete[] a;
			}

			{
				int n{ 1 };
				int* a = new int[n] {-1};

				Assert::AreEqual(true, is_sorted(a, n));

				delete[] a;
			}

			{
				int n{ 1 };
				int* a = new int[n] {0};

				Assert::AreEqual(true, is_sorted(a, n));

				delete[] a;
			}

			{
				int n{ 1 };
				int* a = new int[n] {1};

				Assert::AreEqual(true, is_sorted(a, n));

				delete[] a;
			}
		}

		TEST_METHOD(Bin_find)
		{
			{
				int n{ 5 };
				int* a = new int[n] {1, 2, 3, 4, 5};
				int k;
				
				k = 2;
				Assert::AreEqual(1, bin_find(a, n, k));

				k = 1;
				Assert::AreEqual(0, bin_find(a, n, k));

				k = 5;
				Assert::AreEqual(4, bin_find(a, n, k));

				k = 8;
				Assert::AreEqual(-1, bin_find(a, n, k));

				delete[] a;
			}

			{
				int n{ 1 };
				int* a = new int[n] {1};
				int k;

				k = 1;
				Assert::AreEqual(0, bin_find(a, n, k));

				k = 2;
				Assert::AreEqual(-1, bin_find(a, n, k));

				delete[] a;
			}
		}

		TEST_METHOD(QSort)
		{
			{
				// _CrtMemState _ms;
				// _CrtMemCheckpoint(&_ms);


				int n{ 5 };
				int* a = new int[n] {1, 2, 3, 4, 5};
				int* a_sorted = new int[n] {1, 2, 3, 4, 5};

				qSort(a, 0, n - 1);
				for (int i = 0; i < n; ++i)
					Assert::AreEqual(a_sorted[i], a[i]);

				// delete[] a, a_sorted;

				// _CrtMemDumpAllObjectsSince(&_ms);
			}

			{
				int n{ 5 };
				int* a = new int[n] {5, 4, 3, 2, 1};
				int* a_sorted = new int[n] {1, 2, 3, 4, 5};

				qSort(a, 0, n-1);
				for (int i = 0; i < n; ++i)
					Assert::AreEqual(a_sorted[i], a[i]);

				delete[] a, a_sorted;
			}

			{
				int n{ 5 };
				int* a = new int[n] {1, 4, 3, 2, 5};
				int* a_sorted = new int[n] {1, 2, 3, 4, 5};

				qSort(a, 0, n-1);
				for (int i = 0; i < n; ++i)
					Assert::AreEqual(a_sorted[i], a[i]);

				delete[] a, a_sorted;
			}

			{
				int n{ 5 };
				int* a = new int[n] {5, -4, 3, -2, 1};
				int* a_sorted = new int[n] {-4, -2, 1, 3, 5};

				qSort(a, 0, n-1);
				for (int i = 0; i < n; ++i)
					Assert::AreEqual(a_sorted[i], a[i]);

				delete[] a, a_sorted;
			}

			{
				int n{ 1 };
				int* a = new int[n] {1};
				int* a_sorted = new int[n] {1};

				qSort(a, 0, n-1);
				for (int i = 0; i < n; ++i)
					Assert::AreEqual(a_sorted[i], a[i]);

				delete[] a, a_sorted;
			}
		}
	};
}