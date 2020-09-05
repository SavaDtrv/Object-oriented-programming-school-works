#include <iostream>
#include "Tank.h"

using namespace std;

int const DEFAULT_CAPACITY = 30;

Tank::Tank() {
	this->capacity = DEFAULT_CAPACITY;
}

Tank::Tank(int _capacity) {

	this->setCapacity(_capacity);
}

int Tank::getCapacity() const {
	return this->capacity;
}

void Tank::setCapacity(int _capacity) {

	if(_capacity >= DEFAULT_CAPACITY) {
		this->capacity = _capacity;
	}
	else cout << "Error, capacity can't be lowet than" << DEFAULT_CAPACITY << "L." << '\n';

}