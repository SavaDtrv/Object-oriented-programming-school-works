#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <typeinfo>
#include <string>

using namespace std;

const int DEFAULT_CAP = 10;
const int DEFAULT_CURRENT = 0;


template <typename K, typename V>
class Dictionary {
	K* keys;
	V* values;
	int capKV;
	int currentKV;

	void copy(const Dictionary& other) {
		this->capKV = other.capKV;
		this->currentKV = other.currentKV;

		if (typeid(K) == typeid(char)) {
			for (int i = 0; i < currentKV; i++) {
				strcpy(keys[i], other.keys[i]);
				values[i] = other.values[i];
			}
		}
		else {
			for (int i = 0; i < currentKV; i++) {
				keys[i] = other.keys[i];
				values[i] = other.values[i];
			}
		}
	}

	void add(K newKey, V newValue) {
		if (currentKV == capKV - 1) {
			resize();
		}

		keys[currentKV] = newKey;
		values[currentKV] = newValue;
		currentKV++;
	}

	void removeByKey(K _key) {
		if (typeid(K) == typeid(char)) {
			for (int i = 0; i < currentKV; i++) {
				if (strcmp(keys[i], _key) == 0) {
					strcpy(keys[i], keys[currentKV]);
					values[i] = values[currentKV];
					currentKV--;
				}
			}
		}
		else {
			for (int i = 0; i < currentKV; i++) {
				if (keys[i] = _key) {
					keys[i] = keys[currentKV];
					values[i] = values[currentKV];
					currentKV--;
				}
			}
		}
	}

	void resize() {
		capKV *= 2;

		K* tmpKeys = new K[currentKV];
		V* tmpValues = new V[currentKV];

		if (typeid(K) == typeid(char)) {
			for (int i = 0; i < currentKV; i++) {
				strcpy(tmpKeys[i], keys[i]);
				tmpValues[i] = values[i];
			}
		}
		else {
			for (int i = 0; i < currentKV; i++) {
				tmpKeys[i] = keys[i];
				tmpValues[i] = values[i];
			}
		}

		removeDictionary();
		keys = tmpKeys;
		values = tmpValues;
	}

	void removeDictionary() {
		delete keys;
		keys = nullptr;
		delete values;
		values = nullptr;
	}

public:
	Dictionary();
	Dictionary(const Dictionary& other);
	Dictionary& operator=(const Dictionary& other);
	~Dictionary();

	int getSize() const;
	K getKeyAt(int index) const;
	V getValueAt(int index) const;

	void addKeyAndValues(K key, V value);
	void removeKeyAndValue(K _key);
	const V findByKey(K key);

	friend ostream& operator<<(ostream& os, const Dictionary& myDictionary) {
		for (int i = 0; i < myDictionary.getSize(); i++) {
			os << myDictionary.getKeyAt(i) << ": "
				<< myDictionary.getValueAt(i) << '\n';
		}

		return os;
	}
};

/*****************************************************************************/
/*--------------------------------Definitions--------------------------------*/
/*****************************************************************************/
template<typename K, typename V>
inline Dictionary<K, V>::Dictionary() {
	this->capKV = DEFAULT_CAP;
	this->currentKV = DEFAULT_CURRENT;
	this->keys = new K[capKV];
}

template<typename K, typename V>
inline Dictionary<K, V>::Dictionary(const Dictionary & other) {
	copy(other);
}

template<typename K, typename V>
inline Dictionary & Dictionary<K, V>::operator=(const Dictionary & other)
{
	if (this != &other) {
		removeDictionary();
		copy(other);
	}

	return *this;
}

template<typename K, typename V>
inline Dictionary<K, V>::~Dictionary() {
	removeDictionary();
}

template<typename K, typename V>
inline int Dictionary<K, V>::getSize() const {
	return this->currentKV;
}

template<typename K, typename V>
inline K Dictionary<K, V>::getKeyAt(int index) const {
	return this->keys[index];
}

template<typename K, typename V>
inline V Dictionary<K, V>::getValueAt(int index) const {
	return this->values[index];
}


template<typename K, typename V>
inline void Dictionary<K, V>::addKeyAndValues(K key, V value) {
	add(key, value);
}

template<typename K, typename V>
inline void Dictionary<K, V>::removeKeyAndValue(K _key) {
	removeByKey(_key);
}

template<typename K, typename V>
inline const V Dictionary<K, V>::findByKey(K key) {
	
	if (typeid(K) == typeid(char)) {
		for (int i = 0; i < this->currentKV; i++) {
			if (strcmp(this->keys[i], key) == 0) {
				return this->values[i];
			}
		}
	}
	else {
		for (int i = 0; i < this->currentKV; i++) {
			if (this->keys[i] == key) {
				return this->values[i];
			}
		}
	}

	return V();
}
