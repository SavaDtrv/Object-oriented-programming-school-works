//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "TrapCard.h"
#include "Card.h"

using namespace std;

int const DEFFAULT_ATT_DEFF_POINTS = 0;

Trap::Trap(): Card() {}
Trap::Trap(int _attack, int _deffence)
	:Card(TrapCard, _attack, _deffence) {}

Trap::Trap(const Trap& other) {
	copyTrap(other);
}
Trap& Trap::operator=(const Trap& other) {		
	copyTrap(other);

	return *this;
}

bool Trap::onUse(Monster & other)
{
	other.setAttDeff(other.getAttDeff().attack - getAttDeff().attack,
		other.getAttDeff().deffence - getAttDeff().deffence);
	return true;
}
