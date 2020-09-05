#pragma once
#include <iostream>
#include "Tribute.h"
#include "GirlTribute.h"
#include "MaleTribute.h"

using namespace std;

class HungerGames {
	Tribute** tributes;
	int capacity;
	int currentTribute;

	void add(Tribute& newTribute) {
		if (currentTribute == capacity - 1) {
			resize();
		}

		tributes[currentTribute] = &newTribute;
		currentTribute++;
	}

	void resize() {
		
		capacity *= 2;
		if (currentTribute * 2 > capacity) {
			capacity /= 2;
		}

		Tribute** tributes1 = new Tribute*[capacity];
		for (int i = 0; i < currentTribute; i++) {
			tributes1[i] = tributes[i];
		}

		killTributes();
		tributes = tributes1;
	}

	void killTributes() {

		for (int i = 0; i < currentTribute; i++) {
			delete tributes[i];
		}

		delete[] tributes;
	}
public:

	HungerGames();
	~HungerGames();

	void addIn(Tribute& newTribute);

	Tribute& winnerInHungerGames();

};