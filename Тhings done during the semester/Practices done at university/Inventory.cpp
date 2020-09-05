#include<iostream>
#include "Inventory.h"

using namespace std;

int const MAX_CAPACITY = 10;

Inventory::Inventory() {
	this->current = -1;
	this->capacity = MAX_CAPACITY;
	this->runes = new Rune[capacity];
}

Inventory::Inventory(const Inventory& other) {
	copy(other);
}

Inventory& Inventory::operator=(const Inventory& other) {
	if (this != &other) {

		remove();
		copy(other);
	}

	return *this;
}

void Inventory::setRunes(Rune* _newRunes, int size) {
	if (this->runes != 0)
	{
		remove();
	}

	this->runes = new Rune[size];
	for (int i = 0; i < size; i++)
	{
		this->runes[i] = _newRunes[i];
	}
}

Inventory::~Inventory() {
	remove();
}