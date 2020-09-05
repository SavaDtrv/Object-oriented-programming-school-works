#include <iostream>
#include "Transmission.h"

using namespace std;

Transmission::Transmission() {
	this->type = 1;
	this->gearLevel = 4;
}
Transmission::Transmission(int _type, int _gearLevel) {
	this->setType(_type);
	this->setGearLevel(_gearLevel);
}

int Transmission::getType() const {
	return this->type;
}
int Transmission::getGearLevel() const {
	return this->gearLevel;
}

void Transmission::setType(int _type) {
	if (_type == 0 || _type == 1) {
		this->type = _type;
	}
	else cout << "Error. No such transmission type." << '\n';
}
void Transmission::setGearLevel(int _gearLevel) {
	if (_gearLevel >= 3 && _gearLevel <= 6) {
		this->gearLevel = _gearLevel;
	}
	else cout << "Error. No such gear level." << '\n';
}

