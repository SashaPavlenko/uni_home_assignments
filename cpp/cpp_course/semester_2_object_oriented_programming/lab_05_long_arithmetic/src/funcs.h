#pragma once
#include <string>

enum class sign
{
	positive,
	zero,
	negative,
};

bool is_numeric(std::string s);

int symb_to_int(char s);
char int__to_symb(int num);

void diff(int& num, int& next);