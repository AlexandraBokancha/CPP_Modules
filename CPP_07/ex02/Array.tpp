#include "Array.hpp"

template <typename T>
Array<T>::Array() : _arraySize(0), _aptr(0){
	std::cout << "Template Array default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : _arraySize(n){
	try{
		this->_aptr = new T[n];
	}
	catch (std::bad_alloc){
		memError();
	}
	std::cout << "Template Array parametric constructor called" << std::endl;
	for (unsigned int i = 0; i < this->_arraySize; i++){
		*(_aptr + i) = 0;
	}
}

template <typename T>
Array<T>::Array(const Array & other): _arraySize(other._arraySize){
	this->_aptr = new T[_arraySize];
	if (_aptr == 0)
		memError();
	for (unsigned int i = 0; i < _arraySize; i++){
		*(_aptr + i) = *(other._aptr + i);
	}
	std::cout << "Template Array copy constructor called" << std::endl;
}

template <typename T>
Array<T>::~Array(){
	if (_arraySize > 0)
		delete [] _aptr;
	std::cout << "Template Array deconstructor called" << std::endl;
}

template <typename T>
const Array<T> &Array<T>::operator=(const Array & rhs){
	if (this != &rhs){
		delete [] _aptr;
		_arraySize = rhs._arraySize;
		_aptr = new T[_arraySize];
		for (unsigned int i = 0; i < _arraySize; i++){
			*(_aptr + i) = *(rhs._aptr + i);
		}
	}
	std::cout << "Template Array assignement operator called" << std::endl;
	return *this;
}

template <typename T>
unsigned int Array<T>::size() const{
	return this->_arraySize;
}

template <typename T>
void Array<T>::memError(){
	std::cout << "Error: cannot allocate memory" << std::endl;
	exit (EXIT_FAILURE);
}

/* We need a reference to a T value, beacause it has to
represent a modifiable memory location.
If the operator[] function merely returns an integer, 
it cannot be used to create expressions placed on the
left side of an assignment operator.*/
template <typename T>
T &Array<T>::operator[](const int & sub){
	if (sub < 0 || sub >= static_cast<int>(_arraySize))
		throw SubscriptOutOfBounds();
	return _aptr[sub];	
}

template <typename T>
const T &Array<T>::operator[](const int & sub) const{
	if (sub < 0 || sub >= static_cast<int>(_arraySize))
		throw SubscriptOutOfBounds();
	return _aptr[sub];	
}

const char* SubscriptOutOfBounds::what() const throw() {
	return "\033[31mSubscript is out of bounds of the array\033[0m";
}

