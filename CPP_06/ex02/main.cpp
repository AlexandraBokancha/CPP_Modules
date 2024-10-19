# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
# include "type_functions.cpp"

void test3(){
    
    /* testing identify(Base &p)() funciton*/
    
    Base * a = generate();
    identify(*a);
    Base * b = generate();
    identify(*b);
    Base * c = generate();
    identify(*c);
    Base * d = generate();
    identify(*d);
    Base * e = generate();
    identify(*e);
    delete a;
    delete b;
    delete c;
    delete d;
    delete e;
}
void test2(){
    
    /* testing identify(Base *p)() function */
    
    Base * a = generate();
    identify(a);
    Base * b = generate();
    identify(b);
    Base * c = generate();
    identify(c);
    Base * d = generate();
    identify(d);
    Base * e = generate();
    identify(e);
    Base * f = NULL; // will not detect any type
    identify(f);
    delete a;
    delete b;
    delete c;
    delete d;
    delete e;
}

void test1(){
    
    /* testing generate() function */

    Base * newBase = generate();
    if (newBase)
        std::cout << "creation of new object succeed" << std::endl;
    delete newBase;
}

int main(){
    //test1();
    // test2();
    //test3();
    return 0;
}