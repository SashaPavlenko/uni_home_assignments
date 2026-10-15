#include <iostream>

bool nodd_numer_begins_num(int num, int k) {
	num = abs(num);
	int ost{ num % 10 };

	while (num / 10)
		num /= 10;

	return !(ost % 2) && num == k;
}

int count_of_num(int num) {
	int sum{ 0 };
	num = abs(num);

	while (num) {
		sum++;
		num /= 10;
	}

	return sum;
}
