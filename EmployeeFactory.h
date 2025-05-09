#include <memory>
#include <iostream>
//#include "Employee.h"
#include "ProjectManager.h"
#include "TeamLead.h"
#include "SoftwareDeveloper.h"
#include "EmployeeType.h"

class CEmployeeFactory
{
public:
	static CEmployee* createEmployee(EMPLOYEETYPE type);
};

