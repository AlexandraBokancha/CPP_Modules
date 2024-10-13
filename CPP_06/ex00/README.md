**static methods**

Because static member functions are not associated with a particular object, they can be called directly by using the class name and the scope resolution operator (e.g. Something::getValue()). 

-> they have no *this pointer

interet pour ce module:

Faster execution: Static function in C++ can be faster to execute than non-static functions because they do not have to access any instance data. This can result in better performance for some operations.

Utility functions: Static function in C++ are often used to define utility functions that perform a general utility task and do not need to access or modify the state of the object.