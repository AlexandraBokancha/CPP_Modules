#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"


void test7(){
	
	/* bureaucrat will sign both forms and then execute them successfully */
	
	AForm *newForm;
	PresidentialPardonForm form("rabbit");
	newForm = &form;
	Bureaucrat bureaucrat("John", 2);
	bureaucrat.signForm(form);
	bureaucrat.executeForm(*newForm);
	RobotomyRequestForm form2("robot");
	newForm = &form2;
	bureaucrat.signForm(form2);
	form2.execute(bureaucrat);
}

void test6(){

	/* will throw an exception because form is not signed */
	
	AForm *newForm;
	PresidentialPardonForm form("rabbit");
	newForm = &form;
	Bureaucrat bureaucrat("John", 23);
	bureaucrat.executeForm(*newForm);
}

void test5(){

	/* will execute robotomy form */

	AForm *newForm = new RobotomyRequestForm("robot");
	try{
		Bureaucrat bureacrat("Jim", 32);
		bureacrat.signForm(*newForm);
		newForm->execute(bureacrat);
		delete newForm;
	}
	catch (std::exception & e){
        std::cout << e.what() << std::endl;
		delete newForm; // we need to free memory if we catch a error;
    }
}

void test4(){

	/* will execute presedential form */

	AForm *newForm = new PresidentialPardonForm("rabbit");
	try{
		Bureaucrat bureacrat("Jim", 2);
		bureacrat.signForm(*newForm);
		newForm->execute(bureacrat);
		delete newForm;
	}
	catch (std::exception & e){
        std::cout << e.what() << std::endl;
		delete newForm; // we need to free memory if we catch a error;
    }
}

void test3(){
		
	/* will throw an exception because grade of 
		bureaucrat (149) > gradeToExecute (147) */

	AForm *newForm = new ShrubberyCreationForm("tree");
	try{
		Bureaucrat bureacrat("John", 145);
		bureacrat.signForm(*newForm);
		bureacrat.downGrade();
		bureacrat.downGrade();
		bureacrat.downGrade();
		bureacrat.downGrade();
		newForm->execute(bureacrat);
		delete newForm;
	}
	catch (std::exception & e){
        std::cout << e.what() << std::endl;
		delete newForm; // we need to free memory if we catch a error;
    }
}


void test2(){

	/* will execute ShrubberyForm*/

	AForm *newForm = new ShrubberyCreationForm("new_tree");
	
	try{
		Bureaucrat bureacrat("John", 23);
		bureacrat.signForm(*newForm);
		newForm->execute(bureacrat);
		delete newForm;
	}
	catch (std::exception & e){
        std::cout << e.what() << std::endl;
		delete newForm; // we need to free memory if we catch a error;
    }
}

void test1(){

	/* will throw an exception because form is not signed */

	AForm *newForm = new ShrubberyCreationForm("tree");
	try{
		Bureaucrat bureacrat("John", 23);
		newForm->execute(bureacrat);
		delete newForm;
	}
	catch (std::exception & e){
        std::cout << e.what() << std::endl;
		delete newForm; // we need to free memory if we catch a error;
    }
}

int main(){

	/* SHRUBERRY TESTS*/
	
	//test1();
	//test2();
	//test3();

	/* PRESEDENTIAL TESTS */

    //test4();

	/* ROBOTOMY TESTS */
	//test5();
	
	/* executeForm() function test */
	
	//test6();
	//test7();

	return 0; 
}