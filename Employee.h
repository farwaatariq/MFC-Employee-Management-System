#include "Phone.h"
#include "Team.h"
#include <vector>
#ifndef CEMPLOYEE_H
#define CEMPLOYEE_H

class CEmployee 
{
private:
	int m_id;
	std::string m_initial;
	std::string m_fullName;
	std::string m_gender;
	int m_age;
	std::string m_dob;
	std::vector<CPhone> m_vecPhones;
	std::string m_designation;
	std::string m_roles;
	CTeam* m_pTeams;
	int m_teamCount;

public:
	CEmployee();
	//CEmployee(int id, const std::string& fullName, const std::string& gender, int age, const std::string& DOB, const std::vector<CPhone>& phones, const std::string& designation, int teamSize);
	virtual ~CEmployee();
	virtual std::string GetType() = 0;
	virtual std::string GetRoles() = 0;
	std::string GetString();

	//phone vector management methods
	void AddPhones(CPhone phone);
	void DeletePhone(int index);
	void UpdatePhone(const CPhone& phone, int index);

	//getter setters.
	int GetID() const;
	std::string GetInitial() const;
	std::string GetFullName() const;
	std::string GetGender() const;
	int GetAge() const;
	std::string GetDOB() const;
	std::vector<CPhone> GetPhones() const;
	std::string GetDesignation() const;
	std::string GetRoles() const;
	CTeam* GetTeams() const;
	int GetTeamCount() const;
	void SetTeamCount(int count);
	void SetInitial(const std::string& initial);
	void SetFullName(const std::string& fullName);
	void SetGender(const std::string& gender);
	void SetAge(int age);
	void SetDOB(const std::string& DOB);
	void SetPhones(const std::vector<CPhone>& phones);
	void SetDesignation(const std::string& designation);
	void SetRoles(const std::string& roles);
	void SetTeams(CTeam* teams);
};

#endif