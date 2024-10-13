#include "Cat.hpp"

// Default constructor
Cat::Cat(void) : Animal("Cat"){
    std::cout << "Cat was created" << std::endl;
    return ;
}

// Copy constructor
Cat::Cat(const Cat &other) : Animal(other){
   // std::cout << "Copy constructor called" << std::endl;
}

// Assignment operator overload
Cat &Cat::operator=(const Cat &other)
{
   // std::cout << "Assignment operator called" << std::endl;
    if (this != &other)
        Animal::operator=(other);
    return (*this);
}

void Cat::makeSound() const{
    std::cout << "meooow" << std::endl;
}

// Destructor
Cat::~Cat(void)
{
    std::cout << "Cat was destroyed" << std::endl;
    return ;
}

