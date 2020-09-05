#pragma once
#include <iostream>
#include <string>
#include "Contact.h"
#include "Dictionary.h"

using namespace std;

class ContactBook {
	Dictionary<char*, Contact*> byName;
	Dictionary<char*, Contact*> byNum;
	Dictionary<char*, Contact*> byID;

public:

	void addContact(Contact& newContact);
	void removeContact(Contact& oldContact);
	const Contact& findByCriteria(char* _Criteria, Contact& contactForSearch);

	friend ostream& operator<<(ostream& os, const ContactBook& myBook);
};