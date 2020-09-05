//#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <string>
#include "Hero.h"
#include "Inventory.h"

using namespace std;

class NPC {
public:
	char name[101];
	int health;

	NPC(){
		strcpy(name, "NPC");
	}

	virtual void printName() {
		cout << name;
	}

	friend ostream& operator<<(ostream& os, NPC const& npc) {
		os << "NPC";
		return os;
	}

};

class Attackable : public virtual NPC {
	int attackDamage;

public:
	void attack(Hero const& h) {
		//Metod za ataki na boss-a kum geroq
	}

	void printName() {
		cout << "Attackable";
	}

	friend ostream& operator<<(ostream& os, Attackable const& att) {
		os << (NPC)att;
		os << "Attackable";
		return os;
	}
};

class Lootable :public virtual NPC {
	Inventory inv;

public:
	void loot(Hero const& h) {

	}

	void printName() {
		cout << "Lootable";
	}

	friend ostream& operator<<(ostream& os, Lootable const& loot) {
		os <<(NPC)loot;
		os << "Lootable";
		return os;
	}
};

class Boss : public Attackable, public Lootable{

public:
	void printName();

	friend ostream& operator<<(ostream& os, Boss const& boss) {
		os << (Attackable)boss;
		os << (Lootable)boss;
		os << "Boss";
		return os;
	}
};