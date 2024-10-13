#ifndef AFORM_HPP
# define AFORM_HPP
#include <fstream>
#include <cstdlib>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:

        const std::string   _name;
        const int           _gradeToSign;
        const int           _gradeToExecute;
        bool                _isSigned;

    public:

        AForm(void);
        AForm(std::string name, int gradeToSign, int gradeToExecute);
        AForm(const AForm& other);
        AForm &operator=(const AForm &other);
        virtual ~AForm();

        /* Accesors */

        std::string getName() const;
        bool        getStatus() const;
        int         getGradeToSign() const;
        int         getGradeToExecute() const;

        /* Member functions */

        void			beSigned(const Bureaucrat & obj);
		virtual void	execute(const Bureaucrat & executor) const = 0;


        /* Exception Classes */

        class   GradeTooHighException: public std::exception {
            virtual const char* what() const throw() { return "Grade is hight"; }
        };

        class   GradeTooLowException: public std::exception {
            virtual const char* what() const throw() { return "Grade is low"; }
        };

		class  NotSignedException: public std::exception {
            virtual const char* what() const throw() { return "Form is not signed"; }
        };
};

std::ostream&   operator<<( std::ostream& o, const AForm& rhs );

#endif

