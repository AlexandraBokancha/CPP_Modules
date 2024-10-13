#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure"){
    std::cout << "(Cure) Default constructor called" << std::endl;
    return ;
}

Cure::Cure(const Cure &other) : AMateria(other) {
    std::cout << "(Cure) Copy constructor called" << std::endl;
    return ;
}

Cure &Cure::operator=(const Cure &other){
    std::cout << "(Cure) Assignment operator called" << std::endl;
    if (this != &other)
        AMateria::operator=(other);
    return (*this);
}

Cure::~Cure(void){
    std::cout << "(Cure) Destructor called" << std::endl;
    return ;
}

                        /* MEMBER FUNCTIONS */
                        
AMateria* Cure::clone() const{
    return (new Cure(*this));
}

void Cure::use(ICharacter & target){
    std::cout << "\033[32mCure: * heals " << target.getName() << "'s wounds *\033[0m" << std::endl;
}
