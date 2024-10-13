#include "Form.hpp"

// Default constructor
Form::Form(void) : _name("foo"), _gradeToSign(10), _gradeToExecute(1),  _isSigned(false)
{
    std::cout << "(Form) Default constructor called" << std::endl;
    return ;
}

// Parametric constructor
Form::Form(std::string name, int gradeToSign) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(1), _isSigned(false)
{
    if (_gradeToSign < 1 || _gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw Form::GradeTooLowException();
    std::cout << "(Form) Parametric constructor called" << std::endl;
    return ;
}

// Copy constructor
Form::Form(const Form &other) : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
    std::cout << "(Form) Copy constructor called" << std::endl;
    return ;
}

// Assignment operator overload (only status can be assigned -> other variables are 'const',
// but it doesn't make sense to assign a boolean)
Form &Form::operator=(const Form &other)
{
    std::cout << "(Form) Assignment operator called" << std::endl;
    (void) other;
    return (*this);
}

// Destructor
Form::~Form(void)
{
    std::cout << "(Form) Destructor called" << std::endl;
    return ;
}

std::string Form::getName() const{
    return this->_name;
}

bool        Form::getStatus() const{
    return this->_isSigned;
}

int         Form::getGradeToSign() const{
    return this->_gradeToSign;
}

int         Form::getGradeToExecute() const{
    return this->_gradeToExecute;
}

void Form::beSigned(const Bureaucrat & obj){
    if (obj.getGrade() > _gradeToSign)
        throw Form::GradeTooLowException();
    _isSigned = true;
}

std::ostream&   operator<<( std::ostream& o, const Form& rhs ){
    o << "Form name is " << rhs.getName() << std::endl;
    o << "Grade to sign is " << rhs.getGradeToSign() << std::endl;
    o << "Grade to execute is " << rhs.getGradeToExecute() << std::endl;
    o << "Status is " << rhs.getStatus() << std::endl;
    return o;
}
