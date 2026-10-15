#include <iostream>
#include "funcs.h"
#include <string>
#include <fstream>
#include <map>
#include <sstream>
#include <iterator>

using namespace std;

void count_num_letters(string filename) {
	ifstream f(filename);
	string str;

	map <char, int> mp;

	while (!f.eof()) {
		getline(f, str);

		for(char i : str)
		{
			if (mp.find(i) != mp.end()) {
				mp[i]++;
			}
			else {
				mp[i] = 1;
			}
		}
	}

	for (char i = 'a', j = 'A'; i <= 'z'; i++, j++) {
		if (mp.find(i) != mp.end()) {
			cout << "Character " << i << " occurred " << mp[i] << " times." << endl;
		}

		if (mp.find(j) != mp.end()) {
			cout << "Character " << j << " occurred " << mp[j] << " times." << endl;
		}
	}

	f.close();
}

string biggiest_line(string filename) {
	ifstream f(filename);

	string str, str_max = "";

	while (!f.eof())
	{
		getline(f, str);

		if (str_max == "" || str.length() > str_max.length()) {
			str_max = str;
		}
	}

	f.close();

	return str_max;
}

int num_of_words(string filename) {
	ifstream f(filename);
	int count{ 0 };
	string str;

	while (!f.eof())
	{
		getline(f, str);
		stringstream stream(str);
		count += distance(istream_iterator<string>(stream), istream_iterator<string>());	
	}

	f.close();
	return count;
}

void del_words(string filename, string word) {
	ifstream f(filename);
	string str, fstr{ "" };


	while (!f.eof()) {
		getline(f, str);
		string::size_type pos = str.find(word);

		while (pos != std::string::npos) {
			if (pos == 0 || pos + word.size() == str.size()) {
				if (pos == 0 && str[pos + word.size()] == ' ') {
					str.erase(pos, word.size());
				}

				if (pos + word.size() == str.size() && str[pos - 1] == ' ') {
					str.erase(pos, word.size());
				}

				pos = str.find(word, pos + 1);
				//pos++;

			}
			else {
				if (pos != str.size() && str[pos - 1] == ' ' && str[pos + word.size()] == ' ') {
					str.erase(pos, word.size());
				}
				pos = str.find(word, pos + 1);
			}
		}

		if (str == "\n" || str == "") {
			fstr += str;
		}
		else {
			fstr += str + "\n";
		}
	}


	f.close();
	ofstream fwriter(filename);
	fwriter << fstr;
	fwriter.close();
}

void rep_word_to_num(string filename, string word) {
	ifstream f(filename);
	string str;
	string fstr = "";
	int order = 1;

	while (!f.eof()) {
		getline(f, str);
		string::size_type pos = str.find(word);

		while (pos != string::npos) {

			if (pos == 0 || pos + word.size() == str.size()) {
				if (pos == 0 && str[pos + word.size()] == ' ') {
					str.replace(pos, word.size(), to_string(order));
					order++;
				}
				if (pos + word.size() == str.size() && str[pos - 1] == ' ') {
					str.replace(pos, word.size(), to_string(order));
					order++;
				}
				pos = str.find(word, pos + 1);
				//pos++;

			}
			else {
				if (pos != str.size() && str[pos - 1] == ' ' && str[pos + word.size()] == ' ') {
					str.replace(pos, word.size(), to_string(order));
					order++;
				}
				pos = str.find(word, pos + 1);

			}

		}

		if (str == "\n" || str == "") {
			fstr += str;
		}
		else {
			fstr += str + "\n";
		}
	}

	f.close();
	ofstream fwriter(filename, ios::out | ios::trunc);
	fwriter << fstr;
	fwriter.close();
}