#include "pch.h"
#include "EmployeeManager.h"


CEmployeeManager::CEmployeeManager(): m_listEmployees(){}

CEmployeeManager* CEmployeeManager::instance = nullptr;

CEmployeeManager::~CEmployeeManager()
{
	std::cout << "employee manager destroyed" << std::endl;
}

void CEmployeeManager::Add(CEmployee* newEmployee) {
	this->m_listEmployees.push_back(newEmployee);
}

CEmployeeManager* CEmployeeManager::GetInstance() {
	if (!instance)
		instance = new CEmployeeManager();
	return instance;
}

std::string CEmployeeManager::DisplayEmployee(int id) {
	for (auto employee : m_listEmployees) {
		if (employee->GetID() == id) {
			return employee->GetString();
		}
	}
	return "Employee not found";
}

bool CEmployeeManager::Delete(int id) {
	for (auto it = m_listEmployees.begin(); it != m_listEmployees.end(); ++it) {
		if ((*it)->GetID() == id) {
			m_listEmployees.erase(it);
			return true;
		}
	}
	return false;
}

void CEmployeeManager::DisplayAllEmployees() {
	for (auto employee : m_listEmployees) {
		std::cout << employee->GetString() << std::endl;
	}
}

bool CEmployeeManager::Update(CEmployee* newEmp, int id) {
	for (auto it = m_listEmployees.begin(); it != m_listEmployees.end(); ++it) {
		if ((*it)->GetID() == id) {
			delete* it;              // delete old object
			*it = newEmp;            // replace with new one
			return true;
		}
	}
	return false;
}

std::list<CEmployee*> CEmployeeManager::GetAllEmployees() {
	return m_listEmployees;
}

CEmployee* CEmployeeManager::GetEmployeeById(int id) {
	for (auto employee : m_listEmployees) {
		if (employee->GetID() == id) {
			return employee;
		}
	}
	return nullptr;
}
