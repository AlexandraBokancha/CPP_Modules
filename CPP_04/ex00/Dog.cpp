#include "Dog.hpp"

// Default constructor
Dog::Dog(void) : Animal("Dog"){
    std::cout << "Dog was created" << std::endl;
    return ;
}

// Copy constructor
Dog::Dog(const Dog &other) : Animal(other)
{
  //  std::cout << "Copy constructor called" << std::endl;
    return ;
}

// Assignment operator overload
Dog &Dog::operator=(const Dog &other)
{
   // std::cout << "Assignment operator called" << std::endl;
    if (this != &other)
        Animal::operator=(other);
    return (*this);
}

void Dog::makeSound() const{
    std::cout << "ouf, ouf" << std::endl;
}

// Destructor
Dog::~Dog(void)
{
    std::cout << "Dog was destroyed" << std::endl;
    return ;
}

