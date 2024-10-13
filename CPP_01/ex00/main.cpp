#include "Zombie.hpp"

int	main(void)
{
	std::string	name;

	std::cout << "Choose a name for you stackZombie : " << std::endl;
	std::cin >> name;
	randomChump(name);
	std::cout << "Choose a name for you heapZombie : " << std::endl;
	std::cin >> name;
	Zombie *pZombie = newZombie(name);
	delete pZombie;
	return (0);
};
