#pragma once
#include <iostream>
#include "Card.h"
#include "MagicCard.h"
#include "MonsterCard.h"
#include "TrapCard.h"

using namespace std;

const int MAX_AMOUNT_OF_CARDS_HAND = 10; //in Hand

class Hand {
	Card** handOfCards; //this is where we will keep the cards from all 3 types(monster, magic, trap)
	int capacity;
	int currentCard;

	void copy(const Hand& other) {
		currentCard = other.currentCard;

		for (int i = 0; i < currentCard; i++)
		{
			handOfCards[i] = other.handOfCards[i];
		}
	}

	void add(Card& newCard) {
		if (currentCard == MAX_AMOUNT_OF_CARDS_HAND + 1) {
			currentCard = MAX_AMOUNT_OF_CARDS_HAND;
			cout << "Your hand is full. You already have 10 cards in your hand." << '\n';
			return;
		}

		handOfCards[currentCard] = &newCard;
		currentCard++;
	}

	void removeHand() {
		for (int i = 0; i < currentCard; i++) {
			delete handOfCards[i];
		}

		delete[] handOfCards;
		handOfCards = nullptr;
	}
public:
	Hand();
	Hand(const Hand& other);
	Hand& operator=(const Hand& other);
	~Hand();

	void removeSpecCardFromHand(int);
	void addCardInHand(Card& newCard);

	Card* getAt(int index);

	friend ostream& operator<<(ostream& os, const Hand& hand) {
		for (int i = 0; i < hand.currentCard; i++)
		{
			os << hand.handOfCards[i] << '\n' << '\n';
		}
		os << endl;

		return os;
	}
};