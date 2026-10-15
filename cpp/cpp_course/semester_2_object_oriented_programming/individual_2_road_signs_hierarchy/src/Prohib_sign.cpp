#include "Prohib_sign.h"
#include "funcs.h"

Prohib_sign::Prohib_sign(std::string nm) : prob_deprovation_license{ rand_double() } {
	this->name = nm;
	this->probality = rand_double();
	type_s = type_sign::prohibition;
}

Prohib_sign::~Prohib_sign() { }

bool Prohib_sign::is_violated()
{
	return probality < prob_deprovation_license;
}

std::string Prohib_sign::mess()
{
	std::string s;
	if (this->is_violated()) {
		s = "A violation that leads to the loss of the driving license was detected";
	}
	else {
		s = "No violations that lead to the loss of the driving license were found";
	}

	s += "\nViolation probability: " + std::to_string(probality) + "\nPenalty probability: "\
		+ std::to_string(prob_deprovation_license);
	s += "\n";

	return s;
}

type_sign Prohib_sign::get_type()
{
	return this->type_s;
}
