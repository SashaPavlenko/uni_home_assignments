#pragma once
#include <iostream>
#include "funcs.h"
#include <string>
#include <fstream>
#include <map>

using namespace std;

// 1. A text file consisting of lines is given. Count how many times each letter of the Latin alphabet occurs in the file.
void count_num_letters(string filename);

// 2. A text file consisting of lines is given. Print the longest line in the file.
string biggiest_line(string filename);

// 3. A text file containing lines of words is given. Words in a line are separated by spaces. Count the number of words in the file.
int num_of_words(string filename);

// 4. A text file containing lines of words is given. Words in a line are separated by spaces. Remove a given word from the file.
void del_words(string filename, string word);

// 5. A text file containing lines of words is given. Words in a line are separated by spaces. Replace all occurrences of a given word in the source file with the occurrence number (1, 2, 3, etc.)
void rep_word_to_num(string filename, string word);
