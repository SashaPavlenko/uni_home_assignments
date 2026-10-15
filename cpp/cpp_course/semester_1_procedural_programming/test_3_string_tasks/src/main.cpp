#include <iostream>
#include <string>
#include "funcs.h"

using namespace std;

int main() {

	char str[] = "1122334455";
	char str_check[] = "1122334455";
	char symb = '5';

	remove_chr(str, symb);

	cout << str; 

	/*string str = "11 22 33 44 5";
	string substr = "hello";
	string str_check = "11 22 33 hello44 5";
	char symb = '4';


	insert_word(str, substr, symb);

	cout << endl << str ;*/

	return 0;
}