#include "Dog.hpp"

// Default constructor
Dog::Dog(void) : Animal("Dog"){
    _brain = new Brain();
    std::cout << "Dog was created" << std::endl;
    return ;
}

// Copy constructor
Dog::Dog(const Dog &other) : Animal(other)
{
    _brain = new Brain(*other._brain);
  //  std::cout << "Copy constructor called" << std::endl;
}

// Assignment operator overload
Dog &Dog::operator=(const Dog &other)
{
   // std::cout << "Assignment operator called" << std::endl;
    if (this != &other)
    {
        delete _brain;
        _brain = new Brain(*other._brain); // deep copy
    }
    return (*this);
}

void Dog::makeSound() const{
    std::cout << "Dog: ouf, ouf" << std::endl;
}

// Destructor
Dog::~Dog(void)
{
    delete _brain;
    std::cout << "Dog was destroyed" << std::endl;
    return ;
}

