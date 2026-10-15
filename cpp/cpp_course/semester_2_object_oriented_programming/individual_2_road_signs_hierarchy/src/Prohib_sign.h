#pragma once
#include "Sign.h"
#include <string>
#include "funcs.h"

class Prohib_sign :
    public Sign
{
private:
    double prob_deprovation_license;
public:
    // Constructors.
    Prohib_sign(std::string nm = "Empty prohibition sign");
    virtual ~Prohib_sign();

    // Methods.
    virtual bool is_violated() override;
    virtual std::string mess() override;

    // Getters and setters.
    virtual type_sign get_type() override;
};

