#pragma once
#include <iostream>

using namespace std;

class Equipment {
	char* equipmentName;
	double equipmentPrice;
	double eqMaintenanceCost;

	void copyEquipment(const Equipment& other) {
		setEquipmentName(other.equipmentName);
		setEquipmentPrice(other.equipmentPrice);
		setEqMaintenanceCost(other.eqMaintenanceCost);
	}

	void removeEquipment() {
		delete equipmentName;
		equipmentName = nullptr;
	}

public:
	Equipment();
	Equipment(char*, double, double);
	Equipment(const Equipment& other);
	Equipment& operator=(const Equipment& other);
	~Equipment();

	const char* getEquipmentName() const;
	double getEquipmentPrice() const;
	double getEqMaintenanceCost() const;

	void setEquipmentName(char*);
	void setEquipmentPrice(double);
	void setEqMaintenanceCost(double);
};