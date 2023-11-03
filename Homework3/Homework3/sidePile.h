#pragma once
#include <iostream>

class SidePile {
private:
	int currSize;
	int data[5];
public:
	SidePile();
	void push(int card);
	int pop();
	bool isFull();
	bool isEmpty();
	int getSize();
	void print();
};