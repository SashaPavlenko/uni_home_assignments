#include <string>
#include "funcs.h"

bool is_numeric(std::string s) {
	if (s.length() == 0 || (s.length() == 1 && (s[0] < '0' || s[0] > '9')) || (s.length() > 1 && (s[1] < '0' || s[1] > '9'))) {
		return false;
	}
	
	int index{ 0 };

	if (index < s.length() && (s[index] == '-' || s[index] == '+' || (s[index] >= '0' && s[index] < '9'))) {
		index++;
	}

	while (index < s.length() && s[index] >= '0' && s[index] < '9') {
		index++;
	}

	return index == s.length();
}

int symb_to_int(char s)
{
	if (s < '0' && s > '9') {
		throw "IncorrectData";
	}

	int a;

	switch (s)
	{
	case '0': a = 0; break;
	case '1': a = 1; break;
	case '2': a = 2; break;
	case '3': a = 3; break;
	case '4': a = 4; break;
	case '5': a = 5; break;
	case '6': a = 6; break;
	case '7': a = 7; break;
	case '8': a = 8; break;
	case '9': a = 9; break;
	}

	return a;
}

char int__to_symb(int num)
{
	if (num < 0 && num > 9) {
		throw "IncorrectData";
	}

	int a;

	switch (num)
	{
	case 0: a = '0'; break;
	case 1: a = '1'; break;
	case 2: a = '2'; break;
	case 3: a = '3'; break;
	case 4: a = '4'; break;
	case 5: a = '5'; break;
	case 6: a = '6'; break;
	case 7: a = '7'; break;
	case 8: a = '8'; break;
	case 9: a = '9'; break;
	}

	return a;
}

void diff(int& num, int& next) {
	next = num < 0 ? 1 : 0;
	num = num < 0 ? num + 10 : num;
}