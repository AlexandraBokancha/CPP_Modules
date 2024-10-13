#include "Cat.hpp"

// Default constructor
Cat::Cat(void) : AAnimal("Cat"){
    _brain = new Brain();
    std::cout << "Cat was created" << std::endl;
    return ;
}

// Copy constructor
Cat::Cat(const Cat &other) : AAnimal(other){
    _brain = new Brain(*other._brain); // deep copy
   // std::cout << "Copy constructor called" << std::endl;
}

// Assignment operator overload
Cat &Cat::operator=(const Cat &other)
{
   // std::cout << "Assignment operator called" << std::endl;
    if (this != &other)
    {
        delete _brain;
        _brain = new Brain(*other._brain); // deep copy
    }
    return (*this);
}

void Cat::makeSound() const{
    std::cout << "Cat: meooow" << std::endl;
}

Brain & Cat::getBrain( void ) const{
    return (*_brain);
}

// Destructor
Cat::~Cat(void)
{
    delete _brain;
    std::cout << "Cat was destroyed" << std::endl;
    return ;
}

