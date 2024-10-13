#include "Weapon.hpp"

Weapon::Weapon( std:: string type_name ){
    this->setType(type_name);
}

/*A getType() member function that returns a const reference to type*/

const std::string& Weapon::getType( void ) const{
    return (this->_type);
}

/* A setType() member function that sets type using 
    the new one passed as parameter. */

void    Weapon::setType( std::string new_type ){
    this->_type = new_type;
}

Weapon::~Weapon( void ){
    std::cout << this->_type << " has been destroyed" << std::endl;
}
