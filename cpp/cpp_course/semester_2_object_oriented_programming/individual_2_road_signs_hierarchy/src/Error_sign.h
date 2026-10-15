#pragma once
#include <iostream>
#include <string>
#include <exception>

class Error_sign :
    public std::exception
{
private:
    std::string m_error;
public:
    Error_sign(std::string text = "Undefined error") : m_error{text} {};
    const char* what() const noexcept { return this->m_error.c_str(); };
};

