#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void )
{
	ClapTrap parent("John");

	parent.attack("Jane");
	parent.takeDamage(2);
	parent.beRepaired(1);

	ScavTrap child("Karl");

	child.attack("Suzy");
	child.takeDamage(3);
	child.beRepaired(2);
	child.guardGate();

	return 0;
}
