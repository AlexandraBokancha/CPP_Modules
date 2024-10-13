#ifndef A_MATERIA_HPP
# define A_MATERIA_HPP
# include <iostream>
class ICharacter;
# include "ICharacter.hpp"

// abstract class

class AMateria{

    protected:

        std::string _type;

    public:

        AMateria( void );
        AMateria( std::string const & type );
        AMateria( const AMateria & other );
        AMateria &operator=( const AMateria &other );
        virtual ~AMateria( void );

        std::string const & getType() const; // Returns the materia type
        virtual AMateria* clone() const = 0; // pure method
        virtual void use( ICharacter& target );
};

#endif