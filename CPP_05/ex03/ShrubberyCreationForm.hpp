#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include <iostream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
	
		const std::string		_target;

    public:

        ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string & target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
        ~ShrubberyCreationForm();

		void execute(const Bureaucrat & executor) const;
};

#endif

