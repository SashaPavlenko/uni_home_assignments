#pragma once
#include <iostream>
//#include "Sign.h"
#include <string>

enum class type_sign
{
	prescribing,
	prohibition,
	warning,
	error_type,
};

inline double rand_double() {

	return static_cast <double> (rand()) / static_cast <double> (RAND_MAX);
};

std::string type_to_string(type_sign t, std::string lan = "rus");