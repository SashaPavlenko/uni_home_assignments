#include <iostream>
#include "funcs.h"

using namespace std;

int main() {

	char str1[Max_Length] = "abcbccd";
	char str2[Max_Length] = " f ";

	//while (*str2)
	//{
	//	cout << 1;
	//	str++;
	//}
	//cout << word_count(str1);
	//cout << str_cmp(str2, " ");
	cout << word_count("   f  f f");
	
	char str[Max_Length] = "caaaa";

	char check_str[Max_Length] = "aaaa";

	remove_chr(str, 'c');

	cout << endl << str;

	return 0;
}