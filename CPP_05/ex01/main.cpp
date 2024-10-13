#include "Bureaucrat.hpp"
#include "Form.hpp"

void test4(){
    Form form("quittance", 30);
    Bureaucrat bureacrat("John", 20);
    form.beSigned(bureacrat);
    bureacrat.signForm(form); // will sign
    for (int i = 0; i < 20; i++)
        bureacrat.downGrade();
    form.beSigned(bureacrat); // will throw a error
}

void test3(){
    Form form("quittance", 151); // will throw a error, you can replace it with (nb < 0)
}

void test2(){

    /* we have an exception */

    Form form("quittance", 10);
    Bureaucrat bureacrat("John", 20);
    form.beSigned(bureacrat); // will throw an exception beacaus 20 > 10;
    bureacrat.signForm(form); // this part of the code will not be executed
}

void test1(){

    /* everything is good */

    Form form("quittance", 30);
    std::cout << form;
    Bureaucrat bureacrat("John", 20);
    form.beSigned(bureacrat);
    bureacrat.signForm(form);
}

int main(){

    try{
        //test1();
        //test2();
        //test3();
        //test4();
    }
    catch (std::exception & e){
        std::cout << e.what() << std::endl;
    }
    return 0; 
}