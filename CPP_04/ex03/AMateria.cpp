#include "AMateria.hpp"

AMateria::AMateria( void ) : _type("foo"){
    std::cout << "(Materia) Default constructor called" << std::endl;
    return ;
}

AMateria::AMateria( std::string const & type ) : _type(type){
    std::cout << "(Materia) Parameters constructor called" << std::endl;
    return ;
}

AMateria::AMateria( const AMateria & other ){
    std::cout << "(Materia) Copy constructor called" << std::endl;
    this->_type = other._type;
}

/* While assigning a Materia to another,
copying the type doesn’t make sense */

AMateria &AMateria::operator=( const AMateria &other ){
    (void) other;
    std::cout << "(Materia) assignment operator called" << std::endl;
    return (*this);
}

AMateria::~AMateria( void ){
    std::cout << "(Materia) Destructor called" << std::endl;
    return ;
}

                            /* MEMBER FUNCTIONS */

std::string const & AMateria::getType( void ) const{
    return this->_type;
}

void AMateria::use( ICharacter & target ){
    std::cout << this->_type << "used at " << target.getName() << std::endl;
}
