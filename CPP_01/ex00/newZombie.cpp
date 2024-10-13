#include "Zombie.hpp"

Zombie*	newZombie( std::string name )
{
	Zombie	*pointZ;

	pointZ = new Zombie(name);
	pointZ->announce();
	return (pointZ);
};
