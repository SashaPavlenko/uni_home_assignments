#include <iostream>

using namespace std;

// An array of integers is given. Find the product of the elements located after the last zero element.
int prod_elem_after_last_zero(int* a, int size) {
	int prod{ 1 }, index{ size - 1 };

	while (index >= 0 && a[index] != 0) index--;

	// Exception: the array contains no zero elements.
	// Error code: 1
	if (index == -1)
		throw 1;

	// Exception: the last zero element in the array is the last element, so the product cannot be computed.
	// Error code: 2
	if (index == size-1)
		throw 2;

	for (int i = index + 1; i < size; ++i)
		prod *= a[i];

	return prod;

}

int main() {

	int a[] = { 0, 2, 1, 4, 0 };

	cout << prod_elem_after_last_zero(a, sizeof(a) / sizeof(int));

	return 0;
}
