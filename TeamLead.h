#pragma once
#include "Employee.h"
class CTeamLead : public CEmployee
{
public:
	CTeamLead();
	~CTeamLead();
	std::string GetRoles() override;
	std::string GetType() override;
};

