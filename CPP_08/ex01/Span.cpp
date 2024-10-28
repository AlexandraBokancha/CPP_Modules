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

void Span::addNumber(int nb){
	if (_numbers.size() >= _N)
		throw Span::ContainerIsFull();	
	_numbers.insert(nb);
}

void Span::addNumber(std::multiset<int>::iterator start, std::multiset<int>::iterator end){
    if (_numbers.size() >= _N)
		throw Span::ContainerIsFull();
    size_t distance = std::distance(start, end);
    if (_numbers.size() + distance > _N)
        throw::Span::OutOfBounds();
    _numbers.insert(start, end);
    std::cout << std::endl;
    std::cout << "\033[35mSpan is filled using a range of iterators\033[0m" << std::endl;
}

unsigned int Span::shortestSpan(){
    if (_numbers.size() <= 1)
        throw Span::NoSpanFound();
    int minSpan = std::numeric_limits<int>::max();
	for (std::multiset<int>::iterator it = _numbers.begin(), next = ++_numbers.begin(); next != _numbers.end(); ++it, ++next)
    {
        int span = *next - *it;
        if (span < minSpan){
            minSpan = span;
        }
        if (span == 0)
            return minSpan;
    }
    return static_cast<unsigned int>(minSpan);
}

unsigned int Span::longestSpan(){
    if (_numbers.size() <= 1)
        throw Span::NoSpanFound();
    return *(_numbers.rbegin()) - *(_numbers.begin());
}

void Span::printSpan() const{
	for (std::multiset<int>::iterator it = _numbers.begin(); it != _numbers.end(); it++){
		std::cout << *it << " | ";
	}
    std:: cout << std::endl;		
}

long unsigned int Span::getSize() const{
    return _numbers.size();
}


const char* Span::ContainerIsFull::what() const throw(){
	return "\033[31mContainer is full\033[0m";
}

const char* Span::OutOfBounds::what() const throw(){
	return "\033[31mRange is out of bounds\033[0m";
}

const char* Span::NoSpanFound::what() const throw(){
	return "\033[31mNo span can be found\033[0m";
}

std::multiset<int> generate(int size, int start, int end){
    std::multiset<int> randNums;

    std::srand(static_cast<unsigned int>(std::time(0)));
    for (int i = 0; i < size; i++)
    {
        int randVal = start + rand() % (end - start + 1);
        randNums.insert(randVal);
    }
    std::cout << "Nums to add: " << std::endl;
    for (std::multiset<int>::iterator it = randNums.begin(); it != randNums.end(); it++){
		std::cout << *it << " | ";	
	}
    std::cout << std::endl;
    return randNums;
}
