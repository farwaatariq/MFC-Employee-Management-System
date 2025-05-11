#include "pch.h"
#include "EmployeeManager.h"


CEmployeeManager::CEmployeeManager(): m_listEmployees(){}

CEmployeeManager* CEmployeeManager::instance = nullptr;

int CEmployeeManager::m_countProjectManager = 0;
int CEmployeeManager::m_countTeamLead = 0;
int CEmployeeManager::m_countSoftwareDeveloper = 0;

CEmployeeManager::~CEmployeeManager()
{
	std::cout << "employee manager destroyed" << std::endl;
}

void CEmployeeManager::Add(CEmployee* newEmployee) {
	this->m_listEmployees.push_back(newEmployee);
	IncrementTypeCount(newEmployee->GetType());
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
			DecrementTypeCount((*it)->GetType());
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
			std::string oldType = (*it)->GetType(); 
			std::string newType = newEmp->GetType(); 

			// Replace the old employee with the new one
			delete* it;
			*it = newEmp;

			// Update counters
			if (oldType != newType) {
				DecrementTypeCount(oldType);
				IncrementTypeCount(newType);
			}
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

void CEmployeeManager::IncrementTypeCount(const std::string& type) {
	if (type == "Project Manager") m_countProjectManager++;
	else if (type == "Team Lead") m_countTeamLead++;
	else if (type == "Software Developer") m_countSoftwareDeveloper++;
}

void CEmployeeManager::DecrementTypeCount(const std::string& type) {
	if (type == "Project Manager") --m_countProjectManager;
	else if (type == "Team Lead") --m_countTeamLead;
	else if (type == "Software Developer") --m_countSoftwareDeveloper;
}

int CEmployeeManager::GetProjectManagerCount() {
	return m_countProjectManager;
}

int CEmployeeManager::GetTeamLeadCount() {
	return m_countTeamLead;
}

int CEmployeeManager::GetSoftwareManagerCount() {
	return m_countSoftwareDeveloper;
}
