//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "MonsterCard.h"
#include "Card.h"

using namespace std;

const int DEFAULT_NAME_LENGTH = 2;
int const DEFFAULT_LENGTH_NAME = 2;
int const DEFFAULT_ATT_DEFF_POINTS = 0;

Monster::Monster(): Card()
{
	name = new char[DEFAULT_NAME_LENGTH];
	strcpy(name, "");
	type = NoElement;
}
Monster::Monster(char* _name, int _attack, int _deffence, ElementalType _type)
	:Card(MonsterCard, _attack, _deffence)
{
	setName(_name);
	type = _type;
}
Monster::Monster(const Monster& other) {
	copyMonster(other);
}
Monster& Monster::operator=(const Monster& other) {
	if (this != &other) {
		killMonster();
		copyMonster(other);
	}

	return *this;
}

Monster::~Monster()
{
	killMonster();
}

const char* Monster::getName() const {
	return this->name;
}

ElementalType Monster::getElemType() const
{
	return this->type;
}

bool Monster::onUse(Monster & other)
{
	if (getAttDeff().attack > other.getAttDeff().deffence && 
		getAttDeff().deffence > other.getAttDeff().attack) {
		return true;
	}
	else
		return false;

//Tozi metod vrushta true samo kogato nasheto chudovishte shte ocelee
//tova e nai-prostoq nachin na realizaciq. Ne e efektiven v realna igra,
//tui kato taka moje da produlji prez celiq cikul na igra.
}

void Monster::setName(char* newName) {
	if (name != nullptr)
	{
		killMonster();
	}

	int length = strlen(newName);
	name = new char[length + 1];
	strcpy(name, newName);
}
