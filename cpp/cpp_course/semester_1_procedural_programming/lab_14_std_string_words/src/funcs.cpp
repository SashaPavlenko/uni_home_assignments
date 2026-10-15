#include <iostream>
#include <string>
#include "funcs.h"
#include <sstream>
#include <iterator>
#include <algorithm>

using namespace std;

int count_symb(string s, char c) {
	int count{ 0 };

	for (int i = 0; i < s.length(); ++i)
		if (s[i] == c)
			count++;
	
	return count;
}

int count_words(string s){
	int index{ static_cast<int>(s.find("  ")) };
	while (index != -1) {
		s.replace(index, 2, " ");
		index = s.find("  ");
	}

	int count{ count_symb(s, *" ") };
	
	if (s.length() > 0) {
		if (s[0] == *" ")
			count--;
		if (s[s.length()-1] != *" " && s.length()>0)
			count++;
	}

	return count;
}

void del_symb(string& s, char symb) {
	int index{ static_cast<int>(s.find(symb)) };
	while (index != -1) {
		s.replace(index, 1, "");

		index = s.find(symb, index);
	}
}

string insert_substr_after_symb(string s, string substr, char symb) {
	size_t index_symb{ s.find(symb) };
	
	if (index_symb != -1)
		s = s.substr(0, index_symb+1) + substr + s.substr(index_symb+1);

	return s;
}

void replace_even(string& str, string substr) {
	stringstream stream(str);
	size_t counter = 1;
	int index{ -1 };
	for_each(istream_iterator<string>(stream), istream_iterator<string>(),
		[&](auto word) {
			auto pos = str.find(word, index + 1);
			if (pos != string::npos && ++counter % 2) {
				str.replace(pos, word.length(), substr);
			}
			index = pos;
		});
}
