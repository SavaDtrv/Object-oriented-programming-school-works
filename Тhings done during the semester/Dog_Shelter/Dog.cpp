#include <iostream>
#include "Dog.h"

using namespace std;

Dog::Dog() {
	dogName = nullptr;
}
Dog::Dog(char* newName) : dogName(nullptr) {

	setDogName(newName);
}
Dog::Dog(const Dog& newDog) : dogName(nullptr) {

	setDogName(newDog.getDogName());
}
Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		removeDogName();
		setDogName(other.getDogName());
	}
	
	return *this;
}
bool Dog::operator==(const Dog& other) {
	return strcmp(this->dogName, other.getDogName);
}
bool Dog::operator!=(const Dog& other) {
	return strcmp(this->dogName, other.getDogName);
}

Dog::~Dog() {
	removeDogName();
}

void Dog::setDogName(char* _dogName) {

	removeDogName();

	int length = strlen(_dogName);
	dogName = new char[length + 1];
	strcpy(dogName, _dogName);
}
char* Dog::getDogName() const {
	return this->dogName;
}

void Dog::removeDogName() {
	if (this != nullptr) {
		delete this;
	}
}