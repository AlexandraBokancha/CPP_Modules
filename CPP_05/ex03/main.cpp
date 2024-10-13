#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

void test3(){
	try{
		Intern someRandomIntern;
		Bureaucrat someRandomBureaucrat("John", 5);
		AForm* rrf;
		rrf = someRandomIntern.makeForm("not a form", "Jonny");
		if (rrf)
			rrf->execute(someRandomBureaucrat);
		delete rrf;
	}
	catch (std::exception & e){
		std::cout << e.what() << std::endl;
		//delete rrf;
	}
}

void test2(){

	/* test de makeForm() */

	try{
		Intern someRandomIntern;
		Bureaucrat someRandomBureaucrat("John", 5);
		AForm* rrf;
		rrf = someRandomIntern.makeForm("presedential pardon", "Jimmy");
		if (rrf){
			rrf->beSigned(someRandomBureaucrat); // si on met cette ligne en commentaire, on va catch une exception
			rrf->execute(someRandomBureaucrat);
		}
		delete rrf;
		rrf = someRandomIntern.makeForm("shrubbery creation", "tree");
		if (rrf){
			rrf->beSigned(someRandomBureaucrat); // si on met cette ligne en commentaire, on va catch une exception
			rrf->execute(someRandomBureaucrat);
		}
		delete rrf;
	}
	catch (std::exception & e){
		std::cout << e.what() << std::endl;
		//delete rrf;
	}
}

void test1(){

	/* mandatory test : creates a RobotomyRequestForm targeted on "Bender */
	
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	if (rrf)
		return ;
}

int main(){

	//test1();
	//test2();
	//test3();

	return 0; 
}