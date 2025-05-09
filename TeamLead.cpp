#include "pch.h"
#include "TeamLead.h"
#include "Employee.h"


CTeamLead::CTeamLead() : CEmployee() {};

CTeamLead::~CTeamLead(){
	std::cout << "team lead destroyed" << std::endl;
}

std::string CTeamLead::GetRoles() {
	std::string role = "team lead role";
	return role;
}

std::string CTeamLead::GetType() {
	return GetDesignation();
}
