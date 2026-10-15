#include <iostream>

using namespace std;

void print_num_rev(int num) {

	cout << num % 10;
	if (num /= 10) {
		print_num_rev(num);
	}
	else
		cout << endl;
}

int count_num(int num) {
	int sum = 1;
	if (num /= 10)
		sum = sum + count_num(num);
	return sum;
}

int sum_num(int num) {
	int sum = 0;

	if (num) {
		sum += sum_num(num / 10);
	}
	
	return sum;
}

int rec_gcd_find(int mmax, int mmin) {
	if (mmax < mmin)
		swap(mmax, mmin);
	
	if (mmax % mmin) {
		mmax = mmax % mmin;
		return rec_gcd_find(mmax, mmin);
	}
	else
		return mmin;
}

int iter_gcd_find(int mmax, int mmin) {
	if (mmax < mmin)
		swap(mmax, mmin);

	while (mmax % mmin) {
		mmax = mmax % mmin;
		swap(mmax, mmin);
	}

	return mmin;
}

int prime_sum(int num, int i) {

	int sum{ 0 };
	bool flag = false;

	while (!(num % i))
	{
		num /= i;
		flag = true;
	}

	if (num > 1 && flag)
		sum += i + prime_sum(num, i + 1);
	else
		if (num > 1)
			sum += prime_sum(num, i + 1);
		else
			if (flag)
				sum += i;
		
	return sum;
}

double to_pow(double num, int pow) {
	double sum{ 1 };

	if (pow < 0)
		sum = sum / num * to_pow(num, pow + 1);
	else 
		if (pow > 0)
			sum = sum * num * to_pow(num, pow - 1);

	return sum;

}