#include <iostream>
#include <string>
#include "Employee.h"


using namespace std;

int const MONTHS_IN_YEAR = 12;
int const DEFFAULT_LENGTH_NAME_POSSITION = 1;
int const DEFFAULT_AGE = 0;
double const DEFFAULT_SALARY = 0;
int const MINIMUM_AGE = 18;
double const MINIMUM_WAGE = 460;

Employee::Employee() {
	this->employeeName = new char[DEFFAULT_LENGTH_NAME_POSSITION + 1];
	strcpy(this->employeeName, "");
	this->possition = new char[DEFFAULT_LENGTH_NAME_POSSITION + 1];
	strcpy(this->possition, "");
	this->employeeAge = DEFFAULT_AGE;
	this->salary = DEFFAULT_SALARY;
}

Employee::Employee(char* _employeeName, char* _possition, int _employeeAge, double _salary) {
	this->setEmployeeName(_employeeName);
	this->setPossition(_possition);
	this->setEmployeeAge(_employeeAge);
	this->setSalary(_salary);
}
Employee::Employee(const Employee& other) {
	copy(other);

}
Employee& Employee::operator=(const Employee& other) {
	if (this != &other)
	{
		release();
		copy(other);
	}

	return *this;
}

const char* Employee::getEmployeeName() const {
	return this->employeeName;
}
const char* Employee::getPossition() const {
	return this->possition;
}
int Employee::getEmployeeAge() const {
	return this->employeeAge;
}
double Employee::getSalary() const {
	return this->salary;
}

void Employee::setEmployeeName(char* newEmployeeName) {
	if (this->employeeName != nullptr)
	{
		release();
	}

	int length = strlen(newEmployeeName);
	this->employeeName = new char[length + 1];
	strcpy(this->employeeName, newEmployeeName);
}
void Employee::setPossition(char* newPossition) {
	if (realEmplPossition(newPossition))
	{
		if (this->possition != nullptr)
		{
			release();
		}

		int length = strlen(newPossition);
		this->possition = new char[length + 1];
		strcpy(this->possition, newPossition);
	}
	else cout << "There is no such possition in the company." << '\n';
}
void Employee::setEmployeeAge(int newEmployeeAge) {
	if (newEmployeeAge >= MINIMUM_AGE)
	{
		this->employeeAge = newEmployeeAge;
	}
	else cout << "You cannot hire an under-aged as employee." << '\n';
}
void Employee::setSalary(double newSalary) {
	if (newSalary >= MINIMUM_WAGE)
	{
		this->salary = newSalary;
	}
	else cout << "You cannot give your employees less than"
		<< " the minimum wage." << '\n';
}

Employee::Possition Employee::checkForRealPossition(string const& inString)
{
	if (inString == "Programmer") return Programmer;
	else return NoRealPossition;
	if (inString == "Architect") return Architect;
	else return NoRealPossition;
	if (inString == "Manager") return Manager;
	else return NoRealPossition;
	if (inString == "HR") return HR;
	else return NoRealPossition;
}

bool Employee::realEmplPossition(char* _possition) {
	switch (checkForRealPossition(_possition)) {
	case Programmer: case Architect: case Manager: case HR: 
		return true; break;
	case NoRealPossition: 
		return false; break;
	}
}

double Employee::annualSalary() {
	return getSalary() * MONTHS_IN_YEAR;
}
void Employee::monthSalaryRaise(int percent) {
	this->setSalary(getSalary() + getSalary() * (percent / 100));
}
void Employee::monthSalaryReduction(int _percent) {
	this->setSalary(getSalary() - getSalary() * (_percent / 100));
}

Employee::~Employee() {
	release();
}