#pragma once
#include <iostream>
#include "MonsterCard.h"
#include "Card.h"

class Magic : public Card {
	ElementalType type;

	void copyMagic(const Magic& other) {
		this->type = other.type;
		this->setAttDeff(other.getAttDeff().attack, other.getAttDeff().deffence);
		this->cardType = other.getCardType();
	}

public:
	Magic();
	Magic(int, int, ElementalType);
	Magic(const Magic& other);
	Magic& operator=(const Magic& other);


	ElementalType getElemType() const;

	friend ostream& operator<<(ostream& os, const Magic& magic) {
		os << "Elemental type: " << magic.getElemType() << '\n'
			<< "Attack: " << magic.getAttDeff().attack << '\n'
			<< "Deffence: " << magic.getAttDeff().deffence << '\n'
			<< "Card type: " << magic.getCardType() << '\n';

		return os;
	}

	friend istream& operator >> (istream& is, Magic& magic) {
		is >> magic.attDeff.attack;
		is >> magic.attDeff.deffence;
		
		cout << "Choose the elemental type of the card(with a number between 1 and 4):" << '\n'
			<< "1: Water" << '\n'
			<< "2: Earth" << '\n'
			<< "3: Air" << '\n'
			<< "4: Fire" << '\n';

		int elemNum = 0;
		cin >> elemNum;

		switch (elemNum)
		{
		case 1: magic.type = Water; break;
		case 2: magic.type = Earth; break;
		case 3: magic.type = Air; break;
		case 4: magic.type = Fire; break;
		default: magic.type = NoElement; break;
		}

		return is;
	}

	bool onUse(Monster& other);

};