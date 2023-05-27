#pragma once

template <typename T>
struct Element {
	T _value;

	// The default priority is INT_MAX so that 
	// elements with a priority of 0 or higher
	// are sorted before uninitialized elements.  
	int _priority = INT_MAX;

	Element() = default;
	Element(const T& value, int priority);

	void print() const;
};

template <typename T>
Element<T>::Element(const T& value, int priority) : _value(value), _priority(priority) {

}

// This function is only used to demonstrate how the program works (to display the contents of the queue in main)
template <typename T>
void Element<T>::print() const {
	// _value should have an operator '<<' for the print() function to work
	std::cout << "Value: " << _value << " Priority: " << _priority << std::endl;
}