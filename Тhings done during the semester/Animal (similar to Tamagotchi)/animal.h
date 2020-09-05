#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>

using namespace std;


class Animal {

	double weight;
	int days_Growing;
	double food_Need;
	double water_Need;
	char* name;

public:
	Animal() {
		weight = 0;
		days_Growing = 0;
		food_Need = 0;
		water_Need = 0;
		name = nullptr;
	}

	Animal(char* _name, double _weight, int _days_Growing, double _food_Need, double _water_Need) {
		set_weight(_weight);
		set_days_Gr(_days_Growing);
		set_food_Need(_food_Need);
		set_water_Need(_water_Need);
		set_name(_name);
	}

		//selectors
	double get_weight() { return weight; }
	int get_days_Growing() { return days_Growing; }
	double get_food_Need() { return food_Need; }
	double get_water_Need() { return water_Need; }
	char* get_name() { return name; }

		//mutators
	void set_weight(double new_weight) {
		if (new_weight < 0) {
			cout << "Weight cannot be negative!" << '\n';
			return;
		}

		weight = new_weight;
	}
	void set_days_Gr(int new_days_Gr) {
		if (new_days_Gr <= 0) {
			cout << "The animal is dead." << '\n';
			return;
		}
		
		days_Growing = new_days_Gr;
	}
	void set_food_Need(double new_food_Need) {
		if (new_food_Need < 0) {
			cout << "Food amount cannot be negative." << '\n';
			return;
		}

		food_Need = new_food_Need;
	}
	void set_water_Need(double new_water_Need) {
		if (new_water_Need < 0) {
			cout << "Water amount cannot be negative." << '\n';
			return;
		}

		water_Need = new_water_Need;
	}
	void set_name(char* new_name) {
		if (name != nullptr) {
			delete name;
		}

		name = new char[strlen(new_name) + 1];
		strcpy(name, new_name);
	}

	void needs() {
		cout << "The animal needs " << get_food_Need() << " KG food per day and "
			<< get_water_Need() << " L water per day." << '\n';
	}

	void description() {
		cout << "Type of the animal: " << get_name() << '\n';
		cout << "Animal weight: " << get_weight() << " KG" << '\n';
		cout << "The animal needs " << get_days_Growing() << " days to maturity." << '\n';
		needs();
	}

	void feed(double lw_ic_water, double lw_ic_food) {
		if (lw_ic_water == get_water_Need() && lw_ic_food == get_food_Need()) {
			cout << "The " << get_name() << " will gain weight." << '\n';
		}
		if (lw_ic_water > get_water_Need() && lw_ic_food > get_food_Need()) {
			cout << "The " << get_name() << " is gaining weight. If you continue overfeeding the animal "
				<< "there is a high chance it will die. Please lower the animal food and water intake, "
				<< "at least, to the needed amount per day. Respectively " << get_food_Need()
				<< " KG and " << get_water_Need() << " L per day." << '\n';
		}
		if (lw_ic_water < get_water_Need() && lw_ic_food < get_food_Need()) {
			cout << "The " << get_name() << " is losing weight. If you continue underfeeding the animal "
				<< "there is a high chance it will die. Please increase the animal food and water intake, "
				<< "at least, to the needed amount per day. Respectively " << get_food_Need()
				<< " KG and " << get_water_Need() << " L per day." << '\n';
		}
		if (lw_ic_water > get_water_Need() && lw_ic_food <= get_food_Need()) {
			cout << "The " << get_name() << " is losing weight due to lower need of food because "
				<< "its stomach is full of water and there is no room "
				<< "for the food to be intaken. Please lower the amount of water to "
				<< get_water_Need() << " L per day and if needed increase the amount of food, " 
				<< "at least, to the needed minimum per day: "<< get_food_Need() << " KG. If you want "
				<< "the animal to gain some weight increase the amount of food but not too much."<< '\n';
		}
		if (lw_ic_water <= get_water_Need() && lw_ic_food > get_food_Need()) {
			cout << "The "<< get_name() << " is gaining weight due to lower metabolism "
				<< "because of the lower amount of water taken per day. Increase "
				<< "the amount of water per day to " << get_water_Need() << " L and if needed "
				<< "lower the amount of food intake to " << get_food_Need() << " KG." << '\n';
		}
		
		cout << '\n' << '\n' << "Animals need specific care. Each different animal needs different care like amount of food, "
			<< "water, some need walks, petting or something else, different place to live etc. Take care of the animals as they are "
			<< "children of the Mother Nature!" << '\n';
	}
};