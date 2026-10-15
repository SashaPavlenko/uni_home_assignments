#include <iostream>
#include <string>
#include "func.h"

using namespace std;

int main() {
	
	toFile(const_cast<char*>("test_3.txt"));
	//toFile("test_3.txt");
	swap_ftol("test_3.txt");
	print_bin_file("test_3.txt");
	return 0;
}