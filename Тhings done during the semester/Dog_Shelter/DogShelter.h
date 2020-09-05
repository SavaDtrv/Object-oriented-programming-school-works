#pragma once
#include <iostream>
#include "Dog.h"
#include <fstream>

using namespace std;

class DogShelter {

	Dog* dogs;
	int numDogs;
	char* shelterName;

	void destroyShelter();
	void copyShelter(const DogShelter& other);
public:
	DogShelter();
	DogShelter(char*, int);
	DogShelter(const DogShelter& other);
	DogShelter& operator=(const DogShelter &other);
	~DogShelter();

	void setShelterName(char*);
	char* getShelterName() const;

	Dog operator[](int);
	Dog getDog(int);
	bool operator==(const DogShelter& other);
	bool operator!=(const DogShelter& other);
	
	friend ostream& operator<<(ostream& output, const DogShelter& other) {
		output << other.numDogs << " and name: " << other.getDogName() << '\n';
		return output;
	}

	friend istream& operator >> (istream& input, const DogShelter& _other) {
		//_other.setShelterName("GreenPeaceShelter");
		input.getline(_other.shelterName, 10);
		input >> _other.numDogs;
		cout << "\n";
	}
};