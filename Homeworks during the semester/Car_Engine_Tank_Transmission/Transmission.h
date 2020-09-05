#pragma once
#include <iostream>

class Transmission {

	int type;
	int gearLevel;
	
public:

	enum TransType {
		Automatic = 0,
		Manual = 1
	};

	Transmission();
	Transmission(int, int);

	int getType() const;
	int getGearLevel() const;

	void setType(int);
	void setGearLevel(int);
};