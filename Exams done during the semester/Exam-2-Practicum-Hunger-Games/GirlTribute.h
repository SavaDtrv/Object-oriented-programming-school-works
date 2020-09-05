#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "Tribute.h"
#include <iostream>
#include <string>

using namespace std;

class GirlTribute : public Tribute {
	char* speciality;
	
	void copyGirl(const GirlTribute& other) {
		setName(other.getName());
		setAreaNum(other.getArea());
		setChanceForWin(other.getChance());
		setSpeciality(other.speciality);
	}

	void killGirlTribute() {
		delete speciality;
		speciality = nullptr;
	}

public:

	GirlTribute();
	GirlTribute(char* _name, int _areaNum, double _chanceForWin, char* _speciality);
	GirlTribute(const GirlTribute& other);
	GirlTribute& operator=(const GirlTribute& other);
	~GirlTribute();
	
	void setSpeciality(char* newSpeciality);

	void read(GirlTribute& newGirl);
	double potential();
};