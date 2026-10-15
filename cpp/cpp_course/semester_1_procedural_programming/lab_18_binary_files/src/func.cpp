#include <iostream>
#include <string>
#include <fstream>
#include "func.h"

using namespace std;

int t = sizeof(double);

void toFile(char* nameF) {
	ofstream fout(nameF, ios::out | ios::binary);
	if (!fout.is_open()) {
		cerr << "Can't open " << nameF << "\n";
		exit(1);
	}
	double val;
	cout << "Enter value: ";
	while (cin >> val) {
		fout.write(reinterpret_cast <char*>(&val), t);
		cout << "Enter value (press any letter to stop): ";
	}
	fout.close();
}

void swap_ftol(string filename)
{
	ifstream f(filename, ios::binary);
	double first;

	f.read((char*)&first, sizeof first);
	f.seekg(-(int)(sizeof first), ios::end);

	double last;
	f.read((char*)&last, sizeof last);
	f.close();

	fstream fin;

	fin.open(filename, ios::in | ios::out | ios::binary);
	fin.write(reinterpret_cast<char*>(&last), sizeof last);
	fin.seekp(-(int)(sizeof first), ios::end);
	fin.write(reinterpret_cast<char*>(&first), sizeof first);
	fin.close();
}

void print_bin_file(std::string nameF) {
	std::ifstream fin(nameF, std::ios::in | std::ios::binary);
	double a;
	while (fin.read(reinterpret_cast<char*>(&a), sizeof a)) {
		std::cout << a << " ";
	}
	fin.close();
}