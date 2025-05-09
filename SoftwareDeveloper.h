#pragma once
#include "Employee.h"

class CSoftwareDeveloper : public CEmployee
{
public:
	CSoftwareDeveloper();
	~CSoftwareDeveloper();
	std::string GetRoles() override;
	std::string GetType() override;
};

