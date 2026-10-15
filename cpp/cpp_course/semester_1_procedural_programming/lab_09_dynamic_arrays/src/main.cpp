#include <iostream>
#include <crtdbg.h>
#include "funcs.h"

#ifdef _DEBUG
#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC
#endif

#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)


using namespace std;

const int INT_BUFFER = 1024 * 1024;

void foo() {
	int* a = new int[INT_BUFFER];
}

void foo1() {
	int* a = new int[INT_BUFFER];
	
	delete[] a;
}

int main() {
	_CrtMemState _ms;
	_CrtMemCheckpoint(&_ms);

	//foo();
	//foo1();

	setlocale(LC_ALL, "rus");

	int* a = nullptr;
	size_t n;

	//read(a, n);

	//cout << "printed array: " << endl;
	//print_array(a, n);

	//int* b = random_array(n);
	//
	//cout << endl << "array with random elements: " << endl;
	//print_array(b, n);

	////inser
	//delete[] a;
	//delete[] b;

	read(a, n);

	int k;
	cin >> k;
	// insert_to_the_center(a, n, k);
	del_index(a, n, k);

	print_array(a, n);

	/*int size{ 8 };
	int* a = new int[size] {1, 2, 2, 3, 3, 3, 4, 1};

	print_array(a, size);
	
	del_duplicates(a, size);
	
	print_array(a, size);

	delete[] a; */

	_CrtMemDumpAllObjectsSince(&_ms);

	return 0;
}