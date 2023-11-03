#pragma once

struct Node {
	int value;
	Node* next;
};

class Deck {
public:
	Deck();
	~Deck();
	void addCard(int value);
	int GetCard();
	void MoveToBottom(int values[], int count);
	int cardsLeft();
	void displaydeck() const;
private:
	Node* front;
	Node* rear;
	int size;
};