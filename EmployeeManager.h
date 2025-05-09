#include "Employee.h"
#include <list>

class CEmployeeManager
{
	static CEmployeeManager* instance;
	std::list<CEmployee*> m_listEmployees;
	CEmployeeManager();
public:
	static CEmployeeManager* GetInstance();
	~CEmployeeManager();
	void Add(CEmployee* newEmployee);
	bool Update(CEmployee* emp, int id);
	bool Delete(int id);
	std::string DisplayEmployee(int id);
	void DisplayAllEmployees();
	int GetCount() const;
	std::list<CEmployee*> GetAllEmployees();
	CEmployee* GetEmployeeById(int id);
};

