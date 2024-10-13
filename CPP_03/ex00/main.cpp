#include "ClapTrap.hpp"

int main( void )
{
	std::string name = "Karl";
	ClapTrap obj(name);

	obj.attack("Suzy");
	obj.takeDamage(-7);
	obj.beRepaired(3);
	obj.attack("boo");
	obj.takeDamage(5);
	obj.attack("boo");
	obj.beRepaired(4);
	obj.beRepaired(3);
	obj.beRepaired(5);
	obj.attack("boo");
	return 0;
}
