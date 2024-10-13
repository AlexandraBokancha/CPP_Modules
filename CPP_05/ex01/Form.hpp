#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:

        const std::string   _name;
        const int           _gradeToSign;
        const int           _gradeToExecute;
        bool                _isSigned;

    public:

        Form(void);
        Form(std::string name, int gradeToSign);
        Form(const Form& other);
        Form &operator=(const Form &other);
        ~Form();

        /* Accesors */

        std::string getName() const;
        bool        getStatus() const;
        int         getGradeToSign() const;
        int         getGradeToExecute() const;

        /* Member functions */

        void beSigned(const Bureaucrat & obj);


        /* Exception Classes */

        class   GradeTooHighException: public std::exception {
            virtual const char* what() const throw() { return "Grade is hight"; }
        };

        class   GradeTooLowException: public std::exception {
            virtual const char* what() const throw() { return "Grade is low"; }
        };
};

std::ostream&   operator<<( std::ostream& o, const Form& rhs );

#endif

