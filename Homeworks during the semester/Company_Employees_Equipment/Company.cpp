#include <iostream>
#include <string>
#include "Company.h"

using namespace std;

int const DEFFAULT_EMPL_CAPACITY = 10;
int const DEFFAULT_EMPL_SIZE = 0;
int const DEFFAULT_EQUIP_CAPACITY = 10;
int const DEFFAULT_EQUIP_SIZE = 0;
int const MONTH_PER_YEAR = 12;
int const DEFFAULT_NAME_LENGTH = 1;


Company::Company():companyName(nullptr) {
	this->companyName = new char[DEFFAULT_NAME_LENGTH + 1];
	strcpy(this->companyName, "");
	this->emplCapacity = DEFFAULT_EMPL_CAPACITY;
	this->emplSize = DEFFAULT_EMPL_SIZE;
	this->equipCapacity = DEFFAULT_EQUIP_CAPACITY;
	this->equipSize = DEFFAULT_EQUIP_SIZE;
	employees = new Employee[emplCapacity];
	equipment = new Equipment[equipCapacity];
}

Company::Company(char* _companyName): companyName(nullptr) {
	this->setCompanyName(_companyName);
	this->emplCapacity = DEFFAULT_EMPL_CAPACITY;
	this->emplSize = DEFFAULT_EMPL_SIZE;
	this->equipCapacity = DEFFAULT_EQUIP_CAPACITY;
	this->equipSize = DEFFAULT_EQUIP_SIZE;
	employees = new Employee[emplCapacity];
	equipment = new Equipment[equipCapacity];
}

Company::Company(const Company& other) {
	copyCompany(other);
}

Company& Company::operator=(const Company& other) {
	if (this != &other)
	{
		removeCompany();
		copyCompany(other);
	}

	return *this;
}

const char* Company::getCompanyName() const { return this->companyName; }
int Company::getEmplCapacity() const { return this->emplCapacity; }
int Company::getEmplSize() const { return this->emplSize; }
int Company::getEquipCapacity() const { return this->equipCapacity; }
int Company::getEquipSize() const { return this->equipSize; }

void Company::setCompanyName(char* newCompanyName) {
	if (this->companyName != nullptr)
	{
		delete companyName;
		this->companyName = nullptr;
	}

	int length = strlen(newCompanyName);
	this->companyName = new char[length + 1];
	strcpy(companyName, newCompanyName);
}

double Company::annualEmplSalaries() {
	double salarySum = 0;
	for (int i = 0; i < getEmplSize(); i++)
	{
		salarySum += employees[i].annualSalary();
	}

	return salarySum;
}

double Company::annualEqMaintenanceCost() {
	double maintenanceCostSum = 0;
	for (int i = 0; i < getEquipSize(); i++)
	{
		maintenanceCostSum += equipment[i].getEqMaintenanceCost();
	}
	
	return maintenanceCostSum * MONTH_PER_YEAR;
}

void Company::specificEmplSalaryRaise(char* emplName, int percent) {
	for (int i = 0; i < getEmplSize(); i++)
	{
		if (employees[i].getEmployeeName() == emplName)
		{
			employees[i].monthSalaryRaise(percent);
			return;
		}
	}
}

void Company::specificEmplSalaryDecr(char* emplName, int percent) {
	for (int i = 0; i < getEmplSize(); i++)
	{
		if (employees[i].getEmployeeName() == emplName)
		{
			employees[i].monthSalaryReduction(percent);
			return;
		}
	}
}

void Company::allEmployeesSalaryRaise(int percent) {
	for (int i = 0; i < getEmplSize(); i++)
	{
		employees[i].monthSalaryRaise(percent);
	}
}

void Company::allEmployeesSalaryDecr(int percent) {
	for (int i = 0; i < getEmplSize(); i++)
	{
		employees[i].monthSalaryReduction(percent);
	}
}

void Company::addEmployee(const Employee& newEmployee) {
	addEmpl(newEmployee);
}

void Company::addEquipment(const Equipment& newEquipment) {
	addEquip(newEquipment);
}

Company::~Company() {
	removeCompany();
}