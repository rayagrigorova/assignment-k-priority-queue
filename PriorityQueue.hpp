#pragma once 

#include "Element.hpp"
#include "DynamicArray.hpp"

template <typename T>
class PriorityQueue {
	// The elements in the queue are sorted in ascending order based on their priority 
	// so that pop() is faster - O(1) to decrease the size of the array 
	DynamicArray<Element<T>> _queue;
	unsigned _maxPriority = 0;

	unsigned makePlaceAndShift(const T& val, unsigned priority);
	unsigned shiftQueue(unsigned priority, unsigned oldSize);

public:
	PriorityQueue(unsigned maxPriority);

	void push(const T& val, unsigned priority); // Create a new Element<T> object using the parameters 
	void push(const Element<T>& el); // Push a copy of an existing element
	void push(Element<T>&& el); // Push an existing element (with move)

	void pop();
	const T& peek() const;

	bool isEmpty() const;

	void print() const;
};

template <typename T>
PriorityQueue<T>::PriorityQueue(unsigned maxPriority) : _maxPriority(maxPriority) {

}

template <typename T>
void PriorityQueue<T>::push(const T& val, unsigned priority) {
	if (priority >= _maxPriority) {
		throw std::invalid_argument("Error! no such priority!");
	}

	unsigned i = makePlaceAndShift(val, priority);
	_queue[i] = Element<T>(val, priority);
}

template <typename T>
void PriorityQueue<T>::push(const Element<T>& el) {
	if (el._priority >= _maxPriority) {
		throw std::invalid_argument("Error! no such priority!");
	}

	unsigned i = makePlaceAndShift(el._value, el._priority);
	_queue[i] = el;
}

template <typename T>
void PriorityQueue<T>::push(Element<T>&& el) {
	if (el._priority >= _maxPriority) {
		throw std::invalid_argument("Error! no such priority!");
	}

	unsigned i = makePlaceAndShift(el._value, el._priority);
	_queue[i] = std::move(el);
}

template <typename T>
void PriorityQueue<T>::pop() {
	if (isEmpty()) {
		throw std::logic_error("Error! Empty queue!");
	}

	// The last element in the array is of highest priority 
	_queue.erase(_queue.getSize() - 1);
}

template <typename T>
const T& PriorityQueue<T>::peek() const {
	if (isEmpty()) {
		throw std::logic_error("Error! Empty queue!");
	}

	return _queue[_queue.getSize() - 1]._value;
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

	std::cout << "Elements in descending order of priority:\n";
	int size = _queue.getSize();

	for (int i = size - 1; i >= 0; i--) {
		_queue[i].print();
	}
}

template <typename T>
unsigned PriorityQueue<T>::shiftQueue(unsigned priority, unsigned oldSize) {
	if (oldSize == 0) {
		return 0;
	}

	unsigned i;
	// <= so that the new element is put after ones with the same priority in the queue 
	for (i = oldSize; i >= 1 && priority <= _queue[i - 1]._priority; i--) {
		_queue[i] = _queue[i - 1];
	}
	return i;
}

template<typename T>
inline unsigned PriorityQueue<T>::makePlaceAndShift(const T& val, unsigned priority) {
	// Insert an uninitialized element in the end of the array.
	// This is done to make place for the new element. 
	unsigned oldSize = _queue.getSize();
	_queue.pushBack(Element<T>());

	return shiftQueue(priority, oldSize); // this function returns the index where the new element should be inserted
}
