#pragma once
#include <iostream>
#include "Card.h"
#include "MagicCard.h"
#include "MonsterCard.h"
#include "TrapCard.h"

using namespace std;

const int MAX_AMOUNT_OF_CARDS = 30; //in Deck 
const int CAPACITY_MULTIPLIER = 2;

class Deck {
	Card** cards;
	int capacity;
	int currentCard;

	void copyDeck(const Deck& other) {
		capacity = other.capacity;
		currentCard = other.currentCard;

		for (int i = 0; i < currentCard; i++) {
			cards[i] = other.cards[i];
		}
	}

	void add(Card& newCard) {
		if (currentCard == MAX_AMOUNT_OF_CARDS + 1) {
			currentCard = MAX_AMOUNT_OF_CARDS;
			cout << "The deck is full. You already have 30 cards in your deck." << '\n';
			return;
		}

		if (currentCard == capacity - 1) {
			resize();
		}
		cards[currentCard] = &newCard;
		currentCard++;
	}

	void resize() {
		if (capacity > MAX_AMOUNT_OF_CARDS) {
			capacity = MAX_AMOUNT_OF_CARDS;
		}
		else capacity *= CAPACITY_MULTIPLIER;

		Card** tmpCards = new Card*[capacity];
		for (int i = 0; i < currentCard; i++)
		{
			tmpCards[i] = cards[i];
		}

		removeDeck();
		cards = tmpCards;
	}

	void removeDeck() {
		for (int i = 0; i < currentCard; i++) {
			delete cards[i];
		}

		delete[] cards;
		cards = nullptr;
	}

public:
	Deck();
	Deck(const Deck& other);
	Deck& operator=(const Deck& other);
	~Deck();

	void addCard(Card& newCard);
	void removeSpecCardFromDeck(int);

	int getCurrent() { return this->currentCard; }
	Card* getAt(int index);

	friend ostream& operator<<(ostream& os, const Deck& deck) {
		for (int i = 0; i < deck.currentCard; i++)
		{
			os << deck.cards[i] << '\n' << '\n';
		}
		os << endl;

		return os;
	}
};