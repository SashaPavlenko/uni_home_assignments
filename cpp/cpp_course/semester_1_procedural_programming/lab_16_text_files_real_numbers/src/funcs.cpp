#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include "funcs.h"

using namespace std;

double find_min_abs(string filename) {
	ifstream f(filename);
	double mmin{ DBL_MAX };
	string str;

	while (!f.eof()) {
		getline(f, str);
		stringstream stream(str);

		for_each(istream_iterator<string>(stream), istream_iterator<string>(), [&](auto digit) {
			
			double now{ atof(digit.c_str()) };
			if (abs(now) < abs(mmin)) {
				mmin = now;
			}

		});
	}

	f.close();
	return mmin;
}

void find_min_max_in_rows(string filename) {
	ifstream f(filename);
	double mmin, mmax;
	string str, fstr{ "" };
	int count{ 1 };

	while (!f.eof()) {
		mmin = DBL_MAX; mmax= -DBL_MAX;

		getline(f, str);
		stringstream stream(str);

		for_each(istream_iterator<string>(stream), istream_iterator<string>(), [&](auto digit) {

			double now{ atof(digit.c_str()) };
			if (now < mmin) {
				mmin = now;
			}
			if (now > mmax) {
				mmax = now;
			}

			});

		fstr += to_string(count++) + ": " + "min = " + to_string(mmin) + "; " + "max = " + to_string(mmax)+ ".\n";
	}

	f.close();
	ofstream fwriter("tests/test_2_out.txt", ios::out | ios::trunc);
	fwriter << fstr;
	fwriter.close();
}