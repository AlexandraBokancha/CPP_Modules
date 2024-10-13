#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
    /* TEST 1: subject test of an array of animals */
   
    Animal* animals[10];

    for (int i = 0; i < 5; i++){
        animals[i] = new Dog();
    }
    for (int i = 5; i < 10; i++){
        animals[i] = new Cat();
    }
    for (int i = 0; i < 10; i++)
        delete animals[i];


    /* TEST 2: subject test of a deep copy (chaque objet doit
    posseder sa propre copie de ces membres) */

    // const Animal* j = new Dog();
    // const Animal* i = new Cat();

    // delete j; // should not create a leak
    // delete i;


    /* TEST 3: deep copy and its sources (copieCat)*/

    // Cat originalCat;

    // originalCat.getBrain().setIdea(0, "Ruin a flower");

    // Cat copieCat = originalCat;

    // std::cout << "Original Cat's idea: " << std::endl;
    // originalCat.getBrain().getIdea(0);
    // std::cout << "Copied Cat's idea: " << std::endl;
    // copieCat.getBrain().getIdea(0);

    // /* on modifie l'original pour voir si cela impact la copie (la copie profonde
    //     ne doit pas etre changee apres la modification de loriginal) */

    // originalCat.getBrain().setIdea(0, "Sleep all day");
    // std::cout << "Original Cat's idea: " << std::endl;
    // originalCat.getBrain().getIdea(0);
    // std::cout << "Copied Cat's idea: " << std::endl;
    // copieCat.getBrain().getIdea(0);

    return 0;
}