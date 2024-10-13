#include "Character.hpp"

/* the inventory is empty at construction */

Character::Character(void) : _name("foo"){
    std::cout << "(Character) Default constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        _slots[i] = NULL;
    return ;
}

Character::Character(const std::string & name) : _name(name){
    std::cout << "(Character) Parameters constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        _slots[i] = NULL;
    return ;
}

/* Using clone() for deep copy in copy constructor and for an assignement operator */

Character::Character(const Character &other) {
    std::cout << "(Character) Copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++){
        if (_slots[i])
            delete _slots[i];
        if (other._slots[i])
            _slots[i] = other._slots[i]->clone();
        else
            _slots[i] = NULL;
    }
}

Character &Character::operator=(const Character &other){
    std::cout << "(Character) Assignment operator called" << std::endl;
    if (this != &other){
        this->_name = other._name;
        for (int i = 0; i < 4; i++){
            if (_slots[i])
                delete _slots[i];
            if (other._slots[i])
                _slots[i] = other._slots[i]->clone();
            else
                _slots[i] = NULL;
        }
    }
    return (*this);
}

Character::~Character(void){
    std::cout << "(Character) Destructor called" << std::endl;
    for (int i = 0; i < 4; i++){
        if (_slots[i])
            delete _slots[i];
    }
    return ;
}

                /* MEMBER FUNCTIONS */

std::string const & Character::getName() const{
    return (this->_name);
}

/* in case they try to add a Materia to a full inventory or
use/unequip an unexisting Materia, don't do anything */

void Character::equip(AMateria* m){
    if (!m)
        return ;
    for (int i = 0; i < 4; i++){
        if (_slots[i] == NULL){
            _slots[i] = m;
            return ;
        }
    }
}

/* must NOT delete the Materia */

void Character::unequip( int idx ){
    if (idx >= 0 && idx < 4 && _slots[idx])
        _slots[idx] = NULL;
}

void Character::use( int idx, ICharacter & target){
    if (idx >= 0 && idx < 4 && _slots[idx])
        _slots[idx]->use(target);
}