#include <iostream>
#include "funcs.h"
#include <fstream>

using namespace std;

int main() {

	//cout << check_cond(const_cast<char*>("-123AA")) << endl;
	//cout << check_cond(const_cast<char*>("123AA")) << endl;
	//cout << check_cond(const_cast<char*>("123AA-")) << endl;
	//cout << check_cond(const_cast<char*>("123G")) << endl;
	//cout << check_cond(const_cast<char*>("123f")) << endl;

	//num_two_digit("test2.txt");

	char* filename = const_cast<char*>("test3.txt");
	toFile(filename);
	echoFile(filename);

	fstream fin(filename, ios::in | ios::out | ios::binary);
	int size;
	Student* good_student = get_passed_student(fin, size);

	cout << endl;
	for (int i = 0; i < size; i++) {
		cout << good_student[i].Name << endl;
	}


	change_score(fin, 1002);
	
	fin.close();
	echoFile(filename);
	cout << endl;


	delete good_student;
	return 0;
}