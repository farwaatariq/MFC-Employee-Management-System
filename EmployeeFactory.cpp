#include "pch.h"
#include "EmployeeFactory.h"


CEmployee* CEmployeeFactory::createEmployee(EMPLOYEETYPE type) {
	switch (type) {
	case EMPLOYEETYPE::ProjectManager:
		return new CProjectManager();
		break;

	case EMPLOYEETYPE::TeamLead:
		return new CTeamLead();
		break;

	case EMPLOYEETYPE::SoftwareDeveloper:
		return new CSoftwareDeveloper();
		break;

	default:
		return nullptr;
	}
}
