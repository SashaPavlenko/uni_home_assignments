#include "Prescrib_sign.h"
#include "Error_sign.h"
#include "funcs.h"

Prescrib_sign::Prescrib_sign(std::string nm, double fine) : amount_of_fine{ fine }, prob_violate{ rand_double() } {
	if (fine < 0) {
		throw Error_sign("Incorrect fine");
	}

	this->name = nm;
	this->probality = rand_double();
	type_s = type_sign::prescribing;
}

Prescrib_sign::~Prescrib_sign() { }

bool Prescrib_sign::is_violated()
{
	return probality < prob_violate;
}

std::string Prescrib_sign::mess()
{
	std::string s;
	if (this->is_violated()) {
		s = "You have been fined in the amount of: " + std::to_string(amount_of_fine);
	}
	else {
		s = "There are no violations";
	}

	s += "\nViolation probability: " + std::to_string(probality) + "\nFine probability: " + std::to_string(prob_violate);
	s += "\n";

	return s;
}

double Prescrib_sign::get_fine()
{
	return this->amount_of_fine;
}

type_sign Prescrib_sign::get_type()
{
	return this->type_s;
}
