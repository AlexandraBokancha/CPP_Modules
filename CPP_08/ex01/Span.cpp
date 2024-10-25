#include "Span.hpp"

// Default constructor
Span::Span(void) : _N(10000)
{
    std::cout << "(Span) Default constructor called" << std::endl;
    return ;
}
// Parametricc constructor
Span::Span(unsigned int n) : _N(n)
{
    std::cout << "(Span) Default constructor called" << std::endl;
    return ;
}

// Copy constructor
Span::Span(const Span &other) : _N(other._N)
{
    std::cout << "(Span) Copy constructor called" << std::endl;
    return ;
}

// Assignment operator overload
Span &Span::operator=(const Span &other)
{
    std::cout << "(Span) Assignment operator called" << std::endl;
    if (this != &other){
		_N = other._N;
	}
    return (*this);
}

// Destructor
Span::~Span(void)
{
    std::cout << "(Span) Destructor called" << std::endl;
    return ;
}

void Span::addNumber(){
	if (_numbers.size() >= _N)
		throw Span::ContainerIsFull();
		
	int randomNb = rand();

	_numbers.insert(randomNb);
}

void Span::printSpan() const{
	for (std::multiset<int>::iterator it = _numbers.begin(); it != _numbers.end(); it++){
		std::cout << *it << std::endl;		
	}
}

// unsigned int Span::shortestSpan(){

// }

// unsigned int Span::longestSpan(){

// }

const char* Span::ContainerIsFull::what() const throw(){
	return "\033[31mContainer is full\033[0m";
}