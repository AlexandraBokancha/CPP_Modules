#include "HumanB.hpp"

HumanB::HumanB( std::string name ){
    this->_name = name;
    this->_myWeapon = 0;
}

void    HumanB::setWeapon( Weapon& weapon ){
    this->_myWeapon = &weapon;
}

void    HumanB::attack( void ) const{
    if (_myWeapon == 0)
    {
        std::cout << this->_name << " doesn't have a weapon " << std::endl;
        return ;
    }
    std::cout << this->_name << " attacks with their " \
        << this->_myWeapon->getType() << std::endl;
}

HumanB::~HumanB( void ){
   std::cout << this->_name << " has been destroyed" << std::endl;
}
