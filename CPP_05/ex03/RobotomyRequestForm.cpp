#include "RobotomyRequestForm.hpp"

// Default constructor
RobotomyRequestForm::RobotomyRequestForm(void) : AForm(), _target("foo")
{
    std::cout << "(Robotomy) Default constructor called" << std::endl;
    return ;
}

// Parametric constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string & target) : AForm(target, 72, 45), _target(target)
{
    std::cout << "(Robotomy) Parametric constructor called" << std::endl;
    return ;
}
// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other._target, 72, 45), _target(other._target)
{
    std::cout << "(Robotomy) Copy constructor called" << std::endl;
    return ;
}

// Assignment operator overload
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    std::cout << "(Robotomy) Assignment operator called" << std::endl;
    if (this != &other)
		AForm::operator=(other);
    return (*this);
}

/**
 * @brief Check that the forme is signed and that the grade of
 * the bureaucrat is high enough. Otherwise, throw an appropriate 
 * exception.
 * 
 * In case of success, makes some drilling noises. 
 * Then, informs that <target> has been robotomized
 * successfully 50% of the time.
 * Otherwise, informs that the robotomy failed.
 * 
 * -> std::rand() % 2 == 0 : This gives a 50% chance, as rand() % 2 will return 
 * either 0 or 1. If it's 0, we consider the robotomy a success;
 * if it's 1, the robotomy fails.
 */
void RobotomyRequestForm::execute(const Bureaucrat & executor) const{
	if (getStatus() == false)
		throw AForm::NotSignedException();
	if (executor.getGrade() > getGradeToExecute())
	 	throw AForm::GradeTooLowException();
	std::cout << _target << " makes some drilling noises" << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	std::cout << "The robotomy is failed" << std::endl;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << "(Robotomy) Destructor called" << std::endl;
    return ;
}

