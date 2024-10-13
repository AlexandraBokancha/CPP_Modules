#include "Animal.hpp"

// Default constructor
Animal::Animal(void) : _type("animal"){
    std::cout << "Animal was created" << std::endl;
    return ;
}

Animal::Animal(std::string const & type) : _type(type) {
    std::cout << "Animal was created (parameters constructor)" << std::endl;
}

// Copy constructor
Animal::Animal(const Animal &other){
   // std::cout << "Copy constructor called" << std::endl;
    *this = other;
    return ;
}

// Assignment operator overload
Animal &Animal::operator=(const Animal &other){
   // std::cout << "Assignment operator called" << std::endl;
    if (this != &other)
        this->_type = other._type;
    return (*this);
}

void Animal::makeSound() const{
    return ;
}

std::string const & Animal::getType() const{
    return (this->_type);
}

// Destructor
Animal::~Animal(void){
    std::cout << "Animal was destroyed" << std::endl;
    return ;
}

