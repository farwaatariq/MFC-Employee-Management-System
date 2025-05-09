#include "pch.h"
#include "Phone.h"

CPhone::CPhone() {
	this->m_label = "";
	this->m_number = "";
}

CPhone::CPhone(const std::string& label, const std::string& number) : m_label(label), m_number(number) {}

CPhone::~CPhone() {
	std::cout << "phone destroyed" << std::endl;
}

std::string CPhone::GetString() const{
	return m_label + ": " + m_number;
}

std::string CPhone::GetLabel() const {
	return this->m_label;
}

std::string CPhone::GetNumber() const {
	return this->m_number;
}

void CPhone::SetLabel(const std::string& label) {
	this->m_label = label;
}

void CPhone::SetNumber(const std::string& number) {
	this->m_number = number;
}
