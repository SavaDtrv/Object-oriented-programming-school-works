#pragma once
#include <iostream>

class Tank {

	int capacity;

public:

	Tank();
	Tank(int);

	int getCapacity() const;
	void setCapacity(int);

};