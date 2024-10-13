#include "ShrubberyCreationForm.hpp"

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm(), _target("foo")
{
    std::cout << "(Shrubbery) Default constructor called" << std::endl;
    return ;
}

// Parametric constructor 
ShrubberyCreationForm::ShrubberyCreationForm(const std::string & target) : AForm(target, 145, 137), _target(target)
{
    std::cout << "(Shrubbery) Parametric constructor called" << std::endl;
    return ;
}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other._target, 145, 137), _target(other._target)
{
    std::cout << "(Shrubbery) Copy constructor called" << std::endl;
    return ;
}

// Assignment operator overload
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    std::cout << "(Shrubbery) Assignment operator called" << std::endl;
    if (this != &other)
		AForm::operator=(other);
    return (*this);
}

/**
 * @brief Check that the forme is signed and that the grade of
 * the bureaucrat is high enough. Otherwise, throw an appropriate 
 * exception.
 * 
 * In case of success, create a file <target>_shrubbery in the working directory, 
 * and writes ASCII trees inside it.
 */
void ShrubberyCreationForm::execute(const Bureaucrat & executor) const{
	if (getStatus() == false)
		throw AForm::NotSignedException();
	if (executor.getGrade() > getGradeToExecute())
	 	throw AForm::GradeTooLowException();
	std::string name = _target + "_shrubbery";
	std::ofstream myFile(name.c_str());
	if (myFile.is_open()) {
        myFile << "        ^^\n";
        myFile << "       ^^^^\n";
        myFile << "      ^^^^^^\n";
        myFile << "     ^^^^^^^^^\n";
        myFile << "    ^^^^^^^^^^^\n";
        myFile << "        |||\n";
        myFile << "        |||\n";
    }
	myFile.close();
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << "(Shrubbery) Destructor called" << std::endl;
    return ;
}

