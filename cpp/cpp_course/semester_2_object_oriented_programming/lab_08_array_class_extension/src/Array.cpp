#include "Array.h"
#include <iostream>

void Array::swap(Array& other)
{
	std::swap(this->n, other.n);
	std::swap(this->values, other.values);
}

int Array::length() const
{
	return this->n;
}

int Array::find(int val)
{
	int i{ 0 }, len{ this->length() };
	while (i < len && this->values[i] != val) {
		i++;
	}

	return i != len ? i : -1;
}

void Array::upsize(int size_plus)
{
	if (size_plus == -1) {
		size_plus = this->n;
	}
	else if (size_plus <= 0) {
		throw "IncorrectSize";
	}

	int* new_arr = new int[this->n + size_plus];
	for (int i = 0; i < this->n; ++i) {
		new_arr[i] = this->values[i];
	}

	for (int i = this->n; i < this->n + size_plus; ++i) {
		new_arr[i] = 0;
	}

	delete[] this->values;
	this->values = new_arr;
	this->n = this->n + size_plus;
}

void Array::downsize(int size_minus)
{
	if (size_minus == -1) {
		size_minus = this->n / 2;
	}
	else if (size_minus <= 0 || size_minus > this->n) {
		throw "IncorrectSize";
	}

	if (size_minus == this->n) {
		delete[] this->values;
		this->values = nullptr;
		this->n = 0;
	}
	else {
		int* new_arr = new int[this->n - size_minus];
		for (int i = 0; i < this->n - size_minus; ++i) {
			new_arr[i] = this->values[i];
		}
		delete[] this->values;
		this->values = new_arr;
		this->n = this->n - size_minus;
	}
}

void Array::insert(int index, int elem)
{
	this->upsize(1);
	for (int i = this->length() - 1; i > index; --i) {
		this->values[i] = this->values[i - 1];
	}
	this->values[index] = elem;
}

void Array::rinsert(int elem)
{
	this->upsize(1);
	this->values[this->n - 1] = elem;
}

void Array::pop(int index)
{
	for (int i = index; i < this->n - 1; ++i) {
		this->values[i] = this->values[i + 1];
	}
	this->downsize(1);
}

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

Array Array::operator+=(const Array& arr)
{
	if (this->values == nullptr && arr.values == nullptr) {
		throw "UndefinedArray";
	}

	*this = *this + arr;
	return *this;
}

Array Array::operator+(const int x)
{
	if (this->values == nullptr) {
		throw "UndefinedArray";
	}

	Array arr_copy(*this);
	for (int i = 0; i < arr_copy.n; ++i) {
		arr_copy.values[i] += x;
	}

	return arr_copy;
}

bool Array::operator==(const Array& arr)
{
	if (this->n != arr.n) {
		return false;
	}
	else {
		int i{ 0 };
		while (i < this->n && this->values[i] == arr[i]) {
			i++;
		}
		return i == this->n;
	}
}

Array& Array::operator=(Array arr)
{
	this->swap(arr);
	//arr.~Array();
	return *this;
}

int& Array::operator[](int i)
{
	return this->values[i];
}

int Array::operator[](int i) const
{
	return this->values[i];
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
