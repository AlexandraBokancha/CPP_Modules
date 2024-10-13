#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main(){

    /* exemple 1: on peut pas creer un objet de la classe AAnimal car
    c'est une classe abstraite */
     
    // AAnimal a;

    /* exemple 2: on peut creer un pointer qui va pointer
    sur un objet d'une classe derivee */

    AAnimal *cp = new Cat();

    cp->makeSound();
    delete cp;

    return 0;
}