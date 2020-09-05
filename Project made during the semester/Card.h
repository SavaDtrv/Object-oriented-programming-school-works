#pragma once
#include "MonsterCard.h"
#include <iostream>

using namespace std;

struct Points
{
	int attack;
	int deffence;
};

enum CardType{
	MonsterCard, 
	MagicCard, 
	TrapCard,
	NoType //for the default constructor
};

//ostream& operator<<(ostream& os, CardType type) {
//	switch (type) {
//	case MonsterCard: return os << "MonsterCard"; break;
//	case MagicCard: return os << "MagicCard"; break;
//	case TrapCard: return os << "TrapCard"; break;
//	default:  return os << "NoType"; break;
//	}
//}

//Iskah da moje da mi printira konkretnata enum stoinost kato tekst
//no mi dava greshka, ako vuzmojno da se vidi za da moga da razbera kude
//burkam ili ako ne burkam zashto dava greshka. Sushtoto e i za dolniq
//enum. Tova iskah da go napravq, tui kato mi iskarva tipovete kato chisla.

enum ElementalType { 
	Water, 
	Earth, 
	Air, 
	Fire,
	NoElement //for the default constructor
};

//ostream& operator<<(ostream& os, ElementalType type) {
//	switch (type) {
//	case Water: return os << "Water"; break;
//	case Earth: return os << "Earth"; break;
//	case Air: return os << "Air"; break;
//	case Fire: return os << "Fire"; break;
//	default:  return os << "NoElement"; break;
//	}
//}

class Card {
protected:
	Points attDeff;
	CardType cardType;

	void copyCard(const Card& other) {
		setAttDeff(other.attDeff.attack, other.attDeff.deffence);
		cardType = other.cardType;
	}

public:
	Card();
	Card(CardType, int, int);
	Card(const Card& other);
	Card& operator=(const Card& other);

	Points getAttDeff() const;
	CardType getCardType() const;

	void setAttDeff(int, int);

	virtual bool onUse(Monster& other) = 0;
};