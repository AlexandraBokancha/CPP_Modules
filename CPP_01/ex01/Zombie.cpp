#include "Zombie.hpp"

Zombie::Zombie( void ){
    return ;
}

void    Zombie::setZombie( std::string name ){
    this->_name = name;
}
		
void	Zombie::announce( void ){
	std::cout << this->_name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
};

Zombie::~Zombie( void ){
	std::cout << this->_name << ": has been destroyed" << std::endl;
};
