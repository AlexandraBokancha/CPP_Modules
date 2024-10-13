#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include <iostream>
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
    private:

        std::string _name;

    public:

        DiamondTrap(void);
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap& other);
        DiamondTrap &operator=(const DiamondTrap &other);
        ~DiamondTrap();

        void whoAmI();
        using ScavTrap::attack;

};

#endif

