#pragma once
#include <iostream>
#include <string>
#include "Tribute.h"

using namespace std;

class MaleTribute : public Tribute {
	int malePower;

	void copyMale(const MaleTribute& other) {
		setName(other.getName());
		setAreaNum(other.getArea());
		setChanceForWin(other.getChance());
		setMalePower(other.malePower);
	}

public:

	MaleTribute();
	MaleTribute(char* _name, int _areaNum, double _chanceForWin, int _malePower);
	MaleTribute(const MaleTribute& other);
	MaleTribute& operator=(const MaleTribute& other);

	void setMalePower(int newMalePower);

	void read(MaleTribute& newMale);
	double potential();
};