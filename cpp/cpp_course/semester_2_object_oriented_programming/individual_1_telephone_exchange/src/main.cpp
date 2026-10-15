#include <iostream>
#include "ATS.h"
#include <fstream>
#include <sstream>
#include "func.h"
#include <stdlib.h>
//#include <algorithm>

using namespace std;

int main() {
	
	setlocale(LC_ALL, "rus");

	ATS* list_ATS = new ATS[8];
	int num{ 8 };
	set_ATS(list_ATS, "data.txt");

	for (int i = 0; i < num; ++i) {
		cout << list_ATS[i].summarize_minutes() << " ";
	}
	cout << endl;

	qsort(list_ATS, num, sizeof(ATS), compareMyType);

	cout << "List of departments sorted by descending total minutes spent on calls:\n";

	for (int i = 0; i < num; ++i) {
		cout << list_ATS[i] << endl;
	}

	cout << "List of departments that exceeded the local call limit:\n";
	for (int i = 0; i < num; ++i) {
		if (!list_ATS[i].check_limit_city()) {
			cout << list_ATS[i] << endl;
		}
	}

	return 0;
}