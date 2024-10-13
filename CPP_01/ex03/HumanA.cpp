#include "HumanA.hpp"

// Constructor with initialization list to initialize the reference

HumanA::HumanA( std::string name, Weapon& weapon ) : _name(name), _myWeapon(weapon){};

void    HumanA::attack( void ) const{
    std::cout << this->_name << " attacks with their " \
        << this->_myWeapon.getType() << std::endl;
}

HumanA::~HumanA( void ){
   std::cout << this->_name << " has been destroyed" << std::endl;
}