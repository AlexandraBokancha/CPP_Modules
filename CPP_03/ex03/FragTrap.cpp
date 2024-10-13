#include "FragTrap.hpp"

// Default constructor
FragTrap::FragTrap(): ClapTrap(){
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "Default FragTrap constructor called" << std::endl;
    return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "Default FragTrap constructor called" << std::endl;
    return ;
}

// Copy constructor
FragTrap::FragTrap(const FragTrap &other): ClapTrap(other){
    std::cout << "Copy constructor called" << std::endl;
    return ;
}

// Assignment operator overload
FragTrap &FragTrap::operator=(const FragTrap &other)
{
    std::cout << "Assignment operator called" << std::endl;
    if (this != &other)
        ClapTrap::operator=(other);
    return (*this);
}

void FragTrap::attack(std::string const & target){
    if (_hitPoints && _energyPoints)
    {
        std::cout << "FragTrap " << _name << " attacks " \
        << target << ", causing " << _attackDamage \
        << " points of damage !" << std::endl;
        _energyPoints--;
    }
    else
    {
        if (_energyPoints == 0)
            std::cout << "FragTrap " << _name << " is out of energy. Attack is not possible" << std::endl;
        else if (_hitPoints == 0)
            std::cout << "FragTrap " << _name << " is out of hit points. Attack is not possible" << std::endl;
        return ;
    }
}

void FragTrap::highFivesGuys(){
    std::cout << _name << ": " <<"Who’s up for some high fives? Let’s spread the good vibes!" << std::endl;
    return ;
}

// Destructor
FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap destructor called" << std::endl;
    return ;
}

