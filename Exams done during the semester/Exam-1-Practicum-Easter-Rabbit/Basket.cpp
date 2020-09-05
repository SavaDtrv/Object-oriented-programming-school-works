#include <iostream>
#include <string>
#include "Basket.h"

using namespace std;

int const DEFAULT_CAPACITY = 10;
int const DEFAULT_CURRENT_EGG = 0;

Basket::Basket(char* _ownerName = nullptr) {
	this->setOwnerName(_ownerName);
	capacity = DEFAULT_CAPACITY;
	currentEgg = DEFAULT_CURRENT_EGG;
	eggs = new Egg[capacity];
}
Basket::Basket(const Basket& other) {
	copyBasket(other);
}
Basket& Basket::operator=(const Basket& other) {
	if (this != &other) {
		smashBasket();
		copyBasket(other);
	}
	return *this;
}
Basket::~Basket() {
	smashBasket();
}

const char* Basket::getOwnerName() const { return this->ownerName; }
int Basket::getCapacity() const { return this->capacity; }
int Basket::getCurrentEgg() const { return this->currentEgg; }

void Basket::setOwnerName(char* newName) {
	if (ownerName != nullptr) {
		delete ownerName;
		ownerName = nullptr;
	}

	int length = strlen(newName);
	ownerName = new char[length + 1];
	strcpy(ownerName, newName);
}

void Basket::addEgg(Egg newEgg) {
	add(newEgg);
}
void Basket::trowEgg(char* rottenEggName) {
	int index = 0;
	for (int i = 0; i < currentEgg; i++) {
		if (rottenEggName == eggs[i].getEggName()) {
			index = i;
			break;
		}
	}

	for (int i = index; i < currentEgg; i++) {
		eggs[i] = eggs[i + 1];
	}

	currentEgg--;
}