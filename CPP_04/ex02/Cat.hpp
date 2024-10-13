#ifndef CAT_HPP
# define CAT_HPP
# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
    private:

        Brain* _brain;

    public:

        Cat(void);
        Cat(const Cat& other);
        Cat &operator=(const Cat &other);
        ~Cat();

        Brain & getBrain( void ) const;
        void makeSound() const;
};

#endif
