#include "WrongAnimal.hpp"

// Default constructor
WrongAnimal::WrongAnimal(void) : _type("animal"){
    std::cout << "WrongAnimal was created" << std::endl;
    return ;
}

WrongAnimal::WrongAnimal(std::string const & type) : _type(type){
    std::cout << "WrongAnimal was created (parameters constructor)" << std::endl;
    return ;
}

// Copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal &other){
    *this = other;
    //std::cout << "Copy constructor called" << std::endl;
    return ;
}

// Assignment operator overload
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other){
   // std::cout << "Assignment operator called" << std::endl;
    if (this != &other)
        this->_type = other._type;
    return (*this);
}

void WrongAnimal::makeSound() const {
    std::cout << "(Animal) some spooky sounds" << std::endl;
}

std::string const & WrongAnimal::getType() const{
    return (this->_type);
}

// Destructor
WrongAnimal::~WrongAnimal(void){
    std::cout << "WrongAnimal was destroyed" << std::endl;
    return ;
}

