#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Director-Secretary.h"
#include "Employee-Specialist.h"
#include "Leader.h"

using namespace std;

//I have limited the department class to have 10 employees total 
//and a total of 50 employees in the director class. If we want them to be
//more, then we need to change that in the coresponding .h file.

const char* WORKER = "Worker";
const char* SPECIALIST = "Specialist";
const char* DEPLEADER = "Department Leader";

void formAFirm(Director* director, int allWorkers = 50) {
	
	int specificSpecEmpl, depLeaders, NonSpecEmpl;
	cout << "Enter the required number of specialists, department leaders "
		<< "and employees with no specialisation: ";
	cin >> specificSpecEmpl;
	cout << " ";
	cin >> depLeaders;
	cout << " ";
	cin >> NonSpecEmpl;

	int countNonSpecEmpl = 0, countSpecificSpecEmpl = 0, countDepLeaders = 0;

	for (int i = 0; i < allWorkers; i++)
	{
		if (director->getAt(i)->kindOfEmployee() == WORKER) {
			countNonSpecEmpl++;
		}
		else if (director->getAt(i)->kindOfEmployee() == SPECIALIST) {
			countSpecificSpecEmpl++;
		}
		else if (director->getAt(i)->kindOfEmployee() == DEPLEADER) {
			countDepLeaders++;
		}
	}

	if (countSpecificSpecEmpl >= specificSpecEmpl && countDepLeaders >= depLeaders
		&& countNonSpecEmpl >= NonSpecEmpl) {
		
		cout << "Can we form a firm: " << boolalpha << true << '\n';
		director->moneyNeededForSalaries(director);
		return;
	}
	else { 
		cout << "Can we form a firm: " << boolalpha << false << '\n'; 
		return;
	}
}

void testDynamic() {
	while (true) {
		DepartmentLeader boss;
	}
}

int main() {

	system("pause");
	return 0;
}