#define _CRT_SECURE_NO_WARNINGS
#include "Employee-Specialist.h"
#include <iostream>
#include <string>

using namespace std;

const int DEFAULT_DYNAMIC_DATA_LENGTH = 2;

	//employee
Employee::Employee() {
	name = new char[DEFAULT_DYNAMIC_DATA_LENGTH];
	strcpy(name, "");
	adress = new char[DEFAULT_DYNAMIC_DATA_LENGTH];
	strcpy(adress, "");
	department = new char[DEFAULT_DYNAMIC_DATA_LENGTH];
	strcpy(department, "");
	strcpy(ID, "");
	salary = DEFAULT_SALARY;
}

Employee::Employee(char * _name, char * _adress, 
	char _ID[ID_LENGTH], char * _department, double _salary) {

	setName(_name);
	setAdress(_adress);
	setID(_ID);
	setDepartment(_department);
	setSalary(_salary);
}

Employee::~Employee() {
	fireEmployee();
}

double Employee::getSalary() const { return salary; }
char * Employee::getID() {	return ID; }

void Employee::setName(char * newName) {
	if (name != nullptr) {
		delete name;
		name = nullptr;
	}

	int length = strlen(newName);
	name = new char[length + 1];
	strcpy(name, newName);
}

void Employee::setAdress(char * newAdress) {
	if (adress != nullptr) {
		delete adress;
		adress = nullptr;
	}

	int length = strlen(newAdress);
	adress = new char[length + 1];
	strcpy(adress, newAdress);
}

void Employee::setDepartment(char * newDepartment) {
	if (department != nullptr) {
		delete department;
		department = nullptr;
	}

	int length = strlen(newDepartment);
	department = new char[length + 1];
	strcpy(department, newDepartment);
}

void Employee::setID(char * newID) {
	if (strlen(newID) == 10) {
		strcpy(ID, newID);
	}
	else cout << "The ID has too few numbers." << '\n';
}

void Employee::setSalary(double newSalary) {
	if (newSalary > 450) {
		salary = newSalary;
	}
	else cout << "Invalid amount of money.";
}

 //specialist

Specialist::Specialist() :Employee() {
	spec = new char[2];
	strcpy(spec, "");
}

Specialist::Specialist(char * _name, char * _adress, char _ID[ID_LENGTH], 
	char * _department, double _salary, char* _spec) :
	Employee(_name, _adress, _ID, _department, _salary) {

	setSpec(_spec);
}

Specialist::~Specialist() {
	fireSpecialist();
}

char * Specialist::getSpec() {	return spec; }

void Specialist::setSpec(char * newSpec) {
	if (spec != nullptr) {
		delete spec;
		spec = nullptr;
	}
		
	int lenght = strlen(newSpec);
	spec = new char[lenght + 1];
	strcpy(spec, newSpec);
}
