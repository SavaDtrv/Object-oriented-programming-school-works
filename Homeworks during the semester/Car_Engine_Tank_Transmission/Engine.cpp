#include <iostream>
#include "Engine.h"

using namespace std;

int const DEFAULT_HP = 45;
int const MAX_TYPE_RANGE = 3;

Engine::Engine() {

	this->hp = DEFAULT_HP;
	this->volume = 0;
	this->type = 0;
}
Engine::Engine(int _hp, int _volume, int _type) {
	
	this->setHp(_hp);
	this->setVolume(_volume);
	this->setType(_type);
}

int Engine::getHp() const {
	return this->hp;
}
int Engine::getVolume() const {
	return this->volume;
}
int Engine::getType() const {
	return this->type;
}

void Engine::setHp(int _hp) {
	if (_hp >= DEFAULT_HP) {
		this->hp = _hp;
	}
	else cout << "Error. Too low horse power." << '\n';
}
void Engine::setVolume(int _volume) {
	if (_volume >= 0) {
		this->volume = _volume;
	}
	else cout << "Error. Too low engine volume." << '\n';
}
void Engine::setType(int _type) {
	if (_type >= 0 && _type <= MAX_TYPE_RANGE) {
		this->type = _type;
	}
	else cout << "Error. There is no such engine." << '\n';
}

//enum Engine::Type {
//	Electrical = 0,
//	Hybrid = 1,
//	Gasoline = 2,
//	Diesel = 3
//};