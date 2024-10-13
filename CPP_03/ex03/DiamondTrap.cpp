#include "DiamondTrap.hpp"

// Default constructor
DiamondTrap::DiamondTrap(void) : FragTrap(), ScavTrap(){
    this->_name = ClapTrap::_name;
    _hitPoints = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FragTrap::_attackDamage;
    std::cout << "DiamondTrap default constructor called" << std::endl;
    return ;
}

DiamondTrap::DiamondTrap(std::string name): FragTrap(name), ScavTrap(name){
    this->_name = name;
    ClapTrap::_name = name + "_clap_name";
    _hitPoints = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FragTrap::_attackDamage;
    std::cout << "DiamondTrap default constructor called" << std::endl;
    return ;
}
// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap &other): ClapTrap(other){
    std::cout << "Copy constructor called" << std::endl;
    return ;
}

// Assignment operator overload
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other){
    std::cout << "Assignment operator called" << std::endl;
    if (this != &other)
    {
        ScavTrap::operator=(other);
        this->_name = other._name;
    }
    return (*this);
}

void DiamondTrap::whoAmI(){
    std::cout << "I am a DiamondTrap named " << _name << " and my ClapTrap name: " << ClapTrap::_name << std::endl;
}

// Destructor
DiamondTrap::~DiamondTrap(void){
    std::cout << "DiamondTrap destructor called" << std::endl;
    return ;
}

