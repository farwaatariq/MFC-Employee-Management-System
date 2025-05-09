#include "pch.h"
#include "ProjectManager.h"
#include "Employee.h"


CProjectManager::CProjectManager() : CEmployee() {};

CProjectManager::~CProjectManager()
{
	std::cout << "project manager destroyed" << std::endl;
}

std::string CProjectManager::GetRoles() {
	std::string role = "project manager role";
	return role;
}

std::string CProjectManager::GetType() {
	return GetDesignation();
}
