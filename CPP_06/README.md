** additional rules of 42 for this module **

For each exercise, the type conversion must be solved using one specific type of casting.
Your choice will be checked during defense

**casts in c++**

/* C exemples */ 

1. **type conversion**


int main(void){
    
    int a = 42; // reference value
    double b = a; // implicit conversion cast 
    double c = (double) a; // excplicit conversion cast

}

2. **type reinterpretation**

int main(void){

    float a = 420.042f; // reference value
    void *b = &a; // implicit  reinterpretation
    void *c = (void *) &a; explicit reinterpretation
}

/* C++ exemples */

3. **upcast and downcast**

class Parent;
class Child1: public Parent;
class Child2: public Parent;

int main(void){

    Child1 a; // reference value
    Parent * b = &a; // implicit reinterpretation
    Parent * c = (Parent *) &a; // explicit reinterpretation

    Parent * d = &a; // implicit upcast
    Child1 * e = d; // implicit downcast -> you shouldn't do this, it will not compile 
    Child2 * f = (Child2 *) d; // explicit downcast, but will cause issues, it will interpret child2 as child2 (they are not similiat)

}