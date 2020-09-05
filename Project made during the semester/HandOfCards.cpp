#include <iostream>
#include "HandOfCards.h"

using namespace std;

const int DEFAULT_CAPACITY = 10;
const int DEFFAULT_CURRENTCARD = 0;


Hand::Hand() 
{
	capacity = DEFAULT_CAPACITY;
	currentCard = DEFFAULT_CURRENTCARD;
	handOfCards = new Card*[capacity];
}

Hand::Hand(const Hand& other) {
	copy(other);
}
Hand& Hand::operator=(const Hand& other) {
	if (this != &other) {
		removeHand();
		copy(other);
	}

	return *this;
}
Hand::~Hand() {
	removeHand();
}

void Hand::removeSpecCardFromHand(int index)
{
		handOfCards[index] = handOfCards[currentCard];
		currentCard--;
}

void Hand::addCardInHand(Card & newCard)
{
	add(newCard);
}

Card * Hand::getAt(int index)
{
	return handOfCards[index];
}
