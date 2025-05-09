
#include <iostream>
#ifndef CPHONE_H
#define CPHONE_H

class CPhone {
private:
	std::string m_label;
	std::string m_number;

public:
	CPhone();
	CPhone(const std::string& label, const std::string& number);
	virtual ~CPhone();
	virtual std::string GetString() const;
	void SetLabel(const std::string& label);
	void SetNumber(const std::string& number);
	std::string GetLabel() const;
	std::string GetNumber() const;
};

#endif
