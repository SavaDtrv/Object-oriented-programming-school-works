#pragma once
#include <iostream>
#include "MonsterCard.h"
#include "Card.h"

class Trap : public Card {
	void copyTrap(const Trap& other) {
		this->setAttDeff(other.getAttDeff().attack, other.getAttDeff().deffence);
		this->cardType = other.getCardType();
	}
public:
	Trap();
	Trap(int, int);
	Trap(const Trap& other);
	Trap& operator=(const Trap& other);

	friend ostream& operator<<(ostream& os, const Trap& trap) {
		os << "Attack: " << trap.getAttDeff().attack << '\n'
			<< "Deffence: " << trap.getAttDeff().deffence << '\n'
			<< "Card type: " << trap.getCardType() << '\n';

		return os;
	}

	friend istream& operator >> (istream& is, Trap& trap) {
		is >> trap.attDeff.attack;
		is >> trap.attDeff.deffence;

		return is;
	}

	bool onUse(Monster& other);
};