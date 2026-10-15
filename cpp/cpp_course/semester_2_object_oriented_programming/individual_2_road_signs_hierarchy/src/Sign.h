#pragma once
//#include "stdafx.h"
#include <string>
#include "funcs.h"

//enum class type_sign
//{
//	prescribing,
//	prohibition,
//	warning,
//	error_type,
//};

class Sign
{
protected:
	std::string name;
	type_sign type_s;
	double probality;
public:
	//Sign(std::string nm = "Empty sign");
	virtual ~Sign() {};
	
	virtual bool is_violated() = 0;
	virtual type_sign get_type() = 0;
	virtual std::string mess() = 0;
};
