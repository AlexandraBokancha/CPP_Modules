#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main( void )
{

	/* TEST 1: name constructor */

	DiamondTrap newChild("Boby");

	newChild.attack("Suzy");
	newChild.takeDamage(10);
	newChild.beRepaired(2);
	newChild.highFivesGuys();
	newChild.whoAmI();
	newChild.guardGate();

	/* TEST 2: default constructor */

	DiamondTrap lostChild;

	lostChild.attack("nobody");
	lostChild.takeDamage(10);
	lostChild.beRepaired(2);
	lostChild.highFivesGuys();
	lostChild.whoAmI();
	lostChild.guardGate();
	

	return 0;
}
