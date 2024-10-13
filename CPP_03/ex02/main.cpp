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
	
	FragTrap sillyChild("Paul");

	sillyChild.attack("nobody");
	sillyChild.takeDamage(8);
	sillyChild.beRepaired(0);
	sillyChild.highFivesGuys();;
	
	return 0;
}
