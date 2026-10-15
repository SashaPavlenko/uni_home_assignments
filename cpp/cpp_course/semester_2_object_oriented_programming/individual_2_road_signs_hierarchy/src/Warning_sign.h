#pragma once
#include "Sign.h"
#include <string>
#include "funcs.h"

class Warning_sign:
	public Sign
{
private:
	double prob_road_accident;
public:
	// Constructors.
	Warning_sign(std::string nm = "Empty warning sign");
    virtual ~Warning_sign();


    // Methods.
    virtual bool is_violated() override;
    virtual std::string mess() override;

    // Getters and setters.
    virtual type_sign get_type() override;
};

