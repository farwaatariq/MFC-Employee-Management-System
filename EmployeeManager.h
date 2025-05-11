#include "Employee.h"
#include <list>

class CEmployeeManager
{
	static CEmployeeManager* instance;
	std::list<CEmployee*> m_listEmployees;
	CEmployeeManager();
	static int m_countProjectManager;
	static int m_countTeamLead;
	static int m_countSoftwareDeveloper;

public:
	static CEmployeeManager* GetInstance();
	~CEmployeeManager();
	void Add(CEmployee* newEmployee);
	bool Update(CEmployee* emp, int id);
	bool Delete(int id);
	static void IncrementTypeCount(const std::string& type);
	static void DecrementTypeCount(const std::string& type);
	std::string DisplayEmployee(int id);
	void DisplayAllEmployees();
	static int GetProjectManagerCount();
	static int GetTeamLeadCount();
	static int GetSoftwareManagerCount();
	std::list<CEmployee*> GetAllEmployees();
	CEmployee* GetEmployeeById(int id);
};

