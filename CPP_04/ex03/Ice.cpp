#include "Ice.hpp"

Ice::Ice( void ) : AMateria("ice"){
    std::cout << "(Ice) Default constructor called" << std::endl;
    return ;
}

Ice::Ice( const Ice &other ) : AMateria(other){
    std::cout << "(Ice) Copy constructor called" << std::endl;
    return ;
}

Ice &Ice::operator=( const Ice &other ){
    std::cout << "(Ice) Assignment operator called" << std::endl;
    if (this != &other)
        AMateria::operator=(other);
    return (*this);
}

Ice::~Ice( void ){
    std::cout << "(Ice) Destructor called" << std::endl;
    return ;
}

                        /* MEMBER FUNCTIONS */
                        
AMateria* Ice::clone() const {
    return (new Ice(*this));
}

void Ice::use(ICharacter & target){
    std::cout << "\033[32mIce: * shoots an ice bolt at " << target.getName() << " *\033[0m" << std::endl;
} 

