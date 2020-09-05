#pragma once
#include <iostream>
#include "Card.h"
#include "MagicCard.h"
#include "MonsterCard.h"
#include "TrapCard.h"
#include "Deck.h"
#include "HandOfCards.h"

const int MAX_CARDS_GY = 60;
const int MAX_CARDS_MF = 10;

 //Interface za graveyard i poleto za chudovishta
class GYMFConstruction {
protected:
	int capacity;
	int current;

public:
	virtual void add(Card& card) = 0;
	virtual void remove(int index) = 0;
};

class Graveyard : public GYMFConstruction {
	Card* cards[MAX_CARDS_GY];

public:
	Graveyard() {
		capacity = MAX_CARDS_GY;
		current = 0;
	}

	void add(Card& card) {
		cards[current] = &card;
		current++;
	}

	void remove(int index) {
		for (int i = 0; i < current; i++) {
			if (i == index) {
				cards[i] = cards[current];
				current--;
				return;
			}
		}
	}
};

class MonsterField : public GYMFConstruction {
	Card* cards[MAX_CARDS_MF];

public:
	MonsterField() {
		capacity = MAX_CARDS_MF;
		current = 0;
	}

	void add(Card& card) {
		cards[current] = &card;
		current++;
	}

	void remove(int index) {
		for (int i = 0; i < current; i++) {
			if (i == index) {
				cards[i] = cards[current];
				current--;
				return;
			}
		}
	}

	Card* getAt(int index) {
		return cards[index];
	}
};


class Battlefield {
	Graveyard* gy;
	MonsterField* mfPlayer1;
	MonsterField* mfPlayer2;
	Deck player1Deck;
	Hand player1Hand;
	Deck player2Deck;
	Hand player2Hand;

public:
	//Shte priemem che imame metodi za addvane na 2 testeta karti na poleto

	Battlefield() : gy(), mfPlayer1(), mfPlayer2(), player1Deck(),
		player1Hand(), player2Deck(), player2Hand() {}

	int getCurrentDeck1() { return this->player1Deck.getCurrent(); }
	int getCurrentDeck2() { return this->player2Deck.getCurrent(); }

	void addCardToHand(int index, int playerOnMove) { 
		//tuk index-a shte e random chislo, a 
		//playerOnMove e edno ot chislata 1 i 2, suotvetno za player-a
													 
		if (playerOnMove == 1) {
			player1Hand.addCardInHand(*player1Deck.getAt(index));
			player1Deck.removeSpecCardFromDeck(index);
		}
		else {
			player2Hand.addCardInHand(*player2Deck.getAt(index));
			player2Deck.removeSpecCardFromDeck(index);
		}
	}

	void addToMonsterField(int cardForAdding, int playerOnMove) {
		if (playerOnMove == 1) {
			mfPlayer1->add(*player1Hand.getAt(cardForAdding));
		}
		else
			mfPlayer2->add(*player2Hand.getAt(cardForAdding));
	}

	void monsterFigth(int monsterOnMove,
		 int opponentMonster, int playerOnMove) {
		//monsterOnMove i opponentMonster se qvqvat index-i, koito
		//potrebitelq shte vuvejda

		if (playerOnMove == 1) {
			Monster* playerOnMoveMonster = dynamic_cast<Monster*>(mfPlayer1->getAt(monsterOnMove));
			Monster* oppMonster = dynamic_cast<Monster*>(mfPlayer2->getAt(opponentMonster));
			
			if (playerOnMoveMonster->onUse(*oppMonster)) {
				gy->add(*(mfPlayer2->getAt(opponentMonster)));
				mfPlayer2->remove(opponentMonster);
			}
		}
		else {
			Monster* playerOnMoveMonster = dynamic_cast<Monster*>(mfPlayer2->getAt(monsterOnMove));
			Monster* oppMonster = dynamic_cast<Monster*>(mfPlayer1->getAt(opponentMonster));

			if (playerOnMoveMonster->onUse(*oppMonster)) {
				gy->add(*(mfPlayer1->getAt(opponentMonster)));
				mfPlayer1->remove(opponentMonster);
			}
		}
	}
	void useMagic(int playerOnMoveMagic,
		int playerOnMoveMonster, int playerOnMove) {
		//monsterOnMove i opponentMonster - sushtoto kato pri monsterFigth

		if (playerOnMove == 1) {
			Magic* myMagic = dynamic_cast<Magic*>(player1Hand.getAt(playerOnMoveMagic));
			Monster* myMonster = dynamic_cast<Monster*>(mfPlayer1->getAt(playerOnMoveMonster));

			if (myMagic->onUse(*myMonster)) {
				gy->add(*player1Hand.getAt(playerOnMoveMagic));
				player1Hand.removeSpecCardFromHand(playerOnMoveMagic);
			}
		}
		else {
			Magic* myMagic = dynamic_cast<Magic*>(player2Hand.getAt(playerOnMoveMagic));
			Monster* myMonster = dynamic_cast<Monster*>(mfPlayer2->getAt(playerOnMoveMonster));

			if (myMagic->onUse(*myMonster)) {
				gy->add(*player2Hand.getAt(playerOnMoveMagic));
				player2Hand.removeSpecCardFromHand(playerOnMoveMagic);
			}
		}
	}
	void useTrap(int playerOnMoveTrap,
		int opponentMonster, int playerOnMove) {
		//monsterOnMove i opponentMonster - sushtoto kato pri monsterFigth

		if (playerOnMove == 1) {
			Trap* myTrap = dynamic_cast<Trap*>(player1Hand.getAt(playerOnMoveTrap));
			Monster* oppMonster = dynamic_cast<Monster*>(mfPlayer2->getAt(opponentMonster));
			
			myTrap->onUse(*oppMonster);
			gy->add(*player1Hand.getAt(playerOnMoveTrap));
			player1Hand.removeSpecCardFromHand(playerOnMoveTrap);
		}
		else {
			Trap* myTrap = dynamic_cast<Trap*>(player2Hand.getAt(playerOnMoveTrap));
			Monster* oppMonster = dynamic_cast<Monster*>(mfPlayer1->getAt(opponentMonster));

			myTrap->onUse(*oppMonster);
			gy->add(*player2Hand.getAt(playerOnMoveTrap));
			player2Hand.removeSpecCardFromHand(playerOnMoveTrap);
		}
	}

	char* announceWinner(int player1, int player2, Battlefield& myField) {
		if (player1 == 0 || myField.getCurrentDeck1() == 0)
			return "Player2 wins";
		else if(player2 == 0 || myField.getCurrentDeck2() == 0)
			return "Player1 wins";
	}
};