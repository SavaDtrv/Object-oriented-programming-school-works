#pragma once
#include "Card.h" 

int const NAME_LENGTH_FOR_INPUT = 42;

class Monster : public Card {
	char* name;
	ElementalType type;

	void copyMonster(const Monster& other){
		this->setName(other.name);
		this->type = other.type;
		this->setAttDeff(other.getAttDeff().attack, other.getAttDeff().deffence);
		this->cardType = other.getCardType();
	}

	void killMonster() {
		delete name;
		name = nullptr;
	}

public:
	Monster();
	Monster(char*, int, int, ElementalType);
	Monster(const Monster& other);
	Monster& operator=(const Monster& other);
	~Monster();

	const char* getName() const;
	void setName(char*);

	ElementalType getElemType() const;

	friend ostream& operator<<(ostream& os, const Monster& monster) {
		os << "Name: " << monster.getName() << '\n'
			<< "Elemental type: " << monster.getElemType() << '\n'
			<< "Attack: " << monster.getAttDeff().attack << '\n'
			<< "Deffence: " << monster.getAttDeff().deffence << '\n'
			<< "Card type: " << monster.getCardType() << '\n';

		return os;
	}

	friend istream& operator >> (istream& is, Monster& monster) {
		is.getline(monster.name, NAME_LENGTH_FOR_INPUT);

		cout << "Choose the elemental type of the card(with a number between 1 and 4):" << '\n'
			<< "1: Water" << '\n'
			<< "2: Earth" << '\n'
			<< "3: Air" << '\n'
			<< "4: Fire" << '\n';

		int elemNum = 0;
		cin >> elemNum;

		switch (elemNum)
		{
			case 1: monster.type = Water; break;
			case 2: monster.type = Earth; break;
			case 3: monster.type = Air; break;
			case 4: monster.type = Fire; break;
			default: monster.type = NoElement; break;
		}

		is >> monster.attDeff.attack;
		is >> monster.attDeff.deffence;

		return is;
	}

	bool onUse(Monster& other);
};