#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "Weapon.hpp"

// HumanA takes the Weapon in its constructor
// HumanA will always be armed -> so we can use a reference

class   HumanA{
   
    private:

        std::string _name;
        Weapon& _myWeapon;
        
    public:

        HumanA( std:: string name, Weapon& weapon );
        ~HumanA( void );

        void    attack( void ) const;
};

#endif