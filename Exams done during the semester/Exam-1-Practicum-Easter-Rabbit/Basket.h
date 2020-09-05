#pragma once
#include <iostream>
#include <string>
#include "Egg.h"

using namespace std;

int const CAPACITY_MULTIPLIER = 2;

class Basket {
	char* ownerName;
	Egg* eggs;
	int capacity;
	int currentEgg;

	void copyBasket(const Basket& other) {
		
		this->setOwnerName(other.ownerName);
		this->capacity = other.capacity;
		this->currentEgg = other.currentEgg;
		eggs = new Egg[capacity];

		for (int i = 0; i < currentEgg; i++) {
			eggs[i] = other.eggs[i];
		}
	}


	void resize() {
		
		this->capacity *= CAPACITY_MULTIPLIER;
		Egg* tmpEggs = new Egg[capacity];
		for (int i = 0; i < this->currentEgg; i++)
		{
			tmpEggs[i] = this->eggs[i];
		}

		delete[] eggs;
		this->eggs = tmpEggs;
	}

	void add(Egg newEgg) {
		
		if (currentEgg == capacity - 1) {
			resize();
		}

		eggs[currentEgg] = newEgg;
		currentEgg++;
	}

	void smashBasket() {
		delete ownerName;
		ownerName = nullptr;
		delete[] eggs;
		eggs = nullptr;
	}
public:
	Basket(char*);
	Basket(const Basket& other);
	Basket& operator=(const Basket& other);
	~Basket();

	const char* getOwnerName() const;
	int getCapacity() const;
	int getCurrentEgg() const;

	void setOwnerName(char* newName);

	void addEgg(Egg);
	void trowEgg(char*);

	friend ostream& operator<<(ostream& os, const Basket& basket) {
		os << '\t' << basket.getOwnerName() << '\n';
		os << "Eggs characteristics: " << '\n';
		
		for (int i = 0; i < basket.currentEgg; i++) {
			os << i << ": " << basket.eggs[i];
		}

		return os;
	}
};
