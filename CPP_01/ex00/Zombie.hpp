#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <cstring>
#include <iostream>
#include <new> // new and delete operators;

class	Zombie{
	private:
		std::string	_name;
	public :
	
		/* Constuctor */
		Zombie( std::string name );
		
		/* Destructor */
		~Zombie( void );
		
		void	announce( void );
};

/* It creates a zombie, name it, and return it 
so you can use it outside of the function scope (we should use heap for
this purpose) */

Zombie*	newZombie( std::string name );
	
/* It creates a zombie, name it, and the zombie announces itself. */

void	randomChump( std::string name );

#endif