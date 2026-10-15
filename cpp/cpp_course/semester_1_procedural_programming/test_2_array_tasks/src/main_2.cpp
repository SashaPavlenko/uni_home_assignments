#include <iostream>

using namespace std;

// An array of integers is given. 
// Remove from the array all elements located between the first minimum and the last maximum.
// The array is located in dynamic memory.
void del_elements_cond(int*& a, int& size) {

	int maxn{ a[0] }, minn{ a[0] }, index_max{ 0 }, index_min{ 0 };

	for (int i = 1; i < size; ++i) {
		if (minn > a[i]) {
			minn = a[i];
			index_min = i;
		}

		if (maxn <= a[i]) {
			maxn = a[i];
			index_max = i;
		}
	}
	
	// It is convenient if the value in index_min is less than the value in index_max.
	if (index_max < index_min)
		swap(index_min, index_max);

	// There is nothing to delete. The interval contains no elements.
	if (index_max - index_min <= 1)
		return;

	int* new_arr = new int[size - (index_max - index_min - 1)];
	
	for (int i = 0; i <= index_min; ++i)
		new_arr[i] = a[i];

	for (int i = index_max, index_now = index_min + 1; i < size; ++i)
		new_arr[index_now++] = a[i];

	delete[] a;
	a = new_arr;
	size = size - (index_max - index_min - 1);
}


int main() {

	int* a = new int[] { 4, 2, -1, 3, 3, -2 };
	int size{ 6 };

	del_elements_cond(a, size);

	for (int i = 0; i < size; ++i)
		cout << a[i] << " ";

	return 0;
}
