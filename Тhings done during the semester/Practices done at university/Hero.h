#pragma once
#include <iostream>

using namespace std;

class Hero {
	char* name;
	int health;
	unsigned level;
	unsigned experience;
	int strength;
	int speed;
	int intellect;

public:

	Hero();
	Hero(Hero const& other);
	Hero(char*, int, unsigned, unsigned, int, int, int);

	char* getName() const;
	int getHealth() const;
	unsigned getLevel() const;
	unsigned getExperience() const;
	int getStrength() const;
	int getSpeed() const;
	int getIntellect() const;

	void setName(char*);
	void sethealth(int);
	void setLevel(unsigned);
	void setExperience(unsigned);
	void setStrength(int);
	void setSpeed(int);
	void setIntellect(int);
	
	friend ostream& operator<<(ostream& os, Hero const& hero) {
		os << '\t' << "Your Warrior hero details are:" << '\n';
		os << " " << "Name: " << hero.getName() << '\n';
		os << " " << "Health: " << hero.getHealth() << '\n';
		os << " " << "Level: " << hero.getLevel() << '\n';
		os << " " << "Experience: " << hero.getExperience() << '\n';
		os << " " << "Strength: " << hero.getStrength() << '\n';
		os << " " << "Speed: " << hero.getSpeed() << '\n';
		os << " " << "Intellect: " << hero.getIntellect() << '\n' << '\n';

		return os;
	}

	void print();
};


class IntellectBuff {
	int capacity; // amount of jokers
	int remaining; // remaining jokers
};


template <typename T>
//template <typename T, typename K> //if we want to have more than 1 buff, in the class {K buff;}
class Shapeshifter : public Hero {
	int energy;
	T buff;

public:
	Shapeshifter(char* _name, int _health, unsigned _level, unsigned _experience, int _strength, int _speed, int _intellect, int _energy)
		:Hero(_name, _health, _level, _experience, _strength, _speed, _intellect), energy(_energy) {} //no setters.

	Shapeshifter() = default; //for using default constructor, since we did not make one.

	void print() {
		//heroDescription(); If the names of the prints are different.
		Hero::print();
		cout << "Energy: " << this->energy << '\n';
	}

	void shapeShift();

};

class Warrior :protected Hero {
	int rage;
public:
	friend ostream& operator<<(ostream& os, Warrior const & warr) { //istream - no const
		/*os << '\t' << "Your Warrior hero details are:" << '\n';
		os << " " << "Name: " << warr.getname() << '\n';
		os << " " << "Health: " << warr.gethealth() << '\n';
		os << " " << "Level: " << warr.getlevel() << '\n';
		os << " " << "Experience: " << warr.getexperience() << '\n';
		os << " " << "Strength: " << warr.getstrength() << '\n';
		os << " " << "Speed: " << warr.getspeed() << '\n';
		os << " " << "Intellect: " << warr.getintellect() << '\n' << '\n';*/

		os << (Hero)warr; //only from bigger to smaller type (same as basic types)
		os << " " << "Rage: " << warr.rage << '\n';

		return os;

	}
};

class Mage :public Hero {

};