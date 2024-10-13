#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat
{
    private:

        const std::string   _name;
        int                 _grade;
        
    public:

        Bureaucrat(void);
        Bureaucrat(const std::string & name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();

        /* Accessors */

        std::string getName() const;
        int         getGrade() const;
        
        /* Member functions */

        void    upGrade();
        void    downGrade();
        void    signForm(Form & target);


        /* Exception Classes */

        class   GradeTooHighException: public std::exception {
            virtual const char* what() const throw() { return "Grade is too hight (1 is a limit)"; }
        };

        class   GradeTooLowException: public std::exception {
            virtual const char* what() const throw() { return "Grade is too low (150 is a limit)"; }
        };

};

/* << operator to ostream */

std::ostream&   operator<<( std::ostream& o, const Bureaucrat& rhs );

#endif
