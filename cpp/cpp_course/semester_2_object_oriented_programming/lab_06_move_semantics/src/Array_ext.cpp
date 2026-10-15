// Changes and additions to the Array class to implement the move mechanism

//Changing the destructor
//Destructor
#include "Array_ext.h"
#include <iostream>

using namespace std;

Array::~Array() {
	if (values != nullptr){
	  delete[] values;
	  cout << "Array deleted!" << endl;
	}
}

//move constructor
Array::Array(Array&& other)noexcept{
	n = other.n;
	values = other.values;
	other.values = nullptr;	// Prevents the destructor from deleting the array that was moved to another object right away

	cout << "Used MOVE copy" << endl;
}

//move assignment operator

Array Array::operator+(const Array& arr)
{
	if (this->values == nullptr) {
		throw "UndefinedArray";
	}

	if (arr.values == nullptr) {
		throw "UndefinedArray";
	}

	Array new_arr;
	new_arr.n = this->n + arr.n;
	new_arr.values = new int[new_arr.n];

	for (int i = 0; i < this->n; ++i) {
		new_arr.values[i] = this->values[i];
	}

	for (int i = this->n; i < this->n + arr.n; ++i) {
		new_arr.values[i] = arr.values[i - this->n];
	}

	return new_arr;
}

Array& Array::operator= (Array&& arr) noexcept{
	//if (this != &arr) { - self-assignment cannot happen here
	if (values != nullptr)	
		delete[] values;
	n = arr.n;
	values = arr.values;
	arr.values = nullptr;	// Prevents the destructor from deleting the array that was moved to another object right away

	cout << "Used MOVE =" << endl;
	return *this;
}

Array& Array::operator=(const Array& arr)
{
	Array arr1(arr);
	this->swap(arr1);

	cout << "Used = " << endl;
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Array& arr)
{
	out << "size: " << arr.n << std::endl;

	if (arr.n != 0) {
		out << "{";
		for (int i = 0; i < arr.n - 1; ++i) {
			out << arr.values[i] << "; ";
		}
		out << arr.values[arr.n - 1] << "}" << std::endl;
	}
	else {
		out << "Array: {}" << std::endl;
	}

	return out;
}

std::istream& operator>>(std::istream& in, Array& arr)
{

	in >> arr.n;

	if (arr.values != nullptr) {
		delete[] arr.values;
	}

	// If arr.n == 0, we change nothing in arr.values, because it is nullptr already?
	if (arr.n != 0) {
		arr.values = new int[arr.n];
		for (int i = 0; i < arr.n; ++i) {
			in >> arr.values[i];
		}
	}
	/*else
	{
		arr.values = nullptr;
	}*/

	return in;
}

void Array::swap(Array& other)
{
	std::swap(this->n, other.n);
	std::swap(this->values, other.values);
}