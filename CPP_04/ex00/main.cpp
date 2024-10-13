#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    /* TEST 1 : mandatory test */

    // const Animal* meta = new Animal();
    // const Animal* j = new Dog();
    // const Animal* i = new Cat();
    // std::cout << j->getType() << " " << std::endl;
    // std::cout << i->getType() << " " << std::endl;
    // i->makeSound(); // will output the cat sound!
    // j->makeSound();
    // meta->makeSound();
    // delete j;
    // delete i;
    // delete meta;
    // return 0;

    /* TEST 2 : don't use the virtual keyword */

    // const WrongAnimal* meta = new WrongAnimal();
    // const WrongAnimal* i = new WrongCat();
    // std::cout << "i type is: " << i->getType() << std::endl;
    // std::cout << "meta type is: " << meta->getType() << std::endl;
    // i->makeSound();
    // meta->makeSound();
    // delete i;
    // delete meta;
    // return 0;

    /* TEST 3 : Cat is a cat */

    // WrongCat sillyCat;
    // WrongAnimal fakeCat("Cat");

    // sillyCat.makeSound();
    // fakeCat.makeSound();

    /* TEST 4: not a parametric constructors */

    // Animal animal;
	// std::cout << animal.getType() << std::endl;
	// animal.makeSound();
		
	// Cat cat;
	// std::cout << cat.getType() << std::endl;
	// cat.makeSound();
		
	// Dog dog;
	// std::cout << dog.getType() << std::endl;
	// dog.makeSound();

    return 0;
}