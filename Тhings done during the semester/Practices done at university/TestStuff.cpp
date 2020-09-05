#include <iostream>

using namespace std;

//03.05.17

template <typename T, typename K>
class Bag {
	T fistItem;
	K secondItem;

public:

	friend ostream& operator<<(ostream& os, Bag<T, K> const& bag) { //test - no iostream, std; in the definition of class Bag we dont need to write: Bag<T,K>;
															  // if out of definition we MUST write: Bag<T,K>;
		os << "First item: " << firstItem; //b.firstItem;
		os << "Second item: " << secondItem; //b.secondItem;

		return os;
	}
};

template <typename T, typename K>
ostream& operator<<(ostream& os, Bag<T, K> const& bag) { 
	os << "First item: " << bag.firstItem; //b.firstItem;
	os << "Second item: " << bag.secondItem; //b.secondItem;

	return os;
}

class Animal {
	int numLegs;
	char description[101];
};

class Cat : public Animal {
	void doCatStuff() {
		cout << "Meow!" << '\n';
	}
};

class Mammoth :public Animal {
	void doMammothStuf() {
		cout << "Go extinct!";
	}
};

class Flying {
	double wingSpan;
	double avgDistance;
};

class Canary :public Animal, public Flying {
	void sing() {
		cout << "Pew Pew!" << '\n'; //lol
	}
};

//int main() {
//
//	Bag<int, double> bag;
//	Bag<char, int[]> b;
//	cout << bag;
//
//	Animal a;
//	Cat c;
//
//	Canary canary;
//
//	system("pause");
//	return 0;
//}