#include "WrongCat.hpp"

// Default constructor
WrongCat::WrongCat(void) : WrongAnimal("Cat"){
    std::cout << "WrongCat was created" << std::endl;
    return ;
}

// Copy constructor
WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other){
  //  std::cout << "Copy constructor called" << std::endl;
    return ;
}

// Assignment operator overload
WrongCat &WrongCat::operator=(const WrongCat &other)
{
    //std::cout << "Assignment operator called" << std::endl;
    if (this != &other)
        WrongAnimal::operator=(other);
    return (*this);
}

void WrongCat::makeSound() const {
    std::cout << "(Cat) meow" << std::endl;
}

// Destructor
WrongCat::~WrongCat(void){
    std::cout << "WrongCat was destroyed" << std::endl;
    return ;
}

