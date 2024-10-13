#include "Bureaucrat.hpp"

// Default constructor
Bureaucrat::Bureaucrat(void) :_name("foo"), _grade(1) {
    std::cout << "(Bureaucrat) Default constructor called" << std::endl;
    return ;
}

// Parametric constructor
Bureaucrat::Bureaucrat(const std::string & name, int grade) : _name(name), _grade(grade){
    if (_grade < 1)
        throw  Bureaucrat::GradeTooHighException();
    if (_grade > 150)
        throw Bureaucrat::GradeTooLowException();
    std::cout << "(Bureaucrat) Parametric constructor called" << std::endl;
    return ;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {
    std::cout << "(Bureaucrat) Copy constructor called" << std::endl;
    return ;
}

// Assignment operator overload (name is constant, so we cannot change it)
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other){
    std::cout << "(Bureaucrat) Assignment operator called" << std::endl;
    if (this != &other){
        this->_grade = other.getGrade();
    }
    return (*this);
}

std::string Bureaucrat::getName() const{
    return this->_name;
}

int Bureaucrat::getGrade() const{
    return this->_grade;
}

void Bureaucrat::downGrade(){
    if (this->_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

void Bureaucrat::upGrade(){
    if (this->_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

void Bureaucrat::signForm(Form & target){
    try{
        target.beSigned(*this);
        std::cout << _name << " signed " << target.getName() << std::endl;
    }
    catch(std::exception & e){
        std::cout << _name << " couldn't sign " << target.getName() << " because " << e.what() << std::endl;
    } 
}

// Destructor
Bureaucrat::~Bureaucrat(void){
    std::cout << "(Bureaucrat) Destructor called" << std::endl;
    return ;
}

std::ostream&   operator<<( std::ostream& o, const Bureaucrat& rhs ){
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
    return o;
}
