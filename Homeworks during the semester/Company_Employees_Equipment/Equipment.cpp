#include <iostream>
#include <string>
#include "Equipment.h"

using namespace std;

int const DEFFAULT_LENGTH_NAME = 1;
double const DEFFAULT_EQUIP_PRICE = 0;
double const DEFFAULT_MAINT_COST = 0;
double const LOWEST_EQUIP_PRICE = 0;
double const LOWEST_MAINT_COST = 0;

Equipment::Equipment() {
	this->equipmentName = new char[DEFFAULT_LENGTH_NAME + 1];
	strcpy(this->equipmentName, "");
	this->equipmentPrice = DEFFAULT_EQUIP_PRICE;
	this->eqMaintenanceCost = DEFFAULT_MAINT_COST;
}
Equipment::Equipment(char* _equipmentName, double _equipmentPrice, double _eqMaintenanceCost) {
	this->setEquipmentName(_equipmentName);
	this->setEquipmentPrice(_equipmentPrice);
	this->setEqMaintenanceCost(_eqMaintenanceCost);
}
Equipment::Equipment(const Equipment& other) {
	copyEquipment(other);
}
Equipment& Equipment::operator=(const Equipment& other) {
	if (this != &other) 
	{		
		removeEquipment();
		copyEquipment(other);
	}

	return *this;
}

const char* Equipment::getEquipmentName() const {
	return this->equipmentName;
}
double Equipment::getEquipmentPrice() const {
	return this->equipmentPrice;
}
double Equipment::getEqMaintenanceCost() const {
	return this->eqMaintenanceCost;
}

void Equipment::setEquipmentName(char* newEquipmentName) {
	if (this->equipmentName != nullptr)
	{
		removeEquipment();
	}

	int length = strlen(newEquipmentName);
	this->equipmentName = new char[length + 1];
	strcpy(this->equipmentName, newEquipmentName);
}
void Equipment::setEquipmentPrice(double newEquipmentPrice) {
	if (newEquipmentPrice > LOWEST_EQUIP_PRICE)
	{
		this->equipmentPrice = newEquipmentPrice;
	}
	else cout << "Prices must be higher then 0." << '\n';
}
void Equipment::setEqMaintenanceCost(double newEqMaintCost) {
	if (newEqMaintCost > LOWEST_MAINT_COST)
	{
		this->eqMaintenanceCost = newEqMaintCost;
	}
	else cout << "The maintenance is a gift from the support company." << '\n';
}

Equipment::~Equipment() {
	removeEquipment();
}