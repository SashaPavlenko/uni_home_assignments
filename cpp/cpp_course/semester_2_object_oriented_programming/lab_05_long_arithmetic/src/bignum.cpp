#include "bignum.h"
#include <iostream>
#include <string>
#include "funcs.h"
#include <tuple>

std::ostream& operator<<(std::ostream& out, const bignum& num)
{
	if (num.msign == sign::negative) {
		out << '-';
	}

	int* f = num.digits->get_values();
	for (int i = num.digits->length() - 1; i >= 0; --i) {
		out << f[i];
	}

	return out;
}

std::istream& operator>>(std::istream& in, bignum& num)
{
	std::string s;
	in >> s;

	int* a;
	int size;
	sign znak;

	std::tie(a, size, znak) = convert_number(s);
	
	num.~bignum();
	num.digits = new Array(a, size);
	num.msign = znak;

	return in;
}

bignum abs(const bignum& num)
{
	bignum n_copy(num);
	if (n_copy.msign == sign::negative) {
		n_copy.msign = sign::positive;
	}

	return n_copy;
}

void eq_dims(bignum& num1, bignum& num2)
{
	if (num1.length() != num2.length()) {
		if (num1.length() < num2.length()) {
			num1.up_num_rank(num2.length() - num1.length());
		}
		else {
			num2.up_num_rank(num1.length() - num2.length());
		}
	}
}

bignum dot_10(const bignum& num)
{
	bignum n_copy(num);
	n_copy.up_num_rank();

	for (int i = n_copy.length() - 1; i > 0; i--) {
		n_copy[i] = n_copy[i - 1];
	}

	n_copy[0] = 0;
	return n_copy;
}

bignum factorial(const bignum& num)
{
	if (num.msign == sign::negative)
	{
		throw "IncorrectData";
	}

	bignum count(1), i(1);
	for (i; i <= num; i += 1) {
		//std::cout << count << " " << i << std::endl;
		count *= i;
	}
	return count;
}

std::tuple<int*, int, sign> convert_number(int n) 
{
	int* a, size{ 0 }, index{ 0 };
	sign znak;

	if (n == 0) {
		size = 1;
		a = new int[1]{ 0 };
		znak = sign::zero;
	}
	else {
		znak = n > 0 ? sign::positive : sign::negative;

		int nn{ abs(n) };

		while (nn > 0) {
			size++;
			nn /= 10;
		}

		a = new int[size];
		nn = abs(n);
		while (index < size) {
			a[index++] = nn % 10;
			nn /= 10;
		}
	}

	return std::make_tuple(a, size, znak);
	//return std::tuple<int*, int, sign>(a, size, znak);
}

std::tuple<int*, int, sign> convert_number(std::string s)
{
	if (!is_numeric(s)) {
		//throw std::invalid_argument;
		throw "IncorrectData";
	}

	int index = 0, size{ static_cast<int>(s.length()) };
	sign znak;

	if (s[0] == '0' || ((s[0] == '-' || s[0] == '+') && s[1] == '0')) {
		size = 1;
		if (s[0] != '0') {
			index++;
		}
		znak = sign::zero;
	}
	else {
		if (s[0] == '-') {
			znak = sign::negative;
			index++;
		}
		else if (s[0] == '+') {
			znak = sign::positive;
			index++;
		}
		else if (s[0] >= '0' && s[0] <= '9') {
			znak = sign::positive;
		}
		size = static_cast<int>(s.length() - index);
	}

	int iter{ 0 };
	int* a = new int[size];
	for (int i = s.length() - 1; i >= index; --i, ++iter) {
		a[iter] = symb_to_int(s[i]);
	}

	return std::make_tuple(a, size, znak);
}

void bignum::swap(bignum& other)
{
	std::swap(this->digits, other.digits);
	std::swap(this->msign, other.msign);
}

void bignum::up_num_rank(int n)
{
	if (n < 0) {
		throw "IncorrectData";
	}

	if (n != 0) {
		this->digits->upsize(n);
	}
}

void bignum::down_num_rank(int n)
{
	if (n < 0) {
		throw "IncorrectData";
	}

	if (n != 0) {
		this->digits->downsize(n);
	}
}

void bignum::reverse_values()
{
	int* c = this->digits->get_values();
	for (int i = 0; i < this->length(); ++i) {
		c[i] = -c[i];
	}
}

void bignum::correcting_values()
{
	//std::cout << *this;
	int* c = this->digits->get_values();
	for (int i = 0; i < this->length() - 1; ++i) {
		if (c[i] >= 10) {
			c[i] -= 10;
			c[i + 1] += 1;
		}
		else if (c[i] < 0) {
			c[i] += 10;
			c[i + 1] = c[i+1] + -1 ;
		}
		//std::cout << c[i] << std::endl;
	}

	//std::cout << c[this->length() - 1];

	if (c[this->length() - 1] >= 10) {
		this->up_num_rank();
		c = this->digits->get_values();
		c[this->length() - 1] = 1;
		c[this->length() - 2] -= 10;
	}
	else if (c[this->length() - 1] == 0) {
		int index{ this->length() - 1 };
		while (c[index] >= 0 && c[index] == 0) {
			index--;
		}
		this->down_num_rank(this->length() - index - 1);
	}
	else if (c[this->length() - 1] < 0) {
		c[this->length() - 1] = -c[this->length() - 1];
	}
}

int bignum::length() const
{
	return this->digits->length();
}

sign bignum::get_sign() const
{
	return this->msign;
}

bignum::operator int()
{
	if (*this > MAXINT || *this < MININT) {
		throw "TooLargeNumber";
	}

	int num{ 0 }, count{ 1 };
	int* c = this->digits->get_values();
	for (int i = 0; i < this->length() ; ++i, count *= 10) { 
		num += c[i] * count;
	}

	if (this->msign == sign::negative) {
		num = -num;
	}

	return num;
}

bignum::operator std::string()
{
	std::string s = "";

	if (this->msign == sign::negative) {
		s += "-";
	}

	int* c = this->digits->get_values();
	for (int i = this->length() - 1; i >= 0; --i) {
		s += int__to_symb(c[i]);
	}

	return s;
}

bignum& bignum::operator=(bignum other)
{
	this->swap(other);
	return *this;
}

int& bignum::operator[](int i)
{
	int* A = this->digits->get_values();
	return A[i];
}

int bignum::operator[](int i) const
{
	int* A = this->digits->get_values();
	return A[i];
}

bool bignum::operator==(const bignum& other)
{
	bool flag = this->msign == other.msign;
	flag = flag && this->length() == other.length();

	if (flag == true) {
		int* A = this->digits->get_values();
		int* B = other.digits->get_values();

		int index{ 0 };
		bignum& c = *this;
		while (index < this->length() && c[index] == other[index]) {
			index++;
		}
		flag = index == this->length();
	}

	return flag;
}

bool bignum::operator!=(const bignum& other)
{
	return !(*this == other);
}

bool bignum::operator>(const bignum& other) const 
{
	bool flag;

	if (this->length() == other.length()) {
		if (this->msign == sign::zero || other.msign == sign::zero) {
			if (this->msign != sign::zero && other.msign == sign::zero) {
				flag = this->msign == sign::positive ? true : false;
			}
			else {
				if (this->msign == sign::zero) {
					flag = other.msign == sign::negative ? true : false;
				}
				else {
					flag = this->msign == sign::negative ? false : true;
				}
			}
		}
		else {
			if (this->msign == sign::negative && other.msign == sign::positive) {
				flag = false;
			}
			else if (this->msign == sign::positive && other.msign == sign::negative) {
				flag = true;
			}
			else {

				int* A = this->digits->get_values();
				int* B = other.digits->get_values();

				int index{ this->length() - 1 };
				int* c = this->digits->get_values();
				while (index >= 0 && c[index] == other[index]) {
					index--;
				}

				if (this->msign == sign::positive) {
					flag = (index != -1 && (c[index] > other[index]));
				}
				else {
					flag = (index != -1 && (c[index] < other[index]));
				}
			}
		}
	}
	else {
		if (this->length() > other.length()) {
			// It cannot be 0, because the length of this > the length of other, and the length of other > 1, otherwise it would not be a number.
			flag = this->msign == sign::positive;
		}
		else {
			flag = (this->msign == sign::negative && other.msign == sign::negative) 
				|| (this->msign == sign::zero && other.msign == sign::negative) 
				|| (this->msign == sign::positive && (other.msign == sign::negative || other.msign == sign::zero));
		}
	}

	return flag;
}

bool bignum::operator<=(const bignum& other)
{
	return !(*this > other);
}

bool bignum::operator<(const bignum& other)
{
	return !(*this > other) && (*this != other);
}

bool bignum::operator>=(const bignum& other)
{
	return (*this > other) || (*this == other);
}

bignum bignum::operator-()
{
	bignum n_copy(*this);
	if (n_copy.msign == sign::positive) {
		//std::cout << 1;
		n_copy.msign = sign::negative;
	} 
	else if (n_copy.msign == sign::negative) {
		//std::cout << 2;
		n_copy.msign = sign::positive;
	}

	return n_copy;
}

bignum bignum::GCM(bignum b)
{
	bignum t;
	bignum a(*this);
	while (b.msign != sign::zero) {
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

bool bignum::is_primary()
{
	bignum i(2), end(*this / bignum(2) + bignum(1)), one(1);
	while (i < end && this->GCM(i) == one) {
		i += 1;
	}

	return i == end;
}

bignum bignum::operator+(const bignum& other) {
	sign znak;
	const bignum zero;

	if (abs(*this) == abs(other) 
		&& (this->msign != other.msign || this->msign == sign::zero && other.msign == sign::zero))
	{
		bignum m_copy;
		return m_copy;
	}
	else if ((*this >= other && other > zero) || (*this <= other && *this > zero) || 
		(abs(*this) < abs(other) && other > zero) || (abs(other) < abs(*this) && *this > zero) || 
		(this->msign == sign::zero && other.msign == sign::positive) || 
		(other.msign == sign::zero && this->msign == sign::positive)) {
		znak = sign::positive;
	}
	else {
		znak = sign::negative;
	}

	bignum m_left(*this);
	bignum m_right(other);

	if (abs(m_left) < abs(m_right)) {
		m_left.swap(m_right);
	}

	bool rev{ false };
	if (m_left.msign != m_right.msign) {
		if (m_left.msign == sign::negative) {
			m_right.reverse_values();
		}
		else if (m_right.msign == sign::negative) {
			m_right.reverse_values();
		}
	}
	else if (m_left.msign == sign::negative) {
		rev = true;
		m_left.reverse_values();
		m_right.reverse_values();
	}

	for (int i = 0; i < m_right.length(); ++i) {
		m_left[i] += m_right[i];
	}

	if (rev == true) {
		m_left.reverse_values();
		m_left.correcting_values();
	}
	else {
		m_left.correcting_values();
	}
	
	m_left.msign = znak;

	return m_left;
}

/*
bignum bignum::operator+(const bignum& other)
{
	int next{ 0 };
	bignum n_sum;

	if ((this->msign == sign::positive && other.msign == sign::positive)
		|| (this->msign == sign::negative && other.msign == sign::negative)) {

		n_sum = *this;
		bignum other_pl(other);
		eq_dims(n_sum, other_pl);

		for (int i = 0; i < n_sum.length(); ++i) {
			int d = n_sum[i];
			n_sum[i] = (n_sum[i] + other_pl[i] + next) % 10;
			next = (d + other_pl[i] + next) / 10;
		}

		if (next > 0) {
			n_sum.up_num_rank();
			n_sum[n_sum.length() - 1] = next;
		}

		int count{ 0 }, index{ n_sum.length() - 1 };
		while (index > 0 && n_sum[index] == 0) {
			index--;
			count++;
		}
		n_sum.down_num_rank(count);
	}
	else if (this->msign == sign::zero || other.msign == sign::zero) {
		if (this->msign == sign::zero) {
			n_sum = other;
		}
		else {
			n_sum = *this;
		}
	}
	else {
		bignum& num_more{ *this }, num_less{ other };
		if (abs(num_more) < abs(num_less)) {
			//num_more = *this;
			//num_less = other;
			num_more.swap(num_less);
		}
		sign znak = num_more.msign == sign::positive ? sign::positive : sign::negative;

		eq_dims(num_more, num_less);
		n_sum = num_more;
		int d;
		int diff_s;

		//std::cout << num_more << " " << num_less << std::endl;
		for (int i = 0; i < n_sum.length()-1; ++i) {
			d = n_sum[i];

			diff_s = d - num_less[i] - next;
			diff(diff_s, next);

			n_sum[i] = diff_s;
		}
		d = n_sum[n_sum.length() - 1];
		diff_s = d - num_less[n_sum.length()-1] - next;
		next = diff_s != 0 ? 1 : 0;

		n_sum[n_sum.length() - 1] = n_sum[n_sum.length() - 1] - num_less[n_sum.length() - 1];

		//std::cout << n_sum << std::endl;

		int count{ 0 }, index{ n_sum.length() - 1};

		while (index > 0 && n_sum[index] == 0) {
			index--;
			count++;
		}
		n_sum.down_num_rank(count);

		if (n_sum.length() == 1 && n_sum[0] == 0) {
			n_sum.msign = sign::zero;
		}
		else {
			n_sum.msign = znak;
		}
	}

	return n_sum;
}
*/

bignum bignum::operator-(const bignum& other)
{
	bignum n_copy(*this);
	n_copy = -(-n_copy + other);

	return n_copy;
}

bignum bignum::operator*(int n)
{
	//bignum n_copy(*this);

	int next{ 0 };
	bignum n_sum;

	if (this->msign == sign::zero || n == 0) {
		n_sum = bignum();
	}
	else {
		/*int count{ 0 }, index{ n_sum.length() - 1 };
		while (index > 0 && n_sum[index] == 0) {
			index--;
			count++;
		}
		n_sum.down_num_rank(count);*/

		n_sum = *this;

		for (int i = 0; i < n_sum.length(); ++i) {
			int d = n_sum[i];
			n_sum[i] = (n_sum[i] * n + next) % 10;
			next = (d * n + next) / 10;
		}

		if (next > 0) {
			n_sum.up_num_rank();
			n_sum[n_sum.length() - 1] = next;
		}

		sign znak;
		if (this->msign == sign::positive && n > 0 ||
		this->msign == sign::negative && n < 0) {
			znak = sign::positive;
		} 
		else {
			znak = sign::negative;
		}

		n_sum.msign = znak;
	}
	

	return n_sum;
}

bignum bignum::operator*(const bignum& other)
{
	sign znak;

	if (this->msign == sign::zero || other.msign == sign::zero) {
		bignum m_copy;
		return m_copy;
	}
	else if (this->msign == sign::positive && other.msign == sign::positive ||
		this->msign == sign::negative && other.msign == sign::negative) {
		znak = sign::positive;
	}
	else {
		znak = sign::negative;
	}

	bignum m_copy(*this), i(1), other_abs(abs(other));
	for (i; i < other_abs; i += 1) {
		m_copy += *this;
	}



	m_copy.msign = znak;
	return m_copy;
}

bignum bignum::operator/(const bignum& other)
{
	if (other.msign == sign::zero) {
		throw "DivisionByZero";
	}

	sign znak;

	if (this->msign == sign::zero || other.msign == sign::zero) {
		bignum m_copy;
		return m_copy;
	}
	else if (this->msign == sign::positive && other.msign == sign::positive ||
		this->msign == sign::negative && other.msign == sign::negative) {
		znak = sign::positive;
	}
	else {
		znak = sign::negative;
	}

	bignum m_copy, i(abs(*this)), other_abs(abs(other)), zero;
	while ((i - other_abs) >= zero) {
		//std::cout << i << std::endl << other_abs << std::endl << (i - other_abs) << std::endl << std::endl;
		m_copy += 1;
		i = i - other_abs;
	}

	if (m_copy.msign == sign::zero) {
		znak = sign::zero;
	}
		m_copy.msign = znak;

	return m_copy;
}

bignum bignum::operator%(const bignum& other)
{
	bignum del(*this / other * other);
	bignum m_copy(*this - del);
	return m_copy;
}

bignum& bignum::operator+=(const bignum& other)
{
	*this = *this + other;
	return *this;
}

bignum bignum::operator-=(const bignum& other)
{
	*this = *this - other;
	return *this;
}

bignum bignum::operator*=(const bignum& other)
{
	*this = *this * other;
	return *this;
}

bignum bignum::operator/=(const bignum& other)
{
	*this = *this / other;
	return *this;
}
