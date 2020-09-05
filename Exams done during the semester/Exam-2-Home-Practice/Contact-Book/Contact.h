#pragma once
#include <iostream>
#include <string>

using namespace std;

const int PHONE_NUM_LENGTH = 10;

class Contact {
	char* name;
	char* phoneNum;
	char* ID;

	void copyContact(const Contact& other) {
		this->setName(other.name);
		this->setID(other.ID);
		this->setPhoneNum(other.phoneNum);
	}

	void deleteContact() {
		delete name;
		name = nullptr;
		delete phoneNum;
		phoneNum = nullptr;
		delete ID;
		ID = nullptr;
	}

public:
	Contact();
	Contact(char* _name, char* _phoneNum, char* _ID);
	Contact(const Contact& other);
	Contact& operator=(const Contact& other);

	char* getName() const;
	char* getPhoneNum() const;
	char* getID() const;

	
	void setName(char* newName);
	void setPhoneNum(char* newNum);
	void setID(char* newID);

	friend ostream& operator<<(ostream& os, const Contact& myContact) {
			os << "------Contact information------" << '\n';
			os << "Contact name: " << myContact.getName()
				<< "Contact phone number: " << myContact.getPhoneNum()
				<< "Contact ID: " << myContact.getID();

			return os;
	}
};