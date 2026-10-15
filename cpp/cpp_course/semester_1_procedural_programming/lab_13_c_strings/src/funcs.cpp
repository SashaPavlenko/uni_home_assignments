#include <iostream>
#include "funcs.h"

using namespace std;

int str_cmp(const char* str1, const char* str2) {
	
	while (*str1 && *str2 && *str1 == *str2) {
		str1++;
		str2++;
	}

	int cmp_res;
		
	if (!*str1 && !*str2)
		cmp_res = 0;
	else
		if (!*str2 || *str1 > *str2)
			cmp_res = 1;
		else
			cmp_res = -1;

	return cmp_res;
}

int word_count(const char* str) {
	
	while (*str == *" " && *str) {
		str++;
	}

	int count{ 0 };

	if (*str) {
		count++;
		while (*str) {
			if (*str == *" " && *(str + 1) != *" " && *(str + 1))
				count++;
			str++;
		}
	}

	return count;
}

void remove_chr(char* str, char c) {
	char* begin_str = str;
	
	while (*(str) != c)
		str++;

	if (*str) {
		// Every time we meet the character c, we shift all the other elements by index_miss and increment that variable.
		
		int index_miss{ 0 };
		
		if (str == begin_str)
		{
			index_miss++;
			*str = *(str + index_miss);
			str++;
		}
		
		while (*str && *(str + index_miss))
		{
			if (*(str + index_miss) == c) {
				index_miss++;
				while (*(str + index_miss) == c)
					index_miss++;
			}
			*str = *(str + index_miss);
			str++;
		}
		*str = '\0';
	}
}

void insert_str(char* str, const char* substr, char c) {
	while (*str != c)
		str++;

	// Exception: the string str does not contain the character c.
	// Error code: 1.
	if (!*str)
		throw "Incorrect data";

	// Find out the size of the string to insert.
	const char* begin_substr = substr;
	int size_sub{ 0 };
	
	while (*substr) {
		size_sub++;
		substr++;
	}

	if (size_sub == 0)
		return;
	substr = begin_substr;

	// Go to the end of the string, increase its size by size_sub, copy s[i] = s[i-size_sub], 
	// between the first occurrence and the last copy, insert the substr.
	begin_substr = str;
	
	while (*str)
		str++;
	for (int i = 0; i < size_sub; ++i)
		str++;
	*(str + 1) = '\0';

	while ((str - size_sub) != begin_substr) {
		*str = *(str - size_sub);
		str--;
	}

	str = const_cast<char*>(begin_substr + 1);
	while (*substr) {
		*str = *substr;
		str++;
		substr++;
	}

}