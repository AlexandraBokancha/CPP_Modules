#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void){
    std::cout << "(MateriaSource) Default constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        _slots[i] = NULL;
    return ;
}

MateriaSource::MateriaSource(const MateriaSource &other){
    std::cout << "(MateriaSource) Copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++){
        if (_slots[i])
            delete _slots[i];
        if (other._slots[i])
            _slots[i] = other._slots[i]->clone();
        else
            _slots[i] = NULL;
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other){
    std::cout << "(MateriaSource) Assignment operator called" << std::endl;
    for (int i = 0; i < 4; i++){
        if (_slots[i])
            delete _slots[i];
        if (other._slots[i])
            _slots[i] = other._slots[i]->clone();
        else
            _slots[i] = NULL;
        }
    return (*this);
}

MateriaSource::~MateriaSource(void){
    std::cout << "(MateriaSource) Destructor called" << std::endl;
    for (int i = 0; i < 4; i++){
        if (_slots[i])
            delete _slots[i];
    }
    return ;
}

/** 
* @brief Copies the Materia passed as a parameter and store it in memory so it can be cloned
* later. Like the Character, the MateriaSource can know at most 4 Materias. They
* are not necessarily unique.
*/
void MateriaSource::learnMateria(AMateria* m){
    if (!m)
        return ;
    for (int i = 0; i < 4; i++){
        if (!_slots[i]){
            _slots[i] = m->clone();
            delete (m);
            return ;
        }
    }
}

/**
 * @brief Returns a new Materia. The latter is a copy of the Materia previously learned by
 * the MateriaSource whose type equals the one passed as parameter. Returns 0 if
 * the type is unknown 
 */
AMateria* MateriaSource::createMateria(std::string const & type){
    for (int i = 0; i < 4; i++){
        if (_slots[i] && _slots[i]->getType() == type)
            return (_slots[i]->clone());
    }
    return (0);
}
