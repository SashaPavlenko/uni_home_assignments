#include "Warning_sign.h"
#include "funcs.h"

Warning_sign::Warning_sign(std::string nm) : prob_road_accident { rand_double() } {
	this->name = nm;
	this->probality = rand_double();
	type_s = type_sign::warning;
}

Warning_sign::~Warning_sign() {}

bool Warning_sign::is_violated()
{
	return probality < prob_road_accident;
}

std::string Warning_sign::mess()
{
	std::string s;
	if (this->is_violated()) {
		s = "An accident occurred!";
	}
	else {
		s = "No accident occurred";
	}

	s += "\nViolation probability: " + std::to_string(probality) + "\nAccident probability: " + std::to_string(prob_road_accident);
	s += "\n";

	return s;
}

type_sign Warning_sign::get_type()
{
	return this->type_s;
}
