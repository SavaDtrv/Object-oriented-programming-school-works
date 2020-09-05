#define _CRT_SECURE_NO_WARNINGS
#include "Tribute.h"
#include <iostream>
#include <string>

using namespace std;

const int DEFAULT_NAME_LENGTH = 2;
const int DEFAULT_ARE_NUM = 0;
const double DEFAULT_WIN_CHANCE = 0;
const int MAX_CHANCE_FOR_WIN = 10;
const int MIN_CHANCE_FOR_WIN = 0;

Tribute::Tribute() {
	name = new char[DEFAULT_NAME_LENGTH];
	strcpy(name, "");
	areaNum = DEFAULT_ARE_NUM;
	chanceForWin = DEFAULT_WIN_CHANCE;
}

Tribute::Tribute(char* _name, int _areaNum, double _chanceForWin) {
	setName(_name);
	setAreaNum(_areaNum);
	setChanceForWin(_chanceForWin);
}

Tribute::Tribute(const Tribute & other) {
	copyTribute(other);
}

Tribute & Tribute::operator=(const Tribute & other) {
	
	if (this != &other) {
		killTribute();
		copyTribute(other);
	}

	return *this;
}

Tribute::~Tribute() {
	killTribute();
}

char * Tribute::getName() const { return name; }

int Tribute::getArea() const { return areaNum; }

double Tribute::getChance() const { return chanceForWin; }

void Tribute::setName(char * newName) {

	if (name != nullptr) {
		killTribute();
	}

	int length = strlen(newName);
	name = new char[length + 1];
	strcpy(name, newName);
}

void Tribute::setAreaNum(int newAreaNum) {

	if (newAreaNum >= 1 && newAreaNum <= 12) {
		areaNum = newAreaNum;
	}
	else cout << "There is no such are!" << '\n';
}

void Tribute::setChanceForWin(double newChance) {
	if (newChance >= 0 && newChance <= 10) {
		chanceForWin = newChance;
	}
	else if (newChance > MAX_CHANCE_FOR_WIN) {
		chanceForWin = MAX_CHANCE_FOR_WIN;
	}
	else if (newChance < MIN_CHANCE_FOR_WIN) {
		chanceForWin = MIN_CHANCE_FOR_WIN;
	}
	else cout << "There is no such win chance for a tribute!" << '\n';
	
}
