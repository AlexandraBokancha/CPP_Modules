#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
    public:
        Intern(void);
        Intern(const Intern& other);
        Intern &operator=(const Intern &other);
        ~Intern();

		AForm * makeForm(const std::string & nameForm, const std::string & targetForm) const;
};

// FormCreator points to a member function that creates AForm* 
// object and that takes (const string &) -> name of a form to create;

typedef AForm* (*FormCreator) (const std::string &);

#endif
