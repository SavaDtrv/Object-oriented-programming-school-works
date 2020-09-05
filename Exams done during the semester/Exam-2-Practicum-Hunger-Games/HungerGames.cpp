#include "HungerGames.h"
#include <iostream>
#include <string>

using namespace std;

const int DEFAULT_CURRENT = 0;
const int DEFAULT_CAP = 10;

HungerGames::HungerGames() {
	capacity = DEFAULT_CAP;
	currentTribute = DEFAULT_CURRENT;
	tributes = new Tribute*[capacity];
}

HungerGames::~HungerGames() {
	killTributes();
}

void HungerGames::addIn(Tribute & newTribute) {
	add(newTribute);
}

Tribute& HungerGames::winnerInHungerGames() {
	Tribute* tmpTribure = tributes[0];

	for (int i = 1; i < currentTribute; i++) {
		
		if (tributes[i]->potential() > tmpTribure->potential()) {
			tmpTribure = tributes[i];
		}
	}

	return *tmpTribure;
}
