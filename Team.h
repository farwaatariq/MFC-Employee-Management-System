#include <iostream>
#ifndef CTEAM_H
#define CTEAM_H

class CTeam
{
private:
	std::string m_name;
public:
	CTeam();
	CTeam(const std::string& name);
	virtual ~CTeam();
	virtual std::string GetString();
	std::string GetName() const;
	void SetName(const std::string& name);
};

#endif
