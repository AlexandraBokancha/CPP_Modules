#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class Animal
{
    protected:

        std::string _type;

    public:

        Animal(void);
        Animal(std::string const &type);
        Animal(const Animal& other);
        Animal &operator=(const Animal &other);
        virtual ~Animal();
    
        virtual void makeSound() const;
        std::string const & getType() const;
};

#endif

