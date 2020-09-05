#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Named {
	char* name;
	T value;

	void copy(const Named<T>& other) {
		this->setName(other.name);
		this->value = other.value;
	}

	void remove() {
		delete name;
		name = nullptr;
	}
public:
	Named<T>() {
		this->name = NULL;
		this->value = T();
	}
	Named<T>(char* _name, T _value) {
		this->setName(_name);
		this->value = _value;
	}
	Named<T>(const Named<T>& other) {
		copy(other);
	}
	Named<T>& operator=(const Named<T>& other) {
		if (this != &other) {
			remove();
			copy(other);
		}

		return *this;
	}
	~Named<T>() {
		remove();
	}

	T getValue() const {
		return this->value;
	}
	const char* getName() const {
		return this->name;
	}

	void setValue(T newValue) {
		this->value = newValue;
	}
	void setName(char* newName) {
		if (this != nullptr) {
			remove();
		}

		this->name = new char[strlen(newName) + 1];
		strcpy(this->name, newName);
	}

	template <typename T>
	friend ostream& operator<<(ostream& os, const Named<T>& other) {
		os << "Name: " << other.getName()
			<< "Value: " << other.getValue() << '\n';
	}
	template <typename T>
	friend istream& operator >> (istream& is, Named<T>& other) {
		is.getline(other.name, 100);
		is >> other.getValue;

		return is;
	}
};

template <typename T>
class Variable : public Named<T> {
public:
	Variable(char* name, int value) :Named(name, value){}

	Variable& operator*() {
		return value;
	}
	Variable& operator=(const Variable& other) {
		if (strcmp(this->getName(), other.getName()) != 0) {
			this->setValue(other.getValue());
		}
	}

	bool operator==(const Variable& other) {
		if (strcmp(this->getName(), other.getName()) == 0 && this->getValue() == other.getValue())
			return true;
		else
			return false;
	}

	bool operator!=(const Variable& other) {
		return !this->operator==(other);
	}
};