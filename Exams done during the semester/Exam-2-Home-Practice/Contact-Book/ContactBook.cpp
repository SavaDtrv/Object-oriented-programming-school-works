#include "ContactBook.h"

const char* FIRST_CRITERIA = "Name";
const char* SECOND_CRITERIA = "Phone number";
const char* THIRD_CRITERIA = "ID";

void ContactBook::addContact(Contact & newContact) {
	int criteria;
	cout << "Choose a criteria by which you want to add the contact:"
		<< "1: Person name"
		<< "2: Person phone number"
		<< "3: ID" << '\n';
	
	cin >> criteria;
	switch (criteria)
	{
		case 1: byName.addKeyAndValues(newContact.getName(), &newContact); break;
		case 2: byNum.addKeyAndValues(newContact.getPhoneNum(), &newContact); break;
		case 3: byID.addKeyAndValues(newContact.getID(), &newContact); break;
		default: break;
	}
}

void ContactBook::removeContact(Contact & oldContact) {
	byName.removeKeyAndValue(oldContact.getName());
	byNum.removeKeyAndValue(oldContact.getPhoneNum());
	byID.removeKeyAndValue(oldContact.getID());
}

const Contact & ContactBook::findByCriteria(char * _Criteria, 
	Contact& contactForSearch) {
	int criteria = 0;

	//V maina shte bude kazano koi sa kriteriite.
	if (strcmp(_Criteria, FIRST_CRITERIA) == 0) {
		criteria = 1;
	}
	else if (strcmp(_Criteria, SECOND_CRITERIA) == 0) {
		criteria = 2;
	}
	else if (strcmp(_Criteria, THIRD_CRITERIA) == 0) {
		criteria = 3;
	}
	else cout << "There is no such criteria." << '\n';

	switch (criteria)
	{
		case 1: byName.findByKey(contactForSearch.getName()); break;
		case 2: byNum.findByKey(contactForSearch.getPhoneNum()); break;
		case 3: byID.findByKey(contactForSearch.getID()); break;
		default: break;
	}
}

ostream & operator<<(ostream & os, const ContactBook& myBook) {
	char* criteria;
	os << "Choose a criteria by which you want to add the contact:"
		<< "1: Name"
		<< "2: Phone number"
		<< "3: ID" << '\n';

	cin.getline(criteria, 13);

	if (strcmp(criteria, FIRST_CRITERIA) == 0) {
		for (int i = 0; i < myBook.byName.getSize(); i++) {
			os << myBook.byName.getValueAt(i);
		}
	}
	else if (strcmp(criteria, SECOND_CRITERIA) == 0) {
		for (int i = 0; i < myBook.byNum.getSize(); i++) {
			os << myBook.byNum.getValueAt(i);
		}
	}
	else if (strcmp(criteria, THIRD_CRITERIA) == 0) {
		for (int i = 0; i < myBook.byID.getSize(); i++) {
			os << myBook.byID.getValueAt(i);
		}
	}
	else cout << "There is no such criteria! Try again." << '\n';

	return os;
}
