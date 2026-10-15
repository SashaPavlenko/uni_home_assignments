#pragma once

const int Max_Length = 256;

// String comparison function.
// Input parameters:
//     str1 - the beginning of the first string;    str2 - the beginning of the second string.
// Return value:
//      0 - the strings are equal;
//     >0 - the first differing character of string 1 > that of string 2;
//     <0 - the first differing character of string 1 < that of string 2.
int str_cmp(const char* str1, const char* str2);

// Function that counts the words in a string.
// Input parameters:
//     str - the beginning of the string.
// Return value:
//     the number of sequences of non-whitespace characters separated by spaces.
int word_count(const char* str);

// Removing all occurrences of a given character from a string.
// Input parameters:
//     str - the beginning of the string;    c - the character to remove.
// Result:
//     str does not contain occurrences of the character c.
void remove_chr(char* str, char c);

// Inserting a given substring into a string, 
// after the first occurrence of a given character.
// Input parameters:
//     str - the beginning of the source string;     substr - the string to insert;     c - the character to search for.
// Result:
//     str contains substr after the first occurrence of c.
//     If the insertion is not possible, throws a char* exception.
void insert_str(char* str, const char* substr, char c);