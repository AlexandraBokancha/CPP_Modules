#include "Base.hpp"
#include <cstdlib>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

/* It randomly instanciates A, B or C
and returns the instance as a Base pointer.*/
Base *generate( void ){
    int i = rand() % 3;

    switch (i){
        case 0:
            return new A;
            break;
        case 1:
            return new B;
            break;
        case 2:
            return new C;
            break;
        default:
            std::cout << "No possible instanciation" << std::endl;
            return (NULL);
            break;
    }
}

/* It prints the actual type of the object
pointed to by p: "A", "B" or "C".*/
void identify(Base* p){
    A *a = dynamic_cast<A *>(p);
    if (a != NULL){
        std::cout << "Type of the object pointed by |" << p << "| is 'A'" << std::endl;
        return;
    }
    B *b = dynamic_cast<B *>(p);
    if (b != NULL){
        std::cout << "Type of the object pointed by |" << p << "| is 'B'" << std::endl;
        return;
    }
    C *c = dynamic_cast<C *>(p);
    if (c != NULL)
        std::cout << "Type of the object pointed by |" << p << "| is 'C'" << std::endl;
    if (a == NULL && b == NULL && c == NULL)
        std::cout << "Type was not detected" << std::endl;
}

/* It prints the actual type of the object pointed to by p: "A", "B" or "C". Using a pointer
inside this function is forbidden.*/
void identify(Base& p){
    try{
        A & a = dynamic_cast<A &>(p);
        std::cout << "Type of the object refered by |" << &p << "| is 'A'" << std::endl;
        return (void) a;
    }
    catch (std::exception & e){}
    try{
        B & b = dynamic_cast<B &>(p);
        std::cout << "Type of the object refered by |" << &p << "| is 'B'" << std::endl;
        return (void) b;
    }
    catch (std::exception & e){}
    try{
        C & c = dynamic_cast<C &>(p);
        std::cout << "Type of the object refered by |" << &p << "| is 'C'" << std::endl;
        return (void) c;
    }
    catch (std::exception & e){}
}