#pragma once
#include <string>
#include <tuple>
using std::string;

struct val_month{
	int num_city;
	int num_iternal;
};

class ATS
{
private:
	string department;
	string numbers[2];
	val_month last_3_month[3];

	void set_numbers(string n1, string n2);
	void set_values(const val_month* mass);
	void swap(ATS& obj);
public:
	// constructors
	ATS();
	ATS(string _name, string _phone1, string _phone2, val_month values[]);
	ATS(const ATS& obj);

	// destructor
	~ATS();

	// getter and setter
	std::tuple<string, string, string> get();
	void set(string name, string _phone1, string _phone2);

	// methods
	int summarize_minutes() const;
	bool check_limit_city();

	// operators
	ATS& operator=(ATS obj);	
	bool operator==(const ATS& obj);

	// cout & cin
	friend std::istream& operator >> (std::istream& in, ATS& obj);
	friend std::ostream& operator << (std::ostream& out, const ATS& obj);
};

