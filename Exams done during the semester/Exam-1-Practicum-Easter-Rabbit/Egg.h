#pragma once
#include <iostream>
#include <string>

using namespace std;

enum Color{Red, Green, Blue, Orange, Yellow, NoRealColor};

class Egg {
	char* eggName;
	char* color;
	int grams; //for how big the egg is.

	void copyEgg(const Egg& other) {
		grams = other.grams;
		setEggName(other.eggName);
		setColor(other.color);
	}

	void breakEgg() {
		delete eggName;
		eggName = nullptr;
		delete color;
		color = nullptr;
	}
public:
	Egg();
	Egg(char*, char*, int);
	Egg(const Egg& other);
	Egg& operator=(const Egg& other);
	~Egg();

	const char* getEggName() const;
	const char* getColor() const;
	int getGrams() const;

	void setEggName(char*);
	void setColor(char*);
	void setGrams(int);

	Color push(char*);
	bool checkForRealColor(char*);

	friend ostream& operator<<(ostream& os, const Egg& egg) {
		os << "Egg name: " << egg.getEggName() << " "
			<< "Egg color: " << egg.getColor() << " "
			<< "Egg grams: " << egg.getGrams() << '\n';

		return os;
	}
};