#include "Bureaucrat.hpp"

void test4(){
    /* member function test + ostream operator */ 
   
    Bureaucrat bureaucrat("Suzy", 150);

    bureaucrat.upGrade();
    std::cout << bureaucrat << std::endl;

}

void test3(){
    /* will throw an exception */

    Bureaucrat bureaucrat("Jin", 0);
}

void test2(){
    /* will throw an exception */
       
    Bureaucrat bureaucrat("Carl", 151);
}

void test1(){
    /* will throw an exception */

    Bureaucrat bureaucrat("Suzy", 150);
    bureaucrat.downGrade();
}

int main(){

    try{
        // test1();
        // test2();
        // test3();
        // test4();
    }
    catch (std::exception & e){
        std::cout << e.what() << std::endl;
    }
    return 0; 
}