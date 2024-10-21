#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>

// p. 1050 for class template
template <typename T>
class Array{

    private:

        T *aptr; // to point to the allocated array
        int arraySize; // number of elements in the array
        void subError(); // Handles subscripts out of range
    
    public:

        // Default constructor 
        Array();
        // Parametric constructor (n: for nb of elements)
        Array(unsigned int n);
        // Copy constructor 
        Array(const Array &);
        // Destructor
        ~Array();
        // Assignement operator
        Array &operator=(const Array & other);
        // Overloaded [] operator
        T &operator[](const int &);
        
        int size() const;
};

#endif