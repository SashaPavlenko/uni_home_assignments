#pragma once
#include "Sign.h"
#include <string>
#include "funcs.h"

class Prescrib_sign :
    public Sign
{
private:
    double prob_violate;
    double amount_of_fine;
public:
    // Constructors.
    Prescrib_sign(std::string nm = "Empty prescribing sign", double fine = 1000.);
    virtual ~Prescrib_sign();

    // Methods.
    virtual bool is_violated() override;
    virtual std::string mess() override;

    // Getters and setters.
    double get_fine();
    type_sign get_type() override;
};

