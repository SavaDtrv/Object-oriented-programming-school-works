#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <string>

using namespace std;

class Tribute {
protected:
	char* name;
	int areaNum;
	double chanceForWin;

	void copyTribute(const Tribute& other) {
		setName(other.name);
		setAreaNum(other.areaNum);
		setChanceForWin(other.chanceForWin);
	}


	void killTribute() {
		delete name;
		name = nullptr;
	}

public:

	Tribute();
	Tribute(char*, int, double);
	Tribute(const Tribute& other);
	Tribute& operator=(const Tribute& other);
	virtual ~Tribute();

	char* getName() const;
	int getArea() const;
	double getChance() const;

	void setName(char* newName);
	void setAreaNum(int newAreaNum);
	void setChanceForWin(double newChance);

	virtual void read() = 0;
	virtual double potential() = 0;
};