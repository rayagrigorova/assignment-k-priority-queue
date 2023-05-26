#pragma once 

#include "Element.hpp"
#include "DynamicArray.hpp"

template <typename T>
class PriorityQueue {
	DynamicArray<Element<T>> _queue; 
	unsigned _maxPriority = 0;

public:
	PriorityQueue(unsigned maxPriority);

	void push(const T& el, unsigned priority);
	void push(T&& el, unsigned priority);
	void pop();
	const T& peek() const;

	bool isEmpty() const; 

	void print() const;
};

template <typename T>
PriorityQueue<T>::PriorityQueue(unsigned maxPriority) : _maxPriority(maxPriority){

}

template <typename T>
void PriorityQueue<T>::push(const T& el, unsigned priority) {
	if (priority > _maxPriority) {
		throw std::invalid_argument("Error! no such priority!");
	}

	size_t size = _queue.getSize();
	unsigned i;

	// Insert the element in the array 
	// The elements with the highest priority should come first in the array 
	for (i = size - 1; i >= 1 && el._priority > _queue[i].priority; i--) {
		_queue[i] = _queue[i - 1];
	}
	_queue[i] = el; 
}

template <typename T>
void PriorityQueue<T>::push(T&& el, unsigned priority) {
	if (priority > _maxPriority) {
		throw std::invalid_argument("Error! No such priority!");
	}

	Element<T> toAdd(el, priority);
	_queue.pushBack(toAdd);

	unsigned i;
	size_t size = _queue.getSize();

	// Insert the element in the array 
	// The elements with the highest priority should come first in the array 
	for (i = size - 1; i >= 1 && priority > _queue[i - 1]._priority; i--) {
		_queue[i] = _queue[i - 1];
	}

	_queue.setAtIndex(toAdd, i);
}

template <typename T>
void PriorityQueue<T>::pop() {
	if (isEmpty()) {
		throw std::logic_error("Error! Empty queue!");
	}

	_queue.erase(0);
}

template <typename T>
const T& PriorityQueue<T>::peek() const {
	if (isEmpty()) {
		throw std::logic_error("Error! Empty queue!");
	}
}

template <typename T>
bool PriorityQueue<T>::isEmpty() const {
	return _queue.getSize() == 0;
}

template <typename T>
void PriorityQueue<T>::print() const {
	if (isEmpty()) {
		std::cout << "The queue is currently empty.\n";
		return;
	}

	int size = _queue.getSize();

	for (int i = 0; i < size; i++) {
		_queue[i].print();
	}
}