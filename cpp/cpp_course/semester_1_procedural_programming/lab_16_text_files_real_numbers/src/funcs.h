#pragma once
#include <string>

using namespace std;

// 1. A text file containing a sequence of real numbers is given. 
// The number of values in the file is not known in advance. Find the value with the smallest absolute value in the file.
double find_min_abs(string filename);

// 2. A text file containing lines of real numbers is given. 
// The number of values in each line may differ. Compute the minimum and the maximum in each line. Write the result to a file.
void find_min_max_in_rows(string filename);

bool is_equal_text(const char* filename1, const char* filename2);
