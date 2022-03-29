#include "Iterator.h"

Iterator::Iterator(Queue &que) {
	this->index = que.firstPointer;
	this->queue = que;
}

void Iterator::start() {
	index = queue.firstPointer;
}

void Iterator::next() {
	index = (index + 1) % queue.size;
}

bool Iterator::finish() {
	if (queue.isEmpty()) {
		return 1;
	}
	return index == queue.lastPointer;
}

double Iterator::getValue() {
	return queue.arr[index];
}