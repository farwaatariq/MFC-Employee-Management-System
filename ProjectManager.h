#pragma once
#include "Employee.h"

class CProjectManager : public CEmployee
{
public:
	CProjectManager();
	~CProjectManager();
	std::string GetRoles() override;
	std::string GetType() override;
};

