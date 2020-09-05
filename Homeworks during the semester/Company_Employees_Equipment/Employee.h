#pragma once
#include <iostream>

using namespace std;

class Employee {
	char* employeeName;
	char* possition;
	int employeeAge;
	double salary;
	
	void copy(const Employee& other) {
		this->setEmployeeName(other.employeeName);
		this->setPossition(other.possition);
		this->setEmployeeAge(other.employeeAge);
		this->setSalary(other.salary);
	}

	void release() {
		delete employeeName;
		employeeName = nullptr;
		delete possition;
		possition = nullptr;
	}

public:
	enum Possition {
		Programmer,
		Architect,
		Manager,
		HR,
		NoRealPossition
	};


	Employee();
	Employee(char*, char*, int, double);
	Employee(const Employee& other);
	Employee& operator=(const Employee& other);
	~Employee();

	const char* getEmployeeName() const;
	const char* getPossition() const;
	int getEmployeeAge() const;
	double getSalary() const;

	void setEmployeeName(char*);
	void setPossition(char*);
	void setEmployeeAge(int);
	void setSalary(double);

	bool realEmplPossition(char*);
	Possition checkForRealPossition(string const& inString);

	double annualSalary();
	void monthSalaryRaise(int);
	void monthSalaryReduction(int);

	void description() {
		cout << '\t' << "Employee characteristics" << '\n';
		cout << "Name: " << this->getEmployeeName() << '\n';
		cout << "Age: " << this->getEmployeeAge() << '\n';
		cout << "Salary: " << this->getSalary() << '\n';
		cout << "Possition: " << this->getPossition() << '\n';
	}
};