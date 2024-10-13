#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <iostream>

class   Weapon{

    private:
        std::string _type;

    public:

        Weapon( std::string type_name );
        ~Weapon( void );

        const std::string& getType( void ) const;
        void    setType( std::string new_type );

};

#endif