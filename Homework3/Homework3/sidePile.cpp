#include "sidePile.h"

SidePile::SidePile() {
	for (int i = 0; i < 5; ++i) {
		data[i] = -1;
	}
	currSize = 0;
}

void SidePile::push(int card) {
	if(!isFull()){
		data[currSize] = card;
		currSize++;
	}

}

int SidePile::pop() {
	if(!isEmpty()) {
		for (int i = 4; i > 0; --i) {
			if(data[i] != -1){
				int temp = data[i];
				data[i] = -1;
				currSize--;
				return temp;
			}
		}
	}
}

bool SidePile::isFull() {
	return currSize >= 5;
}

bool SidePile::isEmpty() {
	return currSize == 0;
}

int SidePile::getSize() {
	return currSize;
}

void SidePile::print() {
	for (int i = 0; i < 5; ++i) {
		if (data[i] != -1)
			std::cout << data[i] << " ";
	}
	std::cout << std::endl;
}