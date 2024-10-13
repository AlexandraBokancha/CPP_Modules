#include "PresidentialPardonForm.hpp"

// Default constructor
PresidentialPardonForm::PresidentialPardonForm(void) : AForm(), _target("foo")
{
    std::cout << "(Presidential) Default constructor called" << std::endl;
    return ;
}
// Parametric constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string & target) : AForm(target, 25, 5), _target(target)
{
    std::cout << "(Presidential) Parametric constructor called" << std::endl;
    return ;
}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other._target, 25, 5), _target(other._target)
{
    std::cout << "(Presidential) Copy constructor called" << std::endl;
    return ;
}

// Assignment operator overload
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    std::cout << "(Presidential) Assignment operator called" << std::endl;
    if (this != &other)
		AForm::operator=(other);
    return (*this);
}

/**
 * @brief Check that the forme is signed and that the grade of
 * the bureaucrat is high enough. Otherwise, throw an appropriate 
 * exception.
 * 
 * In case of success, informs that <target> has been pardoned by Zaphod
 * Beeblebrox.
 */
void PresidentialPardonForm::execute(const Bureaucrat & executor) const{
	if (getStatus() == false)
		throw AForm::NotSignedException();
	if (executor.getGrade() > getGradeToExecute())
	 	throw AForm::GradeTooLowException();
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << "(Presidential) Destructor called" << std::endl;
    return ;
}

