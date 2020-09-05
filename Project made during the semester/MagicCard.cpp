//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "MagicCard.h"
#include "Card.h" 

using namespace std;

int const DEFFAULT_LENGTH_NAME = 2;
int const DEFFAULT_ATT_DEFF_POINTS = 0;

Magic::Magic():Card()
{
	type = NoElement;
}
Magic::Magic(int _attack, int _deffence, ElementalType _type)
	:Card(MagicCard, _attack, _deffence) {
	type = _type;
}
Magic::Magic(const Magic& other) {
	copyMagic(other);
}
Magic& Magic::operator=(const Magic& other) {
	copyMagic(other);
	
	return *this;
}

ElementalType Magic::getElemType() const
{
	return this->type;
}

bool Magic::onUse(Monster & other)
{
	if (type == other.getElemType()) {
		other.setAttDeff((other.getAttDeff().attack + getAttDeff().attack),
			(other.getAttDeff().deffence + getAttDeff().deffence));
		return true;
	}
	else
		return false;
}
