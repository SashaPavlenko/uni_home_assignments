#include <iostream>
#include "fract.h"
#include "Time.h"
using namespace std;

int main() {
	/*Fract f1(2, 3), f2(3), f3(1, 2);
	cout << "f1=" << f1 << endl;
	cout << "f2=" << f2 << endl;
	cout << "f3=" << f3 << endl;
	Fract res = f1 + f2;
	cout << res << endl;
	res = f1 + f3;
	cout << res << endl;
	Fract sum;
	sum = sum + f1;
	sum = sum + f2;
	sum = sum + f3;
	cout << sum << endl;*/
	
	//Fract f1(1, 2);
	//Fract f2(1, 2);
	//Fract f3(1, 3);

	//cout << f1 + f2 << endl;
	//cout << (f1 + f3) * Fract(6, 25) << endl;
	//cout << (f1 + f3) / Fract(25, 6) << endl;

	//f.print();

	Time t1;
	Time t2(5, 51, 19);
	Time t3(5, 51, 0);

	//cout << t1 << endl << t2 << endl;
	/*cout << t1 << endl;
	cout << t2 << endl;*/
	cout << t2 + t3 << endl;

	system("pause");
 	return 0;
}