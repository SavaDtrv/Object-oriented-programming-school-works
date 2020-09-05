#pragma once
#include <iostream>
#include "Tank.h"
#include "Engine.h"
#include "Transmission.h"

class Car {

	int numSeats;
	int yearMade;
	Tank tank;
	Engine engine;
	Transmission transmission;

public:

	Car();
	Car(int, int, Tank, Engine, Transmission);

	int getNumSeats() const;
	int getYearMade() const;
	Tank getTank() const;
	Engine getEngine() const;
	Transmission getTransmission() const;

	void setNumSeats(int);
	void setYearMade(int);
	void setTank(Tank);
	void setEngine(Engine);
	void setTransmission(Transmission);

	double calculateEmissions();
	double calculateTax();
	double fuelConsumption(int);
	double maxAvailablePath(int);
	int calculateGear(int);
};