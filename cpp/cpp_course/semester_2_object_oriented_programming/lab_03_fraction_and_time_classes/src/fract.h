#pragma once
#include <iostream>

class Fract {
private:
	int numen, denom;
	//int NOK(const Fract& other) const;
	void simplify();

public:
	Fract() : numen(0), denom(1) {}
	Fract(int a, int b = 1) :numen(a) {
		denom = (b != 0) ? b : 1;

		this->simplify();
	}

	void print();

	Fract operator+(const Fract& other);
	Fract operator-(const Fract& other);
	Fract operator*(const Fract& other);
	Fract operator/(const Fract& other);
	Fract operator+=(const Fract& other);
	Fract operator-=(const Fract& other);
	Fract operator*=(const Fract& other);
	Fract operator/=(const Fract& other);
	Fract operator++(); // ++f
	Fract operator++(int);
	Fract operator--(); // --f
	Fract operator--(int);

	bool operator>(const Fract& other);
	bool operator<(const Fract& other);
	bool operator>=(const Fract& other);
	bool operator<=(const Fract& other);
	bool operator==(const Fract& other);
	bool operator!=(const Fract& other);

	friend std::ostream& operator<<(std::ostream& os, const Fract& fr);
	friend std::istream& operator>>(std::istream& os, Fract& fr);
};
