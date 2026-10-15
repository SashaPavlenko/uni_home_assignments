#include <iostream>
#include "funcs.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	del_words("tratata.txt", "123");
	return 0;
}