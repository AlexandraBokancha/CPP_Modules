#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"

// a derived class from ClapTrap
// it inherit its conststructors and destructor

class ScavTrap : virtual public ClapTrap
{
    public:

        ScavTrap(void);
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap & rhs);
        ScavTrap &operator=(const ScavTrap & rhs);
        ~ScavTrap();

        void guardGate(); // function specific to this class
        void attack(std::string const & target); // should print different message
};

#endif

