#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main() {
	copy(istream_iterator<char>(cin), istream_iterator<char>(), ostream_iterator<char>(cout, ","));


	return 0;
}