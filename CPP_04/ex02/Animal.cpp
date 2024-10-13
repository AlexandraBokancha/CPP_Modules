#include "Animal.hpp"

// Default constructor
AAnimal::AAnimal(void) : _type("Aanimal"){
    std::cout << "AAnimal was created" << std::endl;
    return ;
}

AAnimal::AAnimal(std::string const & type) : _type(type) {
    std::cout << "AAnimal was created (parameters constructor)" << std::endl;
}

// Copy constructor
AAnimal::AAnimal(const AAnimal &other){
   // std::cout << "Copy constructor called" << std::endl;
    *this = other;
    return ;
}

// Assignment operator overload
AAnimal &AAnimal::operator=(const AAnimal &other){
   // std::cout << "Assignment operator called" << std::endl;
    if (this != &other)
        this->_type = other._type;
    return (*this);
}

std::string const & AAnimal::getType() const{
    return (this->_type);
}

// Destructor
AAnimal::~AAnimal(void){
    std::cout << "AAnimal was destroyed" << std::endl;
    return ;
}

