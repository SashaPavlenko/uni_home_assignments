#include <iostream>
#include "fract.h"
#include <string>

//unsigned int greatest_common_divisor(unsigned int a, unsigned int b) {
//	if (a % b == 0)
//		return b;
//	if (b % a == 0)
//		return a;
//	if (a > b)
//		return greatest_common_divisor(a % b, b);
//	return greatest_common_divisor(a, b % a);
//}
//
//int Fract::NOK(const Fract& other) const
//{
//	int a{ this->numen }, b{ other.numen };
//	return (a * b) / greatest_common_divisor(a, b);
//}

void Fract::simplify()
{
	if (this->denom == this->numen) {
		this->denom = 1;
		this->numen = 1;
	}

	for (int i = 2; i <= std::round(std::sqrt(this->denom)); ++i) {
		while (this->denom % i == 0 && this->numen % i == 0) {
			this->denom /= i;
			this->numen /= i;
		}
	}
}

void Fract::print()
{
	int mmax{ std::max(std::abs(this->numen), std::abs(this->denom)) };
	mmax = (std::to_string(mmax).length());
	std::string s = "-";
	
	for (int i = 0; i < mmax; ++i) {
		s = s + "-";
	}


	std::cout << this->numen << std::endl;
	std::cout << s << std::endl;
	std::cout << this->denom << std::endl << std::endl;
}

Fract Fract::operator+(const Fract& other) {
	Fract temp;
	temp.denom = this->denom * other.denom;
	temp.numen = this->denom * other.numen + other.denom * this->numen;

	temp.simplify();

	return temp;
}

Fract Fract::operator-(const Fract& other)
{
	Fract temp;
	temp.denom = this->denom * other.denom;
	temp.numen = this->denom * other.numen - other.denom * this->numen;

	temp.simplify();
	
	return temp;
}

Fract Fract::operator*(const Fract& other)
{
	Fract temp;
	temp.numen = this->numen * other.numen;
	temp.denom = this->denom * other.denom;

	temp.simplify();

	return temp;
}

Fract Fract::operator/(const Fract& other)
{
	Fract ff{ *this * Fract(other.denom, other.numen) };
	
	ff.simplify();

	return ff;
}

Fract Fract::operator+=(const Fract& other)
{
	*this = *this + other;
	
	this->simplify();

	return *this;
}

Fract Fract::operator-=(const Fract& other)
{
	*this = *this - other;

	this->simplify();

	return *this;
}

Fract Fract::operator*=(const Fract& other)
{
	*this = *this * other;

	this->simplify();

	return *this;
}

Fract Fract::operator/=(const Fract& other)
{
	*this = *this / other;

	this->simplify();

	return *this;
}

Fract Fract::operator++()
{
	this->numen += this->denom;

	this->simplify();

	return *this;
}

Fract Fract::operator++(int)
{
	Fract z(*this);
	this->numen += this->denom;

	z.simplify();
	this->simplify();


	return z;
}

Fract Fract::operator--()
{
	this->numen -= this->denom;

	this->simplify();

	return *this;
}

Fract Fract::operator--(int)
{
	Fract z(*this);
	this->numen += this->denom;

	z.simplify();
	this->simplify();


	return z;
}

bool Fract::operator>(const Fract& other)
{	
	int a{ this->numen }, b{ other.numen };
	if (this->denom != other.denom) {
		a *= other.denom;
		b *= this->denom;
	}

	return a > b;
}

bool Fract::operator<(const Fract& other)
{
	int a{ this->numen }, b{ other.numen };
	if (this->denom != other.denom) {
		a *= other.denom;
		b *= this->denom;
	}

	return a < b;
}

bool Fract::operator>=(const Fract& other)
{
	int a{ this->numen }, b{ other.numen };
	if (this->denom != other.denom) {
		a *= other.denom;
		b *= this->denom;
	}

	return a >= b;
}

bool Fract::operator<=(const Fract& other)
{
	int a{ this->numen }, b{ other.numen };
	if (this->denom != other.denom) {
		a *= other.denom;
		b *= this->denom;
	}

	return a <= b;
}

bool Fract::operator==(const Fract& other)
{
	int a{ this->numen }, b{ other.numen };
	if (this->denom != other.denom) {
		a *= other.denom;
		b *= this->denom;
	}

	return a == b;
}

bool Fract::operator!=(const Fract& other)
{
	int a{ this->numen }, b{ other.numen };
	if (this->denom != other.denom) {
		a *= other.denom;
		b *= this->denom;
	}

	return a != b;
}

std::ostream& operator << (std::ostream& os, const Fract& fr) {
	os << fr.numen << " / " << fr.denom;
	return os;
}

std::istream& operator>>(std::istream& os, Fract& fr)
{
	os >>  fr.numen >> fr.denom;
	fr.simplify();
	return os;

}
