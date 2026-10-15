#include <iostream>
#include "funcs.h"
#include <string>

using namespace std;

int main() {

	string s = "    a  f f   f    f  b";
	string s1 = "";

	cout << count_words(s1) << endl;

	cout << count_words(s);
	cout << endl << s;
	del_symb(s, *" ");
	cout << endl << s;

	s = "123456789";

	cout << endl << insert_substr_after_symb(s, "111", *"2");

	string substr, s_check;

	s = "12 12 12 12 12";
	substr = "ff";
	s_check = "12 ff 12 ff 12";
	replace_even(s, substr);

	cout << endl << s;
	return 0;
}