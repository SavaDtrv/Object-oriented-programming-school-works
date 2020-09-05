#define _CRT_SECURE_NO_WARNINGS
#include "GirlTribute.h"
#include <iostream>
#include <string>

using namespace std;

const int DEFAULT_SPECIALITY_LENGTH = 2;
const int LENGTH_NAME_SPEC_FOR_READING = 32;

GirlTribute::GirlTribute() :Tribute() {
	speciality = new char[DEFAULT_SPECIALITY_LENGTH];
	strcpy(speciality, "");
}

GirlTribute::GirlTribute(char * _name, int _areaNum, double _chanceForWin, char * _speciality)
	:Tribute(_name, _areaNum, _chanceForWin)
{
	setSpeciality(_speciality);
}

GirlTribute::GirlTribute(const GirlTribute & other) {
	
	copyGirl(other);
}

GirlTribute & GirlTribute::operator=(const GirlTribute & other) {
	
	if (this != &other) {
		killGirlTribute();
		copyGirl(other);
	}

	return *this;
}

GirlTribute::~GirlTribute() {
	killGirlTribute();
}

void GirlTribute::setSpeciality(char * newSpeciality) {
	if (speciality != nullptr) {
		killGirlTribute();
	}

	int length = strlen(newSpeciality);
	speciality = new char[length + 1];
	strcpy(speciality, newSpeciality);

	if (strcmp(speciality, "archery") == 0) {
		setChanceForWin(chanceForWin + 1);
	}
}

void GirlTribute::read(GirlTribute& newGirl) {
	cout << "Input the name of the girl: ";
	cin.getline(newGirl.name, LENGTH_NAME_SPEC_FOR_READING);
	cout << '\n' << "Input the are the girl is from: ";
	cin >> newGirl.areaNum;
	cout << '\n' << "Input her chance for winning: ";
	cin >> newGirl.chanceForWin;
	cout << '\n' << "Input her speciality: ";
	cin.getline(newGirl.speciality, LENGTH_NAME_SPEC_FOR_READING);
}

double GirlTribute::potential() {
	return getChance();
}
