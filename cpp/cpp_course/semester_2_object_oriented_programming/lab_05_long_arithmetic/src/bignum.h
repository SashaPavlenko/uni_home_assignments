#pragma once
#include "Array.h"
#include "funcs.h"
#include <iostream>
#include <string>
#include <tuple>
#include <stdexcept>

std::tuple<int*, int, sign> convert_number(int n);
std::tuple<int*, int, sign> convert_number(std::string s);

class bignum
{
private:
	Array* digits;
	sign msign;

	void swap(bignum& other);
	void up_num_rank(int n = 1);
	void down_num_rank(int n = 1);
	
	void reverse_values();
	void correcting_values();
public:
	// Constructors and destructor.
	bignum() : msign{ sign::zero } {
		digits = new Array(1);
	};
	bignum(int n) {
		int* a, size;
		sign ssign;

		std::tie(a, size, ssign) = convert_number(n);
		
		this->digits = new Array(a, size);
		this->msign = ssign;
	};
	bignum(std::string s) 
	{
		int* a;
		int size;
		sign znak;

		std::tie(a, size, znak) = convert_number(s);

		this->digits = new Array(a, size);
		this->msign = znak;
	}
	bignum(const bignum& other) {
		this->msign = other.msign;

		int* A = other.digits->get_values(), size{ other.digits->length() };
		this->digits = new Array(A, size);
	}
	~bignum() {
		digits->~Array();
	};

	// Access methods.
	int length() const;
	sign get_sign() const;

	// Conversion to base types.
	operator int();
	operator std::string();

	// Assignment operator overload.
	bignum& operator = (bignum other);

	// Indexing operator overload.
	int& operator [] (int i);
	int operator [] (int i) const;

	// Comparison operator overloads.
	bool operator == (const bignum& other);
	bool operator != (const bignum& other);
	bool operator > (const bignum& other) const;
	bool operator <= (const bignum& other);
	bool operator < (const bignum& other);
	bool operator >= (const bignum& other);

	// Input/output operator overloads.
	friend std::ostream& operator << (std::ostream& out, const bignum& num);
	friend std::istream& operator >> (std::istream& in, bignum& num);

	// Arithmetic operator overloads.
	bignum operator + (const bignum& other);
	bignum operator - (const bignum& other);
	bignum operator * (int n);
	bignum operator * (const bignum& other);
	bignum operator / (const bignum& other);
	bignum operator % (const bignum& other);
	bignum& operator += (const bignum& other);
	bignum operator -= (const bignum& other);
	bignum operator *= (const bignum& other);
	bignum operator /= (const bignum& other);
	bignum operator -();
	bignum operator ++();
	bignum operator ++(int);
	bignum operator --();
	bignum operator --(int);

	// Methods.
	friend bignum abs(const bignum& num);
	friend void eq_dims(bignum& num1, bignum& num2);
	friend bignum dot_10(const bignum& num);
	bignum GCM(bignum b);
	bool is_primary();
	friend bignum factorial(const bignum& num);
};

const bignum MAXINT(INT_MAX), MININT(-2147483647);
