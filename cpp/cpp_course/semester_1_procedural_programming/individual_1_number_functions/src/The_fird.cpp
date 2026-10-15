#include <iostream>

int find_min_num(int n) {
	n = std::abs(n);

	if (n / 10) {
		int n_min{ find_min_num(n / 10) };
		return std::min(n % 10, n_min);
	}
	else
		return n;
}