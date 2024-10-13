**virtual destructor**

Virtual destructors are useful when you might potentially delete an instance of a derived class through a pointer to base class;

We need to declare a destructor as virtual in polymorphic
base classes;

If class has ANY virtual function, it should have a virtual destructor;