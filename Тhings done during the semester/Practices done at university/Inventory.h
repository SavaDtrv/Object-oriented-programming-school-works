#pragma once
#include <iostream>
#include "Rune.h"

class Inventory {

	Rune* runes;
	int current; //amount of elements in runes
	int capacity; //max available elements in runes

	void copy(const Inventory& other) {

		this->current = other.current;
		this->capacity = other.capacity;

		this->runes = new Rune[capacity];
		for (int i = 0; i <= current; i++)
		{
			this->runes[i] = other.runes[i];
		}
	}

	void resize() {

		this->capacity = capacity*1.5;
		Rune *runes2 = new Rune[capacity];
		for (int i = 0; i < capacity; i++) {
			runes2[i] = runes[i];
		}

		remove();
		runes = runes2;
	}
	
	void add(Rune const& rune) {

		if (current = capacity - 1)
		{
			resize();
		}

		current++;
		runes[current] = rune;
	}
	void remove() {
		delete runes;
	}

public:
	Inventory();
	Inventory(const Inventory& other);
	Inventory& operator=(const Inventory& other);

	void setRunes(Rune*, int);

	~Inventory();
};