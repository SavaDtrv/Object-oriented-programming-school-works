#pragma once
#include <iostream>
#include <string>

class Dog {

	char* dogName;

public:

	Dog();
	Dog(char* newName);
	Dog(const Dog& newDog);
	Dog& operator=(const Dog& other);
	bool operator==(const Dog& other);
	bool operator!=(const Dog& other);
	~Dog();

	void removeDogName();
	void setDogName(char*);
	char* getDogName() const;

	friend ostream& operator<<(ostream& output, const Dog& other) {
		
		output << "Name of the dog: " << other.getDogName() << '\n';
		return output;
	}
	friend istream& operator>>(istream& input, const Dog& _other) {
		input.getline(_other.dogName, 10);
		cout << '\n';
	}
};