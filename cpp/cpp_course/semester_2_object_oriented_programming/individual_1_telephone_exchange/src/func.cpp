#include <string>
#include <fstream>
#include <sstream>
#include "ATS.h"
#include "func.h"

bool is_numeric(const std::string& s) {

	bool flag{ s.length() == 1 && (s[0] == '0' && s[0] <= '9') && s.length() > 1 && (s[0] >= '0'
		&& s[0] <= '9' || s[0] == '-' || s[0] == '+') };

	int index{ 1 };
	while (index < s.length() && s[0] >= '0' && s[0] <= '9') {
		index++;
	}

	flag = index == s.length();
	return flag;
}

std::string readFile(const std::string& fileName) {
	std::ifstream f(fileName);
	std::stringstream ss;
	ss << f.rdbuf();
	return ss.str();
}

void set_ATS(ATS arr[], string filename) {
	string str, subs;
	str = readFile(filename);
	int index{ 0 }, pos{ 0 }, i{ 0 };

	while (index != -1)
	{
		pos = str.find('*', pos) + 1;
		subs = str.substr(pos + 1, str.find('*', pos) - pos - 2);

		std::stringstream stream(subs);
		stream >> arr[i++];

		index = str.find('*', pos);
	}

}

int compareMyType(const void* a, const void* b) 
{
	ATS* aa = (ATS*)a;
	ATS* bb = (ATS*)b;

	if (aa->summarize_minutes() < bb->summarize_minutes()) return -1;
	if (aa->summarize_minutes() == bb->summarize_minutes()) return 0;
	if (aa->summarize_minutes() > bb->summarize_minutes()) return 1;
}