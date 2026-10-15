#include <iostream>
#include "funcs.h"
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>

int* del_num_mul_3(int* a, int size, int& new_size) {
	int index{ 0 }, count_cond{ 0 };

	for (int i = 0; i < size; i++)
	{
		if (a[i] % 3 == 0) {
			count_cond++;
		}
	}

	// Exception: the array has no elements that are multiples of 3.
	// Error code: 1.
	if (count_cond == 0) {
		throw 1;
	}

	int* new_m = new int[size - count_cond];
	new_size = size-count_cond;

	for (int i = 0; i < size && count_cond > 0; i++)
	{
		if (a[i] % 3 != 0) {
			new_m[index++] = a[i];
			count_cond--;
		}
	}

	return new_m;
}

int find_pos(char* str) {
	int pos{ 0 };

	while (*str && ('0' <= *str && *str <= '9')) {
		str++;
		pos++;
	}

	return pos;
}

bool first_has_more_digits(int first, int second) {
	first = abs(first);
	second = abs(second);

	while (first != 0 && second != 0) {
		first /= 10;
		second /= 10;
	}

	return first == 0 && second != 0;
}

int find_max_el(char* filename) {
	fstream f(filename);

	string str;

	int mmax;
	f >> mmax;

	while (!f.eof()) {
		getline(f, str);

		stringstream stream(str);
		for_each(istream_iterator<string>(stream), istream_iterator<string>(), [&](auto number) {
			
			int now{ atoi(number.c_str()) };
			if (first_has_more_digits(mmax, now)) {
				mmax = now;
			}
			});
	}

	return mmax;
}