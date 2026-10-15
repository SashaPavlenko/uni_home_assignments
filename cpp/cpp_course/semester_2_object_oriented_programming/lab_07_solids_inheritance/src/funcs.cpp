#include <fstream>
#include <sstream>
#include <string>
#include "funcs.h"

std::string readFile(const std::string& fileName) {
	std::ifstream f(fileName);
	std::stringstream ss;
	ss << f.rdbuf();
	return ss.str();
}

std::tuple<int, int> getRH(const std::string& subs, int k)
{
	int r, h;

	unsigned int ppos{ subs.find(" ") };
	std::string num1 = subs.substr(ppos + 1, subs.find(" ", ppos + 1) - ppos - 1);
	r = atoi(num1.c_str());
	if (k == 2) {
		num1 = subs.substr(subs.find(" ", ppos + 1) + 1);
		h = atoi(num1.c_str());
	}
	else {
		h = 0;
	}

	return std::tuple<int, int>(r, h);
}
