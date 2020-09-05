#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

const int MAX_PAIRS_IN_DICTIONARY = 32;


template <typename K, typename V>
class Pair {
	K key;
	V value;

public:
	Pair() {
		key = K();
		value = V();
	}
	
	V getValue(K);

	bool operator==(const Pair&);
};

template<typename K, typename V>
V Pair<K, V>::getValue(K _key)
{
	if (key == _key) {
		return value;
	}
	
	return V();
}

template<typename K, typename V>
bool Pair<K, V>::operator==(const Pair & otherPair)
{
	if (key == otherPair.key && value == otherPair.value) {
		return true;
	}

	return false;
}

	//Dictionary
template <typename K, typename V>
class Dictionary : public Pair<K, V> {
	Pair pairs[MAX_PAIRS_IN_DICTIONARY];
	int current;
public:
	Dictionary() :Pair() {
		current = 0;
	}

	void addPair(const Pair&);
	void removePair(const Pair&);
	void findValueByKey(K key);
};

template<typename K, typename V>
void Dictionary<K, V>::addPair(const Pair& newPair)
{
	if (current == MAX_PAIRS_IN_DICTIONARY - 1) {
		cout << "The dictionary is full. You cannot add more pair in it." << '\n';
		return;
	}

	pairs[current] = newPair;
	current++;
}

template<typename K, typename V>
void Dictionary<K, V>::removePair(const Pair & pairForRemoval)
{
	for (int i = 0; i < current; i++)
	{
		if (pairs[i] == pairForRemoval) {
			pairs[i] = pairs[current];
			current--;
			return;
		}
	}
}

template<typename K, typename V>
void Dictionary<K, V>::findValueByKey(K key)
{
	for (int i = 0; i < current;i++) {
		getValue(key);
	}
}
