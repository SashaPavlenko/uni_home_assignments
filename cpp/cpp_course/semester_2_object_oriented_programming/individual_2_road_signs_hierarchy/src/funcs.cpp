#include "funcs.h"
#include <iostream>
#include "Sign.h"
#include <string>

std::string type_to_string(type_sign t, std::string lan)
{
    std::string s;
    if (t == type_sign::prescribing) {
        s = std::string(lan == "rus" ? "Mandatory" : "Prescribing");
    }
    else if (t == type_sign::prohibition) {
        s = std::string(lan == "rus" ? "Prohibitory" : "Prohibition");
    }
    else if (t == type_sign::warning) {
        s = std::string(lan == "rus" ? "Warning" : "Warning");
    }
    else if (t == type_sign::error_type) {
        s = std::string(lan == "rus" ? "Error" : "Error");
    }

    return s;
}
