#include "Contact.h"

const int DEFAULT_NAME_LENGTH = 2;
const int DEFAULT_ID_LENGTH = 2;
const int DEFAUL_PHONE_LENGTH = 2;


Contact::Contact() {
	this->name = new char[DEFAULT_NAME_LENGTH];
	strcpy(this->name, "");
	this->ID = new char[DEFAULT_ID_LENGTH];
	strcpy(this->ID, "");
	this->phoneNum = new char[DEFAUL_PHONE_LENGTH];
	strcpy(this->phoneNum, "");
}

Contact::Contact(char* _name, char* _phoneNum, char* _ID) {
	this->setName(_name);
	this->setID(_ID);
	this->setPhoneNum(_phoneNum);
}

Contact::Contact(const Contact & other) {
	copyContact(other);
}

Contact & Contact::operator=(const Contact & other) {
	if (this != &other) {
		deleteContact();
		copyContact(other);
	}

	return *this;
}

char* Contact::getName() const { return this->name; }
char* Contact::getPhoneNum() const { return this->phoneNum; }
char* Contact::getID() const { return this->ID; }

void Contact::setName(char * newName) {
	if (name != nullptr) {
		delete name;
		name = nullptr;
	}

	int length = strlen(newName);
	this->name = new char[length + 1];
	strcpy(this->name, newName);
}

void Contact::setPhoneNum(char * newNum) {
	if (strlen(newNum) > 10) {
		cout << "The phone number you entered is invalid. Try again." << '\n';
		return;
	}
	if (phoneNum != nullptr) {
		delete phoneNum;
		phoneNum = nullptr;
	}

	int length = strlen(newNum);
	phoneNum = new char[length + 1];
	strcpy(phoneNum, newNum);
}

void Contact::setID(char * newID) {
	if (this->ID != nullptr) {
		delete ID;
		ID = nullptr;
	}

	int length = strlen(newID);
	ID = new char[length + 1];
	strcpy(this->ID, newID);
}
