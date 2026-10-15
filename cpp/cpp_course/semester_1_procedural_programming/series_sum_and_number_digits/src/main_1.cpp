#include <iostream>

using namespace std;

// Changes a given integer by prepending a given digit to it on the left.
void leftDig(int&, int);

///*
int main() {
	setlocale(LC_ALL, "rus");
	int a, b;

	cout << "Enter the number you want to change: ";
	cin >> a; 
	cout << "Enter the digit to prepend to the number on the left: ";
	cin >> b;
	cout << endl;

	leftDig(a, b);

	cout << "Changed number: " << a;
	return 0;
}
//*/

void leftDig(int& numb, int cf) {

	int sign{ numb < 0 ? -1 : numb > 0 ? 1 : 0 };

	numb = abs(numb);

	int i;
	for (i = 1; i*10 <= numb; i *= 10);

	if (sign)
		numb = sign * (numb + cf * (i * 10));
	else numb = cf*10;

}