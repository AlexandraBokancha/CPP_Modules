#include "Serializer.hpp"

// Default constructor
Serializer::Serializer(void)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

// Copy constructor
Serializer::Serializer(const Serializer &other)
{
    std::cout << "Copy constructor called" << std::endl;
    (void) other;
    return ;
}

// Assignment operator overload
Serializer &Serializer::operator=(const Serializer &other)
{
    std::cout << "Assignment operator called" << std::endl;
    (void) other;
    return (*this);
}

// Destructor
Serializer::~Serializer(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

