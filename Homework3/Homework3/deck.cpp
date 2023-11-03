#include <iostream>
#include <array>
#include "deck.h"

Deck::Deck() : front(nullptr), rear(nullptr), size(0) {}

Deck::~Deck() {
	while (front != nullptr) {
		Node* tempvar = front;
		front = front->next;
		delete tempvar;
	}
}

//Create card
void Deck::addCard(int value) {
	Node* newNode = new Node{ value, nullptr };
	if (rear == nullptr) {
		front = newNode;
		rear = newNode;
	}
	else {
		rear->next = newNode;
		rear = newNode;
	}
	size++;
}

// Get card from top and take out
int Deck::GetCard(){
	if (size != 0) {
		Node* Top = front;
		front = front->next;
		size--;
		int topval = Top->value;
		delete Top;
		return topval;
	}
	else {
		std::cout << "ERROR";
	}
}

// Return cards to bottom
void Deck::MoveToBottom(int values[], int count){
	for (int i = 0; i < count; i++) {
		addCard(values[i]);
	}
}
//gives cards left
int Deck::cardsLeft() {
	return size;
}

void Deck::displaydeck()const {
	Node* current = front;
	while (current != nullptr) {
		std::cout << current->value << " ";
		current = current->next;
	}
	std::cout << std::endl;
}