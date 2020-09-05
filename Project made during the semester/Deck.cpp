#include <iostream>
#include "Deck.h"

using namespace std;
const int DEFAULT_CAPACITY = 10;
const int DEFFAULT_CURRENTCARD = 0;


Deck::Deck() 
{
	capacity = DEFAULT_CAPACITY;
	currentCard = DEFFAULT_CURRENTCARD;
	cards = new Card*[capacity];
}

Deck::Deck(const Deck& other) {
	copyDeck(other);
}
Deck& Deck::operator=(const Deck& other) {
	if (this != &other) {
		removeDeck();
		copyDeck(other);
	}

	return *this;
}
Deck::~Deck() {
	removeDeck();
}

void Deck::addCard(Card & newCard)
{
	add(newCard);
}

void Deck::removeSpecCardFromDeck(int index)
{
	for (int i = index; i < currentCard; i++)
	{
		cards[i] = cards[i + 1];
	}

	currentCard--;
}

Card * Deck::getAt(int index)
{
	return cards[index];
}
