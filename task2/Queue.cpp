#include "Queue.h"
#include <iostream>

Queue::Queue() {
	arr = nullptr;
	size = 0;
	firstPointer = 0;
	lastPointer = 0;
}

Queue::Queue(int size) {
	arr = new double[size];
	this->size = size;
	firstPointer = 0;
	lastPointer = 0;
}

Queue::Queue(const Queue& copy) {
	this->size = copy.size;
	firstPointer = copy.firstPointer;
	lastPointer = copy.lastPointer;
	arr = new double[copy.size];
	for (int i = 0; i < size; i++) {
		arr[i] = copy.arr[i];
	}
}

void Queue::addElem(double elem) {
	if (isFull()) {
		throw std::exception("isFull");
	}
	arr[lastPointer] = elem;
	lastPointer = (lastPointer + 1) % size;
}

double Queue::getElem() {
	if (isEmpty()) {
		throw std::exception("isEmpty");
	}
	double temp = arr[firstPointer];
	firstPointer = (firstPointer + 1) % size;
	return temp;
}

double Queue::peek() {
	if (isEmpty()) {
		throw std::exception("isEmpty");
	}
	return arr[firstPointer];
}

int Queue::getSize() {
	return size;
}

bool Queue::isEmpty() {
	return firstPointer == lastPointer;
}

bool Queue::isFull() {
	return firstPointer == ((lastPointer + 1) % size);
}

void Queue::clear() {
	firstPointer = 0;
	lastPointer = 0;
}

void Queue::Display() {
	if (isEmpty()) {
		std::cout << "QUEUE is empty" << std::endl;
		return;
	}
	std::cout << std::endl << "QUEUE: " << std::endl;
	for (int i = firstPointer; i < lastPointer; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl << "-----------------------" << std::endl << std::endl;
}