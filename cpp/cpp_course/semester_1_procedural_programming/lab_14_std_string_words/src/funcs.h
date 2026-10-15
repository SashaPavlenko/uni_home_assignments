#pragma once
#include <string>
//#include <iostream>

using namespace std;

// A string consisting of words separated by one or more spaces is given. Count the number of words in the string.
int count_words(string s);

// Remove all occurrences of a given character from the string.
void del_symb(string& s, char symb);

// Inserts a string into another string after the first occurrence of a given character.
string insert_substr_after_symb(string s, string substr, char symb);

// A string consisting of words separated by one or more spaces is given. Replace every even word in the string with a given one.
void replace_even(string& str, string substr);