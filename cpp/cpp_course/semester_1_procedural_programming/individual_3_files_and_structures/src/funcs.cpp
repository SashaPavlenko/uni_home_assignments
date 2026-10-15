#include <iostream>
#include "funcs.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <iomanip>

using namespace std;

bool char_in_str(char symb, char* str) {
	bool flag{ false };

	while (*str && !flag) {
		flag = (*str == symb);
		str++;
	}

	return flag;
}

bool check_cond(char* str) {
	bool flag ;

	char* str_alph = const_cast<char*>("0123456789ABCDEF");

	flag = *str == *"-" || char_in_str(*str, str_alph);
	str++;

	while (*str && flag) {
		flag = char_in_str(*str++, str_alph);
	}

	return flag;
}

void num_two_digit(string filename) {
	ifstream Fread(filename);

	if (!Fread.is_open()) {
		cerr << "Can't open " << filename<< "\n";
		return;
	}

	int count;
	string str, fstr{ "" };

	while (!Fread.eof()) {
		count = 0;

		getline(Fread, str);

		stringstream stream(str);

		for_each(istream_iterator<string>(stream), istream_iterator<string>(), [&](auto number) {
			double now{ atof(number.c_str()) };
			if (9 < now && now < 100) {
				count++;
			}
		});

		fstr += to_string(count) + " two-digit numbers in the line: " + str + "\n";
	}

	Fread.close();

	ofstream Fwriter(filename, ios::out | ios::trunc);
	Fwriter << fstr;
	Fwriter.close();
}

void toFile(char* nameF) {
	Student p;
	ofstream fout(nameF, ios::app | ios::binary);

	if (!fout.is_open()) {
		cerr << "Can't open " << nameF << "\n";
		exit(1);
	}

	cout << "Enter name: \n";
	cin.get(p.Name, 20);
	while (p.Name[0] != '\0') {
		end_of_line();
		cout << "Enter number of record-book: ";
		cin >> p.num_rec_book;
		cout << "Enter the first subject score: ";
		cin >> p.score[0];
		cout << "Enter the second subject score: ";
		cin >> p.score[1];
		cout << "Enter the third subject score: ";
		cin >> p.score[2];
		fout.write(reinterpret_cast <char*>(&p), sizeof p);
		end_of_line();

		cout << "Enter name (blank line to quit) \n";
		cin.get(p.Name, 20);
	}
	fout.close();
}

void echoFile(char* nameF) {
	Student p;
	ifstream fin(nameF, ios::in | ios::binary);
	if (fin.is_open()) {
		while (fin.read(reinterpret_cast <char*>(&p), sizeof p)) {
			cout << setw(20) << p.Name<< " : "
				<< setw(10) << p.num_rec_book 
				<< setw(5) << p.score[0] 
				<< setw(5) << p.score[1] 
				<< setw(5) << p.score[2] 
				<< "\n";
		}
	}
	fin.close();
}

Student* get_passed_student(fstream& f, int& count) {
	streampos posg = f.tellg();
	f.seekg(0, ios_base::beg);

	Student p;
	Student* good_students = new Student[1000];
	count = 0;

	f.read(reinterpret_cast<char*>(&p), sizeof p);
	while (!f.eof()) {
		if (p.score[0] >= 60 && p.score[1] >= 60 && p.score[2] >= 60) {
			good_students[count++] = p;
		}
		f.read(reinterpret_cast<char*>(&p), sizeof p);
	}

	f.clear();
	f.seekg(posg, ios_base::beg);
	
	return good_students;
}

void change_score(fstream& f, int num_book) {
	Student p;

	streampos posg = f.tellg();
	streampos posPrev = f.tellg();

	while (f.read(reinterpret_cast<char*>(&p), sizeof p) &&	p.num_rec_book != num_book)
	{
		//f.seekg(posPrev, ios_base::beg);
		//f.read(reinterpret_cast<char*>(&p), sizeof p);
		streampos posPrev = f.tellg();
	}

	//f.close();

	int a, b, c;
	
	cout << "Rewrite the first subject score: ";
	cin.clear();
	cin >> a;

	cout << "Rewrite the second subject score: ";
	cin.clear();
	cin >> b;
	
	cout << "Rewrite the third subject score: ";
	cin.clear();
	cin >> c;

	//fstream f(filename)
	
	p.score[0] = a;
	p.score[1] = b;
	p.score[2] = c;

	f.seekg(posPrev, ios_base::beg);
	f.write(reinterpret_cast<char*>(&p), sizeof p);
	
	f.clear();
	f.seekg(posg, ios_base::beg);
		
}