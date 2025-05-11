#pragma once
#include <iostream>

class CValidator
{
public:
    static bool IsAlphaOnly(const std::string& input);
    static bool IsDigitsOnly(const std::string& input);
    static bool IsNotEmpty(const std::string& input);
};

