#include <iostream>
#include "funcs.h"
#include "ctime"

#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)

void read(int*& a, std::size_t& n) {
	std::cout << "enter the size of the arrays: ";
	std::cin >> n;

	a = new int[n];

	for (std::size_t i = 0; i < n; i++)
		std::cin >> a[i];
}

int* random_array(std::size_t n) {
	std::srand(std::time(nullptr));

	int* a = new int[n];

	for (std::size_t i = 0; i < n; i++) {
		a[i] = std::rand();
	}

	return a;
}

void print_array(int* a, int size) {
	for (int i = 0; i < size; i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;
}

void insert_to_the_center(int*& a, size_t& size, int element) {
	size_t new_size{ size + 1 };
	size_t end_firs_half{ size / 2 + size % 2 };
	
	int* b = new int[new_size];

	for (int i = 0; i < new_size; i++) {

		if (i < end_firs_half || i > end_firs_half)
			b[i] = a[i];
		else
			b[i] = element;
	}

	delete[] a;
	a = b;

}

void del_index(int*& a, size_t& size, int index) {
	int* b = new int[size - 1];
	
	for (size_t i = 0; i < index; i++)
		b[i] = a[i];

	for (size_t i = index; i < size - 1; i++)
		b[i] = a[i + 1];

	// delete[] a;
	a = b;
	size--;
}

void del_duplicates(int*& a, size_t& size) {
	int i{ 0 };

	while (i < size) {
		int j = i+1;

		while (j < size) {
			if (a[i] == a[j])
				del_index(a, size, j);
			else
				j++;
		}
		i++;
	}
}

bool is_sorted(int*& a, int& size) {
	for (int i = 0; i < size - 1; i++)
		if (a[i] > a[i + 1])
			return false;
	return true;
}

int bin_find(int*& a, int& size, int T) {
	int p{ 0 }, q{ size - 1 };

	while (p != q) {
		int s = (p + q) / 2;

		if (a[s] < T)
			p = s + 1;
		else
			q = s;
	}

	if (a[p] != T)
		p = -1;

	return p;
}

void qSort(int* A, int low, int high) {
	int i{ low }, j{ high };
	int x{ A[(low + high) / 2] }; // x - the pivot
	do {
		while (A[i] < x) ++i; // look for an element to move
		while (A[j] > x) --j; // look for an element to move
		if (i <= j) { // swap the elements:
			std::swap(A[i], A[j]);
			++i; --j; // move on to the next elements:
		}
	} while (i < j);
	if (low < j) qSort(A, low, j);
	if (i < high) qSort(A, i, high);
}
