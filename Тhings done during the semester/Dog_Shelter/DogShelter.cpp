#include <iostream>
#include <string>
#include <fstream>
#include "DogShelter.h"

using namespace std;

#define NUMDOGS_CAP 0;

DogShelter::DogShelter() {
	shelterName = nullptr;
	numDogs = NUMDOGS_CAP;
	dogs = nullptr;
}
DogShelter::DogShelter(char* _shelterName, int _numDogs) : shelterName(nullptr), dogs(nullptr) {
	setShelterName(_shelterName);
	this->numDogs = _numDogs;

	dogs = new Dog[numDogs];
	for (int dogIndex = 0; dogIndex < numDogs;dogIndex++) {
		dogs[dogIndex] = Dog();
	}
}
DogShelter::DogShelter(const DogShelter& newShelter) : shelterName(nullptr), dogs(nullptr) {
	copyShelter(newShelter);
}
DogShelter& DogShelter::operator=(const DogShelter &other) {
	
	if (this != &other) {
		
		destroyShelter();
		copyShelter(other);
	}

	return *this;
}
DogShelter::~DogShelter() {
	destroyShelter();
}

void DogShelter::setShelterName(char* newName) {
	if (shelterName != nullptr) {
		destroyShelter();
	}

	int length = strlen(newName);
	shelterName = new char[length + 1];
	strcpy(shelterName, newName);
}

char* DogShelter::getShelterName() const {
	return this->shelterName;
}

Dog DogShelter::operator[](int index) {
	getDog(index);
}

bool DogShelter::operator==(const DogShelter& other) {
	return this->numDogs == other.numDogs;
}

bool DogShelter::operator!=(const DogShelter& other) {
	return !this->operator==(other);
}

Dog DogShelter::getDog(int index) {
	if (index < 0 || index >= numDogs) {
		return Dog();
	}

	return dogs[index];
}

void DogShelter::destroyShelter() {
	if (this != nullptr) {
		delete this;
	}
}

void DogShelter::copyShelter(const DogShelter& other) {
	
	setShelterName(other.getShelterName());
	numDogs = newShelter.numDogs;
	
	dogs = new Dog[numDogs];
	for (int dogIndex = 0; dogIndex < numDogs;dogIndex++) {
		dogs[dogIndex] = other.dogs[dogIndex];
	}	
}