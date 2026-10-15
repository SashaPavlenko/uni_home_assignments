#pragma once
#include <iostream>

using namespace std;

// 1. Check whether a string is a valid representation of a positive integer in hexadecimal notation.
bool check_cond(char* str);

// 2. A text file is given. For each line in the file, determine the number of two-digit numbers in that line. Change the file so that
// the number of values was written at the beginning of each line.
void num_two_digit(string filename);


// 3. Structures. Processing binary files.
struct Student{
	char Name[256];
	int num_rec_book;
	int score[3];
};

inline void end_of_line() { cin.ignore(1, '\n'); }

// Function that creates a binary file storing information about N students.
void toFile(char* nameF);

// Function that prints a file.
void echoFile(char* nameF);

// Data processing function.
Student* get_passed_student(fstream& f, int& count);

// Function that modifies the file.
void change_score(fstream& f, int num_book);