**additional rules of 42 for this module**

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

4. **static cast**

int main(void){

    int a = 42; // reference value
    double b = a; // ok
    int c = b; // doesn't work
    int d = static_cast<int>(b); // ok
}

// static_cast is used between compatible addresses
in the same inheritance tree

int main(void){
    
    Child1 a;
    Parent * b = &a; // implicit upcast using an address of a
    Child1 * c = b; // doesn't work
    Child2 * d = static_cast<Child2 *>(b); // explicit downcast, but this can be a problem
    
    Unrelated * e = static_cast<Unrelated *>(&a); // no, it's detached from other classes

}

5. **dynamic cast**

-> it's happenning at the runtime and not during the compilation; programm may compile but dynamic cast may fail at runtime

-> it only works with polymorphic instances (at least one of the function in your class has to be virtual)

-> it's useful when you don't know the actual type of your object/value

class Parent {public : virtual ~Parent(void){}};

int main(void){
    
    Child1 a;
    Parent * b = &a; // implicit upcast

    // explicit downcast

    Child1 * c = dynamic_cast<Child1 *>(b);
    if (c == NULL) 
        // conversion is NOT OK
    else
        // conversion is OK
    
    // explicit downcast -> will fail
    try{
        Child2 & d = dynamic_cast<Child2 &>(*b);
    }
    catch{...}
}

6. **reinterpret cast**

-> you can reinterpret any address with this cast (with all the consequences)

int main(void){

    float a = 420.042f;

    void * b = &a;
    int * c = reinterpret_cast<int *>(b);
    int & d = reinterpret_cast<int &>(b);
}

7. **const cast**

-> do it, but be sure you have a good reason 

int main(void){

    int a = 42;

    int const * b  = &a;
    int * c = b; // no, beacause b is not mutable
    int * d = const_cast<int *>(b); // ok
}

8. **cast operators**

private :
    float _v;

operator float() -> {return this->_v};
operator int() -> {return static_cast<int>(this->_v)}

int main(void){
    
    Foo a(420.024f);
    float b = a;
    int c = a;
}

9. **excplicit keyword**

-> say to compiler that our constructor
needs an explicit conversion
