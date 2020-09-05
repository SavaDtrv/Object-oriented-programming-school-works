#pragma once
#include <iostream>

class Rune {

	int strength;
	int speed;
	int intellect;

public:
	Rune();
	Rune(const Rune& other);
	Rune(int, int, int);

	int getStrength() const;
	int getSpeed() const;
	int getIntellect() const;

	void setStrength(int);
	void setSpeed(int);
	void setIntellect(int);
};