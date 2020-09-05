#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <string>
#include "Employee-Specialist.h"
#include "Leader.h"

using namespace std;

const int MAX_NUM_OF_EMPL = 50;

class Secretary : public Employee {
	char* languages;

	void fireSecretary() {
		delete languages;
		languages = nullptr;
	}
public:
	Secretary() :Employee() {
		languages = new char[2];
		strcpy(languages, "");
	}

	Secretary(char* _name, char* _adress, char _ID[ID_LENGTH],
		char* _department, double _salary, char* _languages):
		Employee(_name, _adress, _ID, _department, _salary) {
		
		setLanguages(_languages);
	}

	~Secretary() {
		fireSecretary();
	}

	void setLanguages(char* newLanguages) {
		if (languages != nullptr) {
			fireSecretary();
		}

		int length = strlen(newLanguages);
		languages = new char[length + 1];
		strcpy(languages, newLanguages);
	}
};

class Director {
	Employee** employees;
	int currentEmpl;
	Secretary secretary;

	void addEmpl(Employee& newEmpl) {
		if (currentEmpl == MAX_NUM_OF_EMPL - 1) {
			cout << "The firm has no open work places now." << '\n';
		}

		employees[currentEmpl] = &newEmpl;
		currentEmpl++;
	}

	void fireEmpl(Employee& forFiring) {
		for (int i = 0; i < currentEmpl; i++) {
			
			if (strcmp(employees[i]->getID(), forFiring.getID()) == 0) {
				employees[i] = employees[currentEmpl - 1];
				currentEmpl--;
				return;
			}
		}
	}

	void removeFirm() {
		delete employees;
		employees = nullptr;
	}

public:

	Director() : secretary() {
		employees = new Employee*[MAX_NUM_OF_EMPL];
		currentEmpl = 0;
	}

	Director(char* _name, char* _adress, char _ID[ID_LENGTH],
		char* _department, double _salary, char* _languages) 
		:secretary(_name, _adress, _ID, _department, _salary, _languages) {
		
		employees = new Employee*[MAX_NUM_OF_EMPL];
		currentEmpl = 0;
	}

	~Director() {
		removeFirm();
	}

	Employee* getAt(int index) {
		return this->employees[index];
	}

	void moneyNeededForSalaries(Director* director) {
		double moneyForSalaries = 0;

		for (int i = 0; i < currentEmpl; i++) {
			moneyForSalaries += director->employees[i]->getSalary();
		}

		cout << "The money needed for salaries is: " << moneyForSalaries << '\n';
	}
};