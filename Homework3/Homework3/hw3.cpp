#include <iostream>
#include "sidePile.h"
#include "deck.h"

bool playRound(Deck pDeck, Deck cDeck, SidePile pPile, SidePile cPile) {
	int playerCard = pDeck.GetCard();
	int computerCard = cDeck.GetCard();

	std::cout << "Player card: " << playerCard << "\nComputer card: " << computerCard << std::endl;

	int strategy{};
	while (true) {
		std::cout << "Do you want to pull an additional card or push your current card on the pile?\n1. Pull\n2. Push\n\nChoice: ";
		std::cin >> strategy;

		if (strategy == 1 || strategy == 2) {
			break;
		}
		else {
			std::cout << "Invalid input, please try again.\n";
		}
	}

	if (strategy == 1) {
		// Pull additional card
		playerCard += pDeck.GetCard();
		computerCard += cDeck.GetCard();
	}
	else {
		// Draw new card
		playerCard = pDeck.GetCard();
	}

	std::cout << "Player card: " << playerCard << "\nComputer card: " << computerCard << std::endl;

	if (playerCard > computerCard) {
		// player wins	
		pDeck.addCard(playerCard);
		pDeck.addCard(computerCard);
		std::cout << "Player wins :)\n";
		return true;
	} else {
		// computer wins
		cDeck.addCard(playerCard);
		cDeck.addCard(computerCard);
		std::cout << "Player loses :(\n";
		return false;
	}
}


int main() {
	Deck playerDeck;
	Deck computerDeck;
	SidePile playerSidePile;
	SidePile computerSidePile;
	int pcards[] = { 3, 6, 7 };
	int ccards[] = { 5, 6, 2 };
	playerDeck.MoveToBottom(pcards,3);
	computerDeck.MoveToBottom(ccards,3);
	playerSidePile.push(2);
	computerSidePile.push(2);

	int decision{};

	while (true) {
		std::cout << "1: Play until out of cards\n2: Track number of rounds\n\nChoice: ";
		std::cin >> decision;

		if (decision == 1 || decision == 2) {
			break;
		}
		else {
			std::cout << "Invalid choice, please try again.\n";
		}
	}

	if (decision == 1) {
		// Play until no cards
		std::cout << "Player: ";
		std::cout << playerDeck.cardsLeft() << std::endl;

		std::cout << "Computer: ";
		std::cout << computerDeck.cardsLeft() << std::endl;
		
		std::cout << "Number of cards in player's side pile: " << playerSidePile.getSize() << std::endl;
		std::cout << "Number of cards in Computer's side pile: " << computerSidePile.getSize() << std::endl;
		/*
		while(playerDeck.cardsLeft() > 0 && computerDeck.cardsLeft() > 0){
		}
		*/
		playRound(playerDeck, computerDeck, playerSidePile, computerSidePile);

	} else {
		// Track rounds
		std::cout << "Player: ";
		std::cout << playerDeck.cardsLeft() << std::endl;

		std::cout << "Computer: ";
		std::cout << computerDeck.cardsLeft() << std::endl;

		std::cout << "Number of cards in Player's side pile: " << playerSidePile.getSize() << std::endl;
		std::cout << "Number of cards in Computer's side pile: " << computerSidePile.getSize() << std::endl;

		int playerRoundsWon{};
		int computerRoundsWon{};
		while (playerDeck.cardsLeft() != 0 || computerDeck.cardsLeft() != 0) {
			if (playRound(playerDeck, computerDeck, playerSidePile, computerSidePile)) {
				playerRoundsWon++;
			} else {
				computerRoundsWon++;
			}
		}
		playerRoundsWon > computerRoundsWon ? std::cout << "Player won more rounds\n" : std::cout << "Computer won more rounds\n";
	}

}