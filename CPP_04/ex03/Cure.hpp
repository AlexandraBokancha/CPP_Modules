#ifndef CURE_HPP
# define CURE_HPP
# include "AMateria.hpp"
# include "ICharacter.hpp"

// derived class 

class Cure : public AMateria
{
    public:

        Cure( void );
        Cure( const Cure& other );
        Cure &operator=( const Cure &other );
        ~Cure();

        AMateria* clone() const;
        void use( ICharacter & target );
};

#endif

