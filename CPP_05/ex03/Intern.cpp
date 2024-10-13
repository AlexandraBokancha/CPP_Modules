#include "Intern.hpp"

// Default constructor
Intern::Intern(void)
{
    std::cout << "(Intern) Default constructor called" << std::endl;
    return ;
}

// Copy constructor
Intern::Intern(const Intern &other)
{
    std::cout << "(Intern) Copy constructor called" << std::endl;
    (void) other;
    return ;
}

// Assignment operator overload
Intern &Intern::operator=(const Intern &other)
{
    std::cout << "(Intern) Assignment operator called" << std::endl;
    (void) other;
    return (*this);
}

// Destructor
Intern::~Intern(void)
{
    std::cout << "(Intern) Destructor called" << std::endl;
    return ;
}

// methods 

AForm * PresidentialFormCreator(const std::string & target){
    return new PresidentialPardonForm(target);
}

AForm * RobotomyFormCreator(const std::string & target){
    return new RobotomyRequestForm(target);
}

AForm * ShrubberyFormCreator(const std::string & target){
    return new ShrubberyCreationForm(target);
}

// member function

AForm * Intern::makeForm(const std::string & nameForm, const std::string & target) const{
    FormCreator fnPtr[] = {
        ShrubberyFormCreator,
        RobotomyFormCreator,
        PresidentialFormCreator};
    std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presedential pardon"
    };
    for (int i = 0; i < 3; i++){
        if (nameForm == formNames[i]){
            AForm *newForm =  fnPtr[i](target);
            std::cout << "Intern creates " << newForm->getName() << std::endl;
            return (newForm);
        }
    }
    std::cout << "Intern : no form find with this name" << std::endl;
    return (NULL);
}   

