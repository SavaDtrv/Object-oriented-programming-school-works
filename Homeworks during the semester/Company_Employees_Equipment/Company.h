#pragma once
#include <iostream>
#include "Employee.h"
#include "Equipment.h"

using namespace std;

class Company {
	char* companyName;
	Employee* employees;
	int emplCapacity;
	int emplSize;
	Equipment* equipment;
	int equipCapacity;
	int equipSize;

	void resizeEmployees() {
		if (emplCapacity > emplSize * 2) {
			emplCapacity /= 2;
		}
		if (emplSize == emplCapacity - 1) {
			emplCapacity *= 2;
		}

		Employee* tmpEmployees = new Employee[emplCapacity];
		for (int i = 0; i < emplSize; i++)
		{
			tmpEmployees[i] = employees[i];
		}

		delete[] employees;
		employees = nullptr;
		employees = tmpEmployees;
	}

	void addEmpl(const Employee& newEmployee) {
		if (emplSize == emplCapacity - 1)
		{
			resizeEmployees();
		}

		employees[emplSize] = newEmployee;
		emplSize++;
	}

	void resizeEquipment() {
		if (equipCapacity > equipSize * 2) {
			equipCapacity /= 2;
		}
		if (equipSize == equipCapacity - 1) {
			equipCapacity *= 2;
		}

		Equipment* tmpEquipment = new Equipment[equipCapacity];
		for (int i = 0; i < equipSize; i++)
		{
			tmpEquipment[i] = equipment[i];
		}

		delete[] equipment;
		equipment = nullptr;
		equipment = tmpEquipment;
	}

	void addEquip(const Equipment& newEquipment) {
		if (equipSize == equipCapacity - 1)
		{
			resizeEquipment();
		}

		equipment[equipSize] = newEquipment;
		equipSize++;
	}

	void copyCompany(const Company& other) {
		setCompanyName(other.companyName);
		emplCapacity = other.emplCapacity;
		emplSize = other.emplSize;
		equipCapacity = other.equipCapacity;
		equipSize = other.equipSize;

		for (int i = 0; i < emplSize; i++)
		{
			employees[i] = other.employees[i];
		}

		for (int i = 0; i < equipSize; i++)
		{
			equipment[i] = other.equipment[i];
		}
	}

	void removeCompany() {
		delete companyName;
		companyName = nullptr;
		delete[] employees;
		employees = nullptr;
		delete[] equipment;
		equipment = nullptr;
	}
public:
	Company();
	Company(char*);
	Company(const Company& other);
	Company& operator=(const Company& other);
	~Company();

	const char* getCompanyName() const;
	int getEmplCapacity() const;
	int getEmplSize() const;
	int getEquipCapacity() const;
	int getEquipSize() const;

	void setCompanyName(char*);

	double annualEmplSalaries();
	double annualEqMaintenanceCost();
	void specificEmplSalaryRaise(char*, int);
	void specificEmplSalaryDecr(char*, int);
	void allEmployeesSalaryRaise(int);
	void allEmployeesSalaryDecr(int);
	void addEmployee(const Employee& newEmployee);
	void addEquipment(const Equipment& newEquipment);
};