#include "AForm.hpp"

// Default constructor
AForm::AForm(void) : _name("foo"), _gradeToSign(10), _gradeToExecute(1),  _isSigned(false)
{
    std::cout << "(AForm) Default constructor called" << std::endl;
    return ;
}

// Parametric constructor
AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _isSigned(false)
{
    if (_gradeToSign < 1 || _gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw AForm::GradeTooLowException();
    std::cout << "(AForm) Parametric constructor called" << std::endl;
    return ;
}

// Copy constructor
AForm::AForm(const AForm &other) : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
    std::cout << "(AForm) Copy constructor called" << std::endl;
    return ;
}

// Assignment operator overload (only status can be assigned -> other variables are 'const',
// but it doesn't make sense to assign a boolean)
AForm &AForm::operator=(const AForm &other)
{
    std::cout << "(AForm) Assignment operator called" << std::endl;
    (void) other;
    return (*this);
}

// Destructor
AForm::~AForm(void)
{
    std::cout << "(AForm) Destructor called" << std::endl;
    return ;
}

std::string AForm::getName() const{
    return this->_name;
}

bool        AForm::getStatus() const{
    return this->_isSigned;
}

int         AForm::getGradeToSign() const{
    return this->_gradeToSign;
}

int         AForm::getGradeToExecute() const{
    return this->_gradeToExecute;
}

void AForm::beSigned(const Bureaucrat & obj){
    if (obj.getGrade() > _gradeToSign)
        throw AForm::GradeTooLowException();
    _isSigned = true;
	std::cout << "The form is signed by " << obj.getName() << std::endl;
}

std::ostream&   operator<<( std::ostream& o, const AForm& rhs ){
    o << "Form name is " << rhs.getName() << std::endl;
    o << "Grade to sign is " << rhs.getGradeToSign() << std::endl;
    o << "Grade to execute is " << rhs.getGradeToExecute() << std::endl;
    o << "Status is " << rhs.getStatus() << std::endl;
    return o;
}
