#include <iostream>
#include "Card.h"

using namespace std;

const int DEFAULT_ATT_DEFF = 0;

Card::Card() {
	attDeff.attack = DEFAULT_ATT_DEFF;
	attDeff.deffence = DEFAULT_ATT_DEFF;
	cardType = NoType;
}
Card::Card(CardType _cardType, int _attack, int _deffence) {
	cardType = _cardType;
	setAttDeff(_attack, _deffence);
}
Card::Card(const Card& other) {
	copyCard(other);
}
Card& Card::operator=(const Card& other) {
	copyCard(other);

	return *this;
}

Points Card::getAttDeff() const {
	return this->attDeff;
}
CardType Card::getCardType() const {
	return this->cardType;
}

void Card::setAttDeff(int newAttack, int newDeffence) {
	if (newAttack >= 0 && newDeffence >= 0)
	{
		attDeff.attack = newAttack;
		attDeff.deffence = newDeffence;
	}
	else cout << "Cards cannot have negative values for attack and deffence"
		<< "Please input possitive values." << '\n';
}