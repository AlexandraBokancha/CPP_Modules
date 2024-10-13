#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include <iostream>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private :
	
		const std::string		_target;

    public:

        PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string & target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
        ~PresidentialPardonForm();

		void execute(const Bureaucrat & executor) const;
};

#endif

