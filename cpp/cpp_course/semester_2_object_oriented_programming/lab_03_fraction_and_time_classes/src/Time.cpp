#include "Time.h"
#include <iostream>

void Time::correcting()
{
	while (sec / 60 != 0) {
		min++;
		sec -= 60;
	}

	while (min / 60 != 0) {
		hour++;
		min -= 60;
	}
}

std::ostream& operator<<(std::ostream& os, const Time& t)
{
	//os << t.hour << ":" << t.min << ":" << t.sec;
	os << "H(" << t.hour << "):M(" << t.min << "):S(" << t.sec << ")";
	return os;
}

std::istream& operator>>(std::istream& os, Time& tt)
{
	os >> tt.hour >> tt.min >> tt.sec;

	tt.correcting();

	return os;
}

Time Time::operator+(const Time& other)
{	
	return Time(this->sec + other.sec, this->min + other.min, this->hour + other.hour);
}

Time Time::operator-(const Time& other)
{
	int new_sec{ this->sec - other.sec }, new_min{ this->min - other.min }, new_hour{ this->hour - other.hour };

	if (new_sec < 0) {
		new_sec += 60;
		new_min--;
	}
	if (new_min < 0) {
		new_min += 60;
		new_hour--;
	}
	if (new_hour < 0) {
		new_hour = 0;
		new_min = 0;
		new_sec = 0;
	}

	return Time(new_sec, new_min, new_hour);
}

Time Time::operator+=(const Time& other)
{
	*this = (*this + other);
	this->correcting();

	//this->hour += other.hour;
	//this->min += other.min;
	//this->sec += other.sec;

	this->correcting();

	return *this;
}

Time Time::operator-=(const Time& other)
{
	*this = *this - other;
	this->correcting();

	/*int new_sec{ this->sec - other.sec }, new_min{ this->min - other.min }, new_hour{ this->hour - other.hour };

	if (new_sec < 0) {
		new_sec += 60;
		new_min--;
	}
	if (new_min < 0) {
		new_min += 60;
		new_hour--;
	}
	if (new_hour < 0) {
		new_hour = 0;
		new_min = 0;
		new_sec = 0;
	}

	this->hour = new_hour;
	this->min = new_min;
	this->sec = new_sec;*/

	return *this;
}

Time Time::operator++()
{	
	this->sec += 1;
	this->correcting();

	return *this;
}

Time Time::operator++(int)
{
	Time tt(*this);
	this->sec += 1;

	this->correcting();
	tt.correcting();

	return tt;
}

Time Time::operator--()
{
	this->sec -= 1;
	this->correcting();

	return *this;
}

Time Time::operator--(int)
{
	Time tt(*this);
	this->sec -= 1;

	this->correcting();
	tt.correcting();

	return tt;
}

bool Time::operator>(const Time& other)
{
	return (this->hour > other.hour && this->min > other.min && this->sec > other.sec);
}

bool Time::operator<(const Time& other)
{
	return (this->hour < other.hour && this->min < other.min && this->sec < other.sec);
}

bool Time::operator>=(const Time& other)
{
	return (this->hour >= other.hour && this->min >= other.min && this->sec >= other.sec);
}

bool Time::operator<=(const Time& other)
{
	return (this->hour <= other.hour && this->min <= other.min && this->sec <= other.sec);
}

bool Time::operator==(const Time& other)
{
	return (this->hour == other.hour && this->min == other.min && this->sec == other.sec);
}

bool Time::operator!=(const Time& other)
{
	return !(*this == other);
}
