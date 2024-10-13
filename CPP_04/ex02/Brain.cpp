#include "Brain.hpp"

// Default constructor
Brain::Brain(void){
    std::cout << "Brain was created" << std::endl;
    return ;
}

// Copy constructor
Brain::Brain(const Brain &other){
   // std::cout << "Copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++){
        this->_ideas[i] = other._ideas[i];
    }
    return ;
}

// Assignment operator overload
Brain &Brain::operator=(const Brain &other){
   // std::cout << "Assignment operator called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; i++){
            this->_ideas[i] = other._ideas[i];
        }
    }
    return (*this);
}

void Brain::setIdea(int index, const std::string & idea){
    if (index >= 0 && index < 100){
        _ideas[index] = idea;
    }
    else
        std::cout << "Index is out of range" << std::endl;
}

void Brain::getIdea(int index) const{
    if (index >= 0 && index < 100){
        std::cout << "My idea is " << _ideas[index] << std::endl;
    }
    else
        std::cout << "Index is out of range" << std::endl;
}

// Destructor
Brain::~Brain(void){
    std::cout << "Brain was destroyed" << std::endl;
    return ;
}
