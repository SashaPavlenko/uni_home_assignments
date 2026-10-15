#pragma once
#include <iostream>

class Time
{
private:
	int sec, min, hour;
	void correcting();
public:
	Time() : sec(0), min(0), hour(0) {}
	Time(int sec_ent, int min_ent, int hour_ent) : sec(sec_ent), min(min_ent), hour(hour_ent) {
		if (sec_ent < 0 || min_ent < 0 || hour_ent < 0) {
			throw "incorrect data";
		}

		this->correcting();
	}

	Time operator+(const Time& other);
	Time operator-(const Time& other);
	Time operator+=(const Time& other);
	Time operator-=(const Time& other);
	Time operator++(); // ++f
	Time operator++(int);
	Time operator--(); // --f
	Time operator--(int);

	bool operator>(const Time& other);
	bool operator<(const Time& other);
	bool operator>=(const Time& other);
	bool operator<=(const Time& other);
	bool operator==(const Time& other);
	bool operator!=(const Time& other);

	friend std::ostream& operator<<(std::ostream& os, const Time& t);
	friend std::istream& operator>>(std::istream& os, Time& tt);

};

