#include "ATS.h"
#include <tuple>
#include <iostream>
#include "func.h"

void ATS::set_numbers(string n1, string n2)
{
	this->numbers[0] = n1;
	this->numbers[1] = n2;
}

// void ATS::set_values(const val_month& mass[])
void ATS::set_values(const val_month* mass)
{
	this->last_3_month[0].num_city = mass[0].num_city;
	this->last_3_month[1].num_city = mass[1].num_city;
	this->last_3_month[2].num_city = mass[2].num_city;

	this->last_3_month[0].num_iternal = mass[0].num_iternal;
	this->last_3_month[1].num_iternal = mass[1].num_iternal;
	this->last_3_month[2].num_iternal = mass[2].num_iternal;
}

void ATS::swap(ATS& obj)
{
	std::swap(this->department, obj.department);
	std::swap(this->numbers, obj.numbers);
	std::swap(this->last_3_month, obj.last_3_month);
	
	//for (int i = 0; i < 2; ++i) {
	//	std::swap(this->numbers[i], obj.numbers[i]);
	//}

	//for (int i = 0; i < 3; ++i) {
	//	std::swap(this->last_3_month[i].num_city, obj.last_3_month[i].num_city);
	//	std::swap(this->last_3_month[i].num_iternal, obj.last_3_month[i].num_iternal);
	//}
}

ATS::ATS()
{
	this->department = "EmptyATS";

	this->numbers[0] = "2222222";
	this->numbers[1] = "88005553535";

	val_month t1{ 0, 0 };
	this->last_3_month[0] = t1;
	this->last_3_month[1] = t1;
	this->last_3_month[2] = t1;
}

ATS::ATS(string _name, string _phone1, string _phone2, val_month values[])
{
	if (is_numeric(_phone1) != true || is_numeric(_phone1) != true) {
		throw "IncorrectPhone";
	}

	if (values[0].num_city < 0 || values[1].num_city < 0 || values[2].num_city < 0
		|| values[0].num_iternal < 0 || values[1].num_iternal < 0 || values[2].num_iternal < 0) {
		throw "IncorrectValues";
	}

	this->department = _name;

	set_numbers(_phone1, _phone2);

	this->last_3_month[0] = values[0];
	this->last_3_month[1] = values[1];
	this->last_3_month[2] = values[2];
}

ATS::ATS(const ATS& obj)
{
	this->department = obj.department;
	this->set_numbers(obj.numbers[0], obj.numbers[1]);
	this->set_values(obj.last_3_month);
}

// std::tuple<string, string[2]> ATS::get()
std::tuple<string, string, string> ATS::get()
{
	//string s[2] = { this->numbers[0], this->numbers[1] };
	return std::make_tuple(this->department, this->numbers[0], this->numbers[1]);
}

void ATS::set(string name, string _phone1, string _phone2)
{
	this->department = name;
	set_numbers(_phone1, _phone2);
	val_month t{ 0, 0 };
	val_month tt[3] = { t, t, t };
	this->set_values(tt);
}

ATS::~ATS()
{
}

int ATS::summarize_minutes() const
{
	int sum{ 0 };
	for (int i = 0; i < 3; ++i) {
		sum += this->last_3_month[i].num_city;
		sum += this->last_3_month[i].num_iternal;
	}

	return sum;
}

bool ATS::check_limit_city()
{
	int index{ 0 };
	while (index < 3 && this->last_3_month[index].num_city <= 300) {
		index++;
	}

	return index == 3;
}

ATS& ATS::operator=(ATS obj)
{
	this->swap(obj);
	return *this;
}

bool ATS::operator==(const ATS& obj)
{
	bool flag{ this->department == obj.department };

	int index{ 0 };
	while (index < 2 && flag) {
		flag = this->numbers[index] == obj.numbers[index];
		index++;
	}

	index = 0;
	while (index < 3 && flag) {
		flag = this->last_3_month[index].num_city == obj.last_3_month[index].num_city;
		flag = this->last_3_month[index].num_iternal == obj.last_3_month[index].num_iternal;
		index++;
	}

	return flag;
}

std::istream& operator>>(std::istream& in, ATS& obj)
{
	in >> obj.department;
	in >> obj.numbers[0];
	in >> obj.last_3_month[0].num_city >> obj.last_3_month[1].num_city >> obj.last_3_month[2].num_city;

	in >> obj.numbers[1];
	in >> obj.last_3_month[0].num_iternal >> obj.last_3_month[1].num_iternal >> obj.last_3_month[2].num_iternal;

	return in;
}

std::ostream& operator<<(std::ostream& out, const ATS& obj)
{
	
	out << "Name department: " << obj.department << std::endl;
	out << "City number: " << obj.numbers[0] << "\nLast 3 month: " << obj.last_3_month[0].num_city \
		<< " " << obj.last_3_month[1].num_city << " " << obj.last_3_month[2].num_city << std::endl;
	out << "Iternal numbers: " << obj.numbers[1] << "\nLast 3 month: " << obj.last_3_month[0].num_iternal \
		<< " " << obj.last_3_month[1].num_iternal << " " << obj.last_3_month[2].num_iternal << std::endl;
	return out;
}
