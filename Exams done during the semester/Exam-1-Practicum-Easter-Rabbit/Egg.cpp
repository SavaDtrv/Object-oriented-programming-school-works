#include <iostream>
#include <string>
#include "Egg.h"

using namespace std;

int const DEFAULT_NAME_LENGTH = 1;
int const DEFAULT_COLOR_LENGTH = 1;
int const DEFAULT_GRAMS = 0;
int const GramsInterval[2] = { 0,50 };

Egg::Egg():eggName(nullptr), color(nullptr) {
	this->grams = DEFAULT_GRAMS;
}

Egg::Egg(char* _eggName, char* _color, int _grams) :eggName(nullptr), color(nullptr) {
	this->setEggName(_eggName);
	this->setColor(_color);
	this->setGrams(_grams);
}
Egg::Egg(const Egg& other) {
	copyEgg(other);
}
Egg& Egg::operator=(const Egg& other) {
	if (this != &other) {
		breakEgg();
		copyEgg(other);
	}

	return *this;
}
Egg::~Egg()
{
	breakEgg();
}

const char* Egg::getEggName() const { return this->eggName; }
const char* Egg::getColor() const { return this->color; }
int Egg::getGrams() const { return this->grams; }

void Egg::setEggName(char* newEggName) {
	if (this->eggName != nullptr) {
		delete eggName;
		eggName = nullptr;
	}
	int length = strlen(newEggName);
	this->eggName = new char[length + 1];
	strcpy(this->eggName, newEggName);
}

void Egg::setColor(char* newColor) {
	if (this->color != nullptr) {
		delete color;
		color = nullptr;
	}
	if (checkForRealColor(newColor))
	{
		int length = strlen(newColor);
		this->color = new char[length + 1];
		strcpy(color, newColor);
	}
	else cout << "There is no egg with such color." << '\n';
}

void Egg::setGrams(int newGrams) {
	if (newGrams > GramsInterval[0] && newGrams < GramsInterval[1]) {
		this->grams = newGrams;
	}
	else cout << "The egg too big to be real." << '\n';
}

//Both functions are for checking the correction of the color.
Color Egg::push(char* _color) {
	if (_color == "red") return Red;
	else if (_color == "green") return Green;
	else if (_color == "blue") return Blue;
	else if (_color == "orange") return Orange;
	else if (_color == "yellow") return Yellow;
	else return NoRealColor;
}

bool Egg::checkForRealColor(char* _color) {
	switch (push(_color)) {
	case Red: return true; break;
	case Green: return true; break;
	case Blue: return true; break;
	case Orange: return true; break;
	case Yellow: return true; break;
	case NoRealColor: return false; break;
	}
}