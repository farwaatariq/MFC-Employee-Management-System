#include "pch.h"
#include "Employee.h"
#include <string>

CEmployee::CEmployee() {
	this->m_id = std::rand() % 101;
	this->m_initial = "";
	this->m_fullName = "";
	this->m_gender = "";
	this->m_age = 0;
	this->m_dob = "";
	this->m_vecPhones = {};
	this->m_designation = "";
	this->m_roles = "";
	this->m_pTeams = nullptr;
	this->m_teamCount = 0;
}

CEmployee::~CEmployee()
{
	// delete[] m_pTeams;
	std::cout << "employee destroyed" << std::endl;
}

std::string CEmployee::GetString() {

	std::string str = "--EMPLOYEE--";
	str += "\nID: " + std::to_string(m_id);
	str += "\nFull name: " + m_initial + " " + m_fullName;
	str += "\nGender: " + m_gender;
	str += "\nAge: " + std::to_string(m_age);
	str += "\nDate of Birth: " + m_dob;
	str += "\nDesignation: " + m_designation;
	str += "\nRoles: " + m_roles;
	str += "\n\n--TEAMS--: ";
	/*for (int i = 0; i < m_teamCount ; i++) {
		str+= "\n" + m_pTeams[i].GetString();
	}*/
	if (m_pTeams != nullptr && m_teamCount > 0) {
		for (int i = 0; i < m_teamCount; i++) {
			str += "\n" + m_pTeams[i].GetString();
		}
	}
	else {
		str += "\nNo teams assigned.";
	}
	/*for (int i = 0; i < 8; i++) {
		str += "\n" + m_pTeams[i].GetString();
	}*/
	str += "\n\n--PHONES--: ";
	for (const auto& phone : m_vecPhones) {
		str += "\n" + phone.GetString();
	}

	return str;
}

//----phone management----
void CEmployee::AddPhones(CPhone newPhone) {
	m_vecPhones.push_back(newPhone);
}

void CEmployee::DeletePhone(int index) {
	if (index >= 0 && index < m_vecPhones.size()) {
		m_vecPhones.erase(m_vecPhones.begin() + index);
	}
}

void CEmployee::UpdatePhone(const CPhone& phone, int index) {
	if (index >= 0 && index < m_vecPhones.size()) {
		m_vecPhones[index] = phone;
	}
}

std::string CEmployee::GetInitial() const {
	return this->m_initial;
}

int CEmployee::GetID() const {
	return this->m_id;
}

std::string CEmployee::GetFullName() const {
	return this->m_fullName;
}

std::string CEmployee::GetGender() const {
	return this->m_gender;
}

int CEmployee::GetAge() const {
	return this->m_age;
}

std::string CEmployee::GetDOB() const {
	return this->m_dob;
}

std::vector<CPhone> CEmployee::GetPhones() const {
	return this->m_vecPhones;
}

std::string CEmployee::GetDesignation() const {
	return this->m_designation;
}

std::string CEmployee::GetRoles() const {
	return this->m_roles;
}

CTeam* CEmployee::GetTeams() const {
	return this->m_pTeams;
}

int CEmployee::GetTeamCount() const {
	return this->m_teamCount;
}

void CEmployee::SetTeamCount(int count) {
	this->m_teamCount = count;
}

void CEmployee::SetInitial(const std::string& initial) {
	this->m_initial = initial;
}

void CEmployee::SetFullName(const std::string& fullName) {
	this->m_fullName = fullName;
}

void CEmployee::SetGender(const std::string& gender) {
	this->m_gender = gender;
}

void CEmployee::SetAge(int age) {
	this->m_age = age;
}

void CEmployee::SetDOB(const std::string& dob) {
	this->m_dob = dob;
}

void CEmployee::SetPhones(const std::vector<CPhone>& phones) {
	this->m_vecPhones = phones;
}

void CEmployee::SetDesignation(const std::string& designation) {
	this->m_designation = designation;
}

void CEmployee::SetRoles(const std::string& roles) {
	this->m_roles = roles;
}

void CEmployee::SetTeams(CTeam* teams) {
	m_pTeams = teams;
}

//CEmployee::CEmployee(int id, const std::string& fullName, const std::string& gender, int age, const std::string& DOB, const std::vector<CPhone>& phones, const std::string& designation, int teamSize): m_id(id), m_fullName(fullName), m_gender(gender), m_age(age), m_DOB(DOB), m_vecPhone(phones), m_designation(designation){}