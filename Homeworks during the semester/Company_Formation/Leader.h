#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <string>
#include "Employee-Specialist.h"

using namespace std;

const int DEPARTMENT_NAME_LENGTH = 32;
const int DEPARTMENT_CAPACITY_MAX = 10;


class DepartmentLeader :public Specialist {
	Employee** employees;
	int currentEmpl;
	char leaderDepartment[DEPARTMENT_NAME_LENGTH];

	void add(Employee& newEmpl) {
		if (currentEmpl == DEPARTMENT_CAPACITY_MAX - 1) {
			cout << "This department is full." << '\n';
		}

		employees[currentEmpl] = &newEmpl;
		currentEmpl++;
	}

	void fireDepartLeader() {
		delete[] employees;
		employees = nullptr;
	}
public:

	char* kindOfEmployee() {
		return "Departmenet Leader";
	}

	DepartmentLeader();
	DepartmentLeader(char* _name, char* _adress, char _ID[ID_LENGTH], 
		char* _department, double _salary, char* _spec, 
		char _leaderDepartment[DEPARTMENT_NAME_LENGTH]);

	~DepartmentLeader();
	char* getDep();
};