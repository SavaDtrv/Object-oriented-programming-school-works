#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Leader.h"

using namespace std;

DepartmentLeader::DepartmentLeader() :Specialist() {
		strcpy(leaderDepartment, "");
		currentEmpl = 0;
		employees = new Employee*[DEPARTMENT_CAPACITY_MAX];
	}

DepartmentLeader::DepartmentLeader(char * _name, char * _adress, char _ID[ID_LENGTH], char * _department,
	double _salary, char* _spec, char _leaderDepartment[DEPARTMENT_NAME_LENGTH]) :
	Specialist(_name, _adress, _ID, _department, _salary, _spec) {

	strcpy(leaderDepartment, _leaderDepartment);
	employees = new Employee*[DEPARTMENT_CAPACITY_MAX];
	currentEmpl = 0;
}

char * DepartmentLeader::getDep()
{
	return leaderDepartment;
}

DepartmentLeader::~DepartmentLeader()
{
	fireDepartLeader();
}
