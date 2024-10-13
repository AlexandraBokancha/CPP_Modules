**pure virtual function**

pure virtual function (virtual = 0) : no implementation;

pure virtual function are used :
- if a function doesn't have any use in the base class;
- but the function must be implemented by all its derevid classes;

**abstract classes**

- it has at least one pure virtual function;
- derived class have to override that function;
- it can't be instantiated (creation of a new instance of the class), but you can create a pointer or a reference of Abstract class;
- an abstract class can have a constructor (its derived class will use it);
- it mainly used for Upcasting, so its
derived classes can use its interface;

**interface** 

-no attributes;
-it does not have an implementation of any of its methods;
-it can be considered as a collection of method declarations;
-it can be simulated by making all methods pure virtual;
-we can think of Interface as a header files in C++;