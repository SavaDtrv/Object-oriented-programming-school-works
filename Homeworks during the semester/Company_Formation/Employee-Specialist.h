#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <string>

using namespace std;

const int ID_LENGTH = 11;
const int DEFAULT_SALARY = 0;

class Employee {
	char* name;
	char* adress;
	char ID[ID_LENGTH];
	char* department;
	double salary;

	void fireEmployee() {
		delete name;
		name = nullptr;
		delete adress;
		adress = nullptr;
		delete department;
		department = nullptr;
	}

public:

	char* kindOfEmployee() {
		return "Worker";
	}

	Employee();
	Employee(char* _name, char* _adress, char _ID[ID_LENGTH], 
		char* _department, double _salary);
	virtual ~Employee();

	double getSalary() const;
	char* getID();

	void setName(char* newName);
	void setAdress(char* newAdress);
	void setDepartment(char* newDepartment);
	void setID(char* newID);
	void setSalary(double newSalary);

};

class Specialist :public Employee {
	char* spec;

	void fireSpecialist() {
		delete spec;
		spec = nullptr;
	}

public:
	char* kindOfEmployee() {
		return "Specialist";
	}

	Specialist();
	Specialist(char* _name, char* _adress, char _ID[ID_LENGTH], 
		char* _department, double _salary, char* _spec);
	
	~Specialist();

	char* getSpec();
	void setSpec(char* newSpec);
};