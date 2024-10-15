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

-> compile-time conversion, used for explicit conversions that are considered safe by the compiler

-> used to convert between related types, 
such as numeric types or pointers in the same
inheritance hierarchy 

int main(void){

    int a = 42; // reference value
    double b = a; // ok
    int c = b; // doesn't work
    int d = static_cast<int>(b); // ok, the fractional part will be truncated
}

int main(void){
    
    Child1 a;
    Parent * b = &a; // implicit upcast using an address of a
    Child1 * c = b; // doesn't work
    Child2 * d = static_cast<Child2 *>(b); // explicit downcast, but this can be a problem
    
    Unrelated * e = static_cast<Unrelated *>(&a); // no, it's detached from other classes

}

5. **dynamic cast**

-> mainly uset to perform downcasting (converting
a pointer/reference of a base class to a derived class)

-> it's happenning at the runtime and not during the compilation; programm may compile but dynamic cast may fail at runtime

-> it only works with polymorphic instances (at least one of the function in your class has to be virtual)

-> it's useful when you don't know the actual type of your object/value

-> it the conversion is not possible : returns NULL/bad_cast exception

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

-> used to modify the const or volatile qualifier of a variable

-> it allow to temporarily remove the constancy of an object
and make modifications

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

![alt text](<Screenshot from 2024-10-15 14-03-32.png>)

for more info: https://cplusplus.com/doc/tutorial/typecasting/