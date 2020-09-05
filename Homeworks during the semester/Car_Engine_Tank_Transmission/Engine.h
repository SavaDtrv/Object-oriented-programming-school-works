#pragma once
#include <iostream>


class Engine {

	int hp;
	int volume;
	int type;

public:

	enum Type {
		Electrical = 0,
		Hybrid = 1,
		Gasoline = 2,
		Diesel = 3
	};

	Engine();
	Engine(int, int, int);

	int getHp() const;
	int getVolume() const;
	int getType() const;

	void setHp(int);
	void setVolume(int);
	void setType(int);
};