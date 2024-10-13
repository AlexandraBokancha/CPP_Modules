Inheritance C++

1. Single Inheritance

In single inheritance, a class is allowed to inherit from only one class. i.e. one base class is inherited by one derived class only.

2. Base class access specification 

**protected** : 

when it's only accesible from the instance of a class (or a child class)

**private** :

only from a class (not from a child);
we cannot acces private members of a base class without using a getter/setter;

**public** :

from anywhere


![Screenshot from 2024-09-18 13-49-36](https://github.com/user-attachments/assets/8258825a-7947-4a57-a90c-8d417881f5fa)

3. Constructors and Destructors in Base and Derived Classes

The base class's constructor is called before the derived class's constructor. The destructors are called in reverse order, with the derived class's destructor being called first.
