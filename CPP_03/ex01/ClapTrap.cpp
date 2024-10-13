#include "ClapTrap.hpp"

// Default constructor
ClapTrap::ClapTrap( void ) : _name("Karl"), _hitPoints(10), _energyPoints(10), _attackDamage(0){
    std::cout << "Default ClapTrap constructor called" << std::endl;
    return ;
}

ClapTrap::ClapTrap( std::string name ) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0){
    std::cout << "Default ClapTrap constructor called" << std::endl;
    return ;
}

// Copy constructor
ClapTrap::ClapTrap( const ClapTrap & rhs ) : _name(rhs._name), _hitPoints(rhs._hitPoints), _energyPoints(rhs._energyPoints), _attackDamage(rhs._attackDamage){
    std::cout << "Copy constructor called" << std::endl;
    return ;
}

// Assignment operator overload
ClapTrap &ClapTrap::operator=(const ClapTrap &rhs){
    std::cout << "Assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->_name = rhs._name;
        this->_hitPoints = rhs._hitPoints;
        this->_energyPoints = rhs._energyPoints;
        this->_attackDamage = rhs._attackDamage;
    }
    return (*this);
}

// Destructor
ClapTrap::~ClapTrap(void){
    std::cout << "ClapTrap destructor called" << std::endl;
    return ;
}

void ClapTrap::attack(const std::string & target){
    if (_hitPoints && _energyPoints)
    {
        std::cout << "ClapTrap " << _name << " attacks " \
        << target << ", causing " << _attackDamage \
        << " points of damage !" << std::endl;
        _energyPoints--;
    }
    else
    {
        if (_energyPoints == 0)
            std::cout << "ClapTrap " << _name << " is out of energy. Attack is not possible" << std::endl;
        else if (_hitPoints == 0)
            std::cout << "ClapTrap " << _name << " is out of hit points. Attack is not possible" << std::endl;
        return ;
    }
}

void ClapTrap::takeDamage(unsigned int amount){
    if (_hitPoints <= amount)
    {
        std::cout << "ClapTrap " << _name << " is out of hit points" << std::endl;
        _hitPoints = 0;
        return ;
    }
    _hitPoints -= amount;
    std::cout << "ClapTrap " << _name << " takes damage of " \
        << amount << ". Hit points balance: " << _hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){

    if (_energyPoints <= amount)
    {
        std::cout << "ClapTrap " << _name << " is out of energy" << std::endl;
        _energyPoints = 0;
        return ;
    }
    _hitPoints += amount;
    std::cout << "ClapTrap " << _name << " was repaired of " << amount \
    << ". Hit points balance: " << _hitPoints << std::endl;
    _energyPoints--;
}
