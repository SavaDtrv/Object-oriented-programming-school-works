#include <iostream>
#include "Rune.h"

using namespace std;

Rune::Rune() {
	this->strength = 1;
	this->speed = 1;
	this->intellect = 1;
}
Rune::Rune(const Rune& other) {
	this->setStrength(other.strength);
	this->setSpeed(other.speed);
	this->setIntellect(other.intellect);
}
Rune::Rune(int _strength, int _speed, int _intellect) {
	this->setStrength(_strength);
	this->setStrength(_speed);
	this->setStrength(_intellect);
}

int Rune::getStrength() const {
	return this->strength;
}
int Rune::getSpeed() const {
	return this->speed;
}
int Rune::getIntellect() const {
	return this->intellect;
}

void Rune::setStrength(int _strength) {
	if (_strength > 0) {
		this->strength = _strength;
	}
	else
		cout << "Strength cannot be negative." << '\n';
}
void Rune::setSpeed(int _speed) {
	if (_speed > 0) {
		this->speed = _speed;
	}
}
void Rune::setIntellect(int _intellect) {
	if (_intellect > 0) {
		this->intellect = _intellect;
	}
}