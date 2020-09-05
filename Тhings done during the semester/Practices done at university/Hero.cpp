#define _CRT_SECURE_NO_WARNINGS
#include "Hero.h"
#include <string.h>

using namespace std;

Hero::Hero()
{
	strcpy(this->name, NULL);
	this->health = 10;
	this->level = 1;
	this->experience = 0;
	this->strength = 0;
	this->speed = 0;
	this->intellect = 0;
}

Hero::Hero(Hero const& other)
{
	strcpy(this->name, other.name);
	this->health = other.health;
	this->level = other.level;
	this->experience = other.experience;
	this->strength = other.strength;
	this->speed = other.speed;
	this->intellect = other.intellect;
}

Hero::Hero(char* _name, int _health, unsigned _level, unsigned _experience,
	int _strength, int _speed, int _intellect) {

	this->setName(_name);
	this->sethealth(_health);
	this->setLevel(_level);
	this->setExperience(_experience);
	this->setStrength(_strength);
	this->setSpeed(_speed);
	this->setIntellect(_intellect);
}

char* Hero::getName() const { return this->name; }
int Hero::getHealth()const { return this->health; }
unsigned Hero::getLevel() const { return this->level; }
unsigned Hero::getExperience() const { return this->experience; }
int Hero::getStrength() const { return this->strength; }
int Hero::getSpeed() const { return this->speed; }
int Hero::getIntellect() const { return this->intellect; }

void Hero::setName(char* newName)
{
	if (this->name != NULL) {
		delete this->name;
	}

	this->name = new char[strlen(newName) + 1];
	strcpy(this->name, newName);
}

void Hero::sethealth(int _health)
{
	if (_health > 0)
	{
		this->health = _health;
	}
}

void Hero::setLevel(unsigned _level)
{
	if (_level >= this->level)
	{
		this->level = _level;
	}
}

void Hero::setExperience(unsigned _experience)
{
	if (_experience >= 0) {
		this->experience = _experience;
	}
}

void Hero::setStrength(int _strength)
{
	this->strength = _strength;
}

void Hero::setSpeed(int _speed)
{
	if (_speed > 0)
	{
		this->speed = _speed;
	}
}

void Hero::setIntellect(int _intellect)
{
	if (_intellect > 0)
	{
		this->intellect = _intellect;
	}
	else
		cout << "Not a valid value!";
}

void Hero::print()
{
	cout << '\t' << "Your hero details are:" << '\n';
	cout << " " << "Hero name: " << this->getName() << '\n';
	cout << " " << "Hero health: " << this->getHealth() << '\n';
	cout << " " << "Hero level: " << this->getLevel() << '\n';
	cout << " " << "Hero experience: " << this->getExperience() << '\n';
	cout << " " << "Hero strength: " << this->getStrength() << '\n';
	cout << " " << "Hero speed: " << this->getSpeed() << '\n';
	cout << " " << "Hero intellect: " << this->getIntellect() << '\n' << '\n';
}

