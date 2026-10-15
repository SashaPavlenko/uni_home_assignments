#include <iostream>
#include "funcs.h"
#include "List.h"
#include <sstream>
#include <string>

#ifdef _DEBUG
#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC
#endif

#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)

using namespace std;

int main() {

	_CrtMemState _ms;
	_CrtMemCheckpoint(&_ms);

	List my_list;

	cout << my_list.isEmpty() << endl;

	cin >> my_list;

	cout << my_list << endl;

	auto it = my_list.begin();
	//++it;
	//++it;
	//++it;
	//++it;
	//++it;

	my_list.setIter(it, 10000);
	cout << my_list << endl;

	it = begin(my_list);
	try
	{
		my_list.delIt(it);

	}
	catch (const std::exception& s)
	{
		cout << s.what() << endl;
	}
	cout << my_list << endl;

	my_list.~List();
	//std::string s = "5\n1 2 3 4 5";
	//std::stringstream stream(s);
	//List a;
	//stream >> a;

	//auto it = a.begin();
	//++it;
	//++it;
	//++it;
	//++it;
	////a.delIt(it);
	//a.delLast();

	//stream.clear();
	//stream << a;
	//std:string s_out_test1 = stream.str();
	////cout << s_out_test1;

	//std::string s_check = "first --> 5 --> 4 --> 2 --> 1 --> last\n";

	_CrtMemDumpAllObjectsSince(&_ms);
	return 0;
}