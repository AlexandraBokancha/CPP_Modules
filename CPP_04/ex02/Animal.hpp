#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class AAnimal
{
    protected:

        std::string _type;

    public:

        AAnimal(void);
        AAnimal(std::string const &type);
        AAnimal(const AAnimal& other);
        AAnimal &operator=(const AAnimal &other);
        virtual ~AAnimal();
    
        virtual void makeSound() const = 0; // pure method
        std::string const & getType() const;
};

#endif

