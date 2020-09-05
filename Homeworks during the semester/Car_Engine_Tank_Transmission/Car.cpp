#include <iostream>
#include "Car.h"

using namespace std;

int const MIN_YEAR_MADE = 1850;

int const MIN_NUMBER_SEATS = 2;
int const MAX_NUMBER_SEATS = 8;

Car::Car() {
	this->numSeats = MIN_NUMBER_SEATS;
	this->yearMade = MIN_YEAR_MADE;
	Tank();
	Engine();
	Transmission();
}
Car::Car(int _numSeats, int _yearMade, Tank _tank, Engine _engine, Transmission _transmission) {
	this->setNumSeats(_numSeats);
	this->setYearMade(_yearMade);
	this->setTank(_tank);
	this->setEngine(_engine);
	this->setTransmission(_transmission);
}

int Car::getNumSeats() const {
	return this->numSeats;
}

int Car::getYearMade() const {
	return this->yearMade;
}

Tank Car::getTank() const {
	return this->tank;
}
Engine Car::getEngine() const {
	return this->engine;
}
Transmission Car::getTransmission() const {
	return this->transmission;
}

void Car::setNumSeats(int _numSeats) {
	if (_numSeats >= MIN_NUMBER_SEATS && _numSeats <= MAX_NUMBER_SEATS) {
		this->numSeats = _numSeats;
	}
	else cout << "Error. Cars have between " << MIN_NUMBER_SEATS << " and " << MAX_NUMBER_SEATS << "seats." << '\n';
}

void Car::setYearMade(int _yearMade) {
	if (_yearMade >=MIN_YEAR_MADE) {
		this->yearMade = _yearMade;
	}
	else cout << "Error. Cars year made is " << MIN_YEAR_MADE << "+ ." << '\n';
}

void Car::setTank(Tank _tank) {
	this->tank.setCapacity(_tank.getCapacity());
}

void Car::setEngine(Engine _engine) {
	this->engine.setHp(_engine.getHp());
	this->engine.setType(_engine.getType());
	this->engine.setVolume(_engine.getVolume());
}

void Car::setTransmission(Transmission _transmission) {
	this->transmission.setGearLevel(_transmission.getGearLevel());
	this->transmission.setType(_transmission.getType());
}

double Car::calculateEmissions() {
	return engine.getHp()*engine.getVolume()*engine.getType();
}

double Car::calculateTax() {
	if (engine.getHp() <= 105) {
		if (2017 - getYearMade() > 14)
			return (engine.getHp() * 0.8) * 1;
		else if (2017 - getYearMade() >= 5 && 2017 - getYearMade() <= 14)
			return (engine.getHp() * 0.8) * 1.5;
		else 
			return (engine.getHp() * 0.8) * 2.8;
	}
	else {
		if (2017 - getYearMade() > 14)
			return (engine.getHp() * 0.9) * 1;
		else if (2017 - getYearMade() >= 5 && 2017 - getYearMade() <= 14)
			return (engine.getHp() * 0.9) * 1.5;
		else
			return (engine.getHp() * 0.9) * 2.8;
	}
}

int Car::calculateGear(int speed) {
	if (speed > 0 && speed <= 20) return 1;
	else if (speed > 20 && speed <= 30) return 2;
	else if (speed > 30 && speed <= 50) return 3;
	else if (speed > 50 && speed <= 80) return transmission.getGearLevel() > 4 ? 4 : transmission.getGearLevel();
	else if (speed > 80 && speed <= 200) return transmission.getGearLevel() > 5 ? 5 : transmission.getGearLevel();
	else return transmission.getGearLevel() == 6 ? 6 : transmission.getGearLevel();
}

double Car::fuelConsumption(int speed) {
	return (calculateGear(speed)*engine.getHp()*(engine.getVolume() / 1000)) / 100;
}

double Car::maxAvailablePath(int speed) {
	return (tank.getCapacity() / fuelConsumption(speed)) * 100;
}