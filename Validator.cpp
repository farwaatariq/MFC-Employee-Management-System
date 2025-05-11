#include "pch.h"
#include "Validator.h"
#include <cctype>

bool CValidator::IsAlphaOnly(const std::string& input)
{
    for (char ch : input)
    {
        if (!std::isalpha(static_cast<unsigned char>(ch)) && ch != ' ')
            return false;
    }
    return true;
}

bool CValidator::IsDigitsOnly(const std::string& input)
{
    for (char ch : input)
    {
        if (!std::isdigit(static_cast<unsigned char>(ch)))
            return false;
    }
    return true;
}

bool CValidator::IsNotEmpty(const std::string& input)
{
    return !input.empty();
}
