#include <iostream>

using namespace std;

// Computes, for a given natural number N, the sum of the first N terms by the formula.
double count_sum(int);
/*
int main() {
	setlocale(LC_ALL, "rus");

	int n;
	cout << "Enter N: ";
	cin >> n;
	cout << endl;

	cout << "Result: " << count_sum(n) << endl;

	cout << endl << "Examples: ";
	cout << "\nfor N = 1 the correct answer: " << 0.25 << "; Value returned by the function: " << count_sum(1);
	cout << "\nfor N = 2 the correct answer: " << 0.3125 << "; Value returned by the function: " << count_sum(2);
	cout << "\nfor N = 3 the correct answer: " << 0.34027 << "; Value returned by the function: " << count_sum(3);
	
	return 0;
}
*/


double count_sum(int N) {

	double sum{ 0 };

	for (double k = 1.; k < N || abs(k-N) < 1e-8; k+=1.)
		sum += 1. / 2. / 2. / k / k;

	return sum;
}