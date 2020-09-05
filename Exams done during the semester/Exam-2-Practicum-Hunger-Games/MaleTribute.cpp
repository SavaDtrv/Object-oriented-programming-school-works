#include "MaleTribute.h"
#include "Tribute.h"
#include <iostream>
#include <string>

const int DEFAULT_MALE_POWER = 0;
const int LENGTH_NAME_SPEC_FOR_READING_MALE = 32;


MaleTribute::MaleTribute() : Tribute() {
	malePower = DEFAULT_MALE_POWER;
}

MaleTribute::MaleTribute(char * _name, int _areaNum, double _chanceForWin, int _malePower)
	:Tribute(_name, _areaNum, _chanceForWin) {
	
	setMalePower(_malePower);
}

MaleTribute::MaleTribute(const MaleTribute & other) {
	copyMale(other);
}

MaleTribute & MaleTribute::operator=(const MaleTribute & other) {
	if (this != &other) {
		copyMale(other);
	}

	return *this;
}

void MaleTribute::setMalePower(int newMalePower) {

	if (newMalePower >= 0 && newMalePower <= 10) {
		malePower = newMalePower;
	}
	else
	{
		cout << "The power must be between 0 and 10!" << '\n';
		return;
	}

	if (malePower >= 6 && malePower <= 10) {
		setChanceForWin(chanceForWin + 1);
	}
}

void MaleTribute::read(MaleTribute & newMale) {
	cout << "Input the name of the boy: ";
	cin.getline(newMale.name, LENGTH_NAME_SPEC_FOR_READING_MALE);
	cout << '\n' << "Input the are the boy is from: ";
	cin >> newMale.areaNum;
	cout << '\n' << "Input his chance for winning: ";
	cin >> newMale.chanceForWin;
	cout << '\n' << "Input his power: ";
	cin >> malePower;
}

double MaleTribute::potential()
{
	return getChance();
}
