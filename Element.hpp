#pragma once

template <typename T>
struct Element {
	T _value;

	// The default priority is -1 so that 
	// elements with a priority of 0 or higher
	// are sorted before uninitialized elements.  
	int _priority = -1;

	Element() = default;
	Element(const T& value, int priority);

	void print() const;
};

template <typename T>
Element<T>::Element(const T& value, int priority) : _value(value), _priority(priority) {

}

template <typename T>
void Element<T>::print() const {
	std::cout << "Value: " << _value << " Priority: " << _priority << std::endl;
}