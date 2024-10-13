#include "ScavTrap.hpp"

// Default constructor
ScavTrap::ScavTrap() : ClapTrap(){
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "Default ScavTrap constructor called" << std::endl;
    return ;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name){
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "Default ScavTrap constructor called" << std::endl;
    return ;
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap &rhs): ClapTrap(rhs){
    std::cout << "Copy constructor called" << std::endl;
    return ;
}

// Assignment operator overload
ScavTrap &ScavTrap::operator=(const ScavTrap &rhs){
    std::cout << "Assignment operator called" << std::endl;
    if (this != &rhs)
        ClapTrap::operator=(rhs);
    return (*this);
}

void ScavTrap::attack(std::string const & target){
    if (_hitPoints && _energyPoints)
    {
        std::cout << "ScavTrap " << _name << " attacks " \
        << target << ", causing " << _attackDamage \
        << " points of damage !" << std::endl;
        _energyPoints--;
    }
    else
    {
        if (_energyPoints == 0)
            std::cout << "ScavTrap " << _name << " is out of energy. Attack is not possible" << std::endl;
        else if (_hitPoints == 0)
            std::cout << "ScavTrap " << _name << " is out of hit points. Attack is not possible" << std::endl;
        return ;
    }
}

void ScavTrap::guardGate(){
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
    return;
}

// Destructor
ScavTrap::~ScavTrap(void){
    std::cout << "ScavTrap destructor called" << std::endl;
    return ;
}

