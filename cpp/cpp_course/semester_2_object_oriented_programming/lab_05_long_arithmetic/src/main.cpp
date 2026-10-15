#include <iostream>
#include "bignum.h"
#include "Array.h"

using namespace std;

int main() {

	
	/*string ss = "-10";
	bignum n(ss);
	cout << n;*/

	/*bignum n1(123);
	bignum n2(0);

	cout << (n1 > n2);*/

	//bignum n1(123);
	//string s = static_cast<string>(n1);
	
	bignum n1(31);
	bignum n2(7);
	//bignum n_check(-100);
	bignum n3(n1 % n2);
	//bignum n_check(100);

	cout << factorial(bignum(100)) << endl; 
	
	//bignum i(10);
	//i += 1;
	//cout << (i) << endl;

	//bignum n1(99); 
	//int n2{ 9 };
	////cin >> n1 >> n2;
	//cout << (n1 * n2) << endl;
	//cout << (n_check == n3);

	return 0;
}