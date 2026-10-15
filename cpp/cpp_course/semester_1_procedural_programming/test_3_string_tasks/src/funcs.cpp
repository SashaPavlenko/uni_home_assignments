#include <iostream>
#include <string>
#include "funcs.h"
#include <sstream>
#include <iterator>
#include <algorithm>


using namespace std;

void del_symbs(char* s, char symb) {

	//while

}

void remove_chr(char* str, char symb) {
	char* begin_str = str;
	char symbs[3];

	while (*(str) != symb)
		str++;

	if (*str) {
		// Áóäåì ïðè êàæäîé âñòðå÷å ñ ñèìâîëîì c áóäåì ñäâèãàòü âñå îñòàëüíûå ýëåìåíòû íà index_miss, à ñàìó ïåðåìåííóþ èíêðåìèðîâàòü.

		int index_miss{ 0 };

		if (str == begin_str && *(str + 1) && *(str + 1) == symb && *(str+2))
		{
			index_miss++;
			str += 2;

			*(str) = *(str + index_miss);
			str++;
		}

		while (*(str) && *(str + index_miss) && *((str + 1) + index_miss))
		{
			if (*(str + index_miss) == symb && *(str + 1 + index_miss) == symb) {
				*(str) = *(str++ + index_miss);
				*(str) = *(str++ + index_miss++);

				if (*(str) && *(str + index_miss)) {
					*(str) = *(str++ + index_miss);
				}
			}
			else {
				*(str) = *(str++ + index_miss);
			}
		}

		if (*(str) && *(str + index_miss)) {
			if (*(str + index_miss)) {
				*(str) = *(str++ + index_miss);
			}
			*str = '\0';
		}
		else {
			//*(str - 1) = '\0';
			*(str) = '\0';
		}
	}
}

void insert_word(string& str, string substr, char symb) {
	stringstream stream(str);
	size_t counter = 1;
	int index{ -1 };
	for_each(istream_iterator<string>(stream), istream_iterator<string>(),
		[&](auto word) {
			auto pos = str.find(word, index + 1);
			if (pos != string::npos && word[0] == symb) {
				str.replace(pos, word.length(), substr + word, 0, word.length() + substr.length());
			}
			index = pos;
		});

}

