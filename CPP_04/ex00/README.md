1. Virtual member function

By marking the function in the base class as virtual, you have the possibility of overriding this function in the derived class. This is key to allow polymorphism to work.

Non-virtual members can also be redefined in derived classes, but non-virtual members of derived classes cannot be accessed through a reference of the base class.

**Runtime cost for virtual functions**

    Additional memory is required to store the V table, which allows us to dispatch to the correct function

    Every time when we call a virtual function, we need to go through the V table to determine which function to map to use

the linkage is dynamic and not static;

virtual member function will be called a method
which resolution will be dynamic -> will be done during the execution;

2. Virtual destructor

**make your destructor virtual if your class has any virtual functions.**

        A virtual destructor is used to free up the memory space allocated by 
        the derived class object or instance while deleting instances of the derived
        class using a base class pointer object. A base or parent class destructor
        use the virtual keyword that ensures both base class and the derived class 
        destructor will be called at run time, but it called the derived class first
        and then base class to release the space occupied by both destructors.

more info: https://isocpp.org/wiki/faq/virtual-functions