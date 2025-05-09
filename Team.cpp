#include "pch.h"
#include "Team.h"


CTeam::CTeam() {
	this->m_name = "";
}

CTeam::CTeam(const std::string& name) : m_name(name){}


CTeam::~CTeam()
{
	std::cout << "Team Destroyed" << std::endl;
}

std::string CTeam::GetString() {
	return m_name;
}

std::string CTeam::GetName() const{
	return this->m_name;
}

void CTeam::SetName(const std::string& name) {
	this->m_name = name;
}