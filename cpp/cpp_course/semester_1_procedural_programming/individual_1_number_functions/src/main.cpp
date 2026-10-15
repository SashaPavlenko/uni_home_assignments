#include <iostream>
#include "The_first.h"
#include "The_second.h"
#include "The_fird.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	int count1{ 0 };

	int N, num, k, count{ 0 }, max_num, num_of_max_num;
	cout << "Enter N: ";
	cin >> N;
	cout << "Enter the digit that the numbers must start with: ";
	cin >> k;
	cout << endl;

	// Make one pass to put a value into max_num.
	// ----------------------------------------------------
	cout << "Enter a number: ";
	cin >> num;
	max_num = num;
	num_of_max_num = count_of_num(num);

	if (nodd_numer_begins_num(num, k))
		count++;
	// ----------------------------------------------------

	for (int i = 1; i < N; i++) {
		cout << "Enter a number: ";
		cin >> num;
		//cout << endl;

		if (nodd_numer_begins_num(num, k))
			count++;

		int s = count_of_num(num);
		if (num_of_max_num < s) {
			max_num = num;
			num_of_max_num = s;
		}

	}

	cout << endl << "Number of even numbers starting with the given digit: " << count;
	cout << endl << "The number with the maximum number of digits (if there are several such numbers - the first of them): " << max_num;

	return 0;
}