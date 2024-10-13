#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <cstring>
#include <iostream>
#include <new> // new and delete operators;

class	Zombie{
	private:
		std::string	_name;
	public :
	
        Zombie( void );
		~Zombie( void );

		void    setZombie( std::string name );
		void	announce( void );
};

/* It must allocate N Zombie objects in a single allocation. 
The function returns a pointer to the first zombie */

Zombie* zombieHorde( int N, std::string name );

#endif