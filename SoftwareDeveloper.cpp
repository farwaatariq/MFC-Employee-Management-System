#include "pch.h"
#include "SoftwareDeveloper.h"
#include "Employee.h"


CSoftwareDeveloper::CSoftwareDeveloper() : CEmployee() {};

CSoftwareDeveloper::~CSoftwareDeveloper()
{
	std::cout << "software dev destroyed" << std::endl;
}

std::string CSoftwareDeveloper::GetRoles() {
	std::string role = "software dev role";
	return role;
}

std::string CSoftwareDeveloper::GetType() {
	return GetDesignation();
}
