#ifndef DOG_HPP
# define DOG_HPP
# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
    private:

        Brain* _brain;

    public:

        Dog(void);
        Dog(const Dog& other);
        Dog &operator=(const Dog &other);
        ~Dog();

        Brain & getBrain( void ) const;
        void makeSound() const;
};

#endif

